#include <iostream>
#include <cstdlib>
using namespace std;

//step 1 create a conceptual idea of a chunk. we will build a stack of chunks

class chunk{
public:
  int value;
  chunk *next;
  chunk (){
    value = 0;
    next = NULL;
  }
};

class Stack{
public:
  chunk *top;
  Stack(){
    top = NULL;
  }
//add to the stack using LIFO
  void push(int x){
// get a new chunk we are going to add to this
    chunk *temp;
    temp = new chunk;
    temp->value = x;
  // is my stack empy
    if(top == NULL){
  //new element becomes the top
      top = temp;
    }
    else {
  //stack has more than one chunk in there already
    temp->next = top;
    top = temp;
    }
  }
//delete from the stack
  void pop(){
    if(top == NULL)
      cout << "Empty stack there is nothing to delete" << endl;
    else{
      chunk *temp;
      temp = top;
      top = temp->next; //to points to the second element
      cout << "about tot delete: " << temp->value << endl;
      delete temp;
    }
  }

  void display(){
    chunk *traverse = top;
    if(top == NULL)
      cout << "empty stack, nothing to display" << endl;
    else{
      while(traverse != NULL){
        cout << traverse->value << "-->" << endl;
        traverse = traverse->next;
      }
    }
  }
};

int main(){
  Stack ourstack;
  int choice = 0;
  while(1){
    cout << "press 1 to add to the stack" << endl;
    cout << "press2 to delete from the stack" << endl;
    cout << "press 3 to display" << endl;
    cout << "anything else to quit" << endl;
    cin >> choice;

    switch(choice){
      case 1: cout << "add what?" << endl;
              int value;
              cin >> value;
              ourstack.push(value);
              break;
      case 2: ourstack.pop();
              break;
      case 3: ourstack.display();
              break;
      default: exit(1);
    }
  }
}
