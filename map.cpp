#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {

    map<string, int> words;
    words["vermmer"] = 1;

    map<string, int>::iterator it = words.begin();
    for (; it != words.end(); ++it) {
        cout << "key : " << it->first << endl;
        cout << "value : " << it->second << endl;
    }

    return 0;
}
