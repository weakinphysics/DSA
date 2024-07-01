#ifndef PED_H
#define PED_H

#include <bits/stdc++.h>
#include <assert.h>

extern int INORDER_WALK = 0;
extern int PREORDER_WALK = 1;
extern int POSTORDER_WALK = 2;

extern int CLOCKWISE = 0;
extern int COUNTER_CLOCKWISE = 1;


template <class T>
class TreeNode{
    
    // You can build heterogenous trees

    public:
        T data;
        size_t color;
        size_t multiplicity;
        TreeNode* left = nullptr; // for classic implementation of a binary tree
        TreeNode* right = nullptr; // "
        TreeNode* parent = nullptr; // for binary search trees in particular 
        std::vector <TreeNode*> children;
        bool isDead; // dummy node fuinction, for AVL TREE USE

        TreeNode();
        // TreeNode(const T value);
        TreeNode(T &value); 
        TreeNode(T &value, size_t c);
        TreeNode(TreeNode<T>* t); // copy constructor between nodes with the same data type
        void operator=(TreeNode<T> &rhs); // assignment operator between nodes with the same data type
        // ~TreeNode(); // Destructor

};



template <class T>
class Tree{
    public:
        TreeNode<T>* root;
        size_t type;

        // let us use the default constructor for now

        Tree();
        // ~Tree();
        void executeTreeWalk(int WALK_TYPE);
        void executeTreeWalk(int WALK_TYPE, std::vector <T> &nums);

        void recursivelyDeleteNodes(TreeNode<T> *root);
        void inOrderWalk(TreeNode<T>* root);
        void preOrderWalk(TreeNode<T>* root);
        void postOrderWalk(TreeNode<T>* root);
        void inOrderWalk(TreeNode<T>* root, std::vector <T> &nums);
        void preOrderWalk(TreeNode<T>* root, std::vector <T> &nums);
        void postOrderWalk(TreeNode<T>* root, std::vector <T> &nums);
};

template <class T>
class BST: public Tree<T>{
    public:
        // TreeNode<T>* root;
        T maximum; // so as to ensure operation as a max heap
        T minimum; // so as to ensure operation as a min heap

        BST();
        TreeNode<T>* treeMinimum(TreeNode<T>* root);
        TreeNode<T>* treeMaximum(TreeNode<T>* root);
        TreeNode<T>* search(T& value);
        TreeNode<T>* successor(T &value); // but what about nodes with the same value?
        TreeNode<T>* predecessor(T &value); // but what about nodes with the same value?
        TreeNode<T>* searchNode(T& value); 
        
        void Transplant(TreeNode<T>* a, TreeNode<T> *b, bool deleteTree); // transplant function for tree modification operations 
        
        // bool insertNode(const T value);
        // bool deleteNode(const T value);
        bool insertNode(T &value);
        bool deleteNode(T& value);

    private:

};

template <class T>
class RBTree: public Tree<T>{
    public:
        TreeNode<T> *root;
        TreeNode<int> *sentinel; // uses a dummy node with isDead true
        T maximum;
        T minimum;

        RBTree(); // custom constructor as every Node must have a color

        TreeNode<T>* searchNode(T& value);
        TreeNode<T> *successor(T& value);
        TreeNode<T> *predecessor(T&value);

        void Transplant(TreeNode<T>* a, TreeNode<T> *b, bool deleteTree); // transplant function for tree modification operations 

        void rotate(TreeNode<T> *a, int direction);
        
        TreeNode<T> search(T& value);

        bool insertNode(T &value);
        void rbTreeInsertFixup(TreeNode<T>* point);

        bool deleteNode(T &value);
};








////////////////////////////// IMPLEMENTATION CODE BEGINS HERE ////////////////////////////////////////





template <class T>
TreeNode<T>::TreeNode(){
    std::cout<<"Initialized an empty node"<<std::endl;
}

// template <class T>
// TreeNode<T>::TreeNode(const T value){
//     this->data = value;
//     this->isDead = false;
// }

template <class T>
TreeNode<T>::TreeNode(T &value){    
    this->data = value;
    this->isDead = false;
}

template <class T>
TreeNode<T>::TreeNode(TreeNode* r){
    this->data = r->data;
    this->left = r->left;
    this->right = r->right;
    if(!(r->children).empty()) this->children = r->children;
}

template <class T>
TreeNode<T>::TreeNode(T& value, size_t c){
    this->data = value;
    this->color = c;
}

template <class T>
void TreeNode<T>::operator=(TreeNode<T> &rhs){
    this->data = rhs->data;
    this->left = rhs->left;
    this->right = rhs->right;
    if(!(rhs->children).empty()) this->children = rhs->children;

}


//////////////////////////////////////////////////////  TREE CODE /////////////////////////////////////////////////////////////////////////////


template <class T>
Tree<T>::Tree(){
    std::cout<<"Creating an empty tree"<<std::endl;
    std::cout<<"Use the handle provided to perform addition and deletion operations"<<std::endl;
}

template <class T>
void Tree<T>::executeTreeWalk(int WALK_TYPE){
    switch (WALK_TYPE){
        case 0:
            this->inOrderWalk(this->root);
            break;
        case 1:
            this->preOrderWalk(this->root);
            break;
        case 2:
            this->postOrderWalk(this->root);
            break;
    }
    std::cout<<std::endl;
}

template <class T>
void Tree<T>::executeTreeWalk(int WALK_TYPE, std::vector <T> &nums){
    switch (WALK_TYPE){
        case 0:
            this->inOrderWalk(this->root, nums);
            break;
        case 1:
            this->preOrderWalk(this->root, nums);
            break;
        case 2:
            this->postOrderWalk(this->root, nums);
            break;
    }
}

template<class T>
void Tree<T>::recursivelyDeleteNodes(TreeNode<T>* root){
    if(!root) return;
    this->recursivelyDeleteNodes(root->left);
    this->recursivelyDeleteNodes(root->right);
    if(root->parent){
        if(root->parent->left == root) delete root->parent->left;
        else delete root->parent->right;
    }
}


template<class T>
void Tree<T>::inOrderWalk(TreeNode<T>* node){
    if(!node) return;
    this->inOrderWalk(node->left);
    std::cout<<node->data<<" ";
    this->inOrderWalk(node->right);
}

template<class T>
void Tree<T>::preOrderWalk(TreeNode<T>* root){
    if(!root) return;
    std::cout<<root->data<<" ";
    this->inOrderWalk(root->left);
    this->inOrderWalk(root->right);
}

template<class T>
void Tree<T>::postOrderWalk(TreeNode<T>* root){
    if(!root) return;
    this->inOrderWalk(root->left);
    this->inOrderWalk(root->right);
    std::cout<<root->data<<" ";
}

template<class T>
void Tree<T>::inOrderWalk(TreeNode<T>* root, std::vector <T> &nums){
    if(!root) return;
    this->inOrderWalk(root->left);
    nums.push_back(root->data);
    this->inOrderWalk(root->right);
}

template<class T>
void Tree<T>::preOrderWalk(TreeNode<T>* root, std::vector<T> &nums){
    if(!root) return;
    nums.push_back(root->right);
    this->inOrderWalk(root->left);
    this->inOrderWalk(root->right);
}

template<class T>
void Tree<T>::postOrderWalk(TreeNode<T>* root, std::vector <T> &nums){
    if(!root) return;
    this->inOrderWalk(root->left);
    this->inOrderWalk(root->right);
    nums.push_back(root->data);
}

template<class T>
BST<T>::BST(){
    this->root = nullptr;
    this->minimum = 0;
    this->maximum = 0;
}

template <class T>
bool BST<T>::insertNode(T& value){
    if(!(this->root)){
        this->root = new TreeNode<T>(value);
        return true;
    }
    else{
        TreeNode<T>* temp = this->root;
        while(temp!=nullptr){
            if(value == temp->data){
                temp->multiplicity++;
                return true;
            }
            else if(value < temp->data){
                if(temp->left) temp = temp->left;
                else{
                    temp->left = new TreeNode<T>(value);
                    temp->left->parent = temp;
                    return true;
                }
            }
            else{
                if(temp->right) temp = temp->right;
                else{
                    temp->right = new TreeNode<T>(value);
                    temp->right->parent = temp;
                    return true;
                }
            }
        }
        return false;
    }
}

template <class T>
TreeNode<T>* BST<T>::search(T& value){
    TreeNode<T>* temp = this->root;
    while(temp){
        if(temp->data == value) return temp;
        else if(temp->data > value) temp = temp->left;
        else temp = temp->right;
    }
    return nullptr;
}

template <class T>
TreeNode<T>* BST<T>::treeMinimum(TreeNode<T>* root){
    if(!root) return nullptr;
    TreeNode<T>* temp = root;
    while(temp->left) temp = temp->left;
    return temp;
}

template<class T>
TreeNode<T>* BST<T>::treeMaximum(TreeNode<T>* root){
    if(!root) return nullptr;
    TreeNode<T>* temp = root;
    while(temp->right) temp = temp->right;
    return temp;
}

template <class T>
TreeNode<T>* BST<T>::successor(T& value){
    TreeNode<T>* me = this->search(value);
    if(!me) return me;
    if(me->right) return this->treeMinimum(me->right);
    TreeNode<T>* t = me->parent;
    while(t != nullptr && me == t->right){
        me = t;
        t = t->parent;
    }
    return t;
}

template <class T>
TreeNode<T>* BST<T>::predecessor(T& value){
    TreeNode<T> *me = this->search(value);
    if(!me) return me;
    if(me->left) return this->treeMaximum(me->left);
    TreeNode<T> *t = me->parent;
    while(t != nullptr && me == t->left){
        me = t;
        t = t->parent;
    }
    return t;
}

template <class T>
void BST<T>::Transplant(TreeNode<T>* a, TreeNode<T> *b, bool deleteTree){
    // THIS DISCARDS A AND INTRODUCES B IN ITS PLACE
    // THIS OPERATION WILL DELETE THE ENTIRE TREE     
    TreeNode<T>* papa = a;
    if(papa){
        b->parent = papa;
        if(papa->left == a) papa->left = b;
        else papa->right = b;
    }
    else{
        this->root = b;
        b->parent = nullptr;
    }
    if(deleteTree) this->recursivelyDeleteNodes(a);
}




template <class T>
bool BST<T>::deleteNode(T& value){
    TreeNode<T>* me = this->search(value);
    if(me->multiplicity > 1){
        me->multiplicity--;
        std::cout<<"NIGGAS BE EVERYWHERE"<<std::endl;
        return true;
    }
    if(!me) return false;
    if(me->left == nullptr){
        if(me == me->parent->left){
            me->parent->left = me->right;
            me->right->parent = me->parent;
        }
        else{
            me->parent->right = me->right;
            me->right->parent = me->parent;
        }
    }
    else if(me->right == nullptr){
        if(me == me->parent->left){
            me->parent->left = me->left;
            me->left->parent = me->parent;
        }
        else{
            me->parent->right = me->left;
            me->left->parent = me->parent;
        }
    }
    else{
        TreeNode<T> *s = this->successor(me->data);
        if(me->right != s){
            Transplant(s, s->right, false); // replaces tree at s with tree at s->right
            s->right = me->right;
            s->right->parent = s;
        }
        Transplant(me, s, false);
        s->left = me->left;
        s->left->parent = s;
    }
    delete me;
    return true;
}


//////////////////  RB TREE IMPLEMENTATION BEGINS ///////////////////////////////////////////////

template <class T>
RBTree<T>::RBTree(){
    std::cout<<"RB TREE INITIALIZED"<<std::endl;
    this->sentinel = new TreeNode<int>(0);
    this->sentinel->isDead = true;
    this->sentinel->color = 0;
    // await calls to insert to insert nodes
}

template <class T>
void RBTree<T>::rotate(TreeNode<T>* node, int direction){
    if(direction == 0){
        // clockwise rotation, meaning the node is replaced by its left child
        Transplant(node, node->left);
        TreeNode<T> *l = node->left;
        node->left = l->right;
        l->right = node;
        node->parent = l;
    }
    else{
        Transplant(node, node->right);
        TreeNode<T> *r = node->right;
        node->right = r->left;
        r->left = node;
        node->parent = r;
    }
    return;
}


template <class T>
TreeNode<T> RBTree<T>::search(T& value){
    TreeNode<T>* temp = this->root;
    while(temp){
        if(temp->data == value) return temp;
        else if(temp->data > value) temp = temp->left;
        else temp = temp->right;
    }
    return temp;
}

template <class T>
void RBTree<T>::rbTreeInsertFixup(TreeNode<T>* point){
    TreeNode<T>* node = point;
    TreeNode<T>* parent = point->parent;
    while(node != sentinel && node->parent != sentinel && node->parent->color == 1){
        // executes while the parent is red colored
        if(node->parent->parent == sentinel){
            // this should never happen, since we set the root node to black every time we perform rb tree fixup
            std::cerr<<"NEHA RANDAPA"<<std::endl;
        }
        if(node->parent->parent->left == node){
            TreeNode<T> *uncle = node->parent-parent->right;
            if(uncle->color == 1){
                node->parent->color = 0;
                uncle->color = 0;
                node->parent->parent->color = 1;
                node = node->parent->parent;
            }
            else{
                if(node = node->parent->right){
                    // LR state, must transition to LL state
                    node = node->parent;
                    this->rotate(node, COUNTER_CLOCKWISE);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1; // color the grand parent red, and color the parent black, this preserved the number of black nodes on the branch
                // now we rotate, so as to ensure the newly created black node is accessible to both the paths that originate at the location
                this->rotate(node->parent->parent, CLOCKWISE);
                // after this fresh rotation, we should have a balanced tree, and we will break out of the loop
            }
            
        }
        else{
            TreeNode<T>* uncle = node->parent->parent->left;
            if(uncle->color == 1){
                node->parent->color = 0;
                uncle->color = 0;
                node = node->parent->parent;
                node->color = 1;
                // rinse repeat 
            }
            else{
                if(node = node->parent->left){
                    // RL state, must transition to RR state
                    node = node->parent;
                    this->rotate(node, CLOCKWISE);
                }
                node->parent->color = 0;
                node->parent->parent = 1;
                this->rotate(node->parent->parent, COUNTER_CLOCKWISE);
            }
        }
    }
    this->root->color = 0;
    return;
}

template <class T>
bool RBTree<T>::insertNode(T& value){
    // implement internal search routine, and then call fixup
    TreeNode<T>* t = this->root;
    while(t){
        if(t->data == value){
            t->multiplicity++;
            return true;
        }
        else if(value > t->data){
            if(t->right) t = t->right;
            else break;
        }
        else{
            if(t->left) t = t->left;
            else break;
        }
    }
    if(value < t){
        t->left = new TreeNode<T>(value);
        t->left->color = 1; // color the node red;
        t = t->left;
    }
    else{
        t->right = new TreeNode<T>(value);
        t->right->color = 1; // color the node red;
        t = t->right;
    }
    this->rbTreeInsertFixup(t);
    return true;
}



#endif