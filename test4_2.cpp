/*
--------------------------------------------------------

   练习4.2
        扩展Stack的功能, 以支持find()和count()两个操作.
    find()会查看某值是否存在而返回true或false. count()返回
    某字符串的出现次数. 

--------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iterator>
#include "Stack.h"

using namespace std;

int main(){
    Stack st1;
    string elem[6] = {"abc", "a", "abc", "b", "c", "abc"};
    vector<string> vec(elem, elem + 6);
    vector<string>::iterator it = vec.begin();
    for( ;it != vec.end(); it++){
        st1.push(*it);
    }

    if(st1.find(elem[1])){
        cout << "find " << elem[1] << " success! " << endl;
    }else{
        cout << "find " << elem[1] << " fail! " << endl;
    }

    string findstr = "abc";
    cout << "The \"" << findstr 
         << "\" number of times is " 
         << st1.count(findstr);

    return 0;
}