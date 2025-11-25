#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <class Key, class Value>
class HashTableChaining {
private:
    int M;                     
    vector<list<pair<Key,Value>>> table;

    int hashFunction(Key key) {
        return std::hash<Key>()(key) % M;
    }

public:
    HashTableChaining(int m = 10) : M(m) {
        table.resize(M);
    }

    void insert(Key key, Value val) {
        int i = hashFunction(key);
        
        for (auto &p : table[i]) {
            if (p.first == key) {
                p.second = val;
                return;
            }
        }
        
        table[i].push_back({key, val});
    }

    Value* search(Key key) {
        int i = hashFunction(key);
        for (auto &p : table[i]) {
            if (p.first == key)
                return &p.second;
        }
        return nullptr;
    }

    void remove(Key key) {
        int i = hashFunction(key);
        table[i].remove_if([&](auto &p){ return p.first == key; });
    }

    void print() {
        for (int i = 0; i < M; i++) {
            cout << i << ": ";
            for (auto &p : table[i]) {
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << "\n";
        }
    }
};

int main() {
    HashTableChaining<string,int> ht(5);

    ht.insert("S",0);
    ht.insert("E",1);
    ht.insert("A",2);
    ht.insert("R",3);
    ht.insert("C",4);

    ht.print();

    if (auto p = ht.search("R"))
        cout << "Tim thay R = " << *p << endl;

    return 0;
}
