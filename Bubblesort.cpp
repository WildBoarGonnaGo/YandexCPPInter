//
//  Bubblesort.cpp
//  inter
//
//  Created by Locke Chantelle on 5/15/23.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

template <class T, class Comp = less<T>> class BubbleSort {
public:
    BubbleSort() {}
    void sort(vector<int> &v) {
        for (int i = 0; i < v.size() - 1; ++i) {
            bool s = false;
            for (int j = 0; j < v.size() - i - 1; ++j) {
                if (Comp{}(v[j + 1], v[j])) { swap(v[j], v[j + 1]); s = true; }
            }
            if (!s) break ;
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
    //QuickSort<int> q;
    //q.init(v);
    BubbleSort<int> b;
    b.sort(v);
    for (int a : v) cout << a << ' ';
    cout << endl;
    return 0;
}
