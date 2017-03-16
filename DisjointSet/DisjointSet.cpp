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

void DisjointSet::splitSet() {
    for (int i = 0; i < sets.size(); i++) {
        sets[i] = i;
    }
}

int DisjointSet::cardinality() {
    if (sets.size() == 0) {
        return 0;
    }

    std::vector<int> card;
    card.push_back(findSet(sets[0]));
    for (int i = 1; i < sets.size(); i++) {
        if (std::find(card.begin(), card.end(), findSet(sets[i])) == card.end()) {
            card.push_back(findSet(sets[i]));
        }
    }
    return static_cast<int>(card.size());
}

void DisjointSet::print() const {
    for (auto &i : sets) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}
