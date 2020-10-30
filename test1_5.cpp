/*
--------------------------------------------------------

   练习1.5
       编写一个程序，能够询问用户的姓名，并读取用户所输入的内
    容。请确保用户输入的名称长度大于两个字符。如果用户的确输
    入了有效名称，就响应一些信息。
        请分别以C-Style字符串和String对象实现

--------------------------------------------------------
*/


#include <iostream>
#include <string>
    
using namespace std;

// String对象
int main(){
    int usr_name_len = 0;
    string usr_name;
    bool error_name = true;
    while( error_name ){
        cout << "Please enter your name : " << endl ;
        cin  >> usr_name ;
        error_name = false;
        usr_name_len = usr_name.size();

        if(usr_name_len < 3){
            cout << "Please enter right name ! \n" << endl ;
            error_name = true;
        }  
    }
    
    cout << "Hello " << usr_name << " \n "  << endl ;    

    return 0;
}



// C-Style
// int main(){}
// 
//     int usr_name_len = 0;
//     char usr_name[MAX_LENGTH];
//     bool error_name = true;
//     while (error_name) {
//         printf("Please enter your name: ");
//         scanf("%s", usr_name, MAX_LENGTH);   //scanf_s 会进行缓冲区检测 
//         printf("\n");
//         error_name = false;                 

//         usr_name[MAX_LENGTH - 1] = 0;         //手动在字符串后加 \0
//         usr_name_len = strlen(usr_name);      //计算字符串长度
//         if( usr_name_len <3){
//              printf("Please enter right name ! \n");
//              error_name = true;
//         }
//     }

//     printf("Hello %s \n",usr_name);
//     return 0;
// }
