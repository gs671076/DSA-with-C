#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;

}node;
node *start=NULL;
node *temp=NULL;

void menu();
void create();
void display(node *ptr);
void insertBeginning(node **ptr,int);
void insertEnd(node *ptr,int);
void insertMiddle(node *ptr,int,int);
int deleteFirst(node **ptr);
int deleteEnd(node *ptr);
int deleteMiddle(node *ptr,int);
int search(node *ptr,int);
void main()
{
    menu();
}
void menu()
{
int choice;
printf("\n\nChoose following operation what you perform in Linked List. \n Give the input as integer from 1 to 10. \n");
printf("\n>>>>  MENU  <<<<\n");
printf("1. Create Linked List.\n");
printf("2. Display node in Linked List.\n");
printf("3. Insert node in beginning of Linked List.\n");
printf("4. Insert node after particular node in Linked List.\n");
printf("5. Insert node in end of Linked List.\n");
printf("6. Delete node from the beginning Linked List.\n");
printf("7. Delete node from nth place in Linked List.\n");
printf("8. Delete node from end in Linked List.\n");
printf("9. Liner search of node in Linked List.\n");
printf("10. Exit");
printf("\n\nChoose Option: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
create();
menu();
break;
case 2:
    {
    if(start==NULL)
    {
       printf("\n\nLinked List does not exist.\nCreate Linked List First.");
    }
    else{
        display(start);
    }
    menu();
     break;}
case 3:
{
    if(start==NULL)
    {
       printf("\n\nLinked List does not exist.\nCreate Linked List First.");
    }else{
        int item;
        printf("Enter the data that you want to enter in first node: ");
        scanf("%d",&item);
        insertBeginning(&start,item);
    }
menu();
break;
}
case 4:
{
        if(start==NULL)
    {
       printf("\n\nLinked List does not exist.\nCreate Linked List First.");
    }else{
        int item,data;
        printf("Enter the data that you want to enter in  node: ");
        scanf("%d",&item);
        printf("Enter the data of node after that you want to insert node: ");
        scanf("%d",&data);
        insertMiddle(start,item,data);
    }
menu();
break;
}
case 5:
    {
     if(start==NULL)
    {
       printf("\n\nLinked list does not exist.\nCreate Linked list First.");
    }else{
        int item;
        printf("Enter the data that you want to enter in End of Linked List: ");
        scanf("%d",&item);
        insertEnd(start,item);
    }
menu();
break;
    }
case 6:
    {
        if(start==NULL)
    {
       printf("\n\nLinked List does not exist.\nCreate Linked List First.");
    }
    else{
        deleteFirst(&start);
    }
menu();
break;
    }
case 7:
    {
        if(start==NULL)
    {
       printf("\n\nLinked List does not exist.\nCreate Linked List First.");
    }
    else{
                    int item;
        printf("Enter the data that you want to remove from Linked List: ");
        scanf("%d",&item);
            if(search(start,item)!=-1)
            {deleteMiddle(start,item);}
            else{
              printf("\n\n%d does not exist in linked list so cannot be deleted",item);
            }
    }
menu();
break;
    }
case 8:
    {
        if(start==NULL)
    {
       printf("\n\nLinked List does not exist.\nCreate Linked List First.");
    }
    else{
        deleteEnd(start);
    }
menu();
break;
    }
case 9:
    {
        int t,item;
if(start==NULL)
    {
       printf("\n\nLinked List does not exist.\nCreate Linked List First.");
    }
    else{

           printf("Enter the item that you want to search in Linked list: ");
            scanf("%d",&item);
             t=search(start,item);
           if(t!=-1)
            {
             printf("\n\n%d  exist in Linked List at %d node ",item,t);
            }
            else
             {
              printf("\n\n%d does not exist in linked list",item);
              }
    }

    menu();
    break;
}
case 10:
    {

        exit(0);
        break;
    }
default:
    {printf("Choose valid option From 1 to 10\n");
     menu();
    }
}
}

void create()
{ node *ptr;
    int data;
char c;
temp=(node*)malloc(sizeof(node));
if(temp==NULL)
{
    printf("Unable to allocate memory");
    exit(0);
}
printf("\nEnter the data in first node: ");
scanf("%d",&data);
temp->data=data;
temp->next=NULL;
temp->prev=NULL;
start=temp;
ptr=start;
do
{

    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
{
    printf("Unable to allocate memory");
    exit(1);
}
    printf("\nEnter the data in node: ");
    scanf("%d",&data);
    temp->data=data;
    temp->prev=ptr;
    temp->next=NULL;
    ptr->next=temp;
    ptr=temp;
   getchar();
printf("\nYou want to add more node in linked list.\n if YES then type Y(in capital).\n otherwise enter any key. ");
scanf("%c",&c);

}while(c=='Y');
}

//to display node of linklist.
void display(node *ptr)
{
    printf("\n____LinkList is_____\n\n");
while(ptr!=NULL)
{
int data=ptr->data;
printf("->%d",data);
ptr=ptr->next;
}
}
//to insert node in the beginning of linklist.
void insertBeginning(node **ptr,int item)
{
 temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
{
    printf("Unable to allocate memory");
    exit(1);
}
temp->data=item;
temp->next=*ptr;
temp->prev=NULL;
(*ptr)->prev=temp;
*ptr=temp;
printf("\n iNSERTION OF %d NODE AT BEGINNING OF DOUBLY LINKED LIST has been done\n",item);
}
//to insert node in the end of linklist.
void insertEnd(node *ptr,int item)
{
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
{
    printf("Unable to allocate memory");
    exit(1);
}
temp->data=item;
temp->next=NULL;
temp->prev=ptr;
ptr->next=temp;
printf("\n iNSERTION OF %d NODE AT END OF DOUBLY LINKED LIST has been done.\n",item);
}

//to insert node after particular node of linklist.
void insertMiddle(node  *ptr,int item,int item2)
{
    while(ptr->data!=item2)
    {
        ptr=ptr->next;
    }
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
{
    printf("Unable to allocate memory");
    exit(1);
}
temp->data=item;
temp->next=ptr->next;
temp->prev=ptr;
ptr->next->prev=temp;
ptr->next=temp;
printf("\n INSERTION OF  %d NODE IN MIDDLE OF DOUBLY LINKED LIST has been done.\n",item);
}
//to delete first node of linklist.
int deleteFirst(node **ptr)
{
int t=(*ptr)->data;
node *temp=*ptr;
*ptr=(*ptr)->next;
(*ptr)->prev=NULL;
free(temp);
ptr=NULL;
printf("\n Deletion OF FIRST NODE i.e. %d, FROM DOUBLY LINKED LIST has been done.\n",t);
return t;
}
//to delete last node of linklist.
int deleteEnd(node *ptr)
{ node *temp;
    while(ptr->next!=NULL)
          {
              ptr=ptr->next;
          }
    temp=ptr;
    int t= ptr->data;
    ptr->prev->next=NULL;
    free(temp);
          temp=NULL;
           printf("\n Deletion OF LAST NODE FROM DOUBLY LINKED LIST has been done.\n");
          return t;
 }

//to delete  particular node of linklist.
int deleteMiddle(node *ptr,int data)
{ node *temp;
    while(ptr->data!=data)
    {
        ptr=ptr->next;
    }
    temp=ptr;
        printf("\n Deletion OF MIDDLE NODE FROM DOUBLY LINKED LIST has been done.\n");
    int t= ptr->data;
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    free(temp);
    temp=NULL;
    return t;

}

int search(node *ptr,int item)
{ int count=1;
    while(ptr->data!=item&&ptr->next!=NULL)
    { count++;
        ptr=ptr->next;
    }
    if (ptr->data==item)
    {return count;}
    else
        {
            return -1;}
}
