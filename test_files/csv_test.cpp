#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main () {
    ofstream datafile("data.csv");
    datafile << "test_product,55,32";
    datafile.close();
}