#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the BST
struct node {
    int key;
    struct node *left;
    struct node *right;
};

// Function to insert a new node in the BST
struct node* insertNode(struct node *root, int val) {
    if (root == NULL) {
        // Create a new node if the root is NULL
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->key = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if (val < root->key) {
        root->left = insertNode(root->left, val);
    } else if (val > root->key) {
        root->right = insertNode(root->right, val);
    }
    
    return root;
}

// Inorder traversal: Left -> Root -> Right
void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

// Preorder traversal: Root -> Left -> Right
void preorder(struct node *root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal: Left -> Right -> Root
void postorder(struct node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

// Main function to demonstrate insert and traversal
int main() {
    struct node *root = NULL;
    
    // Insert nodes
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    
    // Traversals
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    
    return 0;
}
