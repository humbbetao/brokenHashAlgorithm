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

int main() {

    string senhaTeste1 = "99999";
    string senhaTeste2 = "banana";
    string senhaTeste3 = "987654321";

    string saidaDoMd5 = md5(senhaTeste2);

    int chave = 1;
    string chaveGerada;
    stringstream resultado;
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

            /* Cria o nosso n�mero. Ele � um vetor de
             * r+1 posi��es, sendo que a �ltima �
             * reservada para indicar quando todos os
             * n�meros de tamanho r foram gerados. */
            num = (int *) calloc((r + 1), sizeof (int));
            if (num == NULL) {
                perror("calloc");
                return -1;
            }

            /* Termina quando a �ltima posi��o do vetor
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

                    cout << "Testando " << str << " ChaveGerada " << chaveGerada << "\n" << endl;

                    /* incrementa o algarismo menos significativo. */
                    num[0]++;
                }

                /* Muda de "casa" e lan�a os vai uns. */
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
