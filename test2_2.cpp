/*
--------------------------------------------------------

   练习2.2
        Pentagonal数列的求值公式是P(n)=n(3n-1)/2，借此产生
    1,5,12,22,35等元素值。试定义一个函数，利用上述公式，将
    产生的元素放到用户传入的vector之中，元素个数由用户指定。
    请检查元素个数的有效性（太大则可能引发overflow问题）。
    接下来编写第二个函数，能够将给定的vector的所有元素一一
    打印。此函数的第二个参数接受一个字符串，表示存放在vector
    内的数列的类型，最后再写一个main()，测试上述两个函数。

--------------------------------------------------------
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool Pentagonal(vector<int> &, int);
void displayPentagonalType(vector<int> &, string);


int main() {

    vector<int> pent;
    string msg = "Pentagonal Sequence type";
    if (Pentagonal(pent, 0)) {
        displayPentagonalType(pent, msg);
    }
    if (Pentagonal(pent, 5)) {
        displayPentagonalType(pent, msg);
    }
    if (Pentagonal(pent, 20)) {
        displayPentagonalType(pent, msg);
    }
    if (Pentagonal(pent, 1200)) {
        displayPentagonalType(pent, msg);
    }
    return 0;
}


bool Pentagonal(vector<int> &pent, int pos) {
    if (pos <= 0 || pos > 1024) {
        cerr << "invalid position: " << pos << endl;
        return false;
    }
    int data = 0;
    for (int n = 1; n <= pos; n++) {
        data = n * (3 * n - 1) / 2;
        pent.push_back(data);
    }
    return true;
}

void displayPentagonalType(vector<int> &pent, string msg) {
    cout << msg << " : " << pent.size() << endl;
    //利用迭代器访问vector容器
    vector<int>::iterator it;
    for (it = pent.begin(); it != pent.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
