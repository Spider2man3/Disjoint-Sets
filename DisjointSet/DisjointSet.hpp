// DisjointSet.hpp
// Thomas Manu and Adams Bala

#include <vector>
#include <iostream>

class DisjointSet {
private:
    std::vector<int> sets;

public:
    DisjointSet(int n);
    virtual ~DisjointSet();
    int findSet(int i);
    void unionSet(int s1, int s2);
    void splitSet(int s);
    int cardinality();
    void print() const;
};
