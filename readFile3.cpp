#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main ( ) {
    string currentWord = "";
    ifstream wordsDB("wordLists/english.txt");
    vector <string> wordsDB_mem;
    int lines = 0;
   
    wordsDB_mem.reserve(10000000);              //!! stage 3
    while(getline(wordsDB, currentWord)) {
        wordsDB_mem.push_back(currentWord);     //!! stage 2
        lines++;
	cout<<currentWord<<endl;
    }
    cout << "Number of lines in vector = " << wordsDB_mem.size() << endl;
    cout << "Number of lines counted = " << lines << endl;

    return 0;
}


