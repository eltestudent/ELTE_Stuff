#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <utility>

class Set {

public:
    enum Exception {OUT_OF_SIZE, MISSING_KEY, EMPTYSET};
    void insert(int e);
    void remove_by_index(int i);
    void remove_by_element(int e);
    bool isEmpty() const { return _seq.empty(); }
    bool isMember(int e) const;
    int random() const;
    int getSum() const { return sum; }
    void print() const;

private:   
    std::pair<bool, int> binSearch(int x) const;
    size_t sum = 0;
    std::vector<int> _seq;

};