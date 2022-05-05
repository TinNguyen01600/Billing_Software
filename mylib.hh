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
    friend class Item;
public:
    void set_data(char *, int);
    Customer *search(char *name_search){
        return(strcmp(name_search,this->name) == 0)?this : NULL;
    };
};

//------------------------------------------------------------------------

class Item{
    char food[LEN];
    int unit_price, quality;

};

//------------------------------------------------------------------------

int print_home_screen();
void loop(Customer *customer, int count);