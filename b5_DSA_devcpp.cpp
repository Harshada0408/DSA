#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;

    Node(string val) {
        data = val;
        left = right = NULL;
    }
};

class Stack {
    private:
        static const int MAX = 15;
        Node* arr[MAX];
        int top;

    public:
        Stack() : top(-1) {}

        void push(Node* node) {
            if (top >= MAX - 1) {
                cout << "Stack overflow!\n";
                return;
            }
            arr[++top] = node;
        }

        Node* pop() {
            if (isEmpty()){
                cout << "Stack underflow!\n";
                return NULL;
            }
            return arr[top--];
        }

        bool isEmpty() {
            return top == -1;
        }
    };


class Tree {
private:
    Node* root;
    Node* insertNode() {
        string value;
        cout << "Enter value (-1 for no node): ";
        cin >> value;

        if (value == "-1") return NULL;

        Node* newNode = new Node(value);
        cout << "Enter left child of " << value << ":\n";
        newNode->left = insertNode();
        cout << "Enter right child of " << value << ":\n";
        newNode->right = insertNode();

        return newNode;
    }

    // Recursive Traversals
    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

public:
    Tree() {
        root = NULL;
    }

    void insert() {
        cout << "Inserting nodes...\n";
        root = insertNode();
    }

    void inorderNonRecursive() {
        if (root == NULL) return;

        Stack s;
        Node* current = root;

        while (current != NULL || !s.isEmpty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }
            current = s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    void preorderNonRecursive() {
        if (root == NULL) return;

        Stack s;
        s.push(root);

        while (!s.isEmpty()) {
            Node* current = s.pop();
            cout << current->data << " ";

            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }
    }

    void postorderNonRecursive() {
        if (root == NULL) return;

        Stack s1, s2;
        s1.push(root);

        while (!s1.isEmpty()) {
            Node* current = s1.pop();
            s2.push(current);

            if (current->left) s1.push(current->left);
            if (current->right) s1.push(current->right);
        }

        while (!s2.isEmpty()) {
            cout << s2.pop()->data << " ";
        }
    }

    void printTree() {
        if (root == NULL) {
            cout << "Tree is empty!\n";
            return;
        }

        int choice;
        cout << "Select traversal type:\n";
        cout << "1. Recursive Traversal\n";
        cout << "2. Non-Recursive Traversal\n";
        cin >> choice;

        if (choice == 1) {
            cout << "1. Inorder\n2. Preorder\n3. Postorder\n";
            cin >> choice;
            switch (choice) {
                case 1: inorder(root); break;
                case 2: preorder(root); break;
                case 3: postorder(root); break;
                default: cout << "Invalid choice!\n"; return;
            }
        } else if (choice == 2) {
            cout << "1. Inorder\n2. Preorder\n3. Postorder\n";
            cin >> choice;
            switch (choice) {
                case 1: inorderNonRecursive(); break;
                case 2: preorderNonRecursive(); break;
                case 3: postorderNonRecursive(); break;
                default: cout << "Invalid choice!\n"; return;
            }
        } else {
            cout << "Invalid choice!\n";
        }
        cout << endl;
    }
};

int main() {
    Tree tree;
    int choice;

    do {
        cout << "\nMenu:\n1. Insert\n2. Print\n3. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: tree.insert(); break;
            case 2: tree.printTree(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
