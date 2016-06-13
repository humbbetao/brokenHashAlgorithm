#include <iostream>
#include "sha1.h"
#include "sha256.h"
#include "md5.h"

using namespace std;

int main(int argc, char *argv[])
{
    string input = "humb8657naval";
    string output1 = sha256(input);

    cout << "sha256('"<< input << "'):" << output1 << endl;
    cout << "sha1('grape'):" << sha1("humb8657naval") << endl;
    cout << "md5 of 'grape': " << md5("humb8657naval") << endl;
    return 0;
}



