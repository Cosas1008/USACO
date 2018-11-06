/*
ID: yuweiic1
LANG: C
TASK: transform
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    FILE *fin, *fout;
    fin = fopen("transform.in","r");
    int n;
    char c;
    fscanf(fin,"%d",&n);
    char *ma = malloc(n*n*sizeof(char));
    memset(ma,0, sizeof(char)*n*n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c = fgetc(fin);
            if(c == '@' || c == '-'){
                *(ma + i*n + j) = c;
            }
        }
    }
    fclose(fin);
    fout = fopen("transform.out","w");
    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
            printf("%c",*(ma + i*n + j));
        }
        printf("\n");
    }
    free(ma);
    fclose(fout);
    return 0;
}