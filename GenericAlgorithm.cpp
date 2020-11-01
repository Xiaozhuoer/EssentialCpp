#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace placeholders;

void sub_vec(const vector<int> &vec, int val){
    vector<int> local_vec(vec);

    //1.对local_vec排序
    sort(local_vec.begin(), local_vec.end(), less<int>());

    vector<int>::iterator it_sort, it_find, it_erase;

    //sort 用less升序排序
    cout << "it_sort : "; 
    for (it_sort = local_vec.begin(); it_sort != local_vec.end(); it_sort++) {
        cout << *it_sort << " ";
    }
    cout << endl;

    //找到指定val值
    it_find = find(local_vec.begin(), local_vec.end(), val);
    if(it_find != local_vec.end()){
        cout << "Get it!" << endl;
    } else {
        cout << "Noooo!" << endl;
    }

    //删除大于指定val值的元素
    local_vec.erase(it_find,local_vec.end());

    cout << "it_erase : "; 
    for (it_erase = local_vec.begin(); it_erase != local_vec.end(); it_erase++) {
        cout << *it_erase << " ";
    }
    cout << endl;
    // vector<int>::iterator iter = find_if(
    //                                 local_vec.begin(), 
    //                                 local_vec.end(), 
    //                                 bind(local_vec.erase(),
    //                                      iter,
    //                                      local_vec.end())
    // };
    //bind绑定适配器，将val作为第二参数和greater绑定，std::placeholders::_1占位符保留第一个参数
    //find_if(first,last,要做的函数指针)
    //greater<int>()内置类型元素会以降序排序
    //auto greater_bind = bind(greater<int>(),val);
    // vector<int>::iterator iter = find_if(
    //                                 local_vec.begin(), 
    //                                 local_vec.end(), 
    //                                 greater<int>());
    // local_vec.erase(iter, local_vec.end());
    // return local_vec;

}



int main(){
    vector<int> vec{6,3,8,4,11,7,14};

    sub_vec(vec, 7);
    

    
    return 0;
}

