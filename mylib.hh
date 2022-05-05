#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;

const int LEN = 50;

class Customer{
    char name[LEN];
    int item_indices;
    friend class Item;
};

//------------------------------------------------------------------------

class Item{

};

//------------------------------------------------------------------------

int print_home_screen();
void loop();