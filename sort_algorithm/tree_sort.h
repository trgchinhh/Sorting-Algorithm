#ifndef TREE_SORT_H
#define TREE_SORT_H

#include "lib//header.h"

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

typedef Node* Nodeptr;

Node* insert(Nodeptr root, int value) {
    if (root == NULL){
        return new Node(value);
    }
    if (value < root->data){
        root->left = insert(root->left, value);
    } else{
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Nodeptr root, vector<int>& a, int& index) {
    if (root == nullptr){
        return;
    }
    inorder(root->left, a, index);
    a[index++] = root->data;
    inorder(root->right, a, index);
}

void destroy(Nodeptr root) {
    if (root == NULL){
        return;
    }
    destroy(root->left);
    destroy(root->right);
    delete root; 
}

void tree_sort(vector<int>& a) {
    Nodeptr root = NULL;
    for (int value : a){
        root = insert(root, value);
    }
    int index = 0;
    inorder(root, a, index);
    destroy(root);
}

#endif