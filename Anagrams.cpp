//
//  Anagrams.cpp
//  inter
//
//  Created by Locke Chantelle on 5/13/23.
//

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int main(void) {
    ifstream in("../input.txt");
    char j;
    multiset<char> a, b;
    
    in.unsetf(ios_base::skipws);
    while (in >> j && j != '\n')
        a.insert(j);
    in.setf(ios_base::skipws);
    while (in >> j)
        b.insert(j);
    cout << (a == b) << endl;
    return 0;
}
