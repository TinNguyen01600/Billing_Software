#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <conio.h>
#include <cstdio>
using namespace std;

const int LEN = 50;

class Customer{
    char name[LEN];
    int item_indices;
public:
    struct Item{
        string food;
        int unit_price, quantity;
    };
    void set_data(char *name, int item_indices){
        strcpy(this->name, name);
        this->item_indices = item_indices;
        Item *item = new Item[item_indices];
        for(int i = 0; i<item_indices; i++){
            cout << endl << "Enter item " << i+1 << ":\t\t";
            getline(cin, item[i].food);
            cout << "Enter the unit price:\t";
            cin >> item[i].unit_price;
            cout << "Enter the quantity:\t";
            cin >> item[i].quantity;
        }
    };
    Customer *search(char *name_search){
        return(strcmp(name_search,this->name) == 0)?this : NULL;
    };
};

//------------------------------------------------------------------------

int print_home_screen();
void loop(Customer *customer, int count);