#include "BinaryTree.cpp"

template <typename K, typename V>
class Entry{
public:
    typedef K Key;
    typedef V Value;
public:
    Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v){}
    const K& key() const{return _key;}
    const V& value() const{return _value;}
    void setKey(const K& k){_key = k;}
    void setValue(const V& v){_value = v;}
private:
    K _key;
    V _value;
};

template <typename T>
class BST{
public: // public types
    typedef typename T::Key K; // a key
    typedef typename T::Value V; // a value
    class Iterator; // an iterator/position
public: // public functions
    SearchTree(); // constructor
    int size() const; // number of entries
    bool empty() const; // is the tree empty?
    Iterator find(const K& k); // find entry with key k
    Iterator insert(const K& k, const V& x); // insert (k,x)
    void erase(const K& k) throw(NonexistentElement); // remove key k entry
    void erase(const Iterator& p); // remove entry at p
    Iterator begin(); // iterator to first entry
    Iterator end(); // iterator to end entry
protected: // local utilities
    typedef BinaryTree<E> BinaryTree; // linked binary tree
    typedef typename BinaryTree::Position TPos; // position in the tree
    TPos root() const; // get virtual root
    TPos finder(const K& k, const TPos& v); // find utility
    TPos inserter(const K& k, const V& x); // insert utility
    TPos eraser(TPos& v); // erase utility
    TPos restructure(const TPos& v) // restructure
    throw(BoundaryViolation);
private: // member data
    BinaryTree BST; // the binary tree
    int n; // number of entries
public:
    class Iterator { // an iterator/position
    private:
        TPos v; // which entry
    public:
        Iterator(const TPos& vv) : v(vv) { } // constructor
        const E& operator*() const { return *v; } // get entry (read only)
        E& operator*() { return *v; } // get entry (read/write)
        bool operator==(const Iterator& p) const // are iterators equal?
        { return v == p.v; } Iterator& operator++(); // inorder successor
        friend class SearchTree; // give search tree access
    };
};
