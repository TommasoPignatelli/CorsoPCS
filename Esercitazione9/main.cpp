#include <iostream>
#include <vector>
#include "contenitori.cpp" 
#include "graph.cpp"       
#include "visit.cpp"
#include "graph_viz.cpp"   // Per l'esportazione in formato DOT
#include "djkstra.cpp"    // Per l'algoritmo di Dijkstra

int main() {
    std::cout << "=== INIZIALIZZAZIONE GRAFO DI TEST ===" << std::endl;
    
    // Grafo complesso con 15 nodi
    std::vector<int> nodi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    
    // Struttura densa con molteplici cicli e percorsi a profondità variabile
    std::vector<undirected_edge> archi = {
        // Diramazioni iniziali dal nodo di partenza
        undirected_edge(0, 1), 
        undirected_edge(0, 2), 
        undirected_edge(0, 3),
        
        // Espansione con cicli orizzontali e incroci
        undirected_edge(1, 4), 
        undirected_edge(1, 5),
        undirected_edge(2, 5), 
        undirected_edge(2, 6),
        undirected_edge(3, 6), 
        undirected_edge(3, 7),
        
        // Zona centrale densa
        undirected_edge(4, 8),
        undirected_edge(5, 8), 
        undirected_edge(5, 9),
        undirected_edge(6, 9), 
        undirected_edge(6, 10),
        undirected_edge(7, 10), 
        undirected_edge(7, 11),
        
        // Convergenza verso i nodi finali
        undirected_edge(8, 12),
        undirected_edge(9, 12), 
        undirected_edge(9, 13),
        undirected_edge(10, 13),
        undirected_edge(11, 14),
        
        // Nodi terminali
        undirected_edge(12, 14), 
        undirected_edge(13, 14)
    };
    
    undirected_graph G(nodi, archi);
    int start_node = 0;
    
    std::cout << "Grafo originale creato." << std::endl;
    std::cout << "Archi del grafo: ";
    for (const undirected_edge& edge : G.all_edges()) {
        std::cout << edge << " ";
    }
    export_to_dot(G, "grafo_originale.dot");
    std::cout << "\nNodo di partenza: " << start_node << "\n\n";

    // --- TEST 1: BFS tramite FIFO ---
    std::cout << "=== TEST BFS ===" << std::endl;
    fifo<int> coda_bfs;
    
    undirected_graph albero_bfs = graph_visit(G, start_node, coda_bfs);
    
    std::cout << "Archi dell'albero BFS: ";
    for (const undirected_edge& edge : albero_bfs.all_edges()) {
        std::cout << edge << " ";
    }
    std::cout << "\n";
    export_to_dot(albero_bfs, "albero_bfs.dot");
    std::cout << "\n";

    // --- TEST 2: DFS tramite LIFO ---
    std::cout << "=== TEST DFS  ===" << std::endl;
    lifo<int> pila_dfs;
    
    undirected_graph albero_dfs = graph_visit(G, start_node, pila_dfs);
    
    std::cout << "Archi dell'albero DFS: ";
    for (const undirected_edge& edge : albero_dfs.all_edges()) {
        std::cout << edge << " ";
    }
    std::cout << "\n";
    export_to_dot(albero_dfs, "albero_dfs.dot");
    std::cout << "\n";

    // --- TEST 3: DFS Ricorsiva ---
    std::cout << "=== TEST DFS RICORSIVA ===" << std::endl;
    
    undirected_graph albero_dfs_ric = recursive_dfs(G, start_node);
    
    std::cout << "Archi dell'albero DFS Ricorsiva: ";
    for (const undirected_edge& edge : albero_dfs_ric.all_edges()) {
        std::cout << edge << " ";
    }
    std::cout << "\n";
    export_to_dot(albero_dfs_ric, "albero_dfs_ricorsiva.dot");


    // --- TEST 4: Dijkstra ---
    std::cout << "=== TEST DIJKSTRA  ===" << std::endl;

    std::map<int, double> distanze = dijkstra(G, start_node);
    
    std::cout << "Distanze minime dal nodo " << start_node << ":" << std::endl;
    for (const auto& pair : distanze) {
        std::cout << "Nodo " << pair.first << " -> Distanza: " << pair.second << std::endl;
    }
    std::cout << "\n";

    return 0;
}