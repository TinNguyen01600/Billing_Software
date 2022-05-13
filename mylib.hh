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
#include <fstream>
using namespace std;

const int LEN = 50;

struct Item{
    string food;
    int unit_price, quantity;
    float tax;
};

class Customer{
    char name[LEN];
    int item_indices;
    float tax, discount, grand_total;
public:
    Item *item;
    
    void set_data(char *name, int item_indices, Item *item, float tax, float discount, float grand_total){
        strcpy(this->name, name);
        this->item_indices = item_indices;
        this->item = item;
        this->tax = tax;
        this->discount = discount;
        this->grand_total = grand_total;
    };
    
    void print_receipt(){
        cout << "\t\t    TN Restaurant"<< endl;
        cout << "\t\t -------------------"<< endl;
        time_t now = time(0);
        char *date = ctime(& now);
        cout << "Date: " << date;
        cout << "Invoice Of: " << this->name << endl;

        for(int i = 0; i<56; i++) cout << "-";
        cout << endl << "Items\t\tQuantity\tTotal\t\tALV Tax" << endl;
        for(int i = 0; i<56; i++) cout << "-"; cout << endl;
        int sub_total = 0;
        for(int i = 0; i<this->item_indices; i++){
            int total = this->item[i].quantity * this->item[i].unit_price;
            sub_total += total;
            cout.width(17);
            cout << left << this->item[i].food << left << this->item[i].quantity << "\t\t " << total << "\t\t " << this->item[i].tax << endl;
        }
        for(int i = 0; i<56; i++) cout << "-";
        cout << endl << endl << "Sub Total \t" << sub_total << endl;
        cout << "Discount\t" << this->discount << endl;
        cout << "AlV Food Tax\t" << this->tax << endl;
        for(int i = 0; i<56; i++) cout << "-"; cout << endl;
        cout.width(50);
        cout << left << "Grand Total" << left << this->grand_total << endl;
        for(int i = 0; i<56; i++) cout << "-"; cout << endl;
    };
    
    void write_file(){
        ofstream myfile;
        myfile.open ("invoice.txt", ios_base::app);
        time_t now = time(0); char *date = ctime(& now);
        myfile << "Date: " << date;
        myfile << "Name: " << this -> name << endl;
        for(int i = 0; i<this->item_indices; i++){
            myfile << "  • " << this->item[i].food << " ---- ";
            myfile << this->item[i].quantity << " x " << this->item[i].unit_price << endl;
        }
        myfile << "Tax: " << this->tax << endl;
        myfile << "Discount: " << this->discount << endl;
        myfile << "Grand Total: " << this->grand_total << endl << endl;
        myfile.close();
    }

    Customer *search(char *name_search){
        return(strcmp(name_search,this->name) == 0)?this : NULL;
    };
};

//------------------------------------------------------------------------

void print_home_screen();
void loop(Customer *customer, int count);
int check_continue();
