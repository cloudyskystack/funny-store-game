#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string item_data; char item_type; int price, stock;
    ifstream readthefile("data.txt");
    while (getline(readthefile, item_data)) {
        item_type = item_data[0];
        price = int(item_data[2]) - 48;
        stock = int(item_data[4]) - 48;
        cout << "item type " << item_type << " - $" << price << " (" << stock << " in stock)\n";
    }
}


// FIX THIS