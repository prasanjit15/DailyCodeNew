#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *graph;

void create(struct node *adj[], int num){
    struct node *new_node, *last;
    int i, j, n, val;
    for(i = 0; i<num; i++){
        last = NULL;
        cout<<"Enter the number of neighbours of "<<i<<": ";
        cin>>n;
        for(int j = 0; j<n; j++){
            cout<<"Enter the value of neighbour "<<j<<"of "<<i<<": ";
            cin>>val;

            new_node = new node();
            new_node->data = val;
            new_node->next = NULL;
            if(adj[i] == NULL)
                adj[i] = new_node;
            else
                last->next = new_node;
            last = new_node;
        }
    } 
}

void deletegraph(struct node *adj[], int n){
    int i;
    struct node *ptr, *temp;
    for(i = 0; i<=n; i++){
        ptr = adj[i];
        while(ptr != NULL){
            temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        adj[i] = NULL;
    }
}

void traverse(struct node *adj[], int n){
    struct node *ptr;
    for(int i = 0; i<n; i++){
        ptr = adj[i];
        cout<<"The nodes adjacent to "<<i<<" are: "<<endl;
        while(ptr != NULL){
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;
    struct node *adj[n];

    for(int i = 0; i<n; i++){
        adj[i] = NULL;
    }

    create(adj, n);
    cout<<"The graph is: "<<endl;
    traverse(adj, n);

    deletegraph(adj, n);

    return 0;
}