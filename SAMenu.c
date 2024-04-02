#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define SIZE 20

typedef struct stack {
    int st[SIZE];
    int top;
} stack;

void push(stack *ptr, int item);
void traverse_stack(stack *ptr);
int pop(stack *ptr);
int peep(stack *ptr);
bool is_empty(stack *ptr);
bool is_full(stack *ptr);
void menu();
stack *s ;
void main()
{
    s = (stack *)malloc(sizeof(stack));
    if (s == NULL) {
        printf("Memory allocation failed.");
    }
    s->top = -1;
    printf("\n\t<< STACK IMPLEMENTATION USING ARRAY >>\n");
    menu();
}
void menu()
{
    int choice;
printf("\n\nChoose following operation what you perform in Stack. \nGive the input as integer from 1 to 7. \n");
printf("\n<<<<<  Menu  >>>>>\n");
printf("1. Push the element in Stack.\n");
printf("2. Traverse the element of Stack.\n");
printf("3. Pop the element from Stack.\n");
printf("4. Data at Top of Stack.\n");
printf("5. Check the Stack is empty or not.\n");
printf("6. Check the Stack is full or not.\n");
printf("7.  Exit\n");
printf("\nChoose option: ");
scanf("%d",&choice);
switch(choice)
{
    case 1:
    { int i;
    printf("\nEnter the element you wantto push into stack: ");
    scanf("%d",&i);
              push(s, i);
    menu();
     break;}
case 2:
{
traverse_stack(s);
menu();
break;
}
case 3:
{
int t = pop(s);
    if (t != -1) {
        printf("\n%d is popped from stack.", t);
    } else {
        printf("\nThe stack is empty or Underflow.");
    }
menu();
break;
}
case 4:
    {
int x=peep(s);
    if(x!=-1){
         printf("\n Top of stack is %d",x);
    }
    else{
        printf("\nThe stack is empty");
    }
menu();
break;
    }
case 5:
    {
bool t3=is_empty(s);
    if(t3)
    {
        printf("\nStack is empty.");
    }
    else
    {
        printf("\nStack is not empty.");
    }
menu();
break;
    }
case 6:
    {
 bool t4=is_full(s);
    if(t4)
    {
        printf("\nStack is Full.");
    }
    else
    {
        printf("\nStack is not Full.");
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
    {printf("Choose valid option From 1 to 8\n");
     menu();
    }

}
}
void push(stack *ptr, int item) {
    if (ptr->top == SIZE - 1) {
        printf("Stack is Full");
    } else {
        (ptr->top)++;
        ptr->st[ptr->top] = item; // Corrected the assignment
        printf("%d is pushed successfully in stack", item);
    }
}

void traverse_stack(stack *ptr) {
    int i = ptr->top;
    printf("\nStack elements:");
    while (i != -1) {
        printf("%d \t", (ptr->st[i]));
        i--;
    }
}

int pop(stack *ptr) {
    if (ptr->top == -1) {
        return -1; // Stack underflow
    } else {
        int t = ptr->st[ptr->top];
        (ptr->top)--;
        return t;
    }
}

int  peep(stack *ptr)
{

    if(ptr->top!=-1)
    {
        return ptr->st[ptr->top];
    }
    else{
           return (-1);
    }
}
bool is_empty(stack *ptr)
{
    if(ptr->top==-1)
        return true;
    else
        return false;
}
bool is_full(stack *ptr)
{
    if(ptr->top==SIZE)
        return true;
    else
        return false;
}

