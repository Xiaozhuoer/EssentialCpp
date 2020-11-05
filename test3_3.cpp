/*
--------------------------------------------------------

   练习3.3
        定义一个map, 以家庭姓氏为key, value则是家庭所有
    小孩的名字. 令此map至少容纳六笔数据

--------------------------------------------------------
*/

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <array>

using namespace std;
bool queryFistname(string, map<string,vector<string>>);

int main(){
    
    string fristname[6]={"zhuoer", "liky", "xinchen", "mengxuan", "mengqi" ,"huiye"};
    map<string,vector<string>> familyName;
    vector<string> xiao(fristname, fristname + 6);
    familyName.insert(map<string,vector<string>>::value_type("xiao",xiao));

    string usr;
    map<string,vector<string>>::iterator itmap;
    while (1){
        cout << "Please enter the last name you want to query(q to quit): " << endl;
        cin >> usr;
        // q -> quit
        if(usr == "q"){
            break;  
        }
        //查询姓氏
        itmap = familyName.find(usr);
        if(itmap == familyName.end()){
            //没有就提示信息，重新while
            cout << "Sorry, The last name is not exist! " << endl;
            continue;
        }
        //itvec取得名字vector的地址
        vector<string>::iterator itvec = (itmap -> second).begin();
        //循环打印
        for(; itvec != (itmap -> second).end(); itvec++){
            cout << *itvec << " ";
        }
        cout << endl;
    }
    
    return 0;
}


