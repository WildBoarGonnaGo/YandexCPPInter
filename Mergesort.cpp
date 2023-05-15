//
//  Mergesort.cpp
//  inter
//
//  Created by Locke Chantelle on 5/14/23.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class MergeSort {
    void merge(vector<int> &s, vector<int> &aux, int &lo, int &mid, int &hi) {
        int i, k, j;

		for (i = lo; i <= hi; ++i)
			aux[i] = s[i];

        i = lo; j = mid + 1;
        for (k = lo; k <= hi; ++k) {
            if (i > mid) s[k] = aux[j++];
            else if (j > hi) s[k] = aux[i++];
            else if (aux[j] < aux[i]) s[k] = aux[j++];
            else s[k] = aux[i++];
        }
    }
    void sort(vector<int> &s, vector<int> &aux, int lo, int hi) {
        if (hi <= lo) return ;
        int mid = lo + (hi - lo) / 2;
        sort(s, aux, lo, mid);
        sort(s, aux, mid + 1, hi);
		if (s[mid] < s[mid + 1]) return ;
        merge(s, aux, lo, mid, hi);
    }
public:
    MergeSort(vector<int> &s) {
		vector<int> aux(s.size());
        sort(s, aux, 0, s.size() - 1);
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
    MergeSort kek(v);
    for (int a : v) cout << a << ' ';
    cout << endl;
    return 0;
}

