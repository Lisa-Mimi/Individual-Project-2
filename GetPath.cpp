//
// Created by Lisa Gihozo & Miriam Uwingabiye on 28/11/2022.
//
#include "Airports.cpp"
#include "Routes.cpp"
#include "Airlines.cpp"
list<string> departure_point;
list<string> destination_point;
string city_departure, city_arrival, country_departure, country_arrival;

void set_departure_arrival_info(){
    string line;
    int count = 0;
    string file_name = "input_data.txt";
    ifstream my_file;
    my_file.open(file_name);
    while (getline(my_file, line)){
        stringstream stream(line);
        if(count == 0){
            getline(stream, city_departure, ',');
            getline(stream,country_departure);
            ++count;
        }
        else{
            getline(stream, city_arrival, ',');
            getline(stream,country_arrival,',');
        }
    }
}
void set_departure_destination_points(){
    list<tuple<string, string, string>> airports_list = Get_airports();
    for(auto element:airports_list) {
        string country = get<0>(element);
        string city = get<1>(element);
        string airport_code = get<2>(element);
        if (country == country_departure and city == city_departure) {
            departure_point.push_back(airport_code);
        }
        if (country == country_arrival and city == city_arrival) {
            destination_point.push_back(airport_code);
        }
    }
}


