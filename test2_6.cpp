/*
--------------------------------------------------------

   练习2.4
        以template重新完成练习2.5, 并对main()函数做适度的
    修改.   

--------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename elemType>
void myMax(elemType a, elemType b){
    cout << a << " " << b << endl;
}

template <typename vecType>
void myMax(vector<vecType> a){
    for(int ix = 0 ; ix < a.size() ; ix++){
        cout << a[ix] << " | ";
    }
    cout << endl;
}

template <typename arrayType>
void myMax(arrayType *arr ,int size){
    for(int ix = 0 ; ix < size ; ix++){
        cout << *arr << " | ";
        arr++;
    }
    cout << endl;
}


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
    myMax(int_a,int_b);
    myMax(double_a,double_b);
    myMax(str_a,str_b);
    myMax(vec_int);
    myMax(vec_double);
    myMax(vec_str);
    myMax(arr_int,arr_size);
    myMax(arr_double,arr_size);
    myMax(arr_str,arr_size);
}
