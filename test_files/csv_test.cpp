#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main () {
    ofstream data_file("data.csv");
    data_file << "test_product,55,32";
    data_file.close();
    
    ifstream read_file("data.csv");
    string item_data;
    while (getline(read_file, item_data)) {
        cout << item_data << endl;
    }
    read_file.close();
}