
/*
--------------------------------------------------------

   练习1.1
       将先前介绍的main()程序依样画葫芦地输入

--------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string user_name;
    cout << "Please enter your first name: ";
    cin >> user_name;
    cout << '\n' 
        << "Hello, "
        << user_name
        << " ... and goodbye! \n ";

    cin >> user_name;

    return 0;
}

