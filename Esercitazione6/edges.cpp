#pragma once
#include <iostream>
#include <string>

// Definizione della classe
class undirected_edge {
private:
    // Membri dato (Stato)
    // Essendo 'private', non possono essere letti o modificati direttamente dall'esterno
    int source;
    int target;

public:
    // Costruttore: un metodo speciale chiamato automaticamente alla creazione dell'oggetto
    undirected_edge(int s, int t) {
        if (s < t) {
            source = s;
            target = t;
        } else {
            source = t;
            target = s;
        }
    }

    // Funzione membro (Comportamento)
    // Essendo 'public', può essere richiamata dal resto del programma
    int from() const{
        return source;
    }
    int to() const {
        return target;
    }

    // Overload dell'operatore <
    bool operator<(const undirected_edge& altro) const {
        // Criterio primario: ordina per livello crescente
        if (source != altro.source) {
            return source < altro.source;
        }
        // Criterio secondario: se i livelli sono uguali, ordina per username
        return target < altro.target;
    }

    bool operator==(const undirected_edge& altro) const {
        return (source == altro.source) && (target == altro.target);
    }

// Overload dell'operatore << per l'output su stream
/////////serve friend perchè << nativamente è esterna alla classe |||||SUGGERITO DA GEMINI||||||
    friend std::ostream& operator<<(std::ostream& os, const undirected_edge& edge) {
        // Formatta l'output come preferisci, ad esempio: (1, 3)
        os << "(" << edge.source << ", " << edge.target << ")";
        return os; // Restituisce lo stream per permettere il concatenamento
    }
};

