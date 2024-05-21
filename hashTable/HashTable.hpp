#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <vector>

class HashTable {
  public:
    //int *buckets = 0;
    std::vector<int> buckets;
    long a, c, m;
    int numOfElements;

    HashTable(long, long, long);
    ~HashTable();
    void insert(int);
    void extend();
    bool find(int);
    void remove(int);
    double loadFactor();
    void printTable();
    int hashNumberCalculator(int);
};

#endif
