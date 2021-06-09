#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int x){
    struct node *tree = new node();
    tree->data = x;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

struct node *insert(struct node *root, int val){
    if(root == NULL){
        return create(val);
    }else{
        if(val < root->data){
            root->left = insert(root->left, val);
        }else{
            root->right = insert(root->right, val);
        }
    }
    return root;
}

struct node *findmin(struct node *root){
    while(root->left != NULL)
        root = root->left;

    return root;
}

struct node *deleteitem(struct node *root, int val){
    
    if(root == NULL){
        return root;
    }else if(val < root->data){
        deleteitem(root->left, val);
    }else if(val > root->data){
        deleteitem(root->right, val);
    }else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }else if(root->left  == NULL){
            struct node *temp = root;
            root = root->right;
            delete temp;
        }else if(root->right == NULL){
            struct node *temp = root;
            root = root->left;
            delete temp;
        }else{
            struct node *temp = findmin(root->right);
            root->data = temp->data;
            root->right = deleteitem(root->right, temp->data); 
        }
    }
}


