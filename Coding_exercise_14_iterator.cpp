#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node *left{nullptr}, *right{nullptr}, *parent{nullptr};

    Node(T value) : value(value) {}

    Node(T value, Node<T> *left, Node<T> *right) : value(value), left(left), right(right) {
      left->parent = right->parent = this;
    }

    // traverse the node and its children preorder
    // and put all the results into `result`
    void preorder_traversal(vector<Node<T>*>& result)
    {
        // todo
        preorder_traversal_impl(result, this);
    }
    
    void preorder_traversal_impl(vector<Node<T>*>& result, Node* node)
    {
        if (!node)
            return;
        result.push_back(node);
        preorder_traversal_impl(result, node->left);
        preorder_traversal_impl(result, node->right);
    }
};
