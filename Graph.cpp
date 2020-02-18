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
//    if (_rows != nullptr) {
//        for (int i = 0; _numVert > 0; i++) {
////            for (int j = 0; _numEdge > 0; j++) {
//            delete _rows[i];
//            _rows[i] = nullptr;
////            _numEdge--;
////                removeEdge(_rows[i], _rows[i]->at(j))
//        }
//    }
//
//    delete[] _rows;
//    _rows = nullptr;
//    }
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
    _Gptr = Gptr;
    _row = 0;

    if (Gptr != NULL) {
        if (enditr) {
            _row = _Gptr->_numVert;
//            _itr = _Gptr->_rows[_row]->end();

        }

        else {
            _row = 0;
            _itr = _Gptr->_rows[_row]->begin();

        }
    }
}
  
tuple<int,int,weight_t> Graph::EgIterator::operator*() {
    int u = 0;
    int v = 0;
    weight_t x=0;
    EntryList::Entry ret;

    if (_Gptr != nullptr) {
        EntryList::Iterator copy;
        int i = 0;
        for (copy = _Gptr->_rows[_row]->begin(); copy != _itr; copy++) {
            i++;
        }
        ret = _Gptr->_rows[_row]->at(i);
        u = _row;
        v = ret.getVertex();
        x = ret.getWeight();
        return (tuple<int, int, weight_t>(u, v, x));
    }
    else {
        cout << "_Gptr == NULL pair function"<< endl;
    }
}

bool Graph::EgIterator::operator!=(const EgIterator& rhs) {return _row != rhs._row; }

void Graph::EgIterator::operator++(int dummy) {
    if( _itr != _Gptr->_rows[_row]->end() ) {
        _itr++;
        EntryList::Iterator copy;
        int i = 0;
        for (copy = _Gptr->_rows[_row]->begin(); copy != _itr; copy++) {
            i++;
        }

        if (_Gptr->_rows[_row]->size()  == i){
            _row++;
            _itr = _Gptr->_rows[_row]->begin();

            if (_Gptr->_rows[_row]->size()  == 0) {
                _row++;
            }
        }
    }
    else {
        _row++;
        _itr = _Gptr->_rows[_row]->begin();
    }
}

Graph::EgIterator Graph::egBegin() { return EgIterator(this, false); }
 
Graph::EgIterator Graph::egEnd() { return EgIterator( this, true); }

Graph::NbIterator::NbIterator(Graph *Gptr, int v, bool enditr) {
    _row = v;
    _Gptr = Gptr;
    if (Gptr != NULL){
        if (enditr){

            _itr = _Gptr->_rows[_row]->end();
        }
        else {
            _itr = _Gptr->_rows[_row]->begin();
        }
    }
}

bool Graph::NbIterator::operator!=(const NbIterator& rhs) { return (_itr!= rhs._itr); }

void Graph::NbIterator::operator++(int dummy) { _itr++; }

pair<int,weight_t> Graph::NbIterator::operator*() {
    int v=0;
    weight_t x=0;
    EntryList::Entry ret;
    if (_Gptr != nullptr) {
        EntryList::Iterator copy;

        int i = 0;
        for (copy = _Gptr->_rows[_row]->begin(); copy != _itr; copy++) {
            i++;
        }
        ret = _Gptr->_rows[_row]->at(i);

        v = ret.getVertex();
        x = ret.getWeight();
        return (pair<int, weight_t>(v, x));
    }
    else {
        cout << "_Gptr == NULL pair function"<< endl;
    }

}

Graph::NbIterator Graph::nbBegin(int v) { return NbIterator(this, v , false); }

Graph::NbIterator Graph::nbEnd(int v) { return  NbIterator(this,  v , true ); }
