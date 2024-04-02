#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Queue
{
int data;
struct Queue *next;
}Queue;
Queue *rear=NULL;
Queue *front=NULL;
void initiliaze();
void traverse(Queue *ptr);
void enqueue(Queue **ptr,int item);
void dequeue(Queue **ptr);
bool is_empty(Queue *ptr);

int main()
{
    menu();
}
void menu()
{
    int choice;
printf("\n\nChoose following operation what you perform in Liner Queue. \nGive the input as integer from 1 to 6. \n");
printf("\n<<<< Menu >>>>\n");
printf("1. INITIALIZE QUEUE.\n");
printf("2. ENQUEQUE.\n");
printf("3. DEQUEUE.\n");
printf("4. TRAVERSE THE QUEUE.\n");
printf("5. QUEUE IS EMPTY?.\n");
printf("6. Exit.\n");
printf("\n\n\nChoose option: ");
scanf("%d",&choice);
switch(choice)
{
    case 1:{
initiliaze();
menu();
break;}
case 2:
    { if(rear!=NULL)
      {
          int item;
    printf("\n Enter The Data You Want to Enter In Queue: ");
scanf("%d",&item);
enqueue(&rear,item);}
    else{
        printf("\nPlease Initialize the Queue First");
    }
    menu();
     break;}
case 3:
{
    if(rear!=NULL)
      {
dequeue(&front);
      }
      else{
        printf("\nPlease Initialize the Queue First");
    }
menu();
break;
}
case 4:
{
traverse(front);
menu();
break;
}
case 5:
    {
bool t3=is_empty(front);
    if(t3)
    {
        printf("\nQueue is Not Empty.");
    }
    else
    {
        printf("\Queue is  Empty.");
    }
menu();
break;
    }

case 6:
    {

        exit(0);
        break;
    }
default:
    {printf("\nChoose Valid Option From 1 to 7\n");
     menu();
    }

}
}
void initiliaze()
{
rear=(Queue*)malloc(sizeof(Queue));
if(rear==NULL)
{
    printf("Memory does not Allocated.");
    exit(0);
}
int item;
printf("Enter The Data You Want to Enter In Queue: ");
scanf("%d",&item);
rear->data=item;
rear->next=NULL;
front=rear;
printf("\nYour Queue has initialized with %d .",item);
}
void traverse(Queue *ptr)
{
while(ptr!=NULL)
{
printf("%5d",ptr->data);
ptr=ptr->next;
}
}
void enqueue(Queue **ptr,int item)
{
Queue *temp;
temp=(Queue*)malloc(sizeof(Queue));
if(temp==NULL){
    printf("Memory does  not allocated.");
    exit(0);
}
temp->data=item;
temp->next=NULL;
(*ptr)->next=temp;
*ptr=temp;
printf("\n %d is now inserted at rear end of QUEUE.",item);
}
void dequeue(Queue **ptr)
{Queue *t = *ptr;
int t1=(*ptr)->data;
    *ptr = (*ptr)->next;
    free(t); // Free memory of dequeued node
    printf("\n %d is now deleted from frond end of QUEUE.",t1);
    if (*ptr == NULL)
    {
        rear = NULL;
        front=NULL; // Update rear when queue becomes empty
        printf("\n Now, QUEUE is Empty.");
    }
}
bool is_empty(Queue *ptr)
{
    if(ptr==NULL)
        return false;
    else
        return true;
}
