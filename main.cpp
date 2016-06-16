#include <iostream>
#include "sha1.h"
#include "sha256.h"
#include "md5.h"
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


std::string sconvert(const char *pCh, int arraySize){
  std::string str;
  if (pCh[arraySize-1] == '\0') str.append(pCh);
  else for(int i=0; i<arraySize; i++) str.append(1,pCh[i]);
  return str;
}


int main(int argc, char *argv[])
{
    string senha = "99999";
    string nomeDoArquivoDeWordListPortuguese = "dictionary_brazilian.dic";
    string nomeDoArquivoDeWordListEnglish = "dictionary_english.dic";
    string saidaDoMd5 = md5(senha);
    string saidaDoSha1 =sha1(senha);
    string saidaDoSha256 = sha256(senha);

    cout << "md5('"<< senha << "'):" << saidaDoMd5 << endl;
    cout << "sha1('"<< senha << "'):" << saidaDoSha1 << endl;
    cout << "sha256('"<< senha << "'):" << saidaDoSha256 << endl;

    int chave = 1;
    int i=0;
    string chaveGerada;
    stringstream resultado;
    string line;
    // test com dictionary
    string fileTest1("passwords.txt");
    string fileTest2("500-worst-passwords.txt");
    string fileTest3("cain.txt");
    string fileTest4("common-passwords.txt");
    string fileTest5("cracklib.txt");
    string fileTest6("facebook-first.l-withcount.txt");
    string fileTest7("english.txt");
    string fileTest8("rockyou.txt");
    string fileTest9("tbswordlist2.txt");
    string fileTest10("dic-0294.txt");


    ifstream myfile ("hashesorg251015.txt");

    ifstream is("wordLists/facebook-names-unique.txt");
    char buf[10*1024];
    int j=0;
    int k=0;
    char buffer[500];
    string nova;

   while(true)  {
        i++;
        chave++;
        
	while(is) {
		is.read(buf, sizeof(buf));
		//cout<<"FOI"<<endl;		
		for(k=0; j<10*1024; j+=1, k++){
			buffer[k]= buf[j];
			//cout<<"kkkkk"<<endl;
			if(buf[j]=='\n'){
				nova = sconvert(buffer, k);
				chaveGerada = md5(nova);
				if(chaveGerada==saidaDoMd5)
				{
				    cout<<"quebrou"<<endl;
				    break;
				}
				cout<<"Testando "<< nova <<" ChaveGerada "<<chaveGerada<<"\n"<<endl;
				k=0;
			 	//cout<<"FOI"<<endl;
			}
		}
		j=0;
		cout<<endl;	
	} 
    }

    return 0;
}

