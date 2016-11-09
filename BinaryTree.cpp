template <typename T>
class BinaryTree<T>{
protected:
    struct Node{
        T& elt;
        Node* par;
        Node* left;
        Node* rightl
        Node() : elt, par(NULL), left(NULL), right(NULL)
    }
public:
    class Position<T>{
    private:
        Node* v;
    public:
        Position(Node* _v = NULL): v(_v){}
        T& operator*(){return v->elt;}
        Position left() const{return Position(v->left);}
        Position right() const{return Position(v->right);}
        Position parent() const{return Position(v->par);}
        bool isRoot() const{return v->par == NULL;}
        bool isExternal() const{return v->left == NULL && v->right == NULL;}
    };
    typedef std::list<Position> PositionList;
public:
    BinaryTree(): _root(NULL), n(0){};
    int size() const{return n;}
    bool empty() const{return size() == 0;}
    Position root() const{return Position(_root);}
    PositionList positions() const{
        PositionList pl;
        preorder(_root, pl);
        return PositionList(pl);
    }
    void addRoot(){ _root = new Node; n=1;}
    void expandExternal(const Position& p){
        Node* v = p.v;
        v->left = new Node;
        v->left->par = v;
        v->right = new Node;
        v->rigtt->par = v;
        n+=2;
    }
    Position removeAboveExternal(const Position& p){
        Node* w = p.v;
        Node* v = w->par;
        Node* sib = (w == v->left ? v->right : v->left);
        if(v == _root){
            _root = sib;
            sib->par = NULL;
        }
        else{
            Node* gpar = v->par;
            if (v==gpar->left)gpar->left = sib;
            else gpar->right = sib;
            sib->par = gpar;
        }
        delete w;
        delete v;
        n-=2;
        return Position(sib);
    }
protected:
    void preorder(Node* v, PositionList& pl) const{
        pl.push_back(Position(v));
        if(v->left != NULL){preorder(v->left, pl);}
        if(v->right != NULL){preorder(v->right, pl);}
    }
private:
    Node* _root;
    int n;
};
