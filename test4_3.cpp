/*
--------------------------------------------------------

   练习4.3
        考虑以下所定义的全局(global)数据:
            string program_name;
            string version_stamp;
            int version_number;
            int tests_run;
            int tests_passed;
        编写一个包装这些数据的类

--------------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;


class globalGS{

    public :
        static string get_program_name(){ return _program_name; }
        static string get_version_stamp(){ return _version_stamp; }
        static int get_version_number(){ return _version_number; }
        static int get_tests_run(){ return _tests_run; }
        static int get_tests_passed(){ return _tests_passed; }

        static string set_program_name(string elem){ _program_name = elem; }
        static string set_program_name(string elem){ _version_stamp = elem; }
        static int set_version_number(int elem){ _version_number = elem; }
        static int set_tests_run(int elem){ _tests_run = elem; }
        static int set_tests_passed(int elem){ _tests_passed = elem; }


    private : 
        static string _program_name;
        static string _version_stamp;
        static int _version_number;
        static int _tests_run;
        static int _tests_passed;

};


string globalGS::_program_name;
string globalGS::_version_stamp;
int globalGS::_version_number;
int globalGS::_tests_run;
int globalGS::_tests_passed;
