#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <tuple>
#include <list>
#include <utility>
using namespace std;

class Node{
public:
    string state;
    list<Node> parent;
    
    void set_state(string state){
        this->state = state;
    }
    void set_parent(Node node){
        parent.emplace_back(node);
    }
    void find_path(){
        cout<<"Child:"<<this->state<<endl;
        Node one = *(this->parent.begin())
        cout<<"Parent:"<<one.state<<endl;
    }
};

void search(list<tuple<string, string>>& a, string source, const string& destination) {
    list<Node> frontier;
    set<string> explored;
    Node parent;
    parent.set_state(source);
    frontier.emplace_back(parent);
    while (!(frontier.empty())) {
        auto var = frontier.front();
        frontier.pop_front();
        explored.insert(var.state);
        for (auto element: a) {
            if (get<0>(element) == var.state) {
                string name = get<1>(element);
                Node child;
                child.set_state(name);
                child.set_parent(var);
                bool status = false;
                for(const auto& elem:frontier){
                    if(elem.state == child.state){
                        Node one = *(elem.parent.begin());
                        Node two = *(elem.parent.begin());
                        if(one.state == two.state){
                            status = true;
                        }
                        }
                        
                    }
                if (explored.count(child.state)== 0 and !status) {
                    if(child.state == destination){
                        return child.find_path();
                    }
                    frontier.emplace_back(child);
                }
            }
        }
    }
}
int main(){
    tuple<string, string> trial_1;
    tuple<string, string> trial_2;
    tuple<string, string> trial_3;
    tuple<string, string> trial_4;
    tuple<string, string> trial_5;
    tuple<string, string> trial_6;
    list<tuple<string, string>> trial;
    trial_1 = make_tuple("Lisa","Miriam");
    trial_2 = make_tuple("Lisa","Samantha");
    trial_3 = make_tuple("Miriam","Brenda");
    trial_4 = make_tuple("Miriam","Angel");
    trial_5 = make_tuple("Angel","Abigail");
    trial_6 = make_tuple("Angel","Cindy");
    trial.emplace_back(trial_1);
    trial.emplace_back(trial_2);
    trial.emplace_back(trial_3);
    trial.emplace_back(trial_4);
    trial.emplace_back(trial_5);
    trial.emplace_back(trial_6);

    

}
