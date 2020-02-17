#include <iostream>
#include <search.h>
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
    int n = G._numVert;
    _rows = new EntryList*[n];

    for (int i = 0; i < n; i++) {
        _rows[i] = new EntryList();
        _rows[i] = G._rows[i];
    }

    _numVert = n;
    _numEdge = G._numEdge;
}

const Graph& Graph::operator=(const Graph& rhs) {
    int n = rhs._numVert;
    _rows = new EntryList*[n];

    for (int i = 0; i < n; i++) {
        _rows[i] = new EntryList();
        _rows[i] = rhs._rows[i];
    }

    _numVert = n;
    _numEdge = rhs._numEdge;
    return *this;
}

Graph::~Graph() {
//    for (int i = 0; i <= _numVert; i++){
//        delete _rows[i];
//        _rows[i] = nullptr;
//    }
    delete [] _rows;
    _rows = nullptr;
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
    if ( (_numVert >= u and u >= 0) and (_numVert >= v and v >= 0)){
        EntryList::Entry edge(v, x);
        _rows[u]->insert(edge);
        _numEdge++;
    }
}

bool Graph::removeEdge(int u, int v) {
    if ( (_numVert >= u and u >= 0) and (_numVert >= v and v >= 0)){
        EntryList::Entry ret(0,0);
        bool been_removed = _rows[u]->remove(v, ret);
        if (been_removed)
            _numEdge--;
    }
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

void Graph::EgIterator::operator++(int dummy) { _row+=1;
}

Graph::EgIterator Graph::egBegin() {
}
 
Graph::EgIterator Graph::egEnd() {
}
 //Todo
 // iterator does not work
Graph::NbIterator::NbIterator(Graph *Gptr, int v, bool enditr) {
    if(enditr){
        _row = v;
        _Gptr = Gptr;
        _itr =_Gptr->_rows[v]->begin();
        auto itr = _Gptr->_rows[v]->begin();

    }
    else {
        _row = v;
        _Gptr = Gptr;
        //_itr =_Gptr->_rows[v]->end();
    }

}

bool Graph::NbIterator::operator!=(const NbIterator& rhs) { return _row != rhs._row;}

void Graph::NbIterator::operator++(int dummy) { _itr++;}

pair<int,weight_t> Graph::NbIterator::operator*() {
    int v=0;
    weight_t x=0;
    EntryList::Entry ret;
    if (_Gptr != nullptr) {
        _Gptr->_rows[_row]->getEntry(0, ret);
        v = ret.getVertex();
        x = ret.getWeight();
        return (pair<int, weight_t>(v, x));
    }
    else {
        cout << "_Gptr == NULL pair function"<< endl;
    }

}
//todo
// check the begin and end
Graph::NbIterator Graph::nbBegin(int v) {
    return NbIterator(this, v , false);
}

Graph::NbIterator Graph::nbEnd(int v) {
    return  NbIterator(this, v, true );
}
