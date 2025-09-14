#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct item {
    string name;
    int price;
    int stock;
};

void new_item() {
    ofstream store_inventory("store_inventory.csv", ios::app);
    if (!store_inventory.is_open()) {
        cout << "error: could not open file :(\n)";
        return;
    }

    int n;
    cout << "\nguidelines for inputs\n---------------------\n";
    cout << "spaces in item names are not allowed. ";
    cout << "separate words with underscores or dashes (otherwise program WILL CRASH)\n";
    cout << "integers only for prices and stocks\n\n";
    cout << "number of items: "; cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "\ncreating new item...\n";
    
        item thing;
        cout << "name:  "; cin >> thing.name;
        cout << "price: "; cin >> thing.price;
        cout << "stock: "; cin >> thing.stock;

        store_inventory << thing.name << "," << thing.price << "," 
        << thing.stock << "\n";
    }
    store_inventory.close();
}

void list_stock() {
    cout << "list of products:\n";
    ifstream store_inventory("store_inventory.csv");
    if (!store_inventory.is_open()) {
        cout << "error: could not open file :(\n\n";
        return;
    }
    string item_data;

    // TO DO: account for csv header line
    while(getline(store_inventory, item_data)) {
        stringstream ss(item_data);
        string item_name;
        int item_price, item_stock;
        char delimiter;

        getline(ss, item_name, ',');
        ss >> item_price >> delimiter >> item_stock;

        cout << item_name << " - $" << item_price 
        << " (" << item_stock << " in stock)\n";
    }
    cout << "end of list\n\n";
    store_inventory.close();
}

// TO DO: edit stock after purchase
void buy() {
    list_stock();
    int n;
    cout << "number of items to buy: "; cin >> n;

    ifstream store_inventory("store_inventory.csv");
    if (!store_inventory.is_open()) {
        cout << "error: could not open file :(\n\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        string name;
        cout << "product name: "; cin >> name;

        string item_data; bool found = false;
        while(getline(store_inventory, item_data)) {
            stringstream ss(item_data);
            string item_name;
            int item_price, item_stock;
            char delimiter;

            getline(ss, item_name, ',');
            ss >> item_price >> delimiter >> item_stock;

            if (name == item_name) {
                found = true;
                int quantity;
                cout << "quantity: "; cin >> quantity;
                if (quantity > item_stock) {
                    cout << "not enough stock :(\n\n";
                } else {
                    cout << "you bought " << quantity << " " 
                    << item_name << "(s) for $" 
                    << item_price * quantity << "\n";
                }
            }
        }
        if (!found) {cout << "item not found :(\n\n"; return;}
        store_inventory.clear(); // clear EOF flag
        store_inventory.seekg(0); // return to beginning of file
    }
    cout << "\nthank you for shopping with us :)\n";
    store_inventory.close();
}

int main() {
    int user, option; bool signed_in = true;
    cout << "\nwelcome to our shop :)\n";
    cout << "\nsigning in as:\n1. customer\n2. staff\n3. admin\n>  ";
    cin >> user;
    while (signed_in) {
        if (user == 1) {
            cout << "\n1. buy\n2. check balance\n3. sign out\n>  ";
            cin >> option;
            if (option == 1) buy();
            else if (option == 2) cout << "placeholder - check\n";
            else if (option == 3) signed_in = false;
            else cout << "invalid option; please enter 1/2/3\n";
        }
        else if (user == 2) {
            cout << "\n1. check stock\n2. add new product\n3. sign out\n>  ";
            cin >> option;
            if (option == 1) list_stock();
            else if (option == 2) new_item();
            else if (option == 3) signed_in = false;
            else cout << "invalid option; please enter 1/2/3\n";
        }
        else if (user == 3) {
            cout << "placeholder - admin menu\n";
            signed_in = false;
        }
    }
    cout << "\nsigning you out. bye bye :D\n\n";
    return 0;
}
