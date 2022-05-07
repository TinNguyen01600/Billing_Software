#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <stdio.h>
#include <Windows.h>
#include <cstdlib>
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
    void print_receipt(float discount){
        cout << endl << endl << "\t\t   TN Restaurant"<< endl;
        cout << "\t\t-------------------"<< endl;
        time_t now = time(0);
        char *date = ctime(& now);
        cout << "Date: " << date << endl;
        cout << "Invoice Of: " << this->name << endl;
        for(int i = 0; i<46; i++) cout << "-";
        cout << endl << "Items\t\tQuantity\t\tTotal" << endl;
        for(int i = 0; i<46; i++) cout << "-";
        cout << endl;
        for(int i = 0; i<this->item_indices; i++){
            int total = this->item[i].quantity * this->item[i].unit_price;
            cout << this->item[i].food << "\t\t" << this->item[i].quantity << "\t\t\t" << total << endl;
        }
        for(int i = 0; i<46; i++) cout << "-";
    };
    Customer *search(char *name_search){
        return(strcmp(name_search,this->name) == 0)?this : NULL;
    };
};

//------------------------------------------------------------------------

void print_home_screen();
void loop(Customer *customer, int count);
