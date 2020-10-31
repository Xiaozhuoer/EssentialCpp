/*
--------------------------------------------------------

   练习2.3
        将练习2.2的Pentagonal数列求值函数拆分为两个函数，
    其中之一为inline，用来检验元素个数是否合理。如果的确
    合理，而且尚未被计算，便执行第二个函数，执行实际的求值
    工作。

--------------------------------------------------------
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

const vector<int>* Pentagonal(int);
inline bool checkPosSize(int);
void displayPentagonalType(const vector<int>*, int, string);

int main() {

    string msg = "Pentagonal Sequence type";
    displayPentagonalType(Pentagonal(5), 5, msg);
    displayPentagonalType(Pentagonal(2), 2, msg);
    displayPentagonalType(Pentagonal(10), 10, msg);
}

//检验元素个数是否合理
inline bool checkPosSize(int pos) {
    if (pos <= 0 || pos > 1024) {
        cerr << "invalid position: " << pos << endl;
        return false;
    }
    return true;
}

//计算Pentagonal数列
//返回的是持久化pent的地址指针
const vector<int>* Pentagonal(int pos) {
    static vector<int> pent;

    //检查pos长度，合法且pos大于当前pent已经计算出的长度
    //则只做没算出来的长度
    if (checkPosSize(pos) && pos > pent.size()) {
        for (int n = pent.size() + 1; n <= pos; n++) {
            pent.push_back(n * (3 * n - 1) / 2);
        }
    }
    return &pent;
}

void displayPentagonalType(const vector<int>* pent, int pos, string msg) {
    vector<int> swap = *pent;
    cout << msg << endl;
    if (pos < swap.size()) {
        for (int ix = 0; ix < pos; ix++) {
            cout << swap[ix] << " ";
        }
    }
    else {
        //利用迭代器访问vector容器
        vector<int>::iterator it;
        for (it = swap.begin(); it != swap.end(); it++) {
            cout << *it << " ";
        }
    }
    cout << endl;
}
