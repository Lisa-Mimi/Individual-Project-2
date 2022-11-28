#include <iostream>
#include <fstream>
#include<string>
#include "GetPath.cpp"
int main() {
    // Create and open a text file
    ofstream MyFile("input_data.txt");
    string  departure_info;
    string  arrival_info;
    cout<<" enter city <Comma>country of departure point e.g: Accra,Ghana:";
    cin>> departure_info;
    cout<<endl;
    cout<<" enter city <Comma>country of destination point e.g: Accra,Ghana:";
    cin>> arrival_info;
    cout<<endl;
    // Write to the file
    MyFile <<departure_info<<endl;
    MyFile<<arrival_info<<endl;
    set_departure_arrival_info();
    set_departure_destination_points();

    // Close the file
    MyFile.close();
    return 0;
}
