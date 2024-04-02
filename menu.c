#include<stdio.h>
#include<stdlib.h>
void create();
void insert(int [],int,int,int);
void Delete(int [],int,int,int);
void sort(int[],int);
int lsearch(int[],int,int);
void binarysearch(int[],int,int,int);
void display(int[],int);
void menu();
void menu1();
int array[100];
static int n;
void main()
{
    printf("\n\t\t\t\t<<<<<<<------Welcome To DSA in Array World------>>>>>>>\n");
    printf("\nName: Gaurav  Soni\nCourse: Master of Computer Application\nRoll No.: 31222391607\nSubmitted To: Dr. Rabins Porwal Sir\n  ");
menu1();
menu();
}
void menu1()
{
printf("\n\n->-> Choose following operation what you perform in array. \n->-> Give the input as integer from 1 to 8. \n");
printf("\n>>>>  MENU  <<<<\n");
printf("1. Create array.\n");
printf("2. Insert element in array.\n");
printf("3. Delete element in array.\n");
printf("4. Sort element in array.\n");
printf("5. Liner search of element in array.\n");
printf("6. Binary search element in array.\n");
printf("7. Display element in array.\n");
printf("8. Exit");

}
void menu()
{
int choice;
printf("\n\n\nChoose Option given in MENU: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
create();
menu();
break;
case 2:
    {
    if(n>0)
    {
    int item,k;
    printf("Enter any element which you want to enter in array: ");
    scanf("%d",&item);
    printf("Enter the position: ");
    scanf("%d",&k);
    if(k<=n){
    insert(array,n,k,item);
    }else{
    printf("Please insert the element from 0 index to %d index and in between.",n);
        }

    }
    else{
        printf("Please create array first. ");
    }
    menu();
     break;}
case 3:
{ if(n>0){
int item;
printf("\nEnter any element which you want to remove from array: ");
scanf("%d",&item);
int r=lsearch(array,n,item);
if(r!=-1){
Delete(array,n,r,item);}
else{
    printf("\n element which you want to remove from array does not exist in array\n please give valid entry: ");
}
}
else{
    printf("Please create array first. ");

}
menu();
break;
}
case 4:
{
if(n>0)
{
display(array,n);
sort(array,n);
printf("\n Sorted Array is \n ");
display(array,n);}
else{
    printf("Please create array first. ");
}
menu();
break;
}
case 5:
    {
if(n>0)
{
int item;
printf("\nEnter any element which you want to search in array: ");
scanf("%d",&item);
lsearch(array,n,item);}
else{
    printf("Please create array first. ");
}
menu();
break;
    }
case 6:
    {
        if(n>0){
        int item;
printf("\nEnter any element which you want to search in array: ");
scanf("%d",&item);
binarysearch(array,0,n,item);
}
else{
    printf("Please create array first. ");
}
menu();
break;
    }
case 7:
    {
        if(n>0){
        display(array,n);}
        else{
            printf("Please create array first. ");
        }
        menu();
        break;
    }
case 8:
    {

        exit(0);
        break;
    }
default:
    {printf("Choose valid option From 1 to 8\n");
     menu();
    }
    }
}
void insert(int b[],int size,int pos,int key)
{
 int j=size;
 while(j>=pos)
 {
  b[j+1]=b[j];
  j--;

  }
  b[pos]=key;
  size++;
  n++;
  display(b,size);
}
void Delete(int b[],int size,int pos,int key)
{
    key=b[pos];
 int j=pos;
 while(j<=size-1)
 {
  b[j]=b[j+1];
  j++;

  }
  size--;
  n--;
  printf("\n%2d is deleted from %2d th position",key,pos);
  printf("\nArray after deletion\n ");
  for(int i=0;i<size;i++)
{
 printf("%5d",b[i]);
}

}
void sort(int b[],int size)
{
int i,j,temp;
for(i=0;i<size;i++)
{
for(j=i+1;j<size;j++)
{
if(b[i]>b[j])
{
temp=b[i];
b[i]=b[j];
b[j]=temp;
}
}
}
}
int lsearch(int b[],int size,int key){
    int i,flag=0;
for(i=0;i<size;i++){
    if(key==b[i]){
    flag++;
    break;
    }
}
if(flag){
    printf("\n%d is found at %dth index",key,i);
    return i;
}
else
    printf("Element not found");
    return -1;
}
void binarysearch(int b[],int lower,int upper,int key)
{
    int flag=0;
    int mid=(lower+upper)/2;
while(lower<=upper)
    {
    if(key==b[mid])
    {
    flag++;
    break;
    }
    else if(b[mid]<key){
    upper=mid-1;
    }
    else
    {
    lower=mid+1;
    }
    mid=(lower+upper)/2;
}
if(flag){
    printf("%d is found at %dth index",key,mid);
}
else
    printf("Element not found");
}
void display(int b[],int size)
{
    printf("Array is \n ");
for(int i=0;i<size;i++)
{
 printf("%5d",b[i]);
}
}

void create()
{

     int i;
printf("\nHow many element you want to enter in array: ");
scanf("%d",&n);
printf("\nEnter Value in array\n");
for(i=0;i<n;i++)
{
 printf("Enter a value in %d th index: ",i);
  scanf("%d",&array[i]);
}
menu();
}
