#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the BST
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Case 1: Insert when the tree is empty (root is NULL)
struct node* insertWhenEmpty(struct node* root, int val) {
    return createNode(val);
}

// Case 2: Insert when the new value is less than the current node’s value
struct node* insertLeft(struct node* root, int val) {
    if (root == NULL) return createNode(val);  // Only needed if this function is called directly
    root->left = createNode(val);
    return root;
}

// Case 3: Insert when the new value is greater than the current node’s value
struct node* insertRight(struct node* root, int val) {
    if (root == NULL) return createNode(val);  // Only needed if this function is called directly
    root->right = createNode(val);
    return root;
}

// General function to handle insertion based on value
struct node* insert(struct node* root, int val) {
    if (root == NULL)
        return insertWhenEmpty(root, val);
    
    if (val < root->data)
        root->left = insert(root->left, val);  // Recursively insert on the left subtree
    else if (val > root->data)
        root->right = insert(root->right, val);  // Recursively insert on the right subtree

    return root;
}

// Search function for BST
struct node* search(struct node* root, int val) {
    if (root == NULL || root->data == val)
        return root;

    if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

// Helper functions for deletion cases
struct node* findMax(struct node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

struct node* findMin(struct node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Case 1: Delete a leaf node
struct node* deleteLeaf(struct node* root) {
    free(root);
    return NULL;
}

// Case 2: Delete a node with one child
struct node* deleteWithOneChild(struct node* root) {
    struct node* child = (root->left != NULL) ? root->left : root->right;
    free(root);
    return child;
}

// Case 3: Delete a node with two children
struct node* deleteWithTwoChildren(struct node* root) {
    struct node* temp = findMax(root->left);  // Can also use findMin(root->right) for inorder successor
    root->data = temp->data;
    root->left = deleteNode(root->left, temp->data);
    return root;
}

// General delete function that selects the correct delete case
struct node* deleteNode(struct node* root, int val) {
    if (root == NULL) {
        printf("Value not found in the tree.\n");
        return root;
    }

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        // Determine the delete case
        if (root->left == NULL && root->right == NULL) {
            return deleteLeaf(root);
        } else if (root->left == NULL || root->right == NULL) {
            return deleteWithOneChild(root);
        } else {
            return deleteWithTwoChildren(root);
        }
    }
    return root;
}

// Simple function to print the tree in order (for testing)
void printTree(struct node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

// Main function to demonstrate all operations
int main() {
    struct node* root = NULL;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Tree after insertions: ");
    printTree(root);
    printf("\n");

    // Search for a node
    int searchVal = 40;
    struct node* searchResult = search(root, searchVal);
    if (searchResult != NULL)
        printf("Node %d found in the tree.\n", searchVal);
    else
        printf("Node %d not found in the tree.\n", searchVal);

    // Delete nodes with all three cases
    root = deleteNode(root, 20); // Deleting a leaf node
    printf("After deleting 20 (leaf node): ");
    printTree(root);
    printf("\n");

    root = deleteNode(root, 30); // Deleting a node with one child
    printf("After deleting 30 (one child): ");
    printTree(root);
    printf("\n");

    root = deleteNode(root, 50); // Deleting a node with two children
    printf("After deleting 50 (two children): ");
    printTree(root);
    printf("\n");

    return 0;
}
