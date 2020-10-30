/*
--------------------------------------------------------

   练习1.6
       编写一个程序，从标准输入设备读取一串整数，并将读入
    的整数依次放到array及vector，然后遍历这两种容器，求取
    数值总和。将总和及平均值输出至标准输出设备

--------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int array_size = 20 ;
char usr_arr[array_size];
vector<int> usr_vec;



int main(){
    
    int i = 0;
    int swap, usr_arr_sum = 0, usr_vec_sum = 0;
    double usr_arr_ave = 0, usr_vec_ave = 0;
    cout << "Please enter a string of integers : " ;

    cin >> swap ;
    usr_arr[i++] = swap;
    usr_vec.push_back(swap);
    while( (swap = getchar()) != '\n'){
        cin >> swap ;
        usr_arr[i++] = swap;
        usr_vec.push_back(swap);
    }
    
    //Array数组遍历
    cout << "Array : " ;
    for(int ix = 0 ; ix < strlen(usr_arr) ; ix++){
        cout << (int)usr_arr[ix] << ' ' ;
        usr_arr_sum += usr_arr[ix]; 
    }
    //Array总和
    cout << "| Array sum : " << usr_arr_sum << ' ' ;
    //Array平均值
    usr_arr_ave = (double) usr_arr_sum/strlen(usr_arr);
    cout << "| Array ave : " << usr_arr_ave << ' ' << endl;
    

    //Vector遍历
    cout << "Vector : " ;
    for(int iy = 0 ; iy < usr_vec.size(); iy++){
        cout << usr_vec[iy] << ' ' ;
        usr_vec_sum += usr_vec[iy];
    }
    //Vector总和
    cout << "| Array sum : " << usr_arr_sum << ' ' ;
    //Vector平均值
    usr_vec_ave = (double) usr_vec_sum/usr_vec.size();
    cout << "| Array ave : " << usr_vec_ave << ' ' << endl;   
}
