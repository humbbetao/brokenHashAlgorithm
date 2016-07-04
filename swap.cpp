/*
 * C++ Program to Find Permutations of Given Character String
 */

#include<iostream>
using namespace std;

/* Function to swap two characters */
void swap(char& a, char& b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

/* Function to obtain permutations of string characters */
void permutation(string s,int i,int n)
{
    int j;
    if (i == n)
        cout << s << "\t";
    else
    {
        for (j = i; j < s.length(); j++)
        {
            swap(s[i],s[j]);
            permutation(s, i + 1, n);
            swap(s[i],s[j]);
        }
    }
}

