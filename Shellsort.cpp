//
//  Shellsort.cpp
//  inter
//
//  Created by Locke Chantelle on 5/13/23.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void Shellsort(vector<int> &v) {
    int h = 0;
    
    while (h < v.size() / 3) h = h * 3 + 1;
    
    while (h >= 1) {
        for (int i = h; i < v.size(); ++i) {
            for (int j = i; j >= h && v[j - h] > v[j]; j -= h)
                swap(v[j], v[j - h]);
        }
        h /= 3;
    }
}

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
    Shellsort(v);
    for (int a : v) cout << a << ' ';
    cout << endl;
    return 0;
}

