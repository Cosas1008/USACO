/*
ID: yuweiic1
LANG: C
TASK: transform
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    FILE *fin, *fout;
    fin = fopen("transform.in","r");
    


    fout = fopen("transform.out","w");


    fclose(fin);
    fclose(fout);
    return 0;
}