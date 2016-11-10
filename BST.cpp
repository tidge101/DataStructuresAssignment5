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

template <typename E>
class BST{
public: // public types
    typedef typename E::Key K; // a key
    typedef typename E::Value V; // a value
    class Iterator; // an iterator/position
public: // public functions
    BST() : T(), n(0){
        T.addRoot();
        T.expandExternal(T.root());
    } // constructor
    int size() const; // number of entries
    bool empty() const; // is the tree empty?
    Iterator find(const K& k){
        TPos v = finder(k, root());
        if(v.isInternal()){return Iterator(v);}
        else{return end();}
    } // find entry with key k
    Iterator insert(const K& k, const V& x){
        TPos v = inserter(k, x);
        return Iterator(v);
    }// insert (k,x)
    void erase(const K& k) throw(NonexistentElement){
        TPos v = finder(k, root());
        if(v.isExternal()){throw NonexistentElement("Erase of nonexistent");}
        eraser(v);
    }// remove key k entry
    void erase(const Iterator& p){eraser(p.v);}// remove entry at p
    Iterator begin(){
        TPos v = root();
        while(v.isInternal()){v = v.left();}
        return Iterator(v.parent())
    }// iterator to first entry
    Iterator end(){return Iterator(T.root())}// iterator to end entry
protected: // local utilities
    typedef BinaryTree<E> BinaryTree; // linked binary tree
    typedef typename Position TPos; // position in the tree
    TPos root() const{return T.root().left();} // get virtual root
    TPos finder(const K& k, const TPos& v){
        if(v.isExternal()){return v;}
        if(k < v->key()){return finder(k, v.left());}
        else if(v->key < k){return finder(k, v.right());}
        else{return v;}
    }// find utility
    TPos inserter(const K& k, const V& x){
        TPos v = finder(k, root());
        while(v.isInternal()){v = finder(k, v.right());}
        T.expandExternal(v);
        v->setKey(k);
        v->setValue(x);
        return v;
    }// insert utility
    TPos eraser(TPos& v){
        TPos w;
        if(v.left().isExternal()){w = v.left();}
        else if(v.right.isExternal()){w = v.right();}
        else{
            w = v.right();
            do{w = w.left();} while(w.isInternal());
            TPos u = w.parent();
            v->setKey(u->key());
            v->setValue(u->value());
        }
        n--;
        return T.removeAboveExternal(w);
    }// erase utility
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
        { return v == p.v; }
        Iterator& operator++(){
            TPos w = v.right();
            if (w.isInternal()) { // have right subtree?
                do { v = w; w = w.left(); } // move down left chain
                while (w.isInternal());
            }else { w = v.parent(); // get parent
                while (v == w.right()) // move up right chain
                { v = w; w = w.parent(); } v = w; // and first link to left
            }return *this;
        }// inorder successor
        friend class BST; // give search tree access
    };
};
