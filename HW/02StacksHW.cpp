#include<iostream>
using namespace std;


class node{
	public:
		int value;
		node *next;


	node(){
		value = 0;
		next = NULL;
	}
};


class Stack{
	public:
		node *top;


	Stack(){
		top = NULL;
	}


	void push(int x){

		node *temp;
		temp = new node;
		temp->value = x;

		if(top == NULL){

			top = temp;
		}
		else{

			temp->next = top;
			top = temp;
		}
	}


	void pop(){

		if(top == NULL){
			cout << "Empty stack, There is nothing to delete" << endl;
		}
		else{
			node *temp;
			temp = top;
			top = temp->next; //top points to second element
			cout << "About to delete: " << temp->value << endl;
			delete temp;
		}
	}


	void display(){
		node *traverse = top;
		if(top == NULL){
			cout << "Empty stack, there is nothing to display" << endl;
		}
		else{
			while(traverse != NULL){
				cout << traverse->value << " --> " << endl;
				traverse = traverse->next;
			}
		}
	}
};

int main(){

	Stack ourStack;
	int choice = 0;

	while(1){
		cout << "Press 1 to add to stack" << endl;
		cout << "Press 2 to delete from stack" << endl;
		cout << "Press 3 to display" << endl;
		cout << "Anything else to quit" << endl;
		cin >> choice;

		switch(choice){
			case 1: cout << "Add what?" << endl;
					int value;
					cin >> value;
					ourStack.push(value);
					break;
			case 2: ourStack.pop();
					break;
			case 3: ourStack.display();
					break;
			default: cout << "Not a valid choice. Goodbye!" << endl;
					 return 0;
		}
	}

}
