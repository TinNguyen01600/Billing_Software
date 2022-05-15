#include "mylib.hh"

void print_home_screen(){
    system("cls");
    cout << endl << "============ Restaurant ============" << endl << endl;   
    cout << "1. Create new invoice" << endl;
    cout << "2. Show all invoices" << endl;
    cout << "3. Search" << endl;
    cout << "4. Exit" << endl << endl;
}

int check_continue(){
    char ch;
    cout << endl << endl << "Do you want to continue? [y/n]: "; cin >> ch;
    while(int(ch)!=121 && int(ch)!=110){
        cout << "Invalid input!!! Please try again." << endl;
        cout << "Do you want to continue? [y/n]: ";cin >> ch;
    }
    if(ch == 'y')   return 1;
    else{
        cout << "\t\t\tGood Bye =))" << endl << endl; 
        exit(0);
        return 0;
    }
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
        case 1:{
            system("cls");
            char name[LEN]; int item_indices;
            int sub_total = 0;
            float tax = 0, discount, grand_total;

            cout << "Enter the customer's name: "; 
            cin.getline(name, LEN);
            cin.getline(name, LEN);
            cout << endl << "Enter number of items: ";
            cin >> item_indices;
            Item *k; k = new Item[item_indices];

            for(int i = 0; i<item_indices; i++){
                cout << endl << "Enter item " << i+1 << ":\t\t";
                getline(cin, k[i].food);
                getline(cin, k[i].food);
                cout << "Enter the unit price:\t";
                cin >> k[i].unit_price;
                cout << "Enter the quantity:\t";
                cin >> k[i].quantity;

                sub_total += k[i].unit_price * k[i].quantity;
                k[i].tax = (float)k[i].unit_price * (float)k[i].quantity * 0.14;
                tax += k[i].tax;
            }

            cout << endl << "Apply 10% discount? [y/n]: "; cin >> ch;
            while(int(ch)!=121 && int(ch)!=110){
                cout << "Invalid input!!! Please try again." << endl;
                cout << "Apply 10% discount? [y/n]: ";cin >> ch;
            }
            if(ch == 'y')    discount = 0.1;
            else    discount = 0;
            discount = sub_total*discount;
            grand_total = sub_total - discount + tax;

            customer[count].set_data(name, item_indices, k, tax, discount, grand_total);
            delete k;
            cout << endl << endl;
            customer[count].print_receipt();

            cout << endl << "Do you want to save this bill in file? [y/n]: "; cin >> ch;
            while(int(ch)!=121 && int(ch)!=110){
                cout << "Invalid input!!! Please try again." << endl;
                cout << "Do you want to save this bill in file? [y/n]: ";cin >> ch;
            }
            if(ch == 'y'){
                customer[count].write_file();
                cout << "Receipt saved in file 'invoice.txt'.";
            }    
            
            if(check_continue()) count++; loop(customer, count);
            break;
        }
        case 2:
            system("cls");
            for(int i = 0; i<count; i++){
                customer[i].print_receipt();
                cout << endl << endl;
            }
            if(check_continue()) loop(customer, count);
            break;
        case 3:{
            system("cls");
            if(count == 0){
                cout << "No customer in database. Cannot search" << endl;
            }
            else{
                char customer_name_search[LEN];
			    Customer *temp; int temp_count = 0;
			    cout << "Enter customer name to be searched: "; 
                cin.getline(customer_name_search, LEN);
                cin.getline(customer_name_search, LEN);
			    // do {
      			//     if (temp_count == count){
                //         cout << "No customer found" << endl;
                //         goto label;
                //     }
                //     temp = customer[temp_count].search(customer_name_search);
      			//     temp_count++;
    		    // }
    		    // while (temp == NULL);
                // temp->print_receipt();

                for (int i = 0; i<count; i++){
                    temp = customer[i].search(customer_name_search);
                    if(temp != NULL){
                        temp->print_receipt();
                        cout << endl;
                        temp_count++;
                    }
                }
                if(temp_count == 0) cout << "No customer found" << endl;
            }
            if(check_continue()) loop(customer, count);
            break;
        }
        case 4:
            delete customer;
            cout << "\t\t\tGood Bye =))" << endl << endl;
            exit(0);
            break;
    }
}