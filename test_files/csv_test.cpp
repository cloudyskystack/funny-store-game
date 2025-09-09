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

    string item_data
    ifstream read_file("data.csv");
    while (getline(read_file, item_data)) {
        cout << item_data;
    }
    item_data.close();
}