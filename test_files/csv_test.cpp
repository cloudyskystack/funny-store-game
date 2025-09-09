#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main () {
    ifstream read_file("data.csv");
    string item_data;
    while (getline(read_file, item_data)) {
        stringstream ss(item_data);
        string item_name;
        int item_price, item_quantity;
        char delimiter;

        getline(ss, item_name, ',');
        ss >> item_price >> delimiter >> item_quantity;

        cout << "Item: " << item_name 
             << ", Price: " << item_price 
             << ", Quantity: " << item_quantity << endl;
    }
    read_file.close();
}