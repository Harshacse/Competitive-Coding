
//BFS
#include <cstdio>
#include <vector>
#include <list>
#include <utility>
 
using namespace std;
 
void breadthFirstSearch(vector< list< int > > adjacencyList, int parent[], int level[])
{
    list<int>::iterator itr;
    int i, par, lev;
    bool flag = true;
    //'lev' represents the level to be assigned
    //'par' represents the parent to be assigned
    //'flag' indicates if graph is unexplored or not
 
    lev = 0;
    level[1] = lev;
    /* We start from node 1
     * So, Node 1 is at level 0
     * All immediate neighbours are at
     * level 1 and so on.
     */
 
    while (flag) {
        flag = false;
        for (i = 1; i < adjacencyList.size(); ++i) {
            if (level[i] == lev) {
                flag = true;
                itr = adjacencyList[i].begin();
                par = i;
 
                while (itr != adjacencyList[i].end()) {
                    if (level[*itr] != -1) {
                        ++itr;
                        continue;
                    }
 
                    level[*itr] = lev + 1;
                    parent[*itr] = par;
                    ++itr;
                }
            }
        }
 
        ++lev;
    }
}
 
int main()
{
    int vertices, edges, v1, v2, weight;
 
    printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);
 
    printf("Enter the Number of Edges -\n");
    scanf("%d", &edges);
 
    // Adjacency List is a vector of lists.
    vector< list<int> > adjacencyList(vertices + 1);
 
    printf("Enter the Edges V1 -> V2\n");
     
    for (int i = 1; i <= edges; ++i) {
        scanf("%d%d", &v1, &v2);
         
        // Adding Edges
        adjacencyList[v1].push_back(v2);
        adjacencyList[v2].push_back(v1);
    }
 
    printf("\nThe Adjacency List-\n");
    // Printing Adjacency List
    for (int i = 1; i < adjacencyList.size(); ++i) {
        printf("adjacencyList[%d] ", i);
 
        list<int>::iterator itr = adjacencyList[i].begin();
 
        while (itr != adjacencyList[i].end()) {
            printf(" -> %d", *itr);
            ++itr;
        }
        printf("\n");
    }
 
    int parent[vertices + 1];
    //Each element of Parent Array holds the Node value of its parent
    int level[vertices + 1];
    //Each element of Level Array holds the Level value of that node
 
    for (int i = 0; i <= vertices; ++i) {
        //Initialising our arrays
        parent[i] = 0;
        level[i] = -1;
    }

    breadthFirstSearch(adjacencyList, parent, level);
    //Level Array
    printf("\nLevel and Parent Arrays -\n");
    for (int i = 1; i <= vertices; ++i) {
        printf("Level of Node %d is %d, Parent is %d\n", i, level[i], parent[i]);
    }
 
    return 0;
}

/*
 * Prim's Algorithm for
 * Undirected Weighted Graph
 * Code using C++ STL
 * 
 * Authored by,
 * Vamsi Sangam.
 *
 */
  
#include <cstdio>
#include <vector>
#include <list>
#include <utility>
  
using namespace std;
  
struct edge
{
    int u, v;
    int weight;
};
  
void Enqueue(struct edge heap[], int size, struct edge value)
{
    heap[size] = value;
      
    int i = size;
    struct edge temp;
      
    while (i >= 1) {
        if (heap[i / 2].weight > heap[i].weight) {
            //Parent node is greater than Child Node
            //Heap Property violated
            //So, swap
            temp = heap[i / 2];
            heap[i / 2] = heap[i];
            heap[i] = temp;
              
            i = i / 2;
        } else {
            //Parent is less or equal to the child
            //Heap property not violated
            //So, Insertion is done, break
            break;
        }
    }
}
  
void Heapify(struct edge heap[], int size, int index)
{
    int i = index;
    struct edge temp;
      
    while ((2 * i) < size) {
        //Left Child exists
          
        if ((2 * i) + 1 >= size) {
            //Right child does not exist, but left does
            if (heap[i].weight > heap[2 * i].weight) {
                //Left child is smaller than parent
                temp = heap[i];
                heap[i] = heap[2 * i];
                heap[2 * i] = temp;
                break;
                //Once you reach this level where it does not
                //have a right child, the heap ends here
                //taking it to the next iteration is pointless
            }
        }
          
        //Both Children exist
        if (heap[i].weight > heap[2 * i].weight || heap[i].weight > heap[2 * i + 1].weight) {
            //One of the other child is lesser than parent
            //Now find the least amoung 2 children
              
            if (heap[2 * i].weight <= heap[(2 * i) + 1].weight) {
                //Left Child is lesser, so, swap
                temp = heap[2 * i];
                heap[2 * i] = heap[i];
                heap[i] = temp;
                //And go down the heap
                i = 2 * i;
            } else if (heap[2 * i].weight > heap[(2 * i) + 1].weight) {
                //Left Child is lesser, so, swap
                temp = heap[(2 * i) + 1];
                heap[(2 * i) + 1] = heap[i];
                heap[i] = temp;
                //And go down the heap
                i = (2 * i) + 1;
            }
        } else {
            //Parent is lesser than its children
            break;
        }
    }
}
  
void DeleteNode(struct edge heap[], int size, int index)
{
    //Swap the indexed element with the last
    struct edge temp = heap[index];
    heap[index] = heap[size - 1];
    heap[size - 1] = temp;
      
    int i = index;
    --size;
      
    Heapify(heap, size, i);
}
  
// Returns the element with
// Minimum Priority and deletes it
struct edge ExtractMin(struct edge heap[], int size)
{
    struct edge min = heap[0];
   
    DeleteNode(heap, size, 0);
   
    return min;
}
  
// Prim's Algorithm function
void Prim(
            vector< list< pair<int, int> > > & adjacencyList, 
            int vertices, 
            int edges, 
            int startVertex, 
            vector< list< pair<int, int> > > & MST
         )
{
    int current = startVertex, newVertex;
    bool visited[vertices + 1];
    struct edge var;
    struct edge PriorityQueue[2 * edges];
    int QueueSize = 0;
   
    int i;
   
    for (i = 0; i <= vertices; ++i) {        // Initializing
        visited[i] = false;
    }
   
    i = 0;
   
    while (i < vertices) {
        if (!visited[current]) {            // If current node is not visited
            visited[current] = true;        // Mark it visited
              
            list< pair<int, int> >::iterator itr = adjacencyList[current].begin();
              
            while (itr != adjacencyList[current].end()) {                
                if (!visited[(*itr).first]) {
                    // If the edge leads to an un-visited
                    // vertex only then enqueue it
                    var.u = current;
                    var.v = (*itr).first;
                    var.weight = (*itr).second;
                  
                    Enqueue(PriorityQueue, QueueSize, var);
                    ++QueueSize;
                }
                  
                ++itr;
            }
   
            var = ExtractMin(PriorityQueue, QueueSize);     // The greedy choice
            --QueueSize;
   
            newVertex = var.v;
            current = var.u;
   
            if (!visited[newVertex]) {
                MST[current].push_back(make_pair(newVertex, var.weight));
                MST[newVertex].push_back(make_pair(current, var.weight));
            }
   
            current = newVertex;
            ++i;
        } else {
   
            var = ExtractMin(PriorityQueue, QueueSize);
            --QueueSize;
   
            newVertex = var.v;
            current = var.u;
   
            if (!visited[newVertex]) {
                MST[current].push_back(make_pair(newVertex, var.weight));
                MST[newVertex].push_back(make_pair(current, var.weight));
            }
   
            current = newVertex;
        }
    }
}
  
int main()
{
    int vertices, edges, v1, v2, weight;
      
    printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);
      
    printf("Enter the Number of Edges -\n");
    scanf("%d", &edges);
      
    // Adjacency List is a vector of list.
    // Where each element is a pair<int, int>
    // pair.first -> the edge's destination
    // pair.second -> edge's weight
    vector< list< pair<int, int> > > adjacencyList(vertices + 1);
    vector< list< pair<int, int> > > MST(vertices + 1);
      
    printf("Enter the Edges V1 -> V2, of weight W\n");
      
    for (int i = 1; i <= edges; ++i) {
        scanf("%d%d%d", &v1, &v2, &weight);
          
        // Adding Edge to the Directed Graph
        adjacencyList[v1].push_back(make_pair(v2, weight));
        adjacencyList[v2].push_back(make_pair(v1, weight));
    }
      
    printf("\nThe Adjacency List-\n");
    // Printing Adjacency List
    for (int i = 1; i < adjacencyList.size(); ++i) {
        printf("adjacencyList[%d] ", i);
          
        list< pair<int, int> >::iterator itr = adjacencyList[i].begin();
          
        while (itr != adjacencyList[i].end()) {
            printf(" -> %d(%d)", (*itr).first, (*itr).second);
            ++itr;
        }
        printf("\n");
    }
   
    int startVertex;
   
    printf("\nEnter a Start Vertex - ");
    scanf("%d", &startVertex);
    Prim(adjacencyList, vertices, edges, startVertex, MST);
   
    printf("\nThe Minimum Spanning Tree-\n");
    // Printing Adjacency List
    for (int i = 1; i < MST.size(); ++i) {
        printf("MST[%d] ", i);
          
        list< pair<int, int> >::iterator itr = MST[i].begin();
          
        while (itr != MST[i].end()) {
            printf(" -> %d(%d)", (*itr).first, (*itr).second);
            ++itr;
        }
        printf("\n");
    }
      
    return 0;
}

// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
 
// iPair ==>  Integer Pair
typedef pair<int, int> iPair;
 
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
 
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
 
    // prints shortest path from s
    void shortestPath(int s);
};
 
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // http://geeksquiz.com/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);
 
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
 
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
 
            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
 
    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.shortestPath(0);
 
    return 0;
}


//Kruskals Algorithm
// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// a structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

    return graph;
}

// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};

// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V];  // Tnis will store the resultant MST
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges

    // Step 1:  Sort all the edges in non-decreasing order of their weight
    // If we are not allowed to change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    // Allocate memory for creating V ssubsets
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }

    // print the contents of result[] to display the built MST
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                                                   result[i].weight);
    return;
}

// Driver program to test above functions
int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);


    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}

//Directed graphs
// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include<iostream>
#include <list>
 
using namespace std;
 
// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}

// C++ program to find single source shortest paths for Directed Acyclic Graphs
#include<iostream>
#include <list>
#include <stack>
#include <limits.h>
#define INF INT_MAX
using namespace std;
 
// Graph is represented using adjacency list. Every node of adjacency list 
// contains vertex number of the vertex to which edge connects. It also 
// contains weight of the edge
class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};
 
// Class to represent a graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices'
 
    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;
 
    // A function used by shortestPath
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
 
    // Finds shortest paths from given source vertex
    void shortestPath(int s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}
 
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node); // Add v to u's list
}
 
// A recursive function used by shortestPath. See below link for details
// http://www.geeksforgeeks.org/topological-sorting/
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
 
    // Push current vertex to stack which stores topological sort
    Stack.push(v);
}
 
// The function to find shortest paths from given vertex. It uses recursive 
// topologicalSortUtil() to get topological sorting of given graph.
void Graph::shortestPath(int s)
{
    stack<int> Stack;
    int dist[V];
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    // Initialize distances to all vertices as infinite and distance
    // to source as 0
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[s] = 0;
 
    // Process vertices in topological order
    while (Stack.empty() == false)
    {
        // Get the next vertex from topological order
        int u = Stack.top();
        Stack.pop();
 
        // Update distances of all adjacent vertices
        list<AdjListNode>::iterator i;
        if (dist[u] != INF)
        {
          for (i = adj[u].begin(); i != adj[u].end(); ++i)
             if (dist[i->getV()] > dist[u] + i->getWeight())
                dist[i->getV()] = dist[u] + i->getWeight();
        }
    }
 
    // Print the calculated shortest distances
    for (int i = 0; i < V; i++)
        (dist[i] == INF)? cout << "INF ": cout << dist[i] << " ";
}
 
// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram.  Here vertex numbers are
    // 0, 1, 2, 3, 4, 5 with following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
 
    int s = 1;
    cout << "Following are shortest distances from source " << s <<" \n";
    g.shortestPath(s);
 
    return 0;
}