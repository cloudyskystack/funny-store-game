#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct item {
    string name;
    int price;
    int stock;
};

vector<item> storeroom;

void new_item() {
    int n;
    cout << "guidelines for inputs\n---------------------\nspaces in item names are not allowed. separate words with underscores or dashes (program WILL CRASH)\nintegers only for prices and stocks\n\n";
    cout << "number of items: "; cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "\ncreating new item...\n";
    
        item thing;
        cout << "name:  "; cin >> thing.name;
        cout << "price: "; cin >> thing.price;
        cout << "stock: "; cin >> thing.stock;
    
        storeroom.push_back(thing);
    }
}

void list_stock() {
    cout << "list of products:\n";
    if (storeroom.size() == 0) cout << "no products in stock";
    else {
        for (int i = 0; i < storeroom.size(); i++) {
            cout << storeroom.at(i).name << " - $" << storeroom.at(i).price << " (" << storeroom.at(i).stock << " in stock)\n";
        }
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
            while (not(option == 1 or option == 2 or option == 3)) {
                if (option == 1) {cout << "placeholder - buy\n"; break;}
                else if (option == 2) {cout << "placeholder - check\n"; break;}
                else if (option == 3) {signed_in = false; break;}
                else {
                    cout << "invalid input. please enter 1 / 2 / 3\n> ";
                }
            }
        }
        else if (user.compare("staff") == 0) {
            cout << "\n1. check stock\n2. add new product\n3. sign out\n> ";
            cin >> option;
            if (option == 1) list_stock();
            else if (option == 2) new_item();
            else signed_in = false;
        }
    }
    cout << "\nsigning you out. bye bye :D";
    return 0;
}
