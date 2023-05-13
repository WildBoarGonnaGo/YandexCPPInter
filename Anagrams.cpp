//
//  Anagrams.cpp
//  inter
//
//  Created by Locke Chantelle on 5/13/23.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main(void) {
    char j;
    multiset<char> a, b;
    cin >> noskipws;
    while (cin >> j && j != '\n') a.insert(j);
    while (cin >> j) b.insert(j);
    cout << (a == b) << endl;
    return 0;
}
