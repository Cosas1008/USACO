#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 255

int find_index(int a[], int num_elements, int value);

int main(int argc, char const *argv[])
{
	FILE* fin, *fout;
	fin = fopen("milk2.in", "r");
	fout = fopen("milk2.out","w");
	int left = 0, right = 0;
	int min, max, num, index;
	int milked = 0, noMilked = 0;
	char line[MAXLINE];
	fgets(line, MAXLINE, fin);
	sscanf(line, "%d",&num);
	int space = 2*(num-1);
	int* interval = malloc(space* sizeof(int));
	memset(interval, 0 , space*sizeof(int));	// neccessory for find_index function
	while(fgets(line, MAXLINE, fin)!= NULL){
		sscanf(line, "%d %d", &min, &max);
		index = find_index(&interval, space, 0);
		if(max < left){// check the max < left or min > right
			// interval happened
			// index = find_index(&interval, space, 0);
			interval[index] = max;
			interval[index+1] = left;
		}else if(min > right){
			// interval happened
			interval[index] = right;
			interval[index+1] = min;
		}else{

		}
		// printf("%d %d \n", min, max);
	}
	free(interval);
	fclose(fin);
	fclose(fout);
	return 0;
}
// refered from https://phanderson.com/C/find_idx.html
int find_index(int array[], int num_elements, int value)
{
   for(int i=0; i<num_elements; i++){
	 if (array[i] == value){
	    return(value);  /* it was found */
	 }
   }
   return(0);  /* if it was not found, return to the beginning of array */
}