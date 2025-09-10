#include <iostream>
#include <filesystem>
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
    fstream store_inventory("store_inventory.csv");
    store_inventory.open("store_inventory.csv", fstream::app); // THIS DOESN'T WORK???
    int n;
    cout << "guidelines for inputs\n---------------------\n";
    cout << "spaces in item names are not allowed. ";
    cout << "separate words with underscores or dashes (program WILL CRASH)\n";
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
    string item_data;

    while(getline(store_inventory, item_data)) {
        stringstream ss(item_data);
        string item_name;
        int item_price, item_quantity;
        char delimiter;

        getline(ss, item_name, ',');
        ss >> item_price >> delimiter >> item_quantity;

        cout << item_name << " - $" << item_price 
        << " (" << item_quantity << " in stock)\n";
    }
    cout << "end of list\n";
    store_inventory.close();
}

void buy() {
    list_stock();
    int n;
    cout << "\nnumber of items to buy: "; cin >> n;
    for (int i = 0; i < n; i++) {
        string name; bool match = false;
        cout << "product name: "; cin >> name;
    }
}

int main() {
    string user; int option; bool signed_in = true;
    cout << "welcome to our shop :)\n\nsigning in as:\ncustomer\nstaff\nadmin\n> ";
    cin >> user;
    while (signed_in) {
        if (user.compare("customer") == 0) {
            cout << "\n1. buy\n2. check balance\n3. sign out\n> ";
            cin >> option;
            if (option == 1) cout << "placeholder - buy stuff\n";
            else if (option == 2) cout << "placeholder - check\n";
            else if (option == 3) signed_in = false;
            else cout << "invalid option; please enter 1/2/3\n";
        }
        else if (user.compare("staff") == 0) {
            cout << "\n1. check stock\n2. add new product\n3. sign out\n> ";
            cin >> option;
            if (option == 1) list_stock();
            else if (option == 2) new_item();
            else if (option == 3) signed_in = false;
            else cout << "invalid option; please enter 1/2/3\n";
        }
    }
    cout << "\nsigning you out. bye bye :D\n\n";
    return 0;
}
