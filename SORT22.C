#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define Max 50
void insert();
//void dele();
void display();


void bisearch();
void Lsearch();

void ssort();
void bsort();
void isort();
void Qsort(int first,int last);
void bucketsort();
void heap();

int a[Max],count=0;
int choice,c,d,first=-1,last=-1;
int main() {
    //clrscr();
    do {
	printf("\nWelcome To our Program\n");
	printf("\nMenu\n");
	printf("\n1.Insert\n2.Display\n3.Searching\n4.Sorting\n5.Exit\n");
	printf("\nEnter Choice:");
	scanf("%d",&choice);
	switch(choice) {
	case 1:
	    insert();
	    break;
      /*  case 2:
	    dele();
	    break;*/
	case 2:
	    display();
	    break;
	case 3:
	    do {
		printf("\n1.Linear Searching\n2.Binary Search\n3.Return\nEnter Choice:");
		scanf("%d",&c);
		switch(c) {
		case 1:
		    Lsearch();
		    break;
		case 2:
		    bisearch();
		    break;
		case 3:
		    break;
		default:
		    printf("\nInvalid Choice\n");
		}
	    } while(c!=3);
	    break;
	case 4:
	    do {
		printf("\n1.Selection sort\n2.Insertion Sort\n3.Bubble sort\n4.Quicksort\n5.Bucket Sort\n6.Heap Sort\n7.Return\nEnter choice:\n");
		scanf("%d",&d);
		switch(d) {
		case 1:
		    printf("\nThe array before sorting is:");
		    display();
		    ssort();
		    break;
		case 2:
		    printf("\nThe array before sorting is:");
		    display();
		    isort();
		    printf("\nThe array after sorting is:");
		    display();
		    break;
		case 3:
		    printf("\nThe array before sorting is:");
		    display();
		    bsort();
		    printf("\nThe array after sorting is:");
		    display();
		    break;
		case 4:
		    printf("\nThe array before sorting is:");
		    display();
		    Qsort(first,last);
		    printf("\nThe array after sorting is:");
		    display();
		    break;
		case 5:
		    printf("\nThe array before sorting is:");
		    display();
		    bucketsort();
		    printf("\nThe array after sorting is:");
		    display();
		    break;
		case 6:
		    printf("\nThe array before sorting is:");
		    display();
		    heap();
		    printf("\nThe array after sorting is:");
		    display();
		    break;
		case 7:
		    break;
		default:
		    printf("\nInvalid Choice\n");
		}
	    } while(d!=7);
	    break;
	case 5:
	    exit(0);
	default:
	    printf("\nInvalid Choice\n");

	}

    }
    while(choice!=5);


    return 0;
}


void insert() {
    int h;
    if(last==Max-1) {
	printf("\nArray is Full\n");
    }
    else {
	printf("\nEnter the element:");
	scanf("%d",&h);
	if(first==-1 && last==-1)
	{
	    first++;
	    last++;
	    a[first]=h;

	}
	else {
	    last++;
	    a[last]=h;
	}
	count++;

    }

}

void display() {
    int i;
    if(first == -1) {
	printf("\nEmpty Array");
    }
    else {
	for(i=0; i<=last; i++) {
	    printf("\n%d\n",a[i]);
	}
    }
}
void ssort() {
    int i,j,e;
    if(first==-1) {
	printf("\nEmpty array\n");
    }
    else {
	for(i=0; i<=last; i++) {
	    for(j=i+1; j<=last; j++) {
		if(a[i]>a[j]) {
		    e=a[i];
		    a[i]=a[j];
		    a[j]=e;
		}

	    }
	}
       /* printf("\nThe sorted array is:");
	display();*/
    }
}
void isort() {
    int i, key, j;
    if(first==-1) {
	printf("\nEmpty array\n");
    }
    else {
	for (i = 1; i < last; i++) {
	    key = a[i];
	    j = i - 1;

	    /* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
	    while (j >= 0 && a[j] > key) {
		a[j + 1] = a[j];
		j = j - 1;
	    }
	    a[j + 1] = key;
	}
       /* printf("\nThe sorted array is:");
	display();*/
    }
}

void Qsort(int first,int last) {
    int mid,e,high,low;
    mid=a[(first+last)/2];
    high=last;
    low=first;
    if(first==-1) {
	printf("\nEmpty array\n");
    }
    else {
	do {
	    while(a[low]<mid) {
		low=low+1;
	    }
	    while(a[high]>mid) {
		high=high-1;
	    }
	    if(a[low]>=a[high]) {
		e=a[low];
		a[ low]= a[high];
		low=low+1;
		a[high]=e;
		high= high-1;
	    }
	} while(low<=high);
	if(low<=last)
	    Qsort(low,last);
	if(high>=first) {
	    Qsort(high,first);
	}
    }
}
void bsort()
{
    int i,j,e;
    if(first==-1) {
	printf("\nEmpty array\n");
    }
    else {
	for(i=0; i<=last; i++) {
	    for(j=0; j<last; j++) {
		if(a[j]>a[j+1]) {
		    e=a[j];
		    a[j]=a[j+1];
		    a[j+1]=e;
		}

	    }
	}
      /*  printf("\nThe sorted array is:");
	display();*/
    }
}

void bisearch() {
    int i, ele, found = 0;
    int start, end, mid;
    printf("Enter the element you want to search\n");
    scanf("%d", &ele);

    start=0;
    end= count-1;


    while (start <= end)
    {
	mid = (start + end) / 2;
	if (ele < a[mid])
	{
	    end = mid - 1;
	}
	else if (ele > a[mid])
	{
	    start = mid + 1;
	}
	else if (ele == a[mid])
	{
	    printf("%d found at index %d",a[mid], mid);
	    found = 1;
	    break;
	}
    }
    if(found==0) {
	printf("\nEmpty Array\n");
    }
}
void Lsearch() {
    int i, ele, found = 0;
    printf("Enter the element you want to search\n");
    scanf("%d", &ele);

    for (i = 0; i <= count; i++)
    {
	if (a[i] == ele)
	{
	    printf("%d Found at %d index\n",a[i],i);
	    found = 1;
	    break;

	}
    }


    if(!found)
    {
	printf("Not Found\n");
    }
}

void bucketsort ()
{
    int j=0,i,c=0,stk[10][10],k,d=0,n,w,q,m,z,o;
    int l[10]= {0};
    for(i=0; i<count; i++) {
	if(a[i]>j) {
	    j=a[i];
	}
    }
    printf("\nThe largest element is=%d\n",j);
    while(j>0) {
	j=j/10;
	c++;
    }
    printf("The number of passes will be %d\n",c);
    for(i=1; i<=c; i++) {
	 //  printf("Pass %d:\n\n",i);
	for(m=0; m<10; m++) {
	    n=m;
	    for(k=0; k<count; k++) {
		w=a[k];
		o=i;
	      //  printf("%d",o);
		while(o>0){
		    z=w%10;
		    w=w/10;
		    o--;
		}

		if(z==m) {
		    stk[m][l[n]]=a[k];
	      //    printf("\n%d\n",stk[m][l[n]]);
		//      printf("\n%d\n",z);
		    l[n]++;

		}
	    }
	}
	printf("\n\n");
	d=count-1;
	for(q=9; q>=0; q--) {
	    while(l[q]!=0) {
		a[d]=stk[q][l[q]-1];
	   //     printf("\n%d\n",a[d]);
		l[q]--;
		d--;
	    }
	}
    }
 /* display();
    getch();*/
}

void heap(){
   int i,j,c,root,temp;
   int no=count;
   
   for(i=1;i<=no;i++){
      c=j;
      do{
	root=(c-1)/2;
	if(a[root]<a[c]){
	  temp=a[root];
	  a[root]=a[c];
	  a[c]=temp;
	  }
	c=root;
	}while(c!=0);
      
      printf("Heap array::\n");
      for(i=0;i<no;i++){
	 printf("\t%d\t",a[i]);
      }
      for(j=no-1;j>=0;j--){
	temp=a[0];
	a[0]=a[j];
	a[j]=temp;
	root=0;
	//left child
	do{
	  c=2*root+1;
	  if(a[c]<a[c+1] && c<j){
	    temp=a[root];
	    a[root]=a[c];
	    a[c]=temp;
	    }
	  root=c;
	}while(c<j);
	//right child
		do{
	  c=2*root+2;
	  if(a[c]<a[c+1] && c<j){
	    temp=a[root];
	    a[root]=a[c];
	    a[c]=temp;
	    }
	  root=c;
	}while(c<j);
      }
   }
} 
