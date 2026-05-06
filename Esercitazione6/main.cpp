
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "edges.cpp"
#include "graph.cpp"

int main() {
    std::cout << "Testiamo undirected_edge" << std::endl;
    std::cout << "_________________" << std::endl;
    // Istanziazione: creazione di due "oggetti" a partire dalla classe undirected_edge
    undirected_edge edge1(3,1);
    undirected_edge edge2(1,2);
    

    // Utilizzo dei metodi pubblici degli oggetti
    int source1 = edge1.from();
    int target1 = edge1.to();
    int source2 = edge2.from();
    int target2 = edge2.to();
    std::cout << "Edge 1: from " << source1 << " to " << target1 << std::endl;
    std::cout << "Edge 2: from " << source2 << " to " << target2 << std::endl;

    std::cout << "Edge 1: " << edge1 << std::endl;
    std::cout << "Edge 2: " << edge2 << std::endl;
    if (edge1 < edge2) {
        std::cout << "L'edge1 ha un indice inferiore a " << "l'edge2" << ".\n";
    } else {
        std::cout << "L'edge1 ha un indice superiore o uguale a " << "l'edge2" << ".\n";
    }

    std::cout << "Testiamo undirected_graph" << std::endl;
    std::cout << "_________________" << std::endl;
    // Istanziazione: creazione di due "oggetti" a partire dalla classe undirected_graph
    std::vector<int> nodes = {1, 2, 3, 4, 5};
    std::vector<undirected_edge> edges = {
        undirected_edge(1, 2),
        undirected_edge(1, 3),
        undirected_edge(2, 4),
        undirected_edge(3, 5),
        undirected_edge(4, 5)
    };
    undirected_graph graph(nodes, edges);

    std::vector<int> tutti_i_nodi = graph.all_nodes();
    std::cout << "All nodes: ";
    for (int n : tutti_i_nodi) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::vector<undirected_edge> tutti_gli_archi = graph.all_edges();
    std::cout << "All edges: ";
    for (const undirected_edge& edge : tutti_gli_archi) {
        std::cout << edge << " ";
    }
    std::cout << std::endl;
    std::vector<int> vicini1 = graph.neighbours(1);
    std::cout << "Neighbours of node 1: ";
    for (int n : vicini1) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    graph.add_edge(1, 4);
    std::vector<undirected_edge> tutti_gli_archi_nuovo = graph.all_edges();
    std::cout << "All edges (after adding edge (1,4)): ";
    for (const undirected_edge& edge : tutti_gli_archi_nuovo) {
        std::cout << edge << " ";
    }
    std::cout << std::endl;

    undirected_edge test_edge(1, 2);
    std::cout << "Index of the edge between nodes 1 and 2: " << graph.edge_number(test_edge) << std::endl;

    undirected_edge test_edge_at = graph.edge_at(0);
    std::cout << "Edge at index 0: " << test_edge_at << std::endl;

    undirected_graph graph_diff = graph - undirected_graph(nodes, {undirected_edge(1, 2)});
    std::cout << "Graph difference (G - G'): ";
    for (const undirected_edge& edge : graph_diff.all_edges()) {
        std::cout << edge << " ";
    }
    std::cout << std::endl;

    return 0;
}