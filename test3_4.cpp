/*
--------------------------------------------------------

   练习3.4
        编写一个程序, 利用istream_iterator从标准输入设备
    读取一连串整数. 利用ostream_iterator将其中的奇数写至
    某个文件, 每个数值皆以空格分隔. 再利用ostream_iterator
    将偶数写到另一个文件, 每个数值单独放在一行中. 

--------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

//分离奇偶数
class separate{
public:
    bool operator()(int elem){
        //是否为奇数(参数mod2) 
        return elem % 2 ? false : true;
    }
};

int main(){
    //odd奇数, even偶数
    ofstream file_odd("test3_4_odd.txt");
    ofstream file_even("test3_4_even.txt");
    if( !file_odd || !file_even){
        cerr << "unable to open the necessary files. \n";
        return -1;        
    }

    string word;
    vector<int> num;
    //将istream_iterator绑定输入设备cin, eof作为结尾
    istream_iterator<int> is(cin);
    istream_iterator<int> eof;
    //back_inserter(container)：使用push_back()在容器尾端安插元素
    //这次会再次触发cin, 只能人为用Ctrl+Z添加eof标志
    copy(is, eof, back_inserter(num));

    //奇偶分离
    vector<int>::iterator it_separate = partition(num.begin(), num.end(), separate());
    
    //奇数之间用空格分割
    ostream_iterator<int> os_odd(file_odd, " ");
    //偶数之间换行
    ostream_iterator<int> os_even(file_even, "\n");

    copy(num.begin(), it_separate, os_odd);
    copy(it_separate, num.end(), os_even);

    file_even.close();
    file_odd.close();
    return 0;
}
