#include "mylib.hh"

void print_home_screen(){
    system("cls");
    cout << endl << "============ Restaurant ============" << endl << endl;   
    cout << "1. Create new invoice" << endl;
    cout << "2. Show all invoices" << endl;
    cout << "3. Search" << endl;
    cout << "4. Exit" << endl << endl;
}

void loop(Customer *customer, int count){
    print_home_screen();
    cout << "Select an operation: ";
    char ch; cin >> ch;
    while(int(ch) < 49 || int(ch)>52){
        cout << "Invalid input!!! Please try again." << endl;
        cout << "Select an operation: ";cin >> ch;
    }
    int choice = int(ch) - 48;
    switch(choice){
        case 1:
            system("cls");
            char name[LEN]; int item_indices;
            cout << "Enter the customer's name: "; 
            cin.getline(name, LEN);
            cin.getline(name, LEN);
            cout << endl << "Enter number of items: ";
            cin >> item_indices;
            customer[count].set_data(name, item_indices);           
            for(int i = 0; i<item_indices; i++){
                cout << endl << "Enter item " << i+1 << ":\t\t";
                getline(cin, customer[count].item[i].food);
                getline(cin, customer[count].item[i].food);
                cout << "Enter the unit price:\t";
                cin >> customer[count].item[i].unit_price;
                cout << "Enter the quantity:\t";
                cin >> customer[count].item[i].quantity;
            }

            cout << endl << "Apply 10% discount? [y/n]: "; cin >> ch;
            while(int(ch)!=121 && int(ch)!=110){
                cout << "Invalid input!!! Please try again." << endl;
                cout << "Apply 10% discount? [y/n]: ";cin >> ch;
            }
            float discount;
            if(ch == 'y')    discount = 0.1;
            else    discount = 0;
            customer[count].print_receipt(discount);
            
            count++;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            cout << "\t\t\tGood Bye =))" << endl << endl; 
            exit(0);
            break;
    }
}