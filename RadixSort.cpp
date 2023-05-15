//
//  RadixSort.cpp
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
#include <fstream>

using namespace std;

class RadixSort {
    void CountSort(vector<int> &s, int exp) {
        vector<int> output(s.size());
        array<int, 10> count = { 0 };
        
        for (int i = 0; i < s.size(); ++i)
            count[(s[i] / exp) % 10]++;
        for (int i = 1; i < 10; ++i)
            count[i] += count[i - 1];
        for (int i = s.size() - 1; i >= 0; --i) {
            output[count[(s[i] / exp) % 10] - 1] = s[i];
            --count[(s[i] / exp) % 10];
        }
        s = output;
    }
    void CountSortChar(string &s, int exp) {
        vector<char> output(s.size());
        array<int, 10> count = { 0 };
        
        for (int i = 0; i < s.size(); ++i)
            count[(s[i] / exp) % 10]++;
        for (int i = 1; i < 10; ++i)
            count[i] += count[i - 1];
        for (int i = s.size() - 1; i >= 0; --i) {
            output[count[(s[i] / exp) % 10] - 1] = s[i];
            --count[(s[i] / exp) % 10];
        }
        copy(output.begin(), output.end(), s.begin());
    }
public:
    RadixSort() {}
    void sort(vector<int> &v) {
        int max = *max_element(v.begin(), v.end());
        
        for ( int exp = 1; max / exp > 0; exp *= 10)
            CountSort(v, exp);
    }
    void sort(string &v) {
        char max = *max_element(v.begin(), v.end());
        
        for ( int exp = 1; max / exp > 0; exp *= 10)
            CountSortChar(v, exp);
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
    //BubbleSort<int> b;
    RadixSort r;
    r.sort(v);
    for (int a : v) cout << a << ' ';
    cout << endl;
    
    ifstream in("../input.txt");
    string j, d;
    in >> j >> d;
    r.sort(j);
    r.sort(d);
    cout << (j == d) << endl;
    return 0;
}
