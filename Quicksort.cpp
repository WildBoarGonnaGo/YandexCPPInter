//
//  Quicksort.cpp
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

template <class T> class InsertionSort {
public:
    InsertionSort() { }
    void sort(vector<T> &v, int lo, int hi) {
        for (int i = lo; i <= hi; ++i) {
            for (int j = i; j > 0; --j) {
                if (v[j] < v[j - 1]) swap(v[j], v[j - 1]);
                else break ;
            }
        }
    }
};

template <class T> class HeapSort {
    void heapify(vector<T> &v, int i, int hi) {
        int b = i, l = i + 1, r = i + 2;
        
        if (l <= hi && v[b] > v[l]) b = l;
        if (r <= hi && v[b] > v[r]) b = r;
        if (b != i) {
            swap(v[i], v[b]);
            heapify(v, b, hi);
        }
    }
public:
    void sort(vector<T> &v, int lo, int hi) {
        for (int i = hi / 2; i >= lo; --i)
            heapify(v, i, hi);
        for (int i = hi; i >= lo; --i) {
            swap(v[lo], v[i]);
            heapify(v, i, hi);
        }
    }
};

template <class T> class QuickSort {
    random_device rd;
    default_random_engine reng;
    HeapSort<T> is;
    
    int partition(vector<T> &s, int lo, int hi) {
        int i = lo, j = hi + 1;
        
        while (true) {
            while (s[lo] > s[++i])
                if (i == hi) break ;
            
            while (s[lo] < s[--j])
                if (j == lo) break ;
            
            if (i >= j) break ;
            swap(s[i], s[j]);
        }
        swap(s[lo], s[j]);
        return j;
    }
    void sort(vector<T> &s, int lo, int hi) {
        if (hi <= lo + 16) {
            is.sort(s, lo, hi);
            return ;
        }
        int lt = lo, gt = hi;
        T v = s[lo];
        //int j = partition(s, lo, hi);
        int i = lo;
        while (i <= gt) {
            if (s[i] < v) swap(s[lt++], s[i++]);
            else if (s[i] > v) swap(s[i], s[gt--]);
            else ++i;
        }
        sort(s, lo, lt - 1);
        sort(s, gt + 1, hi);
    }
public:
    QuickSort() {
        reng = default_random_engine(rd());
    }
    void init(vector<T> &s) {
        shuffle(s.begin(), s.end(), reng);
        sort(s, 0, s.size() - 1);
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
    QuickSort<int> q;
    q.init(v);
    for (int a : v) cout << a << ' ';
    cout << endl;
    return 0;
}

