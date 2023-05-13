//
//  Insertion.cpp
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

void Insertion(vector<int> &v) {
    for (int i = 1; i < v.size(); ++i) {
        for (int j = i; j > 0; --j)
            if (v[j - 1] > v[j]) swap(v[j], v[j - 1]);
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
    Insertion(v);
    for (int a : v) cout << a << ' ';
    cout << endl;
    return 0;
}

