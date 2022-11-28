#include <iostream>
#include <iostream>
#include <fstream>
#include<string>
#include<sstream>
#include<list>
#include<tuple>
using namespace std;
// list<tuple<string, string>>
list<tuple<string, string, string, string>> flight_info_list;
list<tuple<string, string>> Get_routes() {
    list<tuple<string, string>> routes_list;
    string file_name = "routes.csv";
    ifstream my_file;
    my_file.open(file_name);
    string line, airline_code, airline_ID, source_airport_code, source_airport_ID, destination_airport_code,
    destination_airport_ID, codeshare, stops, equipment;
    while (getline(my_file, line)) {
        stringstream stream(line);
        getline(stream, airline_code, ',');
        getline(stream, airline_ID, ',');
        getline(stream, source_airport_code, ',');
        getline(stream, source_airport_ID, ',');
        getline(stream, destination_airport_code, ',');
        getline(stream, destination_airport_ID, ',');
        getline(stream, codeshare, ',');
        getline(stream, stops, ',');
        getline(stream, equipment, ',');
        tuple<string, string> route = make_tuple(source_airport_code, destination_airport_code);
        tuple<string, string, string, string> flight_info;
        flight_info = make_tuple(source_airport_code,destination_airport_code,airline_code,stops);
        flight_info_list.push_back(flight_info);
        routes_list.push_back(route);
    }
    my_file.close();
    return routes_list;
}
list<tuple<string, string, string, string>> get_flight_info(){
    return flight_info_list;
}
