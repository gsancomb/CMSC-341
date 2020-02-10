#include <iostream>
#include "Graph.h"

using std::cout;
using std::endl;
using std::exception;
using std::invalid_argument;

// Constructor - DO NOT MODIFY
Graph::Graph(int n) {
  if (n <= 0)
    throw invalid_argument("Graph::Graph(): number of vertices must be positive");

  _rows = new EntryList*[n];
  for (int i = 0; i < n; i++) {
    _rows[i] = new EntryList();
  }
  _numVert = n;
  _numEdge = 0;
}

Graph::Graph(const Graph& G) {
}

const Graph& Graph::operator=(const Graph& rhs) {
}

Graph::~Graph() {
}

// Number of vertices - DO NOT MODIFY
int Graph::numVert() const {
  return _numVert;
}

// Number of edges - DO NOT MODIFY
int Graph::numEdge() const {
  return _numEdge;
}

void Graph::addEdge(int u, int v, weight_t x) {
}

bool Graph::removeEdge(int u, int v) {
}


// Dump the graph - DO NOT MODIFY
void Graph::dump() const {

  cout << "Dump of graph (numVert = " << _numVert
       << ", numEdge = " << _numEdge << ")" << endl;

  for (int i = 0; i < _numVert; i++) {
    cout << "Row " << i << ": \n";
    _rows[i]->dump();
  }
}


Graph::EgIterator::EgIterator(Graph *Gptr, bool enditr) {
}
  
tuple<int,int,weight_t> Graph::EgIterator::operator*() {
}

bool Graph::EgIterator::operator!=(const EgIterator& rhs) {
}

void Graph::EgIterator::operator++(int dummy) {
}

Graph::EgIterator Graph::egBegin() {
}
 
Graph::EgIterator Graph::egEnd() {
}
 
Graph::NbIterator::NbIterator(Graph *Gptr, int v, bool enditr) {
}

bool Graph::NbIterator::operator!=(const NbIterator& rhs) {
}

void Graph::NbIterator::operator++(int dummy) {
}

pair<int,weight_t> Graph::NbIterator::operator*() {
}

Graph::NbIterator Graph::nbBegin(int v) {
}

Graph::NbIterator Graph::nbEnd(int v) {
}
