#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace placeholders;

template <typename InputIterator, typename OutputIterator,
    typename ElemType, typename Comp>

    OutputIterator sub_vec(InputIterator first, InputIterator last, OutputIterator at, ElemType val, Comp pred) {
    //Comp pred
    //对传入的InputIterator排序
    //less -> 删除小于指定val值的元素
    //greater -> 删除大于指定val值的元素
    sort(first, last, pred);

    //找到指定val值的指针位置
    //find(first,last, val);
    at = find(first, last, val);

    return at;
}
 
int main() {
    const int val = 7;
    int ia[val] = { 14,6,3,8,4,11,7 };
    vector<int> vec{ ia, ia + val };


    //vector<int> 测试
    cout << "vector<int> test : ";
    vector<int> vec2(val);
    vector<int>::iterator it = sub_vec(vec.begin(), vec.end(), vec2.begin(), 8, less<int>());
    while (it != vec.end()) {
        cout << *it << " ";
        *it++;
    }

    cout << endl;
    //array<int> 测试
    cout << "array<int> test : ";
    int ia2[val];
    int *result = sub_vec(ia, ia + val, ia2, 7, less<int>());
    while (*result != ia[val]) {
        cout << *result << " ";
        *result++;
    }

    return 0;
}

// void sub_vec(const vector<int> &vec, int val){
//     vector<int> local_vec(vec);

//     //1.对local_vec排序
//     sort(local_vec.begin(), local_vec.end(), less<int>());

//     vector<int>::iterator it_sort, it_find, it_erase, it_find_if;

//     //sort 用less升序排序
//     cout << "it_sort : "; 
//     for (it_sort = local_vec.begin(); it_sort != local_vec.end(); it_sort++) {
//         cout << *it_sort << " ";
//     }
//     cout << endl;
//     //找到指定val值
//     it_find = find(local_vec.begin(), local_vec.end(), val);
//     if(it_find != local_vec.end()){
//         cout << "Get it!" << endl;
//     } else {
//         cout << "Noooo!" << endl;
//     }

//     //删除大于指定val值的元素
//     local_vec.erase(it_find,local_vec.end());

//     cout << "it_erase : "; 
//     for (it_erase = local_vec.begin(); it_erase != local_vec.end(); it_erase++) {
//         cout << *it_erase << " ";
//     }
//     cout << endl;

// }
