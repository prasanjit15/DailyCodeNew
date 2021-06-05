#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree;

struct node *create(int val){
    struct node *newt = new node();
    newt->data = val;
    newt->left = NULL;
    newt->right = NULL;

    return newt;
}


struct node *insert(struct node * tree, int val){
    if(tree == NULL){
        return create(val);
    }else{
        if(val < tree->data){
            tree->left = insert(tree->left, val);
        }else{
            tree->right = insert(tree->right, val);
        }
    }

    return tree;
}

struct node *deleteitem(struct node *tree, int val){
    if(tree == NULL){
        return tree;
    }else if(val < tree->data){
        deleteitem(tree->left, val);
    }else if(val > tree->data){
        deleteitem(tree->right, val);
    }else{
        //Case 1:
        if(tree->left == NULL && tree->right == NULL){
            delete tree;
            tree = NULL;
            
        }
        //Case 2
        else if(tree->left == NULL){
            struct node *temp = tree;
            tree = tree->right;
            delete temp;
        }else if(tree->right == NULL){
            struct node *temp = NULL;
            tree = tree->left;
            delete temp; 
        }
        //Case 3
        else{
            struct node *temp = findmin(tree->right);
            tree->data = temp->data;
            tree->right = deleteitem(tree->right, temp->data);
        }
    }
    return tree;
}

struct node *findmin(struct node *tree){
    while(tree->left != NULL){
        tree = tree->left;
    }
    return tree;
} 

void inorder(struct node *tree){
    if(tree != NULL){
        inorder(tree->left);
        cout<<tree->data<<" ";
        inorder(tree->right);
    }
}

void preorder(struct node *tree){
    if(tree != NULL){
        cout<<tree->data<<" ";
        inorder(tree->left);
        inorder(tree->right);
    }
}

void postorder(struct node *tree){
    if(tree != NULL){
        inorder(tree->left);
        inorder(tree->right);
        cout<<tree->data<<" ";
    }
}

int countnodes(struct node *tree){
    if(tree == NULL)
        return 0;
    else{
        return(countnodes(tree->left) + countnodes(tree->right) + 1);
    }
}

int countExternalNodes(struct node *tree){
    if(tree == NULL){
        return 0;
    }else if(tree->left  == NULL && tree->right == NULL){
        return 1;
    }else{
        return(countExternalNodes(tree->left) + countExternalNodes(tree->right));
    }
}

int countInternalNodes(struct node *tree){
    if((tree->left  == NULL && tree->right == NULL) || (tree == NULL)){
        return 0;
    }else{
        return(countInternalNodes(tree->left) + countInternalNodes(tree->right));
    }
}

int heightOfTree(struct node *tree){
    int lh, rh;
    if(tree == NULL){
        return 0;
    }else{
        lh = heightOfTree(tree->left);
        rh = heightOfTree(tree->right);

        if(lh > rh){
            return (lh + 1);
        }else{
            return (rh + 1);
        }
    }
}

struct node *mirrorImage(struct node *tree){
    struct node *ptr;
    if(tree != NULL){
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        ptr = tree->left;
        ptr->left = ptr->right;
        ptr->right = ptr;
    }
}

void deleteTree(struct node *tree){
    if(tree != NULL){
        deleteTree(tree->left);
        deleteTree(tree->right);
        delete tree;
    }
}

void smallestElement(struct node *tree){
    if((tree == NULL) ||(tree->left == NULL)){
        cout<<"Smallest Element is: "<<tree->data<<endl;
    }else{
        smallestElement(tree->left);
    }
}

void largestElement(struct node *tree){
    if((tree == NULL) || (tree->right == NULL)){
        cout<<"Largest Element is: "<<tree->data<<endl;
    }else{
        largestElement(tree->right);
    }
}

int main(){

    return 0;
}


