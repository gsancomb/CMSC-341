#include "EntryList.h"

using std::cout;
using std::endl;
using std::range_error;

// Constructor - DO NOT MODIFY
EntryList::EntryList() {
  _array = new Entry[DEFAULT_SIZE];
  _capacity = DEFAULT_SIZE;
  _size = 0;
}

EntryList::EntryList(const EntryList& rhs) {
    _capacity = rhs._capacity;
    _size = rhs._size;

    _array = new Entry[_capacity];

    for (int i = 0; i < _size; i++) {
        _array[i] = rhs._array[i];
    }
}

const EntryList& EntryList::operator=(const EntryList& rhs) {
    _capacity = rhs._capacity;
    _size = rhs._size;

    _array = new Entry[_capacity];

    for (int i = 0; i < _size; i++) {
        _array[i] = rhs._array[i];
    }
    return *this;
}
  
EntryList::~EntryList() {
    delete[] _array;
    _array = NULL;
}

bool EntryList::insert(const Entry& e) {

    Entry temp_position[2];
    if (_size + 1 == _capacity){
        _capacity *= 2;
        auto *new_entry_list = new Entry[_capacity];
        for (int i = 0; i <= _size; i ++){
            new_entry_list[i] = _array[i];
        }
        delete[] _array;
        _array = nullptr;

        _array = new_entry_list;
    }

    if (_size == 0) {
        _array[0] = e;
        cout << "first size ==0" << endl;
        _size++;
        return true;
    } else {
        for (int i = 0; i <= _size; i++) {
            if (e._vertex == _array->_vertex) {
                if (i == _size) {
                    //cout << "if vertex is in array" << endl;
                    return false;
                }


            } else if (e._vertex < _array[i]._vertex) {
                temp_position[0] = _array[i];
                _array[i] = e;
                temp_position[1] = temp_position[0];
               // cout << "saved temp position" << endl;
                for (int j = (i + 1); j <= _size; j++) {
                    cout << "in j loop"<< endl;
                    temp_position[0] = temp_position[1];
                    temp_position[1] = _array[j];
                    _array[j] = temp_position[0];
                }
                _size++;
                return true;
            }

            else if (i == _size){
                _array[_size] = e;
                _size++;
              return true;
            }
        }
    }

}

  
bool EntryList::update(const Entry& e) {
}

bool EntryList::getEntry(int vertex, Entry &ret) {
}

bool EntryList::remove(int vertex, Entry &ret) {
    for (int i = 0; i <=_size; i ++){
        
    }
}

EntryList::Entry& EntryList::at(int indx) const {
}

// dump data structure - DO NOT MODIFY
void EntryList::dump() {
  for (int i = 0; i < _size; i++) {
    cout << "  " << _array[i] << endl;
  }
}

EntryList::Iterator::Iterator(EntryList *EList, int indx) {
}

bool EntryList::Iterator::operator!=(const EntryList::Iterator& rhs) {
}

bool EntryList::Iterator::operator==(const EntryList::Iterator& rhs) {
}

void EntryList::Iterator::operator++(int dummy) {
}

EntryList::Entry EntryList::Iterator::operator*() {
}

EntryList::Iterator EntryList::begin() {
}

EntryList::Iterator EntryList::end() {
}

// Insertion operator for Entry objects - DO NOT MODIFY
ostream& operator<<(ostream& sout, const EntryList::Entry& e) {
  sout << e._vertex << ": " << e._weight;
  return sout;
}

// A convenient way to write test code for a single class is to write
// a main() function at the bottom of the .cpp file.  Just be sure to
// comment-out main() once you are done testing!

// Following is example test code.  There is no guarantee that it is
// complete -- you are responsbile for thoroughly testing your code.
// In particular, passing these tests does not mean your
// implementation will pass all grading tests.

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

//   cout << "size: " << el.size() << ", capacity: " << el.capacity() << endl;
//   el.dump();
//   cout << endl;


//   for (int i = 2; i < 13; i+=2) {
//     el.update( EntryList::Entry(i, 2*i) );
//   }

//   cout << "size: " << el.size() << ", capacity: " << el.capacity() << endl;
//   el.dump();
//   cout << endl;

//   for (int i = 3; i < 13; i*=2) {
//     el.remove(i, e);
//   }

//   cout << "size: " << el.size() << ", capacity: " << el.capacity() << endl;
//   el.dump();
//   cout << endl;

// cout << "\nPrint using iterator:\n";
// for (auto itr = el.begin(); itr != el.end(); itr++) {
//   cout << *itr << endl;
// }

    return 0;
}
