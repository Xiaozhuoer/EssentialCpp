/*
--------------------------------------------------------

   练习3.1
        写一个读取文本文件的程序, 将文件中的每个单字存入map.
    map的key便是刚才所说的单字, map的value则是该单字在文本
    文件中的出现次数. 再定义一份由“排除字眼”组成的set, 其中
    包含诸如a, an, or, the, and和but之类的单字. 将某单字放入
    map之前, 先确定该单字并不在“排除子集”中. 一旦文本文件读取
    完毕, 请显示一份单字清单, 并显示各单字的出现次数. 你甚至
    可以再加以扩展, 在显示单字之前, 允许用户查询某个单字是否
    出现于文本文件中.   

--------------------------------------------------------
*/
#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

string exclusion(string );
string exclusion(string );
void displayMap(map<string,int> );
void usrFindWork(map<string,int> );

string exclusionPum(string );
int exclusionWords(string );


int main(){
    ifstream in_file("test3_1_begin.txt");
    ofstream out_file("test3_1_end.txt");
    
    if( !in_file || !out_file){
        cerr << "unable to open the necessary files. \n";
        return -1;
    }
    string fileWorkSwap;
    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;
    istream_iterator<string> it;

    map<string,int>::iterator iter;
    map<string,int> text;
    
    //读取文本文件, 单字存入map
    //copy(is, eof, back_inserter(text));
    
    //获取单字
    while(in_file >> fileWorkSwap){
        //过滤标点符号   
        fileWorkSwap = exclusionPum(fileWorkSwap);
        //过滤单字
        if(!exclusionWords(fileWorkSwap)){
            continue;
        }
        iter = text.find(fileWorkSwap);
        if(iter != text.end()){
            (iter -> second)++;  //若map里已有, 则key+1
        }else{
            text.insert(map<string,int>::value_type(fileWorkSwap,1)); //map里没有就插入
        }
    }

    int usrchoise;
    while(1){
        cout << "(1) Query word in text files " << endl;
        cout << "(2) Display all words " << endl;
        cout << "(3) Quit " << endl;
        cin >> usrchoise;
        switch(usrchoise){
            case 1: usrFindWork(text);
                    break;
            case 2: displayMap(text);
                    break;
            case 3: return 0;
            default:
                    cout << "Error, Please enter right number!" << endl;
        }
    }
    
    return 0;
}

//过滤标点符号和单字
string exclusionPum(string str){
    int pos;
    if ((pos = str.find(',')) != string::npos){
        str.erase(pos);
    }
    if ((pos = str.find('.')) != string::npos){
        str.erase(pos);
    }    
    if ((pos = str.find('!')) != string::npos){
        str.erase(pos);
    }
    if ((pos = str.find(';')) != string::npos){
        str.erase(pos);
    }
    if ((pos = str.find(':')) != string::npos){
        str.erase(pos);
    }

    return str;
}

//过滤单字
int exclusionWords(string str){
    set<string> word_exclusion = {"a", "an", "or", "the", "and", "but"};
    if(word_exclusion.count(str)){
        return false;
    }
    return true;
}

void usrFindWork(map<string,int> text){
    string usrWord;
    map<string,int>::iterator iter;
    cout << "Please enter the word you want to query: ";
    cin >> usrWord;
    iter = text.find(usrWord);
    if(iter != text.end()){
        //若map里有, 则显示
        cout << "value: " << iter->first << "   ";
        cout << "key: " << iter->second << endl;
    }else{
        cout << "Sorry. The word is not in the text file ";
    }

}

//显示
void displayMap(map<string,int> str){

    map<string,int>::iterator it = str.begin();
    for(; it != str.end(); it++){
        cout << "value: " << it->first << "   ";
        cout << "key: " << it->second << endl;
     }
}


