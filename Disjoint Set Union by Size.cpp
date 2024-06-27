#include<bits/stdc++.h>
using namespace std;

vector<int> parent;     // To Store Parent
vector<int> Node_Size;  // To Store Size

void create(int n)  // Initializing parent and Node_Size array. This can be used for both 0-based and 1-based indexed node.
{
    parent.resize(n+1);
    Node_Size.resize(n+1,1);
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

void Union_By_Size(int u,int v)     // Perform Union by Size
{
    int p1=findParent(u);       // finding the parent of both nodes
    int p2=findParent(v);
    if(p1!=p2)                  // If they are not equal
    {
        if(Node_Size[p1]<=Node_Size[p2])    // If size of both parent are same or p1 has less size .
        {
            parent[p1]=p2;
            Node_Size[p2]+=Node_Size[p1];   //size of p1 is added to p2
        }
        else{                // size of p2 is added to p1
            parent[p2]=p1;
            Node_Size[p1]+=Node_Size[p2];
        }
    }
    return;
}

int main()
{
    int n;
    cin>>n; // Number of nodes
    create(n);  // To initialize the parent and Node_Size vector
    int edges;  // Number of edges
    cin>>edges;
    for(int i=0;i<edges;i++)    
    {
        int u,v;
        cin>>u>>v;
        Union_By_Size(u,v); // Performing union operation on both u and v.
    }
    int u,v;    
    cin>>u>>v;

    if(findParent(u)==findParent(v))    // If u and v have same parent means they are connected
        cout<<"Connected"<<endl;
    else    
        cout<<"NOT Connected"<<endl;
    

    return 0;
}
