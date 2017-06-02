#ifndef LIST
#define LIST

#include <iostream>
#include <cstdlib>
using namespace std;

struct AdjListNode {
  int dest;
  struct AdjListNode* next;
};

struct AdjList {
  struct AdjListNode *head;
};

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

    AdjListNode* newAdjListNode(int dest) {
      AdjListNode* newNode = new AdjListNode;
      newNode->dest = dest;
      newNode->next = NULL;
      return newNode;
    }

    int checkEdge(int src, int dest) {
      AdjListNode* pCrawl = array[src].head;
      if(!pCrawl) return 0;
      while(pCrawl) {
        if(pCrawl->dest == dest) break;
        pCrawl = pCrawl->next;
        if(!pCrawl) return 0;
      }
      return -1;
    }

    void addDirectEdge(int src, int dest) {
      if(!checkEdge(src, dest)) {
        AdjListNode* newNode = newAdjListNode(dest);
        newNode->next = array[src].head;
        array[src].head = newNode;
      }
    }

    void addUnidirectEdge(int src, int dest) {
      if(!checkEdge(src, dest)) {
        AdjListNode* newNode = newAdjListNode(dest);
        newNode->next = array[src].head;
        array[src].head = newNode;
        newNode = newAdjListNode(src);
        newNode->next = array[dest].head;
        array[dest].head = newNode;
      }
    }

    void removeEdge(int src, int dest) {
      AdjListNode* pCrawl = array[src].head;
      while(pCrawl->next->dest != dest) pCrawl = pCrawl->next;
      pCrawl->next = pCrawl->next->next;
    }

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
      AdjListNode* pCrawl = array[u].head;
      while(pCrawl) {
        if(state[pCrawl->dest] == White)
          runDFS(pCrawl->dest, state);
        pCrawl = pCrawl->next;
      }
    }


    void BFS(int start) {
      VertexState *state = new VertexState[vertexCount];
      for (int i = 0; i < vertexCount; i++) state[i] = White;
      state[start] = Grey;
      runBFS(start, state);
      delete [] state;
    }
    void runBFS(int u, VertexState state[]) {
      AdjListNode* pCrawl = array[u].head;
      while(pCrawl) {
        if(state[pCrawl->dest] == White) {
          state[pCrawl->dest] = Grey;
        }
        pCrawl = pCrawl->next;
      }
      state[u] = Black;
      pCrawl = array[u].head;
      while(pCrawl) {
        if(state[pCrawl->dest] != Black)
          runBFS(pCrawl->dest, state);
        pCrawl = pCrawl->next;
      }
    }
};

#endif
