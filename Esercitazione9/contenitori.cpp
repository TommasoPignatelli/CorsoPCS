#pragma once
#include <iostream>
#include <string>
#include <queue> // Necessario per fifo
#include <stack> // Necessario per lifo

template <typename T>
class fifo {
private:
    std::queue<T> container; //uso queue dalla STL
public:
    fifo() = default; // Costruttore di default

    void put(const T& value) {
        container.push(value); // Inoltro la chiamata al metodo push della STL
    }
    
    T get() {
        T value = container.front(); // std::queue::pop() rimuove ma non restituisce l'elemento, prima leggo e poi rimuovo.
        container.pop();
        return value;
    }
    
    bool empty() const {
        return container.empty();
    }
};


template <typename T>
class lifo {
private:
    std::stack<T> container; //uso stack dalla STL

public:
    lifo() = default;// Costruttore di default
    
    void put(const T& value) {
        container.push(value);
    }
    
    T get() {
        T value = container.top();
        container.pop();
        return value;
    }
    
    bool empty() const {
        return container.empty();
    }
};
