#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *left;
    struct NODE *right;
} NODE;

NODE * createNode(int data) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NODE *insertNode(NODE *root, int data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void preorderTraversal(NODE *root) {
    if(root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left); // left subtree
    preorderTraversal(root->right); // right subtree
}

void inorderTraversal(NODE *root) {
    if(root == NULL) {
        return;
    }
    inorderTraversal(root->left); // left subtree
    printf("%d ", root->data);
    inorderTraversal(root->right); // right subtree
}

void postorderTraversal(NODE *root) {
    if(root == NULL) {
        return;
    }
    postorderTraversal(root->left); // left subtree
    postorderTraversal(root->right); // right subtree
    printf("%d ", root->data);
}

int main() {
    NODE *root = NULL;
    int data;
    int choice;
    printf("Choices: \n");
    printf("1. Insert\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Exit\n");
    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            if(data == -1) break;
            root = insertNode(root, data);
            break;
        case 2:
            printf("Preorder Traversal: \n");
            preorderTraversal(root);
            break;
        case 3:
            printf("Inorder Traversal: \n");
            inorderTraversal(root);
            break;
        case 4:
            printf("Postorder Traversal: \n");
            postorderTraversal(root);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}