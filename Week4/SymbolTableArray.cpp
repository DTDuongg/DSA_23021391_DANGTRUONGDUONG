#include <iostream>
#include <string>
using namespace std;

class SymbolTable {
private:
    string keys[100];    
    string values[100]; 
    int size;            

public:
    SymbolTable() {
        size = 0;
    }


    void insert(string key, string value) {
       
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                values[i] = value;
                cout << "Cap nhat key \"" << key << "\" voi value moi: " << value << endl;
                return;
            }
        }


        keys[size] = key;
        values[size] = value;
        size++;
        cout << "Inserted: (" << key << ", " << value << ")" << endl;
    }

    
    string search(string key) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                return values[i];
            }
        }
        return "NOT FOUND";
    }

   
    void remove(string key) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                
                for (int j = i; j < size - 1; j++) {
                    keys[j] = keys[j + 1];
                    values[j] = values[j + 1];
                }
                size--;
                cout << "Removed key: " << key << endl;
                return;
            }
        }
        cout << "Key khong ton tai!" << endl;
    }

    
    void display() {
        cout << "\n===== SYMBOL TABLE =====" << endl;
        for (int i = 0; i < size; i++) {
            cout << keys[i] << " : " << values[i] << endl;
        }
        cout << "========================\n";
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
