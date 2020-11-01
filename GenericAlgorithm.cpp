/*

    2020.11.1 ： 搞不定的BUG, 以后有机会再回来看看这个坑
    

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace placeholders;

template <typename InputIterator, typename OutputIterator,
          typename ElemType>
OutputIterator sub_vec(InputIterator first, InputIterator last ,
                       OutputIterator at, ElemType val){
    //, Comp pred
    //1.对传入的InputIterator排序
    sort(first, last, less<InputIterator>());

    // vector<int>::iterator it_sort, it_find, it_erase, it_find_if;
    // vector<ElemType>::iterator it;
    
    //找到指定val值
    //find(first,last, val);
    //删除大于指定val值的元素
    first = find(first,last, val);

    while(first != last){
        *at++ = *first++;
    }

    return at;

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



int main(){
    const int val = 7;
    vector<int> vec{6,3,8,4,11,7};
    vector<int> vec2(val);
    vector<int> vecResult(sub_vec(vec.begin(), vec.end(), vec2.begin(), val));
    
    vector<int>::iterator it;
    for (it = vecResult.begin(); it != vecResult.end(); it++) {
        cout << *it << " ";
    }
    
    return 0;
}

