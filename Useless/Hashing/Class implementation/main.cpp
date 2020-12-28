#include <iostream>
#include <cstring>
#include "main.h"

using namespace std;

int main(){

	Hashtable<int> price_menu;

	price_menu.insert("Burger",120);
	price_menu.insert("Pepsi",20);
	price_menu.insert("BurgerPizza",150);
	price_menu.insert("Noodles",25);
	price_menu.insert("Coke",40);
	price_menu.insert("McPuff",50);

    int *price = price_menu.search("Coke");
	if(price == NULL){
		cout << "Not Found!" << endl;
	} else{
		cout << "Price is : " << *price << endl;
	}

	// price_menu.erase("Pepsi");
	price_menu["Dosa"] = 60;
	price_menu.print();
	cout << price_menu["Dosa"] << endl;
	return 0;
}
