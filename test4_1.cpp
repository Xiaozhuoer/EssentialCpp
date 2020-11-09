/*
--------------------------------------------------------

   练习4.1
        建立Stack.h, 编写main()函数, 练习操作Stack的所有
    公开接口, 并加以编译执行. 程序代码文件和main()都必须
    包含Stack.h: 
        #include "Stack.h"

--------------------------------------------------------
*/

#include "Stack.h"
#include <iostream>

using namespace std;

int main(){
    string elem = "a";
    string elem_quote = "";
    Stack st;
    if(st.empty()){
        cout << "Stack is empty" << endl;
    }else{
        cout << "Stack is not empty" << endl;
    }

    if(st.push(elem)){
        cout << "Push " << elem << " success " << endl;
    }else{
        cout << "Push error" << endl;
    }

    if(st.peek(elem_quote)){
        cout << "peek " << elem << " success " << endl;
    }else{
        cout << "peek error" << endl;
    }

    if(st.full()){
        cout << "Stack is full" << endl;
    }else{
        cout << "Stack is not full" << endl;
    }

    int stack_size;
    stack_size = st.size();
    cout << "Stack size is " << stack_size << endl;  
    
    if(st.pop(elem_quote)){
        cout << "pop success and the elem_quote is " << elem_quote << endl;
    }else{
        cout << "pop error" << endl;
    }
    

    
    return 0;
}