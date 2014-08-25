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

int* mergearray(int *a,int *b,int la,int lb)
{
	int *c,ap,bp,cp;
	int lc=la+lb;
	c = malloc((lc+1)*sizeof(int));
	for(ap=0,bp=0,cp=0;ap<la&&bp<lb;cp++) {
		if(a[ap]<b[bp])
			c[cp]=a[ap++];
		else
			c[cp]=b[bp++];
	}
	while(ap<la)
		c[cp++]=a[ap++];
	while(bp<lb)
		c[cp++]=b[bp++];

	return c;
}

int* merge_sort(int *list, int len)
{
	int i;
	int *a,*b,la,lb,half;

	if(len==1||len==0) return list;
	la = len/2;
	a = malloc((la)*sizeof(int));
	a = list;
	lb = len - la;
	b = malloc((lb)*sizeof(int));
	b = &list[la];

	printf("l1: ");
	for(i=0;i<la;i++) printf("%d ",a[i]);
	printf("\n");

	printf("l2: ");
	for(i=0;i<lb;i++) printf("%d ",b[i]);
	printf("\n");

	list = mergearray(merge_sort(a,la),merge_sort(b,lb),la,lb);
	return list;
}
	
	

#endif
