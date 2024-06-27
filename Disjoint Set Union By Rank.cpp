#include<bits/stdc++.h>
using namespace std;

vector<int> parent;     // To Store Parent
vector<int> Node_Rank;  // To Store Rank

void create(int n)  // Initializing parent and Node_Rank array. This can be used for both 0-based and 1-based indexed node.
{
    parent.resize(n+1);
    Node_Rank.resize(n+1,0);
    for(int i=0;i<=n;i++)
        parent[i]=i;    // Initially Pointing the parent of every node to itself.
    return;
}

int findParent(int u)   // This function finds the ultimate parent of a node.
{
    if(u==parent[u])
        return u;
    parent[u]=findParent(parent[u]);   // Path-Compression
    return parent[u];
}

void Union_by_Rank(int u,int v)     // Perform Union by Rank
{
    int p1=findParent(u);       // finding the parent of both nodes
    int p2=findParent(v);
    if(p1!=p2)                  // If they are not equal
    {
        if(Node_Rank[p1]==Node_Rank[p2])    // If rank of both parent are same.
        {
            parent[p1]=p2;
            Node_Rank[p2]+=1;   //rank is increased
        }
        else if(Node_Rank[p1]<Node_Rank[p2])    // Rank of p1 is less than p2
            parent[p1]=p2;
        else                // Rank of p2 is less than p1
            parent[p2]=p1;
    }
    return;
}

int main()
{
    int n;
    cin>>n; // Number of nodes
    create(n);  // To initialize the parent and Node_Rank vector
    int edges;  // Number of edges
    cin>>edges;
    for(int i=0;i<edges;i++)    
    {
        int u,v;
        cin>>u>>v;
        Union_by_Rank(u,v); // Performing union operation on both u and v.
    }
    int u,v;    
    cin>>u>>v;

    if(findParent(u)==findParent(v))    // If u and v have same parent means they are connected
        cout<<"Connected"<<endl;
    else    
        cout<<"NOT Connected"<<endl;
    

    return 0;
}
