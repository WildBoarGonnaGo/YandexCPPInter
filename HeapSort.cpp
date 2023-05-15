//
//  HeapSort.cpp
//  inter
//
//  Created by Locke Chantelle on 5/15/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include <array>
#include <string>

using namespace std;

class HeapSort {
    void heapify(vector<int> &v, int i) {
        int b = i, l = i + 1, r = i + 2;
        
        if (l < v.size() && v[b] > v[l]) b = l;
        if (r < v.size() && v[b] > v[r]) b = r;
        if (b != i) {
            swap(v[i], v[b]);
            heapify(v, b);
        }
    }
public:
    void sort(vector<int> &v) {
        for (int i = v.size() / 2 - 1; i >= 0; --i)
            heapify(v, i);
        for (int i = v.size() - 1; i >= 0; --i) {
            swap(v[0], v[i]);
            heapify(v, i);
        }
    }
};

int main(void) {
    size_t s;
    srand(time(NULL));
    s = rand() % 25;
    vector<int> v(s);
    
    for (int i = 0; i < s; ++i) {
        v[i] = rand() % 100;
        cout << v[i] << ' ';
    }
    cout << endl;
    HeapSort h;
    h.sort(v);
    for (int a : v) cout << a << ' ';
    cout << endl;
    return 0;
}
