/**
 * A toy implementation of max heap
 */
#include "maxheap.h"
#include <iostream>
#include <vector>

/**
 * Basic heap operations:
 * - Public methods
 *  - Insert
 *  - Extract
 *
 * - Private method
 *  - shift up (heapify up)
 *  - shift down (heapify down)
 *  - get parent
 *  - get children
 *  - swap
 */

/// default construct
my_max_heap::my_max_heap() : H(0) {}

/// copy constructor
/// build a heap from existing array using Floyd method
my_max_heap::my_max_heap(const std::vector<int>& n) : H(n) {
    if (H.size() < 1) {
        return;
    }
    int t = H.size() - 1;
    int p = _parent(t);
    while (p >= 0) {
        _shiftdown(p);
        int lc = _leftchild(p);
        p = _parent(lc - 1);
    }
}

int my_max_heap::_parent(int x) {
    if (x > 0) {
        return (x - 1) / 2;
    }
    return -1;
}

int my_max_heap::_leftchild(int x) {
    int res = 2 * x + 1;
    if (res >= H.size()) {
        return -1;
    }
    return res;
}

int my_max_heap::_rightchild(int x) {
    int res = 2 * x + 2;
    if (res >= H.size()) {
        return -1;
    }
    return res;
}
void my_max_heap::_swap(int i, int j) {
    int t = H[i];
    H[i] = H[j];
    H[j] = t;
}

void my_max_heap::_shiftup(int idx) {
    int p = _parent(idx);
    while (p >= 0) {
        if (H[idx] > H[p]) {
            _swap(idx, p);
            idx = p;
            p = _parent(p);
        } else {
            return;
        }
    }
    return;
}

void my_max_heap::_shiftdown(int idx) {
    int ll = _leftchild(idx);
    int lr = _rightchild(idx);
    if (ll == -1 && lr == -1) {
        return;
    } else if (lr == -1) {
        if (H[ll] > H[idx]) {
            _swap(ll, idx);
            _shiftdown(ll);
        }
    } else {  // lr exist && ll not exist will never occur for complete
              // tree
        if (H[ll] > H[lr]) {
            _swap(ll, idx);
            _shiftdown(ll);
        } else {
            _swap(lr, idx);
            _shiftdown(lr);
        }
    }
}

/// print element
void my_max_heap::print() {
    for (auto ele : H) {
        std::cout << ele << std::endl;
    }
}

void my_max_heap::insert(int x) {
    int t = H.size();
    H.push_back(x);
    _shiftup(t);
}

int my_max_heap::extract() {
    if (H.size() == 0) {
        throw "Cannot extract empty heap.";
    }
    int res = H[0];
    int last = H.back();
    H.pop_back();
    H[0] = last;
    _shiftdown(0);
    return res;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    my_max_heap b(a);
    b.print();
}