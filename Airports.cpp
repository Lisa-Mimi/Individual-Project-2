#include <iostream>
#include <fstream>
#include<string>
#include<sstream>
#include<list>
#include<tuple>
using namespace std;

list<tuple<string, string, string>> Get_airports() {
    list<tuple<string, string, string>> airport_list;
    string file_name = "airports.csv";
    ifstream my_file;
    my_file.open(file_name);
    string line, Airport_ID, Name, City, Country, IATA_code, ICAO_code, Latitude, Longitude, Altitude, Timezone, DST,
            database_time_zone, Type, Source_data;
    while (getline(my_file, line)) {
        stringstream stream(line);
        getline(stream, Airport_ID, ',');
        getline(stream, Name, ',');
        getline(stream, City, ',');
        getline(stream, Country, ',');
        getline(stream, IATA_code, ',');
        getline(stream, ICAO_code, ',');
        getline(stream, Latitude, ',');
        getline(stream, Longitude, ',');
        getline(stream, Altitude, ',');
        getline(stream, Timezone, ',');
        getline(stream, DST, ',');
        getline(stream, database_time_zone, ',');
        getline(stream, Type, ',');
        getline(stream, Source_data, ',');
        tuple<string, string, string> airport = make_tuple(Country, City, IATA_code);
        airport_list.push_back(airport);
    }
    my_file.close();
    return airport_list;
}

