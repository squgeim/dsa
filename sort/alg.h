#ifndef _alg_h
#define _alg_h

void bubble_sort(int *list,int len)
{
	int pass,i,temp,j;
	for(pass=0;pass<len;pass++) {
		printf("Pass = %d\n",pass);
		for(i=0;i<len-pass-1;i++) {
			if(list[i]>list[i+1]) {
				temp=list[i];
				list[i]=list[i+1];
				list[i+1]=temp;
			}
			for(j=0;j<len;j++) printf("%d  ",list[j]);
			printf("\n");
		}
	}
}

void quick_sort(int *list,int f,int l)
{
	int i;
	int temp,pivot,left,right;
	
	if(f==l) return;

	left=f,right=l;
	pivot = list[(int)((f+l)/2)];
	printf("List: ");
	for(i=f;i<=l;i++) printf("%d  ",list[i]);
	printf("\n");
	while(left<=right) { 
		while(list[left]<pivot)
			left++;
		while(list[right]>pivot)
			right--;
		if(left<=right) {
			if(left!=right) {
				temp=list[left];
				list[left]=list[right];
				list[right]=temp;
			}
			left++;
			right--;
		}
	}
	quick_sort(list,f,right);
	quick_sort(list,left,l);
}

void selection_sort(int *list, int len)
{
	int pass,i,min,temp;
	for(pass=0;pass<len-1;pass++) {
		min=pass;
		for(i=pass;i<len;i++)
			if(list[min]>list[i]) min=i;

		if(min!=pass) {
			temp=list[pass];
			list[pass]=list[min];
			list[min]=temp;
		}
		printf("Pass %d: ",pass);
		for(i=0;i<len;i++) printf("%d ",list[i]);
		printf("\n");
	}
}

void insertion_sort(int *list, int len)
{
	int pass, i, temp;
	for(pass=0;pass<len;pass++) {
		for(i=pass;i>0;i--) {
			if(list[i]<list[i-1]) {
				temp=list[i];
				list[i]=list[i-1];
				list[i-1]=temp;
			}
		}
	}
}

void shell_sort(int *list,int len)
{
	int gap,pass,j,temp,min;
	for(gap=len/2;gap>0;gap/=2) {
		for(pass=0;pass<len;pass+=gap) {
			for(j=pass;j>0;j-=gap) {
				if(list[j]<list[j-gap]) {
					temp=list[j];
					list[j]=list[j-gap];
					list[j-gap]=temp;
				}
			}
		}
	}
}

#endif
