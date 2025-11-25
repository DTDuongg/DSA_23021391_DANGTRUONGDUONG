#include <iostream>
#include <vector>
using namespace std;

template <class Key, class Value>
class HashTableLinear {
private:
    int M;          
    vector<Key> keys;
    vector<Value> vals;
    Key EMPTY_KEY;      

    int hashFunction(Key key) {
        return std::hash<Key>()(key) % M;
    }

public:
    HashTableLinear(int m = 11, Key emptyKey = Key())
        : M(m), EMPTY_KEY(emptyKey) 
    {
        keys.assign(M, EMPTY_KEY);
    }

    void insert(Key key, Value val) {
        int i = hashFunction(key);
        while (keys[i] != EMPTY_KEY && keys[i] != key) {
            i = (i + 1) % M;
        }
        keys[i] = key;
        vals[i] = val;
    }

    Value* search(Key key) {
        int i = hashFunction(key);
        while (keys[i] != EMPTY_KEY) {
            if (keys[i] == key)
                return &vals[i];
            i = (i + 1) % M;
        }
        return nullptr;
    }

    void print() {
        for (int i = 0; i < M; i++) {
            if (keys[i] == EMPTY_KEY) cout << i << ": ---\n";
            else cout << i << ": (" << keys[i] << "," << vals[i] << ")\n";
        }
    }
};

int main() {
    HashTableLinear<string,int> ht(11, "");

    ht.insert("S",0);
    ht.insert("E",1);
    ht.insert("A",2);
    ht.insert("R",3);
    ht.insert("C",4);

    ht.print();

    if (auto p = ht.search("E"))
        cout << "Tim thay E = " << *p << endl;

    return 0;
}
