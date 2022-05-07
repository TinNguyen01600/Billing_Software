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
        cout << endl << endl << "\t\t    TN Restaurant"<< endl;
        cout << "\t\t -------------------"<< endl;
        time_t now = time(0);
        char *date = ctime(& now);
        cout << "Date: " << date;
        cout << "Invoice Of: " << this->name << endl;

        for(int i = 0; i<56; i++) cout << "-";
        cout << endl << "Items\t\tQuantity\tTotal\t\tALV Tax" << endl;
        for(int i = 0; i<56; i++) cout << "-";
        cout << endl;
        int sub_total = 0; float alv_total = 0;
        for(int i = 0; i<this->item_indices; i++){
            int total = this->item[i].quantity * this->item[i].unit_price;
            sub_total += total;
            float alv = total * 0.14;     //Food tax in Finland is 14%
            alv_total += alv;
            cout.width(17);
            cout << left << this->item[i].food << left << this->item[i].quantity << "\t\t " << total << "\t\t " << alv << endl;
        }
        for(int i = 0; i<56; i++) cout << "-";
        cout << endl << endl << "Sub Total \t" << sub_total << endl;
        cout << "Discount\t" << discount*sub_total << endl;
        cout << "AlV Food Tax\t" << alv_total << endl;
        for(int i = 0; i<56; i++) cout << "-"; cout << endl;
        cout.width(50);
        cout << left << "Grand Total" << left << sub_total*(1-discount) + alv_total << endl;
        for(int i = 0; i<56; i++) cout << "-"; cout << endl;
    };
    Customer *search(char *name_search){
        return(strcmp(name_search,this->name) == 0)?this : NULL;
    };
};

//------------------------------------------------------------------------

void print_home_screen();
void loop(Customer *customer, int count);
