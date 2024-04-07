#include<stdio.h>
#include<stdlib.h>

void lsearch(int[],int,int);
void binarysearch(int b[],int lower,int upper,int key);
void menu();
int n,array[20];
void main()
{
int i,item;
printf("how many element you want to enter in array(Max array size 20): ");
scanf("%d",&n);
printf("Enter Value in array\n");
for(i=0;i<n;i++)
{
 printf("Enter a value: ");
  scanf("%d",&array[i]);
}
menu();
}

void menu()
{
printf("\n\n->-> Choose following Searching what you perform in array. \n->-> Give the input as integer from 1 to 8. \n");
printf("\n>>>>  MENU  <<<<\n");
printf("1. Liner search of element in array.\n");
printf("2. Binary search element in array.\n");
printf("3. Exit");

int choice;
printf("\n\n\nChoose Option given in MENU: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
    {
int item;
printf("\nEnter any element which you want to search in array: ");
scanf("%d",&item);
lsearch(array,n,item);
menu();
break;
    }
case 2:
{
int item;
printf("\nEnter any element which you want to search in array: ");
scanf("%d",&item);
 int i,j,temp;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(array[i]>array[j])
{
temp=array[i];
array[i]=array[j];
array[j]=temp;
}
}
}
 printf("Array After Sorting is \n ");
for(int i=0;i<n;i++)
{
 printf("%5d",array[i]);
}
binarysearch(array,0,n-1,item);
menu();
break;
}

case 3:
    {

        exit(0);
        break;
    }
default:
    {printf("Choose valid option From 1 to 3\n");
     menu();
    }
    }
}

void binarysearch(int b[], int lower, int upper, int key) {
    int mid;
    while (lower <= upper) {
        mid = (lower + upper) / 2;
        if (b[mid] == key) {
            printf("\n%d is found at %dth index.", key, mid);
            return;
        } else if (b[mid] < key) {
            lower = mid + 1;
        } else {
            upper = mid - 1;
        }
    }
    printf("\nElement not found.");
}
void lsearch(int b[],int size,int key){
    int i,flag=0;
for(i=0;i<size;i++){
    if(key==b[i]){
    flag++;
    break;
    }
}
if(flag){
    printf("\n%d is found at %dth index",key,i);
}
else
    printf("\nElement not found");
}
