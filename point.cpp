/*
--------------------------------------------------------
                                                      
                指针练习                                                       
                                                      
-------------------------------------------------------- 
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std ;


const int seq_cnt = 6 ;

vector<int> *current_vec = 0;
vector<int> fibonacci, lucas, pell, triangular, square, pentagonal;
vector<int> *seq_addrs[seq_cnt] = {
    &fibonacci, &lucas, &pell, 
    &triangular, &square, &pentagonal, 
};

int main()
{
    int flag;

    for ( int ix = 0; ix < seq_cnt; ++ix)
    {
        current_vec = seq_addrs[ix];
        cout << current_vec << " | " << &lucas << endl ;      
    }  

    cin  >> flag ;

    return 0;
}
