#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}bst;
bst* createnode(int value);
void insert(bst** root, int value);
void preorder(bst* root);
void inorder(bst* root);
void postorder(bst* root);
void main()
{ bst *root=NULL;
int choice,data;
    do {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("How many node want to enter in Binary Search Tree: ");
                int n;
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                {printf("Enter data to insert in Binary Search Tree: ");
                scanf("%d", &data);
                insert(&root, data);}
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option 1 to 5.\n");
        }
    } while(choice != 5);


}


bst* createnode(int value) {
    bst *node = (bst*)malloc(sizeof(bst));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    (node)->data = value;
    (node)->left = (node)->right = NULL;
    return node;
}
void insert(bst** root, int value) {
    if (*root == NULL) {
        *root = createnode(value);
    } else {
        if (value < (*root)->data) {
            insert(&((*root)->left), value);
        } else if (value > (*root)->data) {
            insert(&((*root)->right), value);
        }
    }
}
void preorder(bst *root)
{
    if(root!=NULL){
        printf("%5d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(bst* root)
{
if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%5d",root->data);
       }
}
void inorder(bst* root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%5d",root->data);
        inorder(root->right);
       }
}
