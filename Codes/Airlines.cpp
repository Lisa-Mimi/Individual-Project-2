#include <iostream>
#include <fstream>
#include<string>
#include<sstream>

using namespace std;

void GetAirlines(){
    string file_name = "airlines.csv";
    ifstream my_file;
    my_file.open(file_name);
    string line, Airline_ID, Name, Alias, IATA_code, ICAO_code, Callsign, Country, Active;
    while (getline(my_file, line)) {
        stringstream stream(line);
        getline(stream, Airline_ID, ',');
        getline(stream, Name, ',');
        getline(stream, Alias, ',');
        getline(stream, IATA_code, ',');
        getline(stream, ICAO_code, ',');
        getline(stream, Callsign, ',');
        getline(stream, Country, ',');
        getline(stream, Active, ',');
    }
    my_file.close();
}