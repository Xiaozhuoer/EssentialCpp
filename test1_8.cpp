/*
--------------------------------------------------------

   练习1.8
        1.4节的switch语句让我们得以根据用户答错的次数提供
    不同的安慰语句。请以array储存四种不同的字符串信息，并
    以用户答错次数作为array的索引值，以此方式来显示安慰语
    句

--------------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

const int seq_size = 4;
string pell_seq[seq_size] = {
    "Pull yourself together \n",
    "Keep your chin up \n" ,
    "Do not be so miserable \n" ,
    "It will be ok \n" ,
};

int main(){
    string  error_times = "";
    while(1){
        cout << "Please enter error times(1 ~ 4) (q to quit): "  ;
        cin  >> error_times ;

        //用户输入q 则退出
        if(error_times == "q"){
            break;
        }
        switch (stoi(error_times) - 1){
            case 0:
                cout << pell_seq[0];
                break;
            case 1:
                cout << pell_seq[1];
                break;
            case 2:
                cout << pell_seq[2];
                break;
            case 3:
                cout << pell_seq[3];
                break;
            default:
                break;
        }
    }
}
