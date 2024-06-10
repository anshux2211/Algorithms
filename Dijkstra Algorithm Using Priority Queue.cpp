// S is Source vertex
// adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge.
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) 
    {
        // Code here
        vector<int> dist(V,INT_MAX); // To store shortest path initially all are set infinity
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;    // Min Priority Queue Containing pair element. 2nd Element is node and 1st element is distance from source to that node.
        dist[S]=0;    // Inititally source is set 0.
        pq.push({0,S});    // And Source node is pushed into the queue.
        
        while(pq.size()!=0)    // Util queue is not empty
        {
            pair<int,int> curr=pq.top();    // Top Element
            pq.pop();
            for(auto&i:adj[curr.second])    // Seraching all the paths we can go from this current node
            {
                int tmp=curr.first+i[1];    // And how much time will we take
                if(dist[i[0]]>tmp)            // If we take less distance then we replace it with previous and push it to the queue
                {
                    dist[i[0]]=tmp;
                    pq.push({tmp,i[0]});
                }
            }
        }
        return dist;
    }
