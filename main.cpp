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
#define MAX 250

<<<<<<< HEAD
int main() {
=======

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
>>>>>>> e2417fc92584d6d8ff6b327935bbd25452a38149

    string senhaTeste1 = "99999";
    string senhaTeste2 = "banana";
    string senhaTeste3 = "987654321";

    string saidaDoMd5 = md5(senhaTeste2);

    int chave = 1;
    string chaveGerada;
    stringstream resultado;
<<<<<<< HEAD
    char input[MAX] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLMNBVCXZ1234567890_-";
    char str[MAX];
    int n, r, i, j, k;
    #pragma omp parallel num_threads(4)
    {
        #pragma omp for schedule(dynamic,4)
        for (h = 0; chaveGerada != saidaDoMd5; h++) {
            int *num;
            r = 6;
            n = strlen(input);
            j = 0;
            str[0] = 0;
            for (i = 0; i < n; i++) {
                if (strchr(str, input[i]) == NULL) {
                    str[j] = input[i];
                    j++;
                    str[j] = 0;
                }
            }
            strcpy(input, str);
            n = strlen(input);

            /* Cria o nosso número. Ele é um vetor de
             * r+1 posições, sendo que a última é
             * reservada para indicar quando todos os
             * números de tamanho r foram gerados. */
            num = (int *) calloc((r + 1), sizeof (int));
            if (num == NULL) {
                perror("calloc");
                return -1;
            }

            /* Termina quando a última posição do vetor
             * for 1. */
            int x = 0;
            for (x = 0, num[r] == 0, x++) {
                for (i = 0; i < n; i++) {
                    /* processo de mapeamento. */
                    for (j = 0, k = r - 1; j < r; j++) {
                        str[k] = input[num[j]];
                        k--;
                    }
                    /* Mostra o resultado. */
                    str[r] = 0;
                    chaveGerada = md5(str);
=======
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
>>>>>>> e2417fc92584d6d8ff6b327935bbd25452a38149

                    cout << "Testando " << str << " ChaveGerada " << chaveGerada << "\n" << endl;

<<<<<<< HEAD
                    /* incrementa o algarismo menos significativo. */
                    num[0]++;
                }

                /* Muda de "casa" e lança os vai uns. */
                for (i = 0; i < r; i++) {
                    if (num[i] == n) {
                        num[i] = 0;
                        num[i + 1]++;
                    }
                }
            }

        }

        if (chaveGerada == saidaDoMd5) {
            cout << "quebrou" << endl;
        }
    }

    return 0;
}
=======
>>>>>>> e2417fc92584d6d8ff6b327935bbd25452a38149
