#pragma once
#include <queue>
#include <limits>
#include <map>
#include <vector>
#include <utility> // Per std::pair
#include "graph.cpp"

std::map<int, double> dijkstra(undirected_graph& graph, int source) {
    std::map<int, double> distances;
    
    // Inizializzazione: distanze a infinito
    for (int node : graph.all_nodes()) {
        distances[node] = std::numeric_limits<double>::infinity(); //suggerito da Gemini
    }
    distances[source] = 0.0;

    // Coda di priorità: Min-Heap basato su coppie (distanza, nodo), suggerito da Gemini
    std::priority_queue<std::pair<double, int>, 
                        std::vector<std::pair<double, int>>, 
                        std::greater<std::pair<double, int>>> pq;
    
    pq.push({0.0, source});

    while (!pq.empty()) {
        double d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Se la distanza estratta è maggiore di quella nota, la coppia è obsoleta
        if (d > distances[u]) continue;

        for (int v : graph.neighbours(u)) {
            
            double edge_weight = 1.0; //non abbiamo implementato i pesi, quindi assumiamo peso 1 per ogni arco 
            
            double new_dist = distances[u] + edge_weight;

            if (new_dist < distances[v]) {
                distances[v] = new_dist;
                pq.push({distances[v], v});
            }
        }
    }

    return distances;
}