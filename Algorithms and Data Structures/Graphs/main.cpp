#include <iostream>
#include <stdlib.h>

using namespace std;

#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include "Timer.h"


void decorateGraph(int vertexes, Graph* g=NULL, GraphList* gl=NULL) {
  int src, dest = 0;
  int edges = rand() % vertexes*vertexes + 1;
  for(int i=0; i < edges; i++) {
    src = rand() % vertexes;
    dest = rand() % vertexes;
    if(g) g->addDirectEdge(src, dest);
    if(gl) gl->addDirectEdge(src, dest);
  }
}




int main() {
  srand(time(NULL));
  int vertexes = rand() % 10 + 100;
  Graph graph(vertexes);
  GraphList graphl(vertexes);
  decorateGraph(vertexes, &graph, &graphl);


  cout << "Adjacency Matrix Graph Implementation" << endl;
  graph.printAdjacencyMatrix();
  cout << "Breadth-First Search Algorithm" << endl;
  Timer tmr;
  graph.BFS(0);
  double t = tmr.elapsed();
  cout << "Breadth-First Algorithm Time: " << t << endl;

  cout << "Depth-First Search Algorithm" << endl;
  tmr.reset();
  graph.DFS(0);
  t = tmr.elapsed();
  cout << "Depth-First Algorithm Time: " << t << endl << endl << endl << endl;



  cout << "Adjacency List Graph Implementation" << endl;
  graphl.printAdjacencyList();
  cout << endl <<"Breadth-First Search Algorithm" << endl;
  tmr.reset();
  graphl.BFS(0);
  t = tmr.elapsed();
  cout << "Breadth-First Algorithm Time: " << t << endl;

  cout << "Depth-First Search Algorithm" << endl;
  tmr.reset();
  graph.DFS(0);
  t = tmr.elapsed();
  cout << "Depth-First Algorithm Time: " << t << endl;
}
