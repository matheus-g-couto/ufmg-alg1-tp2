#include <iostream>
#include <string>

#include "graph.hpp"

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[]) {
    int u, j, e;
    std::cin >> u >> j >> e;

    Graph *link_out = new Graph(u, j);

    std::string person_name, role;
    for (int i = 0; i < e; i++) {
        std::cin >> person_name >> role;
        // std::cout << "vasco" << std::endl;
        link_out->addEdge(person_name, role);
    }

    link_out->solveGreedy();
    return 0;
}
