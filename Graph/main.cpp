#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

#include "AdjacencyMatrix.h"


class Timer
{
public:
    Timer() { clock_gettime(CLOCK_REALTIME, &beg_); }

    double elapsed() {
        clock_gettime(CLOCK_REALTIME, &end_);
        return end_.tv_sec - beg_.tv_sec +
            (end_.tv_nsec - beg_.tv_nsec) / 1000000000.;
    }

    void reset() { clock_gettime(CLOCK_REALTIME, &beg_); }

private:
    timespec beg_, end_;
};




int main() {
  // Graph graph(6);
  // // Composizione del grafo
  // graph.addDirectEdge(0,1);
  // graph.addDirectEdge(0,2);
  // graph.addDirectEdge(2,4);
  // graph.addDirectEdge(3,5);
  // graph.addDirectEdge(4,3);
  // graph.addDirectEdge(3,2);
  // graph.printAdjacencyMatrix();


  Graph graph(6);
  // Composizione del grafo
  graph.addDirectEdge(0,1);
  graph.addDirectEdge(0,2);
  graph.addDirectEdge(0,5);
  graph.addDirectEdge(1,2);
  graph.addDirectEdge(1,1);
  graph.addDirectEdge(2,4);
  graph.addDirectEdge(3,4);
  graph.addDirectEdge(3,5);
  graph.addDirectEdge(4,3);
  graph.addDirectEdge(3,2);
  graph.addDirectEdge(4,5);
  graph.printAdjacencyMatrix();


  cout << "Adjacency Matrix Graph Implementation" << endl << endl;
  cout << "Breadth-First Search Algorithm" << endl;
  Timer tmr;
  graph.BFS(0);
  double t = tmr.elapsed();
  cout << "Breadth-First Alghoritm Time: " << t << endl;

  cout << "Depth-First Search Algorithm" << endl;
  tmr.reset();
  graph.DFS(0);
  t = tmr.elapsed();
  cout << "Depth-First Alghoritm Time: " << t << endl;
}
