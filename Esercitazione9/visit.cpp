#pragma once
#include "contenitori.cpp"
#include "graph.cpp"
#include <vector>
#include <functional> // Necessario per dichiarare la lambda ricorsiva con std::function

template <typename tipo_ord>
undirected_graph graph_visit(undirected_graph g, int v, tipo_ord& Q) {
    int n = g.all_nodes().size(); // Numero di nodi nel grafo
    std::vector<bool> reached(n, false);
    
    // Vettori necessari per il return finale
    std::vector<int> visited_nodes;
    std::vector<undirected_edge> tree_edges;
    
    // Inizializzazione del nodo di partenza
    reached[v] = true;
    Q.put(v);
    
    while (!Q.empty()) {
        int u = Q.get();
        
        // Il nodo viene inserito nell'insieme dei nodi del nuovo grafo
        visited_nodes.push_back(u);
        
        for (int w : g.neighbours(u)) {
            if (!reached[w]) {
                reached[w] = true; // Marcato alla scoperta
                
                // Viene creato l'arco orientato da 'u' (scopritore) a 'w' (scoperto)
                // e inserito nel vettore degli archi dell'albero di copertura
                tree_edges.push_back(undirected_edge(u, w));
                
                Q.put(w);
            }
        }
    }
    
    // Restituisce l'albero di visita come istanza di undirected_graph.
    // Il costruttore provvederà internamente a ordinare gli archi 
    // e a generare la nuova lista di adiacenza del sottografo.
    return undirected_graph(visited_nodes, tree_edges);
}


undirected_graph recursive_dfs(undirected_graph g, int start_node) {
    int n = g.all_nodes().size(); 
    
    // Strutture dati locali per mantenere lo stato della visita
    std::vector<bool> visited(n, false);
    std::vector<int> visited_nodes;
    std::vector<undirected_edge> tree_edges;

    // Dichiarazione della funzione lambda ricorsiva interna.
    // Il simbolo [&] permette alla lambda di accedere a tutte le variabili locali per riferimento.
    // Suggerito da Gemini
    std::function<void(int)> dfs_internal = [&](int u) {
        visited[u] = true;
        visited_nodes.push_back(u);
        
        for (int w : g.neighbours(u)) {
            if (!visited[w]) {
                // Registra l'arco dell'albero di copertura
                tree_edges.push_back(undirected_edge(u, w));

                dfs_internal(w);
            }
        }
    };

    // Innesco della visita a partire dal nodo sorgente
    dfs_internal(start_node);

    return undirected_graph(visited_nodes, tree_edges);
}