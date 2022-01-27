#include <iostream>
#include <map>
#include <list>

class Graph
{
    public:
       int V;
       
       std::list<int> * adj;
       
       Graph(int vertices):V{vertices}
       {
           adj = new std::list<int>[V];
       }
       
       void addEdge(int v, int w)
       {
           adj[v].push_back(w);
       }
       
       void BFS(int v)
       {
           bool *visited = new bool[V];
           for(int i =0; i< V; i++)
           {
               visited[i] = false;
           }
           std::list<int> queue;
           
           visited[v] = true;
           
           queue.push_back(v);
           std::list<int>::iterator i;
           while(!queue.empty())
            {
                v = queue.front();
                std::cout<<v<<" ";
                queue.pop_front();
                for(i =adj[v].begin();i!= adj[v].end(); ++i)
                {
                    if(!visited[*i])
                    {
                        visited[*i]=true;
                        queue.push_back(*i);
                    }
                }
            }          
       }
       
};      

int main()
{
     Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    std::cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
