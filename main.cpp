//
// Created by Lisa Gihozo & Miriam Uwingabiye
//

#include <iostream>
#include <fstream>
#include<string>
#include "GetPath.cpp"
int main() {
    // Create and open input and output file
    ofstream MyFile("input_data.txt");
    ofstream File("output_data.txt");
    string  departure_info;
    string  arrival_info;

    // reading input file
    cout<<" enter city <Comma>country of departure point e.g: Accra,Ghana:";
    cin>> departure_info;
    cout<<endl;
    cout<<" enter city <Comma>country of destination point e.g: Accra,Ghana:";
    cin>> arrival_info;
    cout<<endl;

    // Writing to the input file
    MyFile <<departure_info<<endl;
    MyFile<<arrival_info<<endl;

    set_departure_arrival_info();
    set_departure_destination_points();

    // getting valid path
    auto routes = getpath();

    //Writing to output file
    int total_stops = 0;
    for(auto element: routes){
        string departure_airport_code = get<0>(element);
        string arrival_airport_code = get<1>(element);
        string airline_code = get<2>(element);
        string stops = get<3>(element);
        total_stops = total_stops + stoi(stops);
        File<<airline_code<<" from "<<departure_airport_code<<" to "<<arrival_airport_code<<" "<<stops<<" stops"<<endl;
    }
    File<<"Total flights: "<<routes.size()<<endl;
    File<<"Total additional stops: "<<total_stops<<endl;

    // Closing input and output files
    MyFile.close();
    File.close();
    return 0;
}
