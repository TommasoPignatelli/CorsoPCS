#pragma once
#include <fstream>
#include <string>
#include "graph.cpp"

// Funzione per esportare un undirected_graph in formato DOT, scritta con l'aiuto di Gemini
void export_to_dot(undirected_graph g, const std::string& filename) {
    std::ofstream out_file(filename);
    
    if (!out_file.is_open()) {
        std::cerr << "Errore: Impossibile aprire il file " << filename << std::endl;
        return;
    }

    // Intestazione del file DOT per un grafo non orientato
    out_file << "graph Visita {\n";
    out_file << "    node [shape=circle, fontname=\"Helvetica\"];\n"; // Stile opzionale
    
    // Scrittura degli archi
    for (const undirected_edge& edge : g.all_edges()) {
        out_file << "    " << edge.from() << " -- " << edge.to() << ";\n";
    }
    
    // Chiusura
    out_file << "}\n";
    out_file.close();
    
    std::cout << "File " << filename << " generato con successo.\n";
}