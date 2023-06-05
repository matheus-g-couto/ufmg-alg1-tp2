#include "graph.hpp"

#include <string.h>

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
    this->person_total = this->role_total = -1;

    this->person_counter = this->role_counter = 0;
}

void Graph::addPerson(string name) {
    if (!this->person_id[name]) {  // verifica se a pessoa foi inserido previamente
        this->person_id[name] = this->person_counter;
        this->person_counter++;
    }
}

void Graph::addRole(string role) {
    if (!this->role_id[role]) {  // verifica se o cargo foi inserido previamente
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

    vector<bool> matched_role;
    matched_role.resize(role_total);

    map<string, int>::iterator it;
    for (it = this->person_id.begin(); it != this->person_id.end(); it++) {
        for (int i = 0; i < (int)this->adjacency_list[it->second - 1].size(); i++) {
            int role_idx = this->adjacency_list[it->second - 1][i];

            if (!matched_role[role_idx]) {
                matchings[it->second - 1] = role_idx;
                matched_role[role_idx] = true;
                break;
            }
        }
    }

    return matchings.size();
}

bool Graph::findAugmentingPath(int person_idx, bool visited[], int role_match[]) {
    for (int role_idx : adjacency_list[person_idx]) {
        if (!visited[role_idx]) {
            visited[role_idx] = true;

            if (role_match[role_idx] < 0 || findAugmentingPath(role_match[role_idx], visited, role_match)) {
                role_match[role_idx] = person_idx;
                return true;
            }
        }
    }

    return false;
}

int Graph::solveAccurate() {
    int matchings = 0;

    int role_match[role_total];
    memset(role_match, -1, sizeof(role_match));

    for (int i = 0; i < person_total; i++) {
        bool visited[role_total];
        memset(visited, false, sizeof(visited));

        if (findAugmentingPath(i, visited, role_match)) matchings++;
    }

    return matchings;
}