#include <stdio.h>
#include <stdlib.h>
#include "alg.h"

int main(int argc, char* argv[])
{
	int i;
	int *list,len;

	printf("Enter the length of the list: ");
	scanf("%d",&len);
	list = malloc(len*sizeof(int));

	printf("Enter the list: ");
	for(i=0;i<len;i++) scanf("%d",&list[i]);

//	bubble_sort(list,len);
//	quick_sort(list,0,len-1);
//	selection_sort(list,len);
//	insertion_sort(list,len);
	shell_sort(list,len);

	printf("The sorted list is: ");
	for(i=0;i<len;i++) printf("%d  ",list[i]);

	free(list);
	return 0;
}
