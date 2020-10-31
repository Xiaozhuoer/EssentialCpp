/*
--------------------------------------------------------

   练习2.5
        实现一个重载的max()函数, 让它接受以下参数: 
        1. 两个整数
        2. 两个浮点数
        3. 两个字符串
        4. 一个整数vector
        5. 一个浮点数vector
        6. 一个字符串vector
        7. 一个整数数组, 以及一个表示数组大小的整数值
        8. 一个浮点数数组, 以及一个表示数组大小的整数值
        9. 一个字符串数组, 以及一个表示数组大小的整数值
        最后编写main()测试这些函数.    

--------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void max(int , int );
void max(double, double);
void max(string, string);
void max(vector<int> );
void max(vector<double> );
void max(vector<string> );
void max(int * ,int );
void max(double * ,int );
void max(string * ,int );

int main(){
    int int_a =7, int_b = 77;
    double double_a= 7.77, double_b = 7.7777;
    string str_a = "Love you Liky", str_b = "Love me too";
    vector<int> vec_int = {7,77,777};
    vector<double> vec_double = {7.777,77.7777,777.777777};
    vector<string> vec_str = {"Love you Liky","Love me too","Happy everyday"};
    const int arr_size = 4;
    int arr_int[arr_size] = {7,77,77,7777};
    double arr_double[arr_size] = {7.777,77.7777,77.77,7.7777};
    string arr_str[arr_size] = {"Love you Liky","Love me too","Happy everyday","Good Lucky"};
    max(int_a,int_b);
    max(double_a,double_b);
    max(str_a,str_b);
    max(vec_int);
    max(vec_double);
    max(vec_str);
    max(arr_int,arr_size);
    max(arr_double,arr_size);
    max(arr_str,arr_size);
}

void max(int a, int b){
    cout << "1. Here are two integer : " << a << " " << b << endl;
}
void max(double a, double b){
    cout << "2. Here are two double : " << a << " " << b << endl;
}
void max(string a, string b){
    cout << "3. Here are two string : \"" << a << "\"  \"" << b << "\""<< endl;
}
void max(vector<int> a){
    //用迭代器遍历vector
    cout << "4. Here are integer's vector : ";
    vector<int>::iterator it;
    for(it = a.begin(); it != a.end(); it++){
        cout << *it << " " ;
    }
    cout << endl;
}
void max(vector<double> a){
    //用迭代器遍历vector
    cout << "5. Here are double's vector : ";
    vector<double>::iterator it;
    for(it = a.begin(); it != a.end(); it++){
        cout << *it << " " ;
    }
    cout << endl;
}
void max(vector<string> a){
    cout << "6. Here are string's vector : ";
    //用迭代器遍历vector
    vector<string>::iterator it;
    for(it = a.begin(); it != a.end(); it++){
        cout << "\"" << *it << "\" " ;
    }
    cout << endl;
}
void max(int *arr ,int size){
    cout << "7. Here are integer's array : ";
    for(int ix = 0 ; ix < size ; ix++){
        cout << *arr << " ";
        arr++;
    }
    cout << endl;
}
void max(double *arr ,int size){
    cout << "8. Here are double's array : ";
    for(int ix = 0 ; ix < size ; ix++){
        cout << *arr << " ";
        arr++;
    }
    cout << endl;
}
void max(string *arr ,int size){
    cout << "9. Here are string's array : ";
    for(int ix = 0 ; ix < size ; ix++){
        cout << "\"" << *arr << "\" " ;
        arr++;
    }
    cout << endl;
}
