#ifndef MATRIX
#define MATRIX

#include <iostream>
using namespace std;

#include "Queue.h"

class Graph {
  private:
    bool** adjacencyMatrix;
    int vertexCount;
    enum VertexState { White, Grey, Black };
  public:
    Graph(int vertexCount) {
      this->vertexCount = vertexCount;
      cout << "vertexCount: " << vertexCount << endl;
      adjacencyMatrix = new bool*[vertexCount];
      cout << "adjacencyMatrix : " << adjacencyMatrix << endl;
      for (int i = 0; i < vertexCount; i++) {
        adjacencyMatrix[i] = new bool[vertexCount];
        for (int j = 0; j < vertexCount; j++) {
                adjacencyMatrix[i][j] = false;
        }
      }
    }

    void printAdjacencyMatrix() {
      for (int i = 0; i < vertexCount; i++) {
        cout << "adjacencyMatrix[" << i << "]: " << adjacencyMatrix[i] << "   ";
        for (int j = 0; j < vertexCount; j++) {
            adjacencyMatrix[i][j] ? cout << 1 << " " : cout << 0 << " ";
        }
        cout << endl;
      }
      cout << endl;
    }

    void addDirectEdge(int i, int j) {
      if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
        adjacencyMatrix[i][j] = true;
      }
    }

    void addUnidirectEdge(int i, int j) {
      if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
        adjacencyMatrix[i][j] = true;
        adjacencyMatrix[j][i] = true;
      }
    }

    void removeEdge(int i, int j) {
      if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount) {
        adjacencyMatrix[i][j] = false;
        adjacencyMatrix[j][i] = false;
      }
    }

    bool isEdge(int i, int j) {
      if (i >= vertexCount || j >= vertexCount) throw invalid_argument("Vertex doesn't exist");
      if (i >= 0 && j > 0)
        return adjacencyMatrix[i][j];
      else
        return false;
    }

    bool checkEdge(int i, int j) {
      try {
        return adjacencyMatrix[i][j];
      }
      catch(invalid_argument &e) {
        cerr << e.what() << endl;
        return false;
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
      for (int v = 0; v < vertexCount; v++) {
        if (checkEdge(u, v) && state[v] == White) {
          runDFS(v, state);
        }
      }
  	  state[u] = Black;
  	}


    void BFS(int start) {
      VertexState *state = new VertexState[vertexCount];
      for (int i = 0; i < vertexCount; i++)
        state[i] = White;
      state[start] = Grey;
      TQueue Q = queue_create(vertexCount);
      queue_add(&Q, start);
      runBFS(start, state, &Q);
      delete [] state;
    }
    int runBFS(int u, VertexState state[], TQueue* Q) {
      if(queue_is_empty(Q)) return 0;
      for(int v = 0; v < vertexCount; v++) {
        if(checkEdge(u,v) && state[v] == White) {
          state[v] = Grey;
          queue_add(Q, v);
        }
      }
      state[u] = Black;
      queue_remove(Q);
      for(int j = Q->a[Q->front]; Q->front != Q->back; j = Q->a[j+1]) {
        runBFS(j, state, Q);
      }
      return 1;
    }

    ~Graph() {
      for (int i = 0; i < vertexCount; i++)
        delete[] adjacencyMatrix[i];
        delete[] adjacencyMatrix;
    }
};

#endif
