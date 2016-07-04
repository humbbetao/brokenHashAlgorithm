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

int main(){

    string senhaTeste1 = "99999";
    string senhaTeste2 = "banana";
    string senhaTeste3 = "987654321";

    string saidaDoMd5 = md5(senhaTeste2);
    string saidaDoSha1 =sha1(senhaTeste2);
    string saidaDoSha256 = sha256(senhaTeste2);

    int chave = 1;
    string chaveGerada;
    stringstream resultado;
    string line;
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

     char input[MAX] = "qwertyuiopasdfghjklzxcvbnm1234567890_-";
     char str[MAX];
    int n, r, i, j, k ;
    #pragma omp parallel num_threads(4)
    {
         #pragma omp for schedule(dynamic,4)
    for(h=0; chaveGerada!=saidaDoMd5; h++)
    {
            int *num ;
    /* input é a string de entrada, e str
     * receberá cada permutação.
     */

    //scanf("%s", input) ;

    //printf("Entre com o r: ") ;
    //scanf("%d", &r) ;
    r=6;

    n = strlen(input) ;
    j = 0;
    str[0] = 0 ;
    for ( i = 0; i < n; i++ ) {
        if ( strchr(str, input[i]) == NULL ) {
            str[j] = input[i] ;
            j++ ;
            str[j] = 0 ;
        }
    }
    strcpy(input, str) ;
    n = strlen(input) ;

    /* Cria o nosso número. Ele é um vetor de
     * r+1 posições, sendo que a última é
     * reservada para indicar quando todos os
     * números de tamanho r foram gerados. */
    num = (int *) calloc( (r+1), sizeof(int)) ;
    if ( num == NULL ) {
        perror("calloc") ;
        return -1;
    }

    /* Termina quando a última posição do vetor
     * for 1. */
     int x =0;
    for (x=0, num[r] == 0, x++) {
        for ( i = 0; i < n; i++ ) {
            /* processo de mapeamento. */
            for ( j = 0, k = r-1; j < r; j++ ) {
                str[k] = input[num[j]] ;
                k-- ;
            }
            /* Mostra o resultado. */
            str[r] = 0 ;
            chaveGerada = md5(str);

            cout<<"Testando "<< str<<" ChaveGerada "<<chaveGerada<<"\n"<<endl;

            /* incrementa o algarismo menos significativo. */
            num[0]++ ;
        }

        /* Muda de "casa" e lança os vai uns. */
        for ( i = 0; i < r; i++ ) {
            if ( num[i] == n ) {
                num[i] = 0 ;
                num[i+1]++ ;
            }
        }
    }

    }



    if(chaveGerada==saidaDoMd5)
    {
        cout<<"quebrou"<<endl;
    }else{
        chaveGerada = md5(resultado.str());
        resultado.str("");
        resultado.clear();
        cout<<"Testando "<< i<<" ChaveGerada "<<chaveGerada<<"\n"<<endl;

    }
    }

    return 0;
}
