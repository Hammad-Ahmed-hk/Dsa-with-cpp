#include <iostream>
using namespace std;

// Structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert nodes into the binary tree
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value); // Create a new node if root is empty
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value); // Insert into left subtree
    } else {
        root->right = insertNode(root->right, value); // Insert into right subtree
    }

    return root; // Return updated root
}

// Inorder traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter the number of nodes to insert: ";
    cin >> n;

    cout << "Enter the node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insertNode(root, value); // Insert values into the tree
    }

    // Display different traversals
    cout << "\nInorder Traversal (Sorted Order): ";
    inorderTraversal(root);

    cout << "\nPreorder Traversal (Root-Left-Right): ";
    preorderTraversal(root);

    cout << "\nPostorder Traversal (Left-Right-Root): ";
    postorderTraversal(root);

    cout << endl;
    return 0;
}
