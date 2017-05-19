#ifndef LIST
#define LIST

#include <iostream>
#include <cstdlib>
using namespace std;

/* Adjacency List Node */
struct AdjListNode {
  int dest;
  struct AdjListNode* next;
};

/* Adjacency List */
struct AdjList {
  struct AdjListNode *head;
};

/* Class Graph */
class GraphList {
  private:
    int vertexCount;
    struct AdjList* array;
    enum VertexState { White, Grey, Black };
  public:
    GraphList(int vertexCount) {
      this->vertexCount = vertexCount;
      array = new AdjList[vertexCount];
      for (int i = 0; i < vertexCount; ++i)
        array[i].head = NULL;
    }

    /* Creating New Adjacency List Node */
    AdjListNode* newAdjListNode(int dest) {
      AdjListNode* newNode = new AdjListNode;
      newNode->dest = dest;
      newNode->next = NULL;
      return newNode;
    }

    /* Adding Undirect Edge to Graph */
    void addUnidirectEdge(int src, int dest) {
      AdjListNode* newNode = newAdjListNode(dest);
      newNode->next = array[src].head;
      array[src].head = newNode;
      newNode = newAdjListNode(src);
      newNode->next = array[dest].head;
      array[dest].head = newNode;
    }

    /* Adding Direct Edge to Graph */
    void addDirectEdge(int src, int dest) {
      AdjListNode* newNode = newAdjListNode(dest);
      newNode->next = array[src].head;
      array[src].head = newNode;
    }


    /* Print the graph */
    void printAdjacencyList() {
      for (int v = 0; v < vertexCount; ++v) {
        AdjListNode* pCrawl = array[v].head;
        cout << "Adjacency list of vertex " << v << "\n head ";
        while(pCrawl) {
          cout << "-> " << pCrawl->dest;
          pCrawl = pCrawl->next;
        }
        cout << endl;
      }
    }



    void DFS(int start) {
  	  VertexState *state = new VertexState[vertexCount];
  	  for (int i = 0; i < vertexCount; i++) state[i] = White;
      runDFS(start, state);
  	  delete [] state;
  	}
    void runDFS(int u, VertexState state[]) {
      state[u] = Grey;
      // cout << "Il nodo " << u << " è in esplorazione, il suo stato è grigio" << endl;
      AdjListNode* pCrawl = array[u].head;
      while(pCrawl) {
        if(state[pCrawl->dest] == White)
          runDFS(pCrawl->dest, state);
        pCrawl = pCrawl->next;
      }
      // cout << "Il nodo " << u << " è stato esplorato, il suo stato è nero" << endl << endl;
    }


    void BFS(int start) {
      VertexState *state = new VertexState[vertexCount];
      for (int i = 0; i < vertexCount; i++) state[i] = White;
      state[start] = Grey;
      runBFS(start, state);
      delete [] state;
    }
    void runBFS(int u, VertexState state[]) {
      // cout << "La frontiera del nodo " << u << " è in esplorazione" << endl;
      AdjListNode* pCrawl = array[u].head;
      while(pCrawl) {
        if(state[pCrawl->dest] == White) {
          state[pCrawl->dest] = Grey;
          // cout << "Il nodo " << pCrawl->dest << " della frontiera del nodo " << u << " è stato esplorato" << endl;
        }
        pCrawl = pCrawl->next;
      }
      state[u] = Black;
      // cout << "La frontiera del nodo " << u << " è stato esplorata, il suo stato è nero" << endl << endl;
      pCrawl = array[u].head;
      while(pCrawl) {
        if(state[pCrawl->dest] != Black)
          runBFS(pCrawl->dest, state);
        pCrawl = pCrawl->next;
      }
    }
};


#endif
