/*
--------------------------------------------------------
                                                      
                文件的读写练习                                                       
                                                      
-------------------------------------------------------- 
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// 如果指定的文件不存在，便会有一个文件被产生出来并打开供输出使用。
// 如果指定的文件已经存在，这个文件会被打开用于输出，而文件中原有的数据会被丢弃。
//  -->  ofstream outfile("seq_data.txt");

// 以追加模式( append mode ) 打开文件
int main()
{
    ofstream outfile("seq_data.txt", ios_base::app);

    if (!outfile)
        cerr << "Unable to save session data! \n";
    else
        outfile << usr_name << ' ' 
                << num_tries << ' '
                << num_right << endl;

    return 0;
}
