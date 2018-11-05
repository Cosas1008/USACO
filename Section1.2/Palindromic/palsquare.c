/*
ID: yuweiic1
LANG: C
TASK: palsquare
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUFF 255


char result[MAX_BUFF] = {0};

char* intToBase(int number, int base)
{
    char hex[36] = {'0','1','2','3','4','5','6','7',
                        '8', '9','A','B','C','D','E','F',
                        'G','H','I','J','K','L','M','N',
                        'O','P','Q','R','S','T','U','V',
                        'W','X','Y','Z'};   // support up to base 35
    while( number > 0){
        char n = hex[number%base];
        strcat(result,&n);
        int len = strlen(result);
        printf("Len: %d Result: %s\n",len, result);
        number /= base;
    }
    return result;
}

int checkPalindrom(char* str)
{
    size_t len = strlen(str);
    if(len == 1) return 1;
    for(int i = 0; i < len; i++){

    }
}

int main(int argc, char const *argv[])
{
    FILE* fin, fout;
    int base;
    fin = fopen("palsquare.in","r");
    fscanf(fin,"%d", &base);
    printf("Base %d\n", base);
    for(int i = 1; i <= 3; i++)
    {
        intToBase(i, base);
        // printf("%s\n", cha1);
        memset(result,0,MAX_BUFF);
        intToBase(i^2, base);
        memset(result,0,MAX_BUFF);
    }
    fclose(fin);
    // fclose(fout);
    return 0;
}
