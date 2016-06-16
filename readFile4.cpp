#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream is("wordLists/facebook-names-unique.txt");
	char buf[1024*8];
	int i=0;
	do {
		is.read(buf, sizeof(buf));
		i++;
		cout<<"\n"<<endl;
	    	cout<<"Bloco "<<i<<"|\n"<<buf<<endl;
			
	} while(is);
	return 0;
}
