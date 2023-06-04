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

    this->adjacency_list[this->person_id[person_name] - 1].push_back(this->role_id[role] - 1);
}

void Graph::printAdjacencyList() {
    for (int i = 0; i < person_total; i++) {
        std::cout << i << ": ";
        for (int j = 0; j < (int)adjacency_list[i].size(); j++) {
            std::cout << adjacency_list[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::printPeopleMap() {
    map<string, int>::iterator it;
    for (it = person_id.begin(); it != person_id.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

void Graph::printRolesMap() {
    map<string, int>::iterator it;
    for (it = role_id.begin(); it != role_id.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

int Graph::solveGreedy() {
    map<int, int> matchings;

    // bool *matched_person = new bool[person_total];
    bool *matched_role = new bool[role_total];

    map<string, int>::iterator it;
    for (it = this->person_id.begin(); it != this->person_id.end(); it++) {
        for (int i = 0; i < (int)this->adjacency_list[it->second - 1].size(); i++) {
            if (!matched_role[this->adjacency_list[it->second - 1][i]]) {
                matchings[it->second - 1] = this->adjacency_list[it->second - 1][i];
                matched_role[this->adjacency_list[it->second - 1][i]] = true;
                break;
            }
        }
    }

    return matchings.size();
}

int Graph::solveAccurate() { return 0; }
