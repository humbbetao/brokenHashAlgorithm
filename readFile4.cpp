#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream is("wordLists/realuniq.lst");
	char buf[512*1024];
	int i=0;
	do {
		is.read(buf, sizeof(buf));
		i++;
		cout<<"\n"<<endl;
	    	cout<<"Bloco "<<i<<"|\n"<<buf<<endl;
		int j =0;
		
	} while(is);
	return 0;
}
