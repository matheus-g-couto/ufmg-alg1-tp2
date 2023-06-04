#include "graph.hpp"

#include <bits/stdc++.h>

#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

Graph::Graph() {}

Graph::Graph(int person_total, int role_total) {
    this->person_total = person_total;
    this->role_total = role_total;
    this->adjacency_list.resize(person_total);

    this->person_counter = this->role_counter = 1;
}

Graph::~Graph() {
    this->adjacency_list.resize(0);
    this->person_total = -1;
}

void Graph::addPerson(string name) {
    if (!this->person_id[name]) {
        this->person_id[name] = this->person_counter;
        this->person_counter++;
    }
}

void Graph::addRole(string role) {
    if (!this->role_id[role]) {
        this->role_id[role] = this->role_counter;
        this->role_counter++;
    }
}

void Graph::addEdge(string person_name, string role) {
    this->addPerson(person_name);
    this->addRole(role);

    std::cout << this->adjacency_list.size() << std::endl;

    this->adjacency_list[this->person_id[person_name]].push_back(10);
    // this->adjacency_list[this->person_id[person_name]].push_back(this->role_id[role]);
}

int Graph::solveGreedy() {
    map<int, int> matchings;

    map<string, int>::iterator it2;
    for (it2 = person_id.begin(); it2 != person_id.end(); it2++) {
        std::cout << it2->first << ": " << it2->second << std::endl;
    }

    map<string, int>::iterator it;
    for (it = role_id.begin(); it != role_id.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // for (int i = 0; i < person_total; i++) {
    //     std::cout << i + 1 << ": ";
    //     for (int j = 0; j < (int)adjacency_list[i].size(); j++) {
    //         std::cout << adjacency_list[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // bool *matched_person = new bool[person_total];
    // bool *matched_role = new bool[role_total];

    // map<string, int>::iterator it;
    // for (it = this->person_id.begin(); it != this->person_id.end(); it++) {
    //     for (int i = 0; i < (int)this->adjacency_list[it->second].size(); i++) {
    //         if (!matched_role[i]) {
    //             matchings[it->second] = i;
    //             matched_role[i] = true;
    //             break;
    //         }
    //     }
    // }

    // map<int, int>::iterator it2;
    // for (it2 = matchings.begin(); it2 != matchings.end(); it2++) {
    //     std::cout << it2->first << ": " << it2->second << std::endl;
    // }

    return 0;
}
