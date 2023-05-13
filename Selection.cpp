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

void Selection(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < v.size(); ++j)
            if (v[j] < v[min]) min = j;
        if (i != min) swap(v[i], v[min]);
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
    Selection(v);
    for (int a : v) cout << a << ' ';
    cout << endl;
    return 0;
}
