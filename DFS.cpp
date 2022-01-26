#include <iostream>
#include <map>
#include <list>

class Graph
{
    public:
        std::map<int, std::list<int>> adj;
        
        std::map<int, bool> visited;
        
        void addEdge(int v, int n)
        {
            adj[v].push_back(n);
        }
        
        
        void DFSUtil(int v)
        {
            visited[v] = true;
            
            std::cout << v << " ";
            std::list<int>::iterator i;
            for(i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                if(!visited[*i])
                     DFSUtil(*i);
            }
        }
        
        void DFS()
        {
            for(auto i : adj)
            {
                if (visited[i.first]==false)
                    DFSUtil(i.first);
            }
        }
    
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    std::cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    //g.DFS();
    
    // If I need only the edges of one node
    g.DFSUtil(2);
}
