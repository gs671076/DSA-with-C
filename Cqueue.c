#include <stdio.h>
#include <stdlib.h>
#define size 20
typedef struct CircularQueue
{
int cq[size];
int rear;
int front;
}cq;
void create(cq **ptr);
void traverse(cq *ptr);
void enqueue(cq *ptr);
void dequeue(cq *ptr);
void is_full(cq *ptr);
void is_empty(cq *ptr);
cq *temp;
void main()
{
temp=(cq *)malloc(sizeof(cq));
if (temp == NULL) {
        printf("Memory allocation failed\n");
      exit(0);
    }
temp->rear=-1;
temp->front=-1;
menu();
}
void menu()
{
int choice;
printf("\n\nChoose following operation what you perform in Circular Array. \nGive the input as integer from 1 to 7. \n");
printf("\n<<<< Menu >>>>\n");
printf("1. INITIALIZE QUEUE.\n");
printf("2. ENQUEQUE.\n");
printf("3. DEQUEUE.\n");
printf("4. TRAVERSE THE QUEUE.\n");
printf("5. QUEUE IS EMPTY?.\n");
printf("6. QUEUE IS FULL?.\n");
printf("7. Exit.\n");
printf("\n\n\nChoose option: ");
scanf("%d",&choice);
switch(choice)
{
    case 1:{
create(&temp);
menu();
break;}
case 2:
    { enqueue(temp);
    menu();
     break;}
case 3:
{
    dequeue(temp);
menu();
break;
}
case 4:
{
traverse(temp);
menu();
break;
}
case 5:
    {
is_empty(temp);
menu();
break;
    }
case 6:
    {
is_full(temp);
menu();
break;
    }


case 7:
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

void create(cq **ptr)
{
printf("How Many Element you want to enter in Circular Queue: ");
int n;;
scanf("%d",&n);
(*ptr)->front=0;
(*ptr)->rear=0;
if (n> 20) {
        printf("Queue size exceeded maximum capacity (20)\n");
    }
    else{
    for(int i=0;i<n;i++)
    {
      printf("Enter Data In Circular Queue: ");
      scanf("%d",&(*ptr)->cq[(*ptr)->rear]);
      (*ptr)->rear=((*ptr)->rear+1)%size;
    }
    }
}
void traverse(cq* ptr)
{
    if((ptr->front==-1)&&(ptr->rear==-1))
    {
    printf("Circular Queue is Empty.\n");
    }
    else
    {
        printf("Element in Circular Queue are..\n");
        for(int i=ptr->front;i!=ptr->rear;i=(i+1)%size)
        {
            printf("%5d",ptr->cq[i]);
        }
    }
}
void enqueue(cq* ptr)
{
    if(ptr->front==-1)
    {
        ptr->front=0;
        ptr->rear=0;
        printf("Enter Data In Circular Queue: ");
       scanf("%d",&ptr->cq[ptr->rear]);
      ptr->rear=(ptr->rear+1)%size;
    }
    else if(ptr->front==0&&ptr->rear==size-1)
    {
        printf("Circular Queue is Full.");
    }
    else if(ptr->rear==ptr->front)
    {
        printf("Circular Queue is Full.");
    }
    else
    {
        int item ;
        printf("\nEnter the element Which you want to Insert in Circular Queue: ");
        scanf("%d",&item);
        ptr->cq[ptr->rear]=item;
        ptr->rear=(ptr->rear+1)%size;
    }
}
void dequeue(cq* ptr)
{
    if(ptr->front==-1&&ptr->rear==-1)
    {
    printf(" Circular Queue is empty.");
    }
    else if(ptr->front==ptr->rear)
    {
    printf("\nDequeued element: %d\n", ptr->cq[ptr->front]);
    ptr->front=-1;
    ptr->rear=-1;
    }
    else
    {
        printf("Dequeued element: %d\n", ptr->cq[ptr->front]);
        ptr->front = (ptr->front + 1) % size;
    }

}
void is_empty(cq *ptr)
{
    if (ptr->front == -1 && ptr->rear == -1)
    {
        printf("Circular Queue is empty.\n");
    }
    else
    {
        printf("Circular Queue is not empty.\n");
    }

}
void is_full(cq *ptr)
{
    if (ptr->front==0&&ptr->rear==size-1||ptr->rear==ptr->front)
    {
        printf("Circular Queue is full.\n");
    }
    else
    {
        printf("Circular Queue is not full.\n");
    }

}
