/**
 * simple implementation of heap
 */
#include <vector>

#ifndef _MY_MAX_HEAP_
#define _MY_MAX_HEAP_

class my_max_heap {
private:
    std::vector<int> H;
    inline int _parent(int i);
    inline int _leftchild(int i);
    inline int _rightchild(int i);
    inline void _swap(int i, int j);
    inline void _shiftup(int i);
    inline void _shiftdown(int i);

public:
    my_max_heap();
    my_max_heap(const std::vector<int>& arr);
    void print();
    void insert(int n);
    int extract();
    ~my_max_heap(){};
};

#endif