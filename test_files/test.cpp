#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream myfile("filename.txt");
    myfile << "Files can be tricky, but it is fun enough!\n";
    myfile << "this is the second line in the text file";
    myfile.close();

    string mytext;
    ifstream myreadfile("filename.txt");
    while (getline(myreadfile, mytext)) {
        cout << mytext;
    }
    myreadfile.close();
}