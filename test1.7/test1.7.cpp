/*
--------------------------------------------------------

   练习1.7
       输入两行文字并存盘。然后编写一个程序，打开该文本文
    件，将其中的每个字都读取到一个vector<string>对象中。
    遍历该vector,将内容显示到cout。然后利用泛型算法sort(),
    对所有文字排序:
        #include <algorithm>
        sort( container.begin(), container.end());
        再将排序后的结果输出到另一个文件。

--------------------------------------------------------
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<string> fileSession;
//string outfilename = "test1_7_begin.txt";
char infilename[] = "test1_7_begin.txt";
char outfilename[] = "test1_7_end.txt";
int main() {

    string fileSession_swap;

    //打开文件
    //BUG -> C++的string类无法作为ifsteam的参数
    ifstream infile(infilename);
    //ifstream infile("test1_7_begin.txt"); 直接写文件名也可以
    //文件无法打开输出错误信息
    if (!infile) {
        cerr << " Unable to open " << infilename << " file " << endl;
    }
    else {
        //文件打开后，读取每一行数据到fileSession里
        while (infile >> fileSession_swap) {
            fileSession.push_back(fileSession_swap);
        }
        infile.close();
    }

    //将fileSession存储的数据显示
    for (int ix = 0; ix < fileSession.size(); ix++) {
        cout << fileSession[ix] << endl;
    }
    //fileSession里的数据用sort排序
    string word;
    //将fileSession里的每一行数据都拼接成一个字符串存放到数组里
    for (int iy = 0; iy < fileSession.size(); iy++) {
        word.append(fileSession[iy]);
    }

    char charWord[] = "";

    //尽量别用strcpy，容易缓冲区溢出 用strncpy(vscode)或strcpy_s(vs2019)
    //strncpy(charWord, word.c_str(), word.length() + 1);
    //sort(charWord, charWord + strlen(charWord));
    //for (int iz = 0; iz < strlen(charWord); iz++) {
    //    cout << charWord[iz];
    //}

     strcpy_s(charWord,strlen(word.c_str()) +1 , word.c_str());
     sort(charWord, charWord + strlen(charWord));
     for (int iz = 0; iz < strlen(charWord); iz++)
         cout << charWord[iz];


    // 再将排序后的结果输出到另一个文件
    ofstream outfile(outfilename);
    if (!outfile) {
        //文件无法打开输出错误信息
        cerr << " Unable to open " << outfilename << " file " << endl;
    }
    else {
        outfile << charWord << endl;
        outfile.close();
    }

    return 0;

}

