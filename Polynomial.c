#include<stdlib.h>
#include<stdio.h>
typedef struct  polynomial
{
int coeff;
int pow;
struct polynomial *next;
}poly;
poly *start1=NULL;
poly *start2=NULL;
poly *start3=NULL;
void createpoly1();
void createpoly2();
void display(poly *exp);
void addpoly(poly *exp1,poly *exp2,poly** exp);
void main()
{
    int choice;
    do {
        printf("\nPolynomial Operations Menu\n");
        printf("1. Create Polynomial 1\n");
        printf("2. Create Polynomial 2\n");
        printf("3. Display Polynomial 1\n");
        printf("4. Display Polynomial 2\n");
        printf("5. Add Polynomials\n");
        printf("6. Display Resultant Polynomial\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            createpoly1();
                break;
            case 2:
                createpoly2();
                break;
            case 3:
                printf("\nPolynomial 1: ");
                display(start1);
                break;
            case 4:
                printf("\nPolynomial 2: ");
                display(start2);
                break;
            case 5:
                addpoly(start1,start2,&start3);
                printf("\nPolynomials added successfully.\n");
                break;
            case 6:
                printf("\nResultant Polynomial: ");
                display(start3);
                break;
            case 7:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 7.\n");
        }
    } while (choice != 7);

}
void createpoly1()
{ int coef, pow, item;
    printf("\nHow many terms are in Polynomial expression 1: ");
    scanf("%d", &item);

    poly *temp, *ptr;
    for (int i = 0; i < item; i++) {
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%d", &coef);
        printf("Enter the power of term %d: ", i + 1);
        scanf("%d", &pow);

        temp = (poly *)malloc(sizeof(poly));
        temp->coeff = coef;
        temp->pow = pow;
        temp->next = NULL;

        if (start1 == NULL) {
            start1 = temp;
            ptr = temp;
        } else {
            ptr->next = temp;
            ptr = temp;
        }
    }
    }
    void createpoly2()
{ int coef, pow, item;
    printf("\nHow many terms are in Polynomial expression 2: ");
    scanf("%d", &item);

    poly *temp, *ptr;
    for (int i = 0; i < item; i++) {
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%d", &coef);
        printf("Enter the power of term %d: ", i + 1);
        scanf("%d", &pow);

        temp = (poly *)malloc(sizeof(poly));
        temp->coeff = coef;
        temp->pow = pow;
        temp->next = NULL;

        if (start2 == NULL) {
            start2 = temp;
            ptr = temp;
        } else {
            ptr->next = temp;
            ptr = temp;
        }
    }
    }
void display(poly *exp)
{
     if (exp == NULL) {
        printf("Polynomial is empty\n");
    } else{
    printf("\nYour Polynomial Expression is->");
    while(exp!=NULL){
    printf("%dx^%d",exp->coeff,exp->pow);
    exp=exp->next;
    if (exp != NULL)
            printf("+");}
}
}
void addpoly(poly *exp1, poly *exp2, poly** exp) {
    poly *exp3, *ptr;
    while (exp1 != NULL || exp2 != NULL) {
        exp3 = (poly *)malloc(sizeof(poly));
        if (exp3 == NULL) {
            printf("Memory allocation failed!");
            exit(1);
        }
        exp3->next = NULL;

        if (exp1 == NULL) {
            exp3->coeff = exp2->coeff;
            exp3->pow = exp2->pow;
            exp2 = exp2->next;
        } else if (exp2 == NULL) {
            exp3->coeff = exp1->coeff;
            exp3->pow = exp1->pow;
            exp1 = exp1->next;
        } else if (exp1->pow > exp2->pow) {
            exp3->coeff = exp1->coeff;
            exp3->pow = exp1->pow;
            exp1 = exp1->next;
        } else if (exp1->pow < exp2->pow) {
            exp3->coeff = exp2->coeff;
            exp3->pow = exp2->pow;
            exp2 = exp2->next;
        } else {
            exp3->coeff = exp2->coeff + exp1->coeff;
            exp3->pow = exp2->pow;
            exp2 = exp2->next;
            exp1 = exp1->next;
        }

        if (*exp == NULL) {
            *exp = exp3;
            ptr = *exp; // Assign ptr to the result polynomial
        } else {
            ptr->next = exp3;
            ptr = exp3;
        }
    }
}
