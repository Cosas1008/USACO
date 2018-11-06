/*
ID: yuweiic1
LANG: C
TASK: transform
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUFF 255

int main(void)
{
    FILE *fin, *fout;
    int n;
    char c;
    char *ma, *mb,*mc, *buff;    
    fin = fopen("transform.in","r");
    if (fin == NULL) {
        printf("Error: file pointer is null.");
        exit(1);
    }

    fscanf(fin,"%d",&n);
    printf("%d\n", n);
    ma = malloc(n*n*sizeof(char));
    mb = malloc(n*n*sizeof(char));
    mc = malloc(n*n*sizeof(char));
    buff = malloc(MAX_BUFF*sizeof(char));

    memset(ma,0, sizeof(char)*n*n);
    memset(mb,0, sizeof(char)*n*n);
    memset(mc,0, sizeof(char)*n*n);
    memset(buff,0,sizeof(char)*MAX_BUFF);

    printf("A:\n");
    for(int i=0; i<n; i++){
        fgets(buff,MAX_BUFF,(FILE*)fin);
        printf("%s\n", buff);
        memcpy(ma+i*n,buff,n);
    }
    printf("B:\n");
    for(int i=0; i<n; i++){
        fgets(buff,MAX_BUFF,(FILE*)fin);
        printf("%s\n", buff);
        memcpy(mb+i*n,buff,n);
    }
    // done reading
    fout = fopen("transform.out","w");
    printf("%s",mb);
    free(ma);
    free(mb);
    free(mc);
    free(buff);
    fclose(fin);
    fclose(fout);
    return 0;
}