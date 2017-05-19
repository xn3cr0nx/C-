#ifndef MATRIX
#define MATRIX

#include <iostream>
using namespace std;

#include "Queue.h"


/*
 *  Implementazione di un grafo con la tecnica della matrice di adiacenza
 *  ogni riga corrisponde ad un vertice e la corrispondente colonna è
 *  0 se non c'è un collegamento tra  il vertice corrispondente al numero
 *  della riga e vertice corrispondente al numero della colonna e 1 in caso
 *  contrario.
 *
 *      1 2 3 4 5
 *    1 0 0 0 0 0
 *    2 0 0 0 0 0
 *    3 0 1 0 0 0   //1 indica che c'è un collegamento unidirezionale
 *    4 0 0 0 0 0   //tra il vertice 3 verso il vertice 2
 *    5 0 0 0 0 0
 *
 *      1 2 3 4 5
 *    1 0 0 0 0 0
 *    2 0 0 1 0 0
 *    3 0 1 0 0 0   //in questo caso il collegamento è bidirezionale
 *    4 0 0 0 0 0
 *    5 0 0 0 0 0
 *
 */

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
      if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount) {
        adjacencyMatrix[i][j] = true;
      }
    }

    void addUnidirectEdge(int i, int j) {
      if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount) {
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
      // cout << "Edge beetwen vertex " << i << " and vertex " << j << "? ";
      if (i >= vertexCount || j >= vertexCount) throw invalid_argument("Vertex doesn't exist");
      if (i >= 0 && j > 0)
        return adjacencyMatrix[i][j];
      else
        return false;
    }

    bool checkEdge(int i, int j) {
      try {
        // isEdge(i,j) ? cout << "True" << endl: cout << "False" << endl;
        return adjacencyMatrix[i][j];
      }
      catch(invalid_argument &e) {
        cerr << e.what() << endl;
        return false;
      }
    }

    //  Depth-First Search
    // Questo metodo parte da un vertice ed esplora il grafo proseguendo per la strada
    //dove trova un collegamento ed andando fin quando questo non si esaurisce, per poi
    // tornare ad esplorare la frontiera del vertice da cui era partito
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





    //  Breadth-First Search
    // Questo metodo procede un vertice per volta esplorandone tutta la frontiera
    // prima di proseguire esplorando le frontiere dei vertici ad esso collegati
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
