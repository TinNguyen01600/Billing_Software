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
    Item *item;
    void set_data(char *name, int item_indices){
        strcpy(this->name, name);
        this->item_indices = item_indices;
        this->item = new Item [item_indices];
    };
    Customer *search(char *name_search){
        return(strcmp(name_search,this->name) == 0)?this : NULL;
    };
};

//------------------------------------------------------------------------

int print_home_screen();
void loop(Customer *customer, int count);
void print_receipt(Customer *customer);