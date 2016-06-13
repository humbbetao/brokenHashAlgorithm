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
using namespace std;

int main(int argc, char *argv[])
{
    string senha = "99999";

    string saidaDoMd5 = md5(senha);
    string saidaDoSha1 =sha1(senha);
     string saidaDoSha256 = sha256(senha);

    cout << "md5('"<< senha << "'):" << saidaDoMd5 << endl;
    cout << "sha1('"<< senha << "'):" << saidaDoSha1 << endl;
    cout << "sha256('"<< senha << "'):" << saidaDoSha256 << endl;

    //int i =0;
    int chave = 1;
    int i=0;
    string chaveGerada;
    stringstream resultado;
    while(true)
    {
        i++;
        chave++;

        resultado<<i;
        chaveGerada = md5(resultado.str());
        resultado.str("");
        resultado.clear();
        if(chaveGerada==saidaDoMd5)
        {
            cout<<"quebrou"<<endl;
            break;
        }
        cout<<"Testando "<< i<<" ChaveGerada "<<chaveGerada<<"\n"<<endl;

    }

    return 0;
}



