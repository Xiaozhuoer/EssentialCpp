/*
--------------------------------------------------------

   练习3.2
        读取文本文件内容---和练习3.1一样---并将内容存储于
    vector. 以字符串长度为依据, 对vector排序. 定义一个
    function object并传给sort(); 将一function object接
    受两个字符串, 当第一字符串的长度小于第二字符串的长度
    时, 就返回true. 最后, 打印排序后的vector内容.

--------------------------------------------------------
*/

#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

//过滤标点符号和单字
string exclusionPum(string);
//过滤单字
int exclusionWords(string);
//显示
void displayVec(vector<string>);
//自定义sort排序
class cmp {
public:
    bool operator() (const string& a, const string& b) {
        return a.size() < b.size(); //从大到小排序
    }
};

int main() {
    ifstream in_file("test3_1_begin.txt");
    if (!in_file) {
        cerr << "unable to open the necessary files. \n";
        return -1;
    }

    vector<string> verStr;
    string fileWorkSwap;

    //获取单字
    while (in_file >> fileWorkSwap) {
        //过滤标点符号   
        fileWorkSwap = exclusionPum(fileWorkSwap);
        //过滤单字
        //如果存在过滤字就不执行后面的语句, continue后重新迭代到while
        if (!exclusionWords(fileWorkSwap)) {
            continue;
        }
        //存入vector
        verStr.push_back(fileWorkSwap);
    }
    sort(verStr.begin(), verStr.end(), cmp());
    displayVec(verStr);

    return 0;
}

//过滤标点符号和单字
string exclusionPum(string str) {
    int pos;
    if ((pos = str.find(',')) != string::npos) {
        str.erase(pos);
    }
    if ((pos = str.find('.')) != string::npos) {
        str.erase(pos);
    }
    if ((pos = str.find('!')) != string::npos) {
        str.erase(pos);
    }
    if ((pos = str.find(';')) != string::npos) {
        str.erase(pos);
    }
    if ((pos = str.find(':')) != string::npos) {
        str.erase(pos);
    }

    return str;
}

//过滤单字
int exclusionWords(string str) {
    set<string> word_exclusion = { "a", "an", "or", "the", "and", "but" };
    if (word_exclusion.count(str)) {
        return false;
    }
    return true;
}

//显示
void displayVec(vector<string> vecStr) {
    vector<string>::iterator it = vecStr.begin();
    for (; it != vecStr.end(); it++) {
        cout << *it << endl;
    }
}
