#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;      
    string value;    
    Node* next;

    Node(string k, string v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class SymbolTable {
private:
    Node* head;  

public:
    SymbolTable() {
        head = nullptr;
    }

    
    void insert(string key, string value) {
       
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->key == key) {
                temp->value = value;
                cout << "Cap nhat key: " << key << " voi value moi: " << value << endl;
                return;
            }
            temp = temp->next;
        }

        
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted: (" << key << ", " << value << ")" << endl;
    }

    // Tìm kiếm bằng key
    string search(string key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        return "NOT FOUND";
    }

    // Xóa phần tử theo key
    void remove(string key) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr) {
                    head = temp->next; // xóa node đầu
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Removed key: " << key << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Key khong ton tai!" << endl;
    }

    // In toàn bộ Symbol Table
    void display() {
        Node* temp = head;
        cout << "\n===== SYMBOL TABLE =====\n";
        while (temp != nullptr) {
            cout << temp->key << " : " << temp->value << endl;
            temp = temp->next;
        }
        cout << "=========================\n";
    }
};

int main() {
    SymbolTable st;

    st.insert("x", "int");
    st.insert("y", "float");
    st.insert("name", "string");

    st.display();

    cout << "\nSearch 'y' → " << st.search("y") << endl;
    cout << "Search 'z' → " << st.search("z") << endl;

    st.remove("x");
    st.display();

    return 0;
}
