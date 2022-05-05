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

void loop(){
    int choice = print_home_screen();
    switch(choice){
        case 1:

        case 2:

        case 3:

        case 4:
            cout << "\t\tGood Bye =))"; 
            exit(0);
    }
}