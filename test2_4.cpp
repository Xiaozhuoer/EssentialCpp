/*
--------------------------------------------------------

   练习2.4
        写一个函数，以局部静态(local static)的vector储存
    Pentagonal数列元素。此函数返回一个const指针，指向该
    vector。如果vector的大小小于指定的元素个数，就扩充
    vector的大小。接下来再实现第二个函数，接受一个位置
    值，返回该位置上的元素。最后，编写main()测试这些函数。  

--------------------------------------------------------
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

const vector<int>* Pentagonal(int);
inline bool checkPosSize(int );
void returnPosElem(int );

int main(){
    int pos;
    cout << "Please enter a position : " ;
    cin >> pos;
    cout << "The element at position " << pos << " of Pentagoal is : ";
    returnPosElem(pos);
}

inline bool checkPosSize(int pos){
    if(pos <= 0 || pos > 1024){
        cerr << "invalid position: " << pos << endl;
        return false;
    }
    return true;
}

const vector<int>* Pentagonal(int elem_num){
    //持久化pent
    static vector<int> pent;
    //检查元素大小访问 和 判断是否大于当前pent的大小
    if(checkPosSize(elem_num) && elem_num > pent.size()){
        for(int n = pent.size() + 1; n <= elem_num ; n++){
            pent.push_back(n * (3 * n - 1) / 2);
        }
    }
    return &pent;
}

void returnPosElem(int pos){
    vector<int> swap = *(Pentagonal(pos));
    //vector.at() 获取该元素位置的引用 注意-1
    cout << swap.at(pos - 1) << endl;
}
