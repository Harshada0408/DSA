#include <iostream>
using namespace std;

class set {
private:
    int cset[10];
    int count;

public:
    set() {
        count = 0;
    }

    void addele(int a) {
        for (int i = 0; i < count; i++) {
            if (cset[i] == a)
                return;
        }
        if (count < 10) {
            cset[count++] = a;
        } else {
            cout << "The set is full" << endl;
        }
    }

    void remove(int a) {
        int index = -1;
        for (int i = 0; i < count; i++) {
            if (cset[i] == a) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "The number is not present" << endl;
        } else {
            for (int i = index; i < count - 1; i++) {
                cset[i] = cset[i + 1];
            }
            count--;
        }
    }

    void iterator() {
        if (count == 0) {
            cout << "Set is empty.";
        }
        for (int i = 0; i < count; i++) {
            cout << cset[i] << " ";
        }
        cout << endl;
    }

    int size() {
        return count;
    }

    bool contains(int a) {
        for (int i = 0; i < count; i++) {
            if (cset[i] == a)
                return true;
        }
        return false;
    }

    void setunion(set& oset, set& result) {
        for (int i = 0; i < count; i++) {
            result.addele(cset[i]);
        }
        for (int i = 0; i < oset.count; i++) {
            result.addele(oset.cset[i]);
        }
    }

    void inter(set& oset, set& result) {
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < oset.count; j++) {
                if (cset[i] == oset.cset[j]) {
                    result.addele(cset[i]);
                    break;
                }
            }
        }
    }

    void differ(set& oset, set& result) {
        for (int i = 0; i < count; i++) {
            bool found = false;
            for (int j = 0; j < oset.count; j++) {
                if (cset[i] == oset.cset[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.addele(cset[i]);
            }
        }
    }

    void subset(set& oset) {
        for (int i = 0; i < oset.count; i++) {
            bool found = false;
            for (int j = 0; j < count; j++) {
                if (cset[j] == oset.cset[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Not a subset" << endl;
                return;
            }
        }
        cout << "It is a subset" << endl;
    }
};

int main() {
    set s1, s2;
    int n, a;

    cout << "Enter number of elements for Set 1: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a;
        s1.addele(a);
    }

    cout << "Enter number of elements for Set 2: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a;
        s2.addele(a);
    }

    int choice;
    do {
        cout << "\n-------- MENU --------\n";
        cout << "1. Display Sets\n";
        cout << "2. Add Element\n";
        cout << "3. Remove Element\n";
        cout << "4. Contains\n";
        cout << "5. Size\n";
        cout << "6. Union\n";
        cout << "7. Intersection\n";
        cout << "8. Difference (Set1 - Set2)\n";
        cout << "9. Subset Check (Is Set2 ? Set1?)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int element;
        set result;

        switch (choice) {
        case 1:
            cout << "Set 1: ";
            s1.iterator();
            cout << "Set 2: ";
            s2.iterator();
            break;

        case 2:
            cout << "Add to which set (1 or 2)? ";
            cin >> n;
            cout << "Enter element to add: ";
            cin >> element;
            if (n == 1) s1.addele(element);
            else s2.addele(element);
            break;

        case 3:
            cout << "Remove from which set (1 or 2)? ";
            cin >> n;
            cout << "Enter element to remove: ";
            cin >> element;
            if (n == 1) s1.remove(element);
            else s2.remove(element);
            break;

        case 4:
            cout << "Check which set (1 or 2)? ";
            cin >> n;
            cout << "Enter element to check: ";
            cin >> element;
            if (n == 1)
                cout << (s1.contains(element) ? "Present" : "Not Present") << " in Set 1\n";
            else
                cout << (s2.contains(element) ? "Present" : "Not Present") << " in Set 2\n";
            break;

        case 5:
            cout << "Size of Set 1: " << s1.size() << endl;
            cout << "Size of Set 2: " << s2.size() << endl;
            break;

        case 6:
            s1.setunion(s2, result);
            cout << "Union: ";
            result.iterator();
            break;

        case 7:
            s1.inter(s2, result);
            cout << "Intersection: ";
            result.iterator();
            break;

        case 8:
            s1.differ(s2, result);
            cout << "Difference (Set1 - Set2): ";
            result.iterator();
            break;

        case 9:
            cout << "Checking if Set 2 is a subset of Set 1:\n";
            s1.subset(s2);
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
