/*
ID: yuweiic1
LANG: C
TASK: barn1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(const void *a, const void *b)
{
    int va = *(const int *)a;
    int vb = *(const int *)b;
    if (va > vb)
        return 1;
    else
        return -1;
}
int main(int argc, char const *argv[])
{
    FILE *fin, *fout;
    int m, s, c;
    int *stall, *interval;
    fin = fopen("barn1.in", "r");
    fscanf(fin, "%d %d %d", &m, &s, &c);
    stall = malloc(c * (sizeof(int)));
    memset(stall, 0, c * sizeof(int)); // int is 4-byte data for 64-bit system

    for (int i = 0; i < c; i++)
    {
        fscanf(fin, "%d", &stall[i]);
    }
    int space;
    interval = malloc((c - 1) * 4);
    memset(interval, 0, (c - 1) * 4);
    fout = fopen("bar1.out", "w");
    for (int i = 0; i < c - 1; i++)
    {
        space = stall[i + 1] - stall[i];
        interval[i] = space;
        // fprintf(fout, "original interval : %d\n", interval[i]); // debug
    }
    qsort(interval, sizeof(interval) / sizeof(int), sizeof(int *), comp);
    for (int i = 0; i < c - 1; i++)
    {
        fprintf(fout, "interval : %d\n", interval[i]); // debug
    }
    fclose(fin);
    fclose(fout);
    free(stall);
    free(interval);
    return 0;
}
