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
    char *matrix = malloc(n*n*sizeof(char));
    memset(matrix,0, sizeof(char)*n*n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c = fgetc(fin);
            if(c == '@' || c == '-'){
                *(matrix + i*n + j) = c;
            }
        }
    }
    fclose(fin);
    fout = fopen("transform.out","w");
    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
            printf("%c",*(matrix + i*n + j));
        }
        printf("\n");
    }
    fclose(fout);
    return 0;
}