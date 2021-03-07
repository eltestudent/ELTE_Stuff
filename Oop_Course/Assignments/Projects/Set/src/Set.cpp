#include "../include/Set.h"

std::pair<bool, int> Set::binSearch(int x) const {

    bool l = false;
    int low = 0;
    int high = _seq.size() - 1;
    int ind;
    while(!l && low <= high) {

        ind = low + (high - low) / 2;

        if(x < _seq[ind]) {
            high = ind-1;
        }
        else {
            low = ind+1;
        }

        if(x == _seq[ind]) 
            l = true;

    }

    if(!l) {
        ind = low;
    }

    return std::pair<bool, int>(l, ind);
}

void Set::insert(int e) {

    // Use binary search to find the right position
    // Insert the element
    auto p = binSearch(e);
    if(!p.first) {

        // increase the sum
        sum+=e;

        _seq.resize(_seq.size()+1);
        for(int i=_seq.size()-2;i>=p.second;--i) {
            _seq[i+1] = _seq[i];
        }
        _seq[p.second] = e;
    }
}

void Set::remove_by_index(int ind) {

    if(ind >= _seq.size() || ind < 0) 
        throw OUT_OF_SIZE;
    
    // Decrease the sum
    sum-=_seq[ind];

    for(uint i = ind+1;i<_seq.size();++i) {
        _seq[i-1] = _seq[i];
    }

    _seq.pop_back();
    
}

void Set::remove_by_element(int e) {

    auto p = binSearch(e);
    if(p.first) {
        for(uint i=p.second+1;i<_seq.size();++i) {
            _seq[i-1] = _seq[i];
        }

        // Decrease the sum
        sum-=e;

        _seq.pop_back();
    } else {
        throw MISSING_KEY;
    }
    
}

bool Set::isMember(int e) const {

    // find element using Binary Search
    return binSearch(e).first;
}

int Set::random() const {

    if(isEmpty()) {
        throw EMPTYSET;
    }

    // Init random seed
    srand((unsigned)time(0));

    // Generate random number
    // less than the number of elements in the sequence
    int randNum = rand() % _seq.size();


    return _seq[randNum];

}

void Set::print() const {

    if(isEmpty()) {
        throw EMPTYSET;
    }

    std::cout << std::endl << "Set: (";
    for(int i=0;i<_seq.size();++i) {
        bool isEnd = i ==_seq.size()-1;
        std::cout << _seq[i] << (isEnd ? "" : ", ");
    }
    std::cout << ")" << std::endl;
}