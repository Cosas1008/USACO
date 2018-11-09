/*
ID: yuweiic1
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <stdlib.h>

int n;
int Equal(char **a, char **b)
{
    char *tar1, *tar2;
    int i, j;
    for (i = 0; i < n; i++)
    {
        tar1 = (char *)(a + i);
        tar2 = (char *)(b + i);
        for (j = 0; j < n; j++)
        {
            if (tar1[j] != tar2[j])
                return 0;
        }
    }
    return 1;
}
void r90(char **transformed, char **original)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transformed[j][n - i - 1] = original[i][j];
        }
    }
}

void filp(char **transformed, char **original)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transformed[i][n - j - 1] = original[i][j];
        }
    }
}

int main()
{
    int i, j, k, identical = 0, opt = 0;
    char **ori, **tag, **tmp1, **tmp2; // 2d char array
    FILE *fin, *fout;

    // Read File
    fin = fopen("transform.in", "r");
    fscanf(fin, "%d", &n);

    // memory allocation
    // modefied sizeof(char) to sizeof(char*)
    ori = (char **)malloc(n * sizeof(char*));
    tag = (char **)malloc(n * sizeof(char*));
    tmp1 = (char **)malloc(n * sizeof(char*));
    tmp2 = (char **)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        ori[i] = (char *)malloc(n * sizeof(char));
        tag[i] = (char *)malloc(n * sizeof(char));
        tmp1[i] = (char *)malloc(n * sizeof(char));
        tmp2[i] = (char *)malloc(n * sizeof(char));
    }

    // load data
    for (i = 0; i < n; i++)
    {
        fscanf(fin, "%s", &ori[i][0]);
        // printf("%c%c%c%c\n",ori[i][0], ori[i][1], ori[i][2], ori[i][3]); // n = 4
    }
    for (i = 0; i < n; i++)
    {
        fscanf(fin, "%s", &tag[i][0]);
    }

    //check identical
    //90   cw opt:1
    r90(tmp1, ori);
    if (Equal(tmp1, tag))
        opt = 1;
    else
    { //180  cw opt:2
        r90(tmp2, tmp1);
        if (Equal(tmp2, tag))
            opt = 2;
        else
        { //270  cw opt:3
            r90(tmp1, tmp2);
            if (Equal(tmp1, tag))
                opt = 3;
            else
            { //nochange  opt:6
                if (Equal(ori, tag))
                    opt = 6;
                else
                { // flip opt:4
                    filp(tmp1, ori);
                    if (Equal(tmp1, tag))
                        opt = 4;
                    else
                    { //90  fcw opt:5
                        r90(tmp2, tmp1);
                        if (Equal(tmp2, tag))
                            opt = 5;
                        else
                        { //180 fcw opt:5
                            r90(tmp1, tmp2);
                            if (Equal(tmp1, tag))
                                opt = 5;
                            else
                            { //270  fcw opt:5
                                r90(tmp2,tmp1);
                                if(Equal(tmp2, tag))
                                    opt = 5;
                                else
                                {  // invalid transform
                                    opt = 7;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    //output file
    fout = fopen("transform.out", "w");
    fprintf(fout, "%d\n", opt);
    // Free dynamic allocated memory
    for (i = 0; i < n; i++)
    {
        free(ori[i]);
        free(tag[i]);
        free(tmp1[i]);
        free(tmp2[i]);
    }

    free(ori);
    free(tag);
    free(tmp1);
    free(tmp2);
    // Close file
    fclose(fin);
    fclose(fout);
    return 0;
}