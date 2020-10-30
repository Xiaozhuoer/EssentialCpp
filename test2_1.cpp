/*
--------------------------------------------------------

   练习2.1
        先前的main()只让用户输入一个位置值，然后便结束程序。
    如果用户想取得两个甚至更多元素值，他必须执行这个程序两
    次或多次。请该写main()，使它允许用户不断输入位置值，直
    到用户希望停止为止

--------------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

bool fibon_elem( int, int & );
bool print_sequence( int);

int main(){
    string usr_enter = "";
    int pos;
    int elem;
    while(1){
        cout << "Please enter a position (q to quit): ";
        cin >> usr_enter;
        if( usr_enter == "q"){
            break;
        }
        pos = stoi(usr_enter);
        if(fibon_elem(pos,elem)){
            cout << "element # " << pos
                << " is " << elem << endl;
        } else {
            cout << "Sorry. Could not calculate element # "
                << pos << endl;
        }
        print_sequence(pos);
    }
}


bool print_sequence(int pos){
    if(pos <= 0 || pos > 1024){
        cerr << " invalid position: " << pos
             << " -- cannot handle request! \n";

        return false;
    }
    cout << "The Fibonacci Sequence for "
         << pos << " positions: \n\t ";
    
    //所有位置都会打印出1 1，只有pos == 1 除外
    switch (pos){
    default:    
    case 2:
        cout << "1 ";
        //此处无break
    case 1:
        cout << "1 ";
        break;
    }

    int elem;
    int n_2 = 1 , n_1 = 1;
    for(int ix = 3; ix <= pos ; ++ix){
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;

        //一行打印10个元素
        cout << elem << ( !(ix % 10 ) ? "\n\t" : " ");
    }
    cout << endl;

    return true;
}

bool fibon_elem(int pos, int &elem){
    //检查位置值是否合理
    if(pos <= 0 || pos > 1024 ){
        elem = 0;
        return false;
    }
    //位置值为1和2时，elem的值为1
    elem = 1;
    int n_2 = 1 , n_1 = 1;

    for(int ix = 3; ix <= pos ; ++ix){
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }
    return true;
}
