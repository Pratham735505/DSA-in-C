#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define Max 50
void insert();
void dele();
void display();


void bisearch();
void lsearch();

void ssort();
void bsort();
void isort();
void qsort(int,int);
void bucketsort();

int a[Max],count=0;
int choice,c,d,first=-1,last=-1;
int main() {
    clrscr();
    do {
        printf("\nWelcome To our Program\n");
        printf("\nMenu\n");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Searching\n5.Sorting\n6.Exit\n");
        printf("\nEnter Choice:");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            insert();
            break;
        case 2:
            dele();
            break;
        case 3:
            display();
            break;
        case 4:
            do {
                printf("\n1.Linear Searching\n2.Binary Search\n3.Return\nEnter Choice:");
                scanf("%d",&c);
                switch(c) {
                case 1:
                    lsearch();
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
        case 5:
            do {
                printf("\n1.Selection sort\n2.Insertion Sort\n3.Bubble sort\n4.Quicksort\n5.Bucket Sort\n6.Return\nEnter choice:\n");
                scanf("%d",&d);
                switch(d) {
                case 1:
                    ssort();
                    break;
                case 2:
                    isort();
                    break;
                case 3:
                    bsort();
                    break;
                case 4:
                    qsort(first,last);
                    break;
                case 5:
                    bucketsort();
                    break;
                case 6:
                    break;
                default:
                    printf("\nInvalid Choice\n");
                }
            } while(d!=6);
            break;
        case 6:
            exit(0);
        default:
            printf("\nInvalid Choice\n");

        }

    }
    while(choice!=6);


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
void dele() {
    if(first==-1) {
        printf("\nEmpty Linked list\n");
    }
    else {
        printf("\nThe deleted element is=%d",a[last]);
        if(last==1)
            first=-1;
        last--;
        count--;
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
        printf("\nThe sorted array is:");
        display();
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
        printf("\nThe sorted array is:");
        display();
    }
}

void qsort(int first,int last) {
 int mid,e,high,low;
mid=a[(first+last)/2];
high=last;
low=first;
    if(first==-1) {
        printf("\nEmpty array\n");
    }
    else{
       do{
    while(a[low]<mid){
      low=low+1;
    }
    while(a[high]>mid){
      high=high-1;
    }
    if(a[low]>=a[high]){
      e=a[low];
    a[ low]= a[high];
    low=low+1;
    a[high]=e;
    high= high-1;
    }
    }while(low<=high);
    if(low<=high)
    qsort(low,last);
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
        printf("\nThe sorted array is:");
        display();
    }
}

void bisearch() {
    int i, ele, found = 0;
    printf("Enter the element you want to search\n");
    scanf("%d", &ele);
    int start, end, mid;
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
void lsearch() {
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
   int arr[10][5],j=0,i,c=0,stk[10][10];
   for(i=0;i<count;i++){
      if(a[i]>j){
          j=a[i];
          }
      }
    while(j>0){
    j=j%10;
    c++;
    }
    
    for(i=0;i<c;i++){
       for(j=0;j<10;j++){
          
       }
    }
}
    