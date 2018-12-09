/*
ID: yuweiic1
LANG: C
TASK: milk
*/
#include <stdio.h>

struct farmer
{
    int unit;
    int price;
};

typedef struct farmer farm; // farm is struct array

int milkSack()
{
}

int main()
{
    FILE *fin, fout;
    fin = fopen("milk.in", "r");
    int amount, n_farmer;
    int i;
    fscanf(fin, "%d %d", &amount, &n_farmer);
    farm list[amount];
    for (i = 0; i < n_farmer; i++)
    {
        fscanf(fin, "%d %d", &list[i].price, &list[i].unit);
    }
    fclose(fin);

    // Greedy algo take place?
    // find the min price and buy all, then check the amount left, if left > 0 => seek the next
    int current_price = 0, left = amount;
    while(left > 0){
        
    }
    return 0;
}