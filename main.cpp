#include <iostream>
#include <string>

/*
 Генерация скобочных случайных последовательностей (Yandex задача)
 **/

using namespace std;

void PrintBraceSeq(string str, int open, int close, int n) {
    if (str.size() == 2 * n) {
        cout << str << endl;
        return ;
    }
    if (open < n)
        PrintBraceSeq(str + "(", open + 1, close, n);
    if (close < open)
        PrintBraceSeq(str + ")", open, close + 1, n);
}

int main(void) {
    int n;
    cin >> n;
    
    PrintBraceSeq("", 0, 0, n);
    return 0;
}

/*#include <iostream>
#include <fstream>

int main(void) {
    std::ifstream i("../input.txt");
    std::ofstream o("../outuput.txt");

    long long a, b;
    i  >> a >> b;
    o << a + b;
    return 0;
}*/
