#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <map>
#include <vector>

using namespace std;

class Graph {
   private:
    int person_total;
    int role_total;
    vector<vector<int>> adjacency_list;
    map<string, int> person_id;
    map<string, int> role_id;

    int person_counter;
    int role_counter;

    // mapeia uma nova pessoa
    void addPerson(string name);

    // mapeia um novo cargo
    void addRole(string role);

   public:
    Graph();

    // @param node_total: número de nós (cidades) no grafo
    Graph(int person_total, int role_total);

    ~Graph();

    /*
        Adicona uma aresta ao grafo
        @param node_1: extremidade da aresta
        @param node_2: extremidade da aresta
    */
    void addEdge(string person_name, string role);

    int solveGreedy();
};

#endif  // GRAPH_HPP