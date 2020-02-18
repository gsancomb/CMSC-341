#include <iostream>
#include <search.h>
#include "Graph.h"
#include "EntryList.h"
#include "Graph.h"

using std::cout;
using std::endl;
using std::exception;
using std::invalid_argument;


using namespace std;


int main() {
   EntryList el;
   EntryList::Entry e;

   cout << "size: " << el.size() << ", capacity: " << el.capacity() << endl;
   el.dump();
   cout << endl;

   for (int i = 1; i < 13; i++) {
       el.insert( EntryList::Entry((i*5)%13, i) );
   }
   cout << "size: " << el.size() << ", capacity: " << el.capacity() << endl;
   el.dump();
   cout << endl;

   for (int i = 1; i < 13; i+=2) {
       el.remove(i, e);
   }
   cout << "size: " << el.size() << ", capacity: " << el.capacity() << endl;
   el.dump();
   cout << endl;

   cout << "size: " << el.size() << ", capacity: " << el.capacity() << endl;
   el.dump();
   cout << endl;


   for (int i = 2; i < 13; i+=2) {
     el.update( EntryList::Entry(i, 2*i) );
   }

   cout << "size: " << el.size() << ", capacity: " << el.capacity() << endl;
   el.dump();
   cout << endl;

   for (int i = 3; i < 13; i*=2) {
     el.remove(i, e);
   }

   cout << "size: " << el.size() << ", capacity: " << el.capacity() << endl;
   el.dump();
   cout << endl;

 cout << "\nPrint using iterator:\n";
    for (auto itr = el.begin(); itr != el.end(); itr++) {
     cout << *itr << endl;
    }

    return 0;

}
