#include <iostream>
#include <string>

using namespace std;

struct Node {
    string keyword;
    string meaning;
    Node* left;
    Node* right;
    int height;

    Node(string k, string m) : keyword(k), meaning(m), left(NULL), right(NULL), height(0) {}
};

class Dictionary {
private:
    Node* root;

    int height(Node* n) {
        if (n == NULL)
            return -1;  
        return n->height;
    }

    int balanceFactor(Node* n) {
        if (n == NULL)
            return 0;
        return height(n->left) - height(n->right);
    }

    int max(int a, int b) {
        if(a > b)
            return a;
        return b;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* insert(Node* node, string keyword, string meaning) {
        if (node == NULL)
            return new Node(keyword, meaning);

        if (keyword < node->keyword)
            node->left = insert(node->left, keyword, meaning);
        else if (keyword > node->keyword)
            node->right = insert(node->right, keyword, meaning);

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = balanceFactor(node);

        if (balance > 1 && keyword < node->left->keyword)
            return rotateRight(node);
        if (balance < -1 && keyword > node->right->keyword)
            return rotateLeft(node);
        if (balance > 1 && keyword > node->left->keyword) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && keyword < node->right->keyword) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, string keyword) {
        if (node == NULL)
            return node;

        if (keyword < node->keyword)
            node->left = deleteNode(node->left, keyword);
        else if (keyword > node->keyword)
            node->right = deleteNode(node->right, keyword);
        else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->keyword = temp->keyword;
                node->meaning = temp->meaning;
                node->right = deleteNode(node->right, temp->keyword);
            }
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = balanceFactor(node);

        if (balance > 1 && balanceFactor(node->left) >= 0)
            return rotateRight(node);
        if (balance < -1 && balanceFactor(node->right) <= 0)
            return rotateLeft(node);
        if (balance > 1 && balanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && balanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->keyword << " : " << node->meaning << endl;
            inorder(node->right);
        }
    }

    void reverseInorder(Node* node) {
        if (node != NULL) {
            reverseInorder(node->right);
            cout << node->keyword << " : " << node->meaning << endl;
            reverseInorder(node->left);
        }
    }

    Node* search(Node* node, string keyword, int& count) {
        if (node == NULL)
            return NULL;

        count++;
        if (keyword == node->keyword)
            return node;
        else if (keyword < node->keyword)
            return search(node->left, keyword, count);
        else
            return search(node->right, keyword, count);
    }

public:
    Dictionary() : root(NULL) {}

    void insert(string keyword, string meaning) {
        root = insert(root, keyword, meaning);
    }

    void remove(string keyword) {
        root = deleteNode(root, keyword);
    }

    void update(string keyword, string newMeaning) {
        int count = 0;
        Node* node = search(root, keyword, count);
        if (node)
            node->meaning = newMeaning;
        else
            cout << "Keyword not found.\n";
    }

    void displayAsc() {
        cout << "Ascending Order:\n";
        inorder(root);
    }

    void displayDesc() {
        cout << "Descending Order:\n";
        reverseInorder(root);
    }

    void find(string keyword) {
        int count = 0;
        Node* node = search(root, keyword, count);
        if (node)
            cout << "Found: " << node->keyword << " = " << node->meaning << endl;
        else
            cout << "Keyword not found.\n";
        cout << "Comparisons made: " << count << endl;
    }

    void showHeight() {
        cout << "Maximum comparisons (Tree Height): " << height(root) << endl;
    }
};

int main() {
    Dictionary dict;
    int choice;
    string keyword, meaning;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Delete\n3. Update\n4. Display Ascending\n5. Display Descending\n6. Search\n7. Tree Height\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter meaning: ";
                cin >> meaning;
                dict.insert(keyword, meaning);
                break;
            case 2:
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                dict.remove(keyword);
                break;
            case 3:
                cout << "Enter keyword to update: ";
                cin >> keyword;
                cout << "Enter new meaning: ";
                cin >> meaning;
                dict.update(keyword, meaning);
                break;
            case 4:
                dict.displayAsc();
                break;
            case 5:
                dict.displayDesc();
                break;
            case 6:
                cout << "Enter keyword to search: ";
                cin >> keyword;
                dict.find(keyword);
                break;
            case 7:
                dict.showHeight();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
