
#ifndef bst_hpp
#define bst_hpp

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<class T>
class bst_node
{

public:
    int key;
    bst_node* left;
    bst_node* right;
    bst_node* parent;
    // Size includes the node itself.
    int size;
    // Height does not include the node itself.
    int height;
    
    bst_node()
    {
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        this->size = 1;
        this->height = 0;
        this->key = T();
    }
    bst_node(T key)
    {

        this->key = key;
        size = 1;
        height = 0;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        
    }
    
    bst_node(T _key, bst_node* _parent, bst_node* _left, bst_node* _right)
    {

        this->key = _key;
        size = 1;
        height = 0;
        this->parent = _parent;
        this->left = _left;
        this->right = _right;
        
    }

};

template<class T>
class bst_avl
{
private:
    //return root.
    bst_node<T>* build_avl(vector<T> keys);
    void left_rotation(bst_node<T>* node);
    void right_rotation(bst_node<T>* node);
    void update_height(bst_node<T>* node);
    void balance(bst_node<T>* node);
    
public:
    bst_node<T>* root;
    bst_avl()
    {
        this->root = nullptr;
    }
    bst_avl(vector<T> keys)
    {
        this->root = nullptr;
        
        for(T key : keys)
        {
            this->insert(key);
        }
    }
    bst_node<T>* find(T key);
    bst_node<T>* find_first();
    bst_node<T>* find_successor(bst_node<T>* node);
    // First value before key.
    T lower_bound(T key);
    // First value after key.
    T upper_bound(T key);
    bst_node<T>* mimimum(bst_node<T>* node);
    void insert(bst_node<T>* node);
    void insert(T key);
    void remove(bst_node<T>* node);
    vector<T> order_keys();
    vector<bst_node<T>*> order_nodes();
    int skew(bst_node<T>* node);

};

template<class T>
void bst_avl<T>::insert(T key)
{
    bst_node<T>* node = new bst_node<T>(key, nullptr, nullptr, nullptr);
    //On insertion we need to insure that we maintain our balanced tree condition. No skew greater than 1 or less than -1.
    bst_node<T>* previous = nullptr;
    bst_node<T>* current = this->root;
    
    while(current)
    {
        previous = current;
        
        if(node->key < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    
    node->parent = previous;
    
    if(!previous)
    {
        this->root = node;
    }
    else if(node->key < previous->key)
    {
        previous->left = node;
    }
    else
    {
        previous->right = node;
    }
    
    this->update_height(node);
        
    this->balance(node);
    
}

template<class T>
bst_node<T>* bst_avl<T>::mimimum(bst_node<T> *node)
{
    while(node->left)
    {
        node = node->left;
    }
    
    return node;
}

template<class T>
bst_node<T>* bst_avl<T>::find_successor(bst_node<T>* node)
{
    if(node->right)
    {
        return this->mimimum(node->right);
    }
    bst_node<T>* parent = node->parent;
    
    while(parent && node == parent->right)
    {
        node = parent;
        parent = parent->parent;
    }
    
    return parent;
}

template<class T>
vector<T> bst_avl<T>::order_keys()
{
    vector<T> travesal_order;
    
    bst_node<T>* node = this->mimimum(this->root);
    
    
    while(node)
    {
        travesal_order.push_back(node->key);

        node = find_successor(node);
                
    }
    
    return travesal_order;
}

template<class T>
vector<bst_node<T>*> bst_avl<T>::order_nodes()
{
    vector<bst_node<T>*> travesal_order;
    
    bst_node<T>* node = this->mimimum(this->root);
    
    while(node)
    {
        travesal_order.push_back(node);

        node = find_successor(node);
                
    }
    
    return travesal_order;
}

template<class T>
void bst_avl<T>::update_height(bst_node<T>* node)
{
    while(node)
    {
        if(node->right && node->left)
        {
            node->height = 1 + max(node->right->height, node->left->height);
        }
        else if(node->right)
        {
            node->height = 1 + node->right->height;
        }
        else if(node->left)
        {
            node->height = 1  + node->left->height;
        }
        else
        {
            node->height = 0;
        }
        
        node = node->parent;
        
    }
}

template<class T>
int bst_avl<T>::skew(bst_node<T>* node)
{
    int left = 0;
    int right = 0;
    
    if(node->left)
    {
        left = node->left->height;
    }
    
    if(node->right)
    {
        right = node->right->height;
    }
    
    return right - left;
}

template <class T>
void bst_avl<T>::left_rotation(bst_node<T> *node)
{
    if(!node->right)
        return;
    //Let pivot be nodes's right child
    bst_node<T>* pivot = node->right;
    //Set nodes's right child to be right's left child
    node->right = pivot->left;
    
    if(pivot->left)
    {   //Set pivot's left child's parent to node
        node->right->parent = node;
    }
    
    //Set pivot's left child to be node
    pivot->left = node;
    pivot->parent = node->parent;
    //Set P's parent to Q
    node->parent = pivot;
}

template <class T>
void bst_avl<T>::right_rotation(bst_node<T> *node)
{
    return;
    if(!node->left)
        return;
    
    bst_node<T>* pivot = node->left;
    node->left = pivot->right;
    if(pivot->right)
    {
        node->left->parent = node;
    }
    pivot->right = node;
    pivot->parent = node->parent;
    node->parent = pivot;
}

template <class T>
void bst_avl<T>::balance(bst_node<T> *node)
{
    bst_node<T>* start = node;
    
    while(node)
    {
        if(abs(skew(node)) > 1)
        {
            if(skew(node) > 0)
            {
                if(skew(node->right) == -1)
                {
                    right_rotation(node->right);
                    left_rotation(node);
                }
                else
                {
                    left_rotation(node);
                }
            }
            else
            {
                if(skew(node->left) == -1)
                {
                    left_rotation(node->left);
                    right_rotation(node);
                }
                else
                {
                    right_rotation(node);
                }
            }
        }

        node = node->parent;
    }
        
    update_height(start);
    
    return;
    
}


#endif
