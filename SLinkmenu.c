#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stack
{
int data;
struct stack *next;
}stack;
stack *top=NULL,*temp=NULL;
void traverse_stack(stack *ptr);
void init_stack(stack *ptr,int item);
void push(stack **ptr,int item);
void pop(stack **ptr);
void peep(stack **ptr);
bool is_empty(stack *ptr);
void main()
{
printf("\n\t<< STACK IMPLEMENTATION USING LINKLIST >>\n");
    menu();
}
void menu()
{
    int choice;
printf("\n\nChoose following operation what you perform in Stack. \nGive the input as integer from 1 to 7. \n");
printf("\n<<<< Menu >>>>\n");
printf("1. Initialize Stack.\n");
printf("2. Push the element in Stack.\n");
printf("3. Traverse the element of Stack.\n");
printf("4. Pop the element from Stack..\n");
printf("5. Data at Top of Stack.\n");
printf("6. Check the Stack is empty or not.\n");
printf("7. Exit");
printf("\n\n\nChoose option: ");
scanf("%d",&choice);
switch(choice)
{
    case 1:{
        top=(stack*)malloc(sizeof(stack));
    if (top == NULL) {
        printf("Memory allocation failed.");
        exit(0);}
 int item;
    printf("\nEnter The Data You Want To Enter In Stack:");
    scanf("%d",&item);
    init_stack(top,item);
menu();
break;}
case 2:
    { if(top!=NULL)
      {
    int item1;
    printf("\nEnter The Data You Push To Enter In Stack:");
    scanf("%d",&item1);
    push(&top,item1);}
    else{
        printf("\nPlease Initialize the Stack First");
    }
    menu();
     break;}
case 3:
{
    if(top!=NULL)
      {
traverse_stack(top);
      }
      else{
        printf("\nPlease Initialize the Stack First");
    }
menu();
break;
}
case 4:
{
pop(&top);
menu();
break;
}
case 5:
    {
peep(&top);
menu();
break;
    }
case 6:
    {
bool t3=is_empty(top);
    if(t3)
    {
        printf("\nStack is Not Empty.");
    }
    else
    {
        printf("\nStack is  Empty.");
    }
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

void init_stack(stack *ptr,int item)
{
    ptr->data=item;
    ptr->next=NULL;
}

void push(stack **ptr,int item)
{
    temp=(stack*)malloc(sizeof(stack));
    if (temp == NULL) {
        printf("Memory allocation failed.");
        exit(0);
    }
    temp->data=item;
    temp->next=*ptr;
    *ptr=temp;
    printf("\n%d is Pushed into Stack\n",item);
}


void traverse_stack(stack *ptr)
{
    while(ptr!=NULL)
    {
        printf("%5d",ptr->data);
            ptr=ptr->next;
    }
}
void pop(stack **ptr)
{    stack *temp;
if(*ptr==NULL)
{
      printf("\nStack Underflow.\n");
}
else{
      temp=*ptr;
    int d=temp->data;
    *ptr=temp->next;
    free(temp);
    printf("\n%d is Popped from Stack",d);
}
}

void peep(stack **ptr)
{
    if(*ptr!=NULL){
        printf("\n%d is the TOP OF STACK.",(*ptr)->data);
    }
    else
    {
        printf("\nSTACK IS EMPTY.");
    }
}
bool is_empty(stack *ptr)
{
    if(ptr!=NULL)
        return true;
    else
        return false;
}
