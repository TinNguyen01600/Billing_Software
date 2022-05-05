#include "mylib.hh"

int print_home_screen(){
    system("cls");
    cout << endl << "============ Restaurant ============" << endl << endl;
    
    cout << "1. Create new invoice" << endl;
    cout << "2. Show all invoices" << endl;
    cout << "3. Search" << endl;
    cout << "4. Exit" << endl << endl;
    cout << "Select an operation: ";
    int choice; cin >> choice;
    return choice;
}

void loop(Customer *customer, int count){
    int choice = print_home_screen();
    switch(choice){
        case 1:
            char name[LEN]; int item_indices;
            cout << "Enter the customer's name: "; 
            cin.getline(name, LEN);
            cin.getline(name, LEN);
            cout << endl << "Enter number of items: ";
            cin >> item_indices;
            customer[count].set_data(name, item_indices);
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