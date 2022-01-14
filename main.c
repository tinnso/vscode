#include <string>
#include <stdio.h>

using namespace std;
int main () {
    string str1("my");
    string str2("my");

    if (str1 == str2) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    getchar();

}