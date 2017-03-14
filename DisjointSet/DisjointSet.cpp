// DisjointSet.cpp
// Thomas Manu and Adams Bala

#include "DisjointSet.hpp"

DisjointSet::DisjointSet(int n) {
    sets = std::vector<int> (n, -1);
    for (int i = 0; i < n; i++) {
        sets[i] = i;
    }
}

DisjointSet::~DisjointSet() {
    std::cout << "Destruct" << '\n';
}

int DisjointSet::findSet(int i) {
    if (sets[i] == i) {
        return i;
    }
    else
        return findSet(sets[i]);
}

void DisjointSet::unionSet(int s1, int s2) {
    int p1 = findSet(s1), p2 = findSet(s2);
    sets[p1] = p2;
}

void DisjointSet::splitSet(int s) {
    
}

int DisjointSet::cardinality() {
    int sum = 0;
    return sum;
}

void DisjointSet::print() const {
    for (auto &i : sets) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}
