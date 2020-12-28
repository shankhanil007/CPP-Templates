#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class node{
public:
	string key;
	T value;
	node* next;

	node(string key, T val){
		this->key = key;
		value = val;
		next = NULL;
	}
	~node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template<typename T>
class Hashtable{

	node<T>** table;     // pointer to an array of pointers
	int current_size;
	int table_size;

	int hashFn(string key){
		int idx = 0;
		int p = 1;
		for(int i=0; i<key.length(); i++){
			idx = idx + (key[i]*p)%table_size;
			idx = idx % table_size;
			p = (p*27) % table_size;
		}
		return idx;
	}

	// expensive operation .. O(N)
	void rehash(){
		node<T>** oldTable = table;
		int oldTableSize = table_size;
		table_size = 2*(table_size); // approximation.. find the next prime
		table = new node<T>*[table_size];

		for(int i=0; i<table_size; i++){
			table[i]=NULL;
		}
		current_size = 0;

		// shifting old elements to the new table
		for(int i=0; i<oldTableSize; i++){
			node<T>* temp = oldTable[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
			// deletion of old LL
			if(oldTable[i]!=NULL){
				delete oldTable[i];  // head of LL .. delete
			}
		}
		delete [] oldTable;

	}

public:
	Hashtable(int ts=7){
		table_size = ts;
		table = new node<T>*[table_size];
		current_size = 0;

		for(int i=0; i<table_size; i++){
			table[i]=NULL;
		}
	}

	void insert(string key, T value){

		int idx = hashFn(key);

		node<T>* n = new node<T>(key,value);
		// Inserting at head of Linked list with id = idx
		// Inserting at head beneficial... need not traverse whole LL for deletion
		n->next = table[idx];
		table[idx] = n;
		current_size++;

		// ....//  REHASH
		float load_factor = current_size/(1.0 * table_size);
		if(load_factor>0.7){
			// Rehash
			rehash();
		}

	}

	void print(){        // not a part of hashtable class ... just for learning

		for(int i=0; i<table_size; i++){
			cout << "Bucket " << i << "->";
			node<T>* temp = table[i];
			while(temp!=NULL){
				cout << temp->key << "->";
				temp = temp->next;

			}
			cout << endl;
		}
	}

	T* search(string key){
		int idx = hashFn(key);
		node<T>* temp = table[idx];
		while(temp!=NULL){
			if(temp->key==key){
				return &temp->value;   // returning the address
			}
			temp = temp->next;
		}
		return NULL;   // T*
	}

	// CB TA code
	void erase(string key){
		int idx = hashFn(key);
		node<T>* temp = table[idx];
		node<T>* prev = NULL;
		while(temp!=NULL){
			if(temp->key==key){
				if(prev!=NULL){
					prev->next = temp->next;
				}
				else{
					table[idx] = temp->next;
				}
				temp->next=NULL;
				delete temp;
			}
			prev = temp;
			temp = temp->next;
		}
	}

	T& operator[](string key){
		T* f = search(key);
		if(f==NULL){
			T garbage;
			insert(key,garbage);
			f = search(key);
		}
		return *f;
	}


};
