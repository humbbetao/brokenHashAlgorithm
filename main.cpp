#include <iostream>
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

#define OMP_STACKSIZE = "3G"

int main(int argc, char *argv[]){


    string senhaTeste1 = "99999";
    string senhaTeste2 = "banana";
    string senhaTeste3 = "qwertyuiop";
    string saidaDoMd5 = md5(senhaTeste1);
    int chave = 1;
    string chaveGerada="";
    stringstream resultado;
    char input[MAX] = "abcdefghijklmnopqrstuvxywzABCDEFGHJIKLMNOPQRSTUVXZYW1234567890_-";
    char str[MAX];
    int n, r, i, j, k;
    int h=0;
	int b=0;
	#pragma omp parallel for schedule(dynamic,100) num_threads(2)
	for(b=0; b<8; b++){

        for (h = 0; h<1; h++) {
            int *num;
            r = b;
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
            //if (num == NULL) {
              //  perror("calloc");
              //  return -1;
            //}

            /* Termina quando a última posição do vetor
             * for 1. */
            int x = 0;
            for (x = 0; num[r] == 0; x++) {
                for (i = 0; i < n; i++) {
                    /* processo de mapeamento. */
                    for (j = 0, k = r - 1; j < r; j++) {
                        str[k] = input[num[j]];
                        k--;
                    }
                    /* Mostra o resultado. */
                    str[r] = 0;
                    chaveGerada = md5(str);


                    cout << "Testando " << str << " ChaveGerada " << chaveGerada << "\n" << endl;
			if (chaveGerada == saidaDoMd5) {
			    cout << "quebrou" << endl;
			}
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
	}
    return 0;
}
