
#include "Airports.cpp"
#include "Routes.cpp"
#include "Airlines.cpp"
#include<set>
#include <utility>

list<string> departure_point, destination_point; //stores airport codes of departure and arrival points
list<tuple<string, string, string, string>> route_path;
string city_departure, city_arrival, country_departure, country_arrival;

class Node{
public:
    string destination;
    string airline;
    string stops_num;
    list<Node> source;

    void set_destination(string location){
        this->destination = std::move(location);
    }
    void set_source(const Node& node){
        source.emplace_back(node);
    }
    void set_airline(string airline_code){
        airline = std::move(airline_code);
    }
    void set_stops(const string& stop){
        stops_num = stop;
    }

    // generating valid path
    void find_path(){
        string location = this->destination;
        string stops = this->stops_num;
        string airline_code = this->airline;
        Node locale = *(this->source.begin());
        tuple<string, string, string, string> flight_info;
        flight_info = make_tuple(locale.destination, location, airline_code, stops);
        route_path.push_back(flight_info);

        while(!(locale.source.empty())){
            Node arrival_point = *(locale.source.begin());
            flight_info = make_tuple(arrival_point.destination, locale.destination, locale.airline,
                                     locale.stops_num);
            route_path.push_back(flight_info);
            locale = arrival_point;
        }
        route_path.reverse();
    }
};

//reading information of input file
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

// getting airport codes of all possible arrival & departure points
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


void search_path(list<tuple<string, string, string, string>>& routes_list, string source, const list<string>& destination)
{
    list<Node> frontier;
    set<string> explored;
    Node parent; //node of source airport
    parent.set_destination(std::move(source));
    frontier.emplace_back(parent);
    while (!(frontier.empty())) {
        auto var = frontier.front();
        frontier.pop_front();
        explored.insert(var.destination);
        for (auto element: routes_list) {
            if (get<0>(element) == var.destination) {
                string destination_airport_code= get<1>(element);
                string airport_code = get<2>(element);
                string stops = get<3>(element);
                Node child; //node of destination airport
                child.set_destination(destination_airport_code);
                child.set_airline(airport_code);
                child.set_stops(stops);
                child.set_source(var);
                bool child_in_frontier = false; //determines if child node in frontier
                for(const auto& elem:frontier){
                    if(elem.destination == child.destination){
                        child_in_frontier = true;
                        }
                    }

                if (explored.count(child.destination)== 0 and !child_in_frontier) {
                    for(const auto& elem:destination){
                        if(child.destination == elem){
                            return child.find_path();
                        }
                    }
                    frontier.emplace_back(child);
                }
            }
        }
    }
}

//getting valid path
list<tuple<string, string, string, string>> getpath(){
    list<tuple<string, string, string, string>> routes_list = Get_routes();
    for(const auto& source:departure_point){
        search_path(routes_list,source,destination_point);
        if(!route_path.empty()){
            break;
        }
    }
    return route_path;
}
