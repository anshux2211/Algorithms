// S is Source vertex
// adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge.
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V,INT_MAX); // To Store shortest Path of each vertex from source
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  // Min Priority Queue that stores pair in which second element will be vertex V and First element will be distance from to vertex V.
        pq.push({0,S}); // Initially we push Source vertex and its distance as 0.
        
        while(pq.size()!=0)  
        {
            pair<int,int> curr=pq.top();  // This will get top element of Priority Queue that will be minimum of all.
            pq.pop();
            if(ans[curr.second]==INT_MAX) // If it is not visited till now, It will be minimum for sure
            {
                ans[curr.second]=curr.first;  // Update it
                for(auto&i:adj[curr.second])  // Traverse to all its adjacent vertex and push it in Priority Queue
                {
                        pq.push({curr.first+i[1],i[0]});  
                }
            }
        }
        return ans;
    }
