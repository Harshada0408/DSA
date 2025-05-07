#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int value) {
        if (root == NULL)
            return new Node(value);
        if (value < root->data)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);
        return root;
    }

    int height(Node* root) {
        if (root == NULL)
            return -1;
        return 1 + max(height(root->left), height(root->right));
    }

    int findMin(Node* root) {
        if (root == NULL) {
            cout << "Tree is empty!\n";
            return -1;
        }
        while (root->left != NULL)
            root = root->left;
        return root->data;
    }

    Node* mirrorTree(Node* root) {
        if (root == NULL)
            return NULL;
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }

    bool search(Node* root, int value) {
        if (root == NULL)
            return false;
        if (root->data == value)
            return true;
        if (value < root->data)
            return search(root->left, value);
        return search(root->right, value);
    }

    void inorder(Node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void display() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void findHeight() {
        cout << "Longest path from root (height of tree): " << height(root) << endl;
    }

    void findMinimum() {
        cout << "Minimum value in BST: " << findMin(root) << endl;
    }

    void mirror() {
        root = mirrorTree(root);
        cout << "Tree structure swapped (Mirrored BST)\n";
    }

    void searchValue(int value) {
        if (search(root, value))
            cout << value << " is found in the BST.\n";
        else
            cout << value << " is NOT found in the BST.\n";
    }
};
int main() {
    BST tree;
    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Display BST (Inorder)\n";
        cout << "3. Find Longest Path from Root\n";
        cout << "4. Find Minimum Value in BST\n";
        cout << "5. Mirror (Swap Left and Right Pointers)\n";
        cout << "6. Search a Value\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            tree.display();
            break;
        case 3:
            tree.findHeight();
            break;
        case 4:
            tree.findMinimum();
            break;
        case 5:
            tree.mirror();
            tree.display(); 
            break;
        
        case 6:
            cout << "Enter value to search: ";
            cin >> value;
            tree.searchValue(value);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}