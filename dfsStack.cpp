#include<bits/stdc++.h>

using namespace std;

class graph{
    public:
    int v;
    list<int> *adj;

    graph(int v){
        this->v = v;
        adj = new list<int>[v];
    }

    void addEdge(int v, int w){
        adj[v].push_back(w);
    }

    void dfs(int s){
        vector<bool> visited(v, false);
        stack<int> st;

        st.push(s);

        while(!st.empty()){
            int s = st.top();
            st.pop();

           
            if(!visited[s]){
                cout<<s<<" ";
                visited[s] = true;
            }

            for(auto i = adj[s].begin(); i != adj[s].end(); i++){
                if(!visited[*i])
                    st.push(*i);
            }
        }
    }
};

int main(){
    graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
 
    cout << "Following is Depth First Traversal\n";
    g.dfs(0);
 
    return 0;
}