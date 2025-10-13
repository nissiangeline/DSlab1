#include <stdio.h>
#include <stdlib.h>

// Define a node
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Utility: create a new node
Node* newNode(int key) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Insert a key into BST (returns updated root)
Node* insert(Node* root, int key) {
    if (root == NULL) {
        // empty spot found
        return newNode(key);
    }
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    // if equal, do nothing (no duplicates) — or handle as desired
    return root;
}

// Find the node with minimum key in a tree (go left as far as possible)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a key from the BST, returns new root
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // This is the node to be deleted
        
        // Case 1: node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Case 2: node with two children
        // Get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);
        
        // Copy the inorder successor's content to this node
        root->key = temp->key;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Inorder traversal (for checking correctness)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Example usage
int main() {
    Node* root = NULL;
    // Insert
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    
    // Delete 20 (leaf)
    root = deleteNode(root, 20);
    printf("After deleting 20: ");
    inorder(root);
    printf("\n");
    
    // Delete 30 (one child)
    root = deleteNode(root, 30);
    printf("After deleting 30: ");
    inorder(root);
    printf("\n");
    
    // Delete 50 (two children)
    root = deleteNode(root, 50);
    printf("After deleting 50: ");
    inorder(root);
    printf("\n");
    
    return 0;
}

