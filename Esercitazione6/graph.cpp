#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "edges.cpp"

//Voglio capire se ha più senso usare la classe edges appena create per rappresentare gli archi

// Definizione della classe
class undirected_graph {
private:
    // Membri dato (Stato)
    // Essendo 'private', non possono essere letti o modificati direttamente dall'esterno
    std::vector<int>  nodi;
    std::vector<undirected_edge> archi;
    std::map<int, std::vector<int>> adjacency_list;

public:
    // Costruttore: un metodo speciale chiamato automaticamente alla creazione dell'oggetto
    undirected_graph(std::vector<int>  n, std::vector<undirected_edge> c)
    {
    nodi = n;
    archi = c;
    // Ordiniamo gli archi
    std::sort(archi.begin(), archi.end());
    // Costruzione della lista di adiacenza
    for (const undirected_edge& edge : archi) {
        adjacency_list[edge.from()].push_back(edge.to());
        adjacency_list[edge.to()].push_back(edge.from());
    }
    
    }

    std::vector<int> neighbours(int nodo) {
        return adjacency_list[nodo];
    }

    void add_edge(int source, int target) {
        undirected_edge new_edge(source, target);
        archi.push_back(new_edge);
        adjacency_list[source].push_back(target);
        adjacency_list[target].push_back(source);
    }

    const std::vector<int>& all_nodes() const{
        return nodi;
    }

    const std::vector<undirected_edge>& all_edges() const {
        return archi;
    }

    int edge_number(undirected_edge edge) {
        // 1. Esegue la ricerca
         auto it = std::find(archi.begin(), archi.end(), edge);
        // 2. Verifica se l'elemento è stato trovato
        if (it != archi.end()) {
        // 3. Calcola l'indice
        int index = std::distance(archi.begin(), it);
        return index; // Restituisce l'indice dell'elemento
    }
    return -1; // Restituisce -1 se l'elemento non è stato trovato
    }

    undirected_edge edge_at(size_t index) {
        if (index >= 0 && index < archi.size()) {
            return archi[index];
        }
        throw std::out_of_range("Index out of range");
    }

    // Manca solo l'operatore - per la differenza tra gli archi di due grafi (G-G' dà un grafo con gli archi di G che non sono in G')
    undirected_graph operator-(const undirected_graph& altro) const {
        std::vector<undirected_edge> new_edges;
        for (const undirected_edge& edge : archi) {
            if (std::find(altro.archi.begin(), altro.archi.end(), edge) == altro.archi.end()) {
                new_edges.push_back(edge);
            }
        }
        return undirected_graph(nodi, new_edges);
    }
};

