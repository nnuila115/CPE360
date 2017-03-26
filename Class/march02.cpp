#include <iostream>
using namespace std;

class legoChunk{
public:
  int x;
  int y;
  legoChunk *next;

  legoChunk(){
    x = 0;
    y = 0;
    next = NULL;
  }
};

int main(){
  //create pointer to store addresses for chunks in the heap
  legoChunk *ptr;

//use the pointer to get the chunk in the heap
  ptr = new legoChunk;
  cout << "x: " << ptr->x << endl;
// use tha arrow -> to access elements in the chunk
  ptr ->x = 10;
  ptr ->y = 20;
  cout << "x is now " << ptr->x << ", and y is now" << ptr->y ,, endl;

  ptr->next = new legoChunk;
  ptr->next->x=45;
  ptr->next->y=55;

  cout << "x in first chunk: " << ptr->x << ", and second chunk: " << ptr->next->x << endl;

  //use second chunk to create a third chunk
  //we now have this oing on: ptr-> 1st->2nd->3rd

  ptr->next->next = new legoChunk;
  ptr->next->next->x=10;
  ptr->next->next->y=11;

  //one more chunk, with the third pointing the the fourth
  ptr->next->next->next = new legoChunk;
  ptr->next->next->next->x = 5;
  ptr->next->next->next->y = 7;


  //delete the second chunk bu usig temp pointer to point to the second chunk
  legoChunk *temp;
  temp = ptr->next;

  //now take the pointer of the first one and point it to the third chunk
  ptr->next = ptr->next->next;

  //now you can safely delete the second chunk, which temp is pointing to
  delete temp;
}
