#include<iostream>
using namespace std;

class chunk{
public:
	int x;
	chunk *next;

	chunk(){
		x = 0;
		next = NULL;
	}
};

class linkedlist{
public:
	chunk *head;
	int length;

	linkedlist()
	{
		head = NULL;
		length = 0;
	}

	//add something to the head of the linked list
	void insertAtHead(int value) {
		chunk *temp;
		temp = new chunk;
		temp -> x = value;

		//check to see if linked list is empty
		if(head == NULL){
			head = temp;
			length ++;
		}
		else{
			temp->next = head;
			head = temp;
			length ++;
		}
	}

	//insert somthing anywhere in the linked list
	void insertAtPosition(int position, int value) {
		chunk *temp;
		chunk *chase;
		chunk *follow;

		follow = chase = head;

		temp = new chunk;
		temp -> x = value;

		if(position == 1)
		{
			cout << "Use the function add to head if you want to put something at the front" << endl;
		}

		else if (position <= length+1)
		{
			for(int i = 0; i < position-1; i++)
			{
				follow = chase;
				chase = chase -> next;
			}
				temp -> next = chase;
				follow -> next = temp;
				length++;
		}

		else
		{
			cout << "You chose an invalid position" << endl;
		}
	}


	//delete something from the linked list
	void removeFromPosition(int position){
		chunk *chase;
		chunk *follow;
		chunk *temp;

		if(head == NULL){
			cout << "Empty linked list! Nothing to delete" << endl;
		}
		else if(position == 1)
		{
			temp = head;
			head = head->next;
			cout << "Deleting: " << temp->x << endl;
			delete temp;
			length--;
		}
		else if(position < length+1)
		{
			follow = chase = head;
			for(int i = 0; i < position-1; i++)
			{
				follow = chase;
				chase = chase -> next;
			}
			follow -> next = chase -> next;
			cout << "Deleting: " << chase->x << endl;
			length--;
			delete chase;

		}
		else
		{
			cout << "You chose an invalid position." << endl;
		}
	}

	//display the linked list
	void displayContents(){
		chunk *traverse;
		traverse = head;

		while(traverse != NULL) {
			cout << traverse -> x << "----->";
			traverse = traverse -> next;
		}
		cout << endl;
	}

};

int main()
{
	linkedlist object;

	int choice;
	int value;
	int position;

	while(1){
		cout << "Press 1 to add something to the head of the linked list" << endl;
		cout << "Press 2 to add something anywhere on the linked list" << endl;
		cout << "Press 3 to delete something anywhere on the linked list" << endl;
		cout << "Press 4 to display the linked list" << endl;
		cout << "Press 5 to exit the program" << endl;
		cin >> choice;
		switch(choice){
			case 1 : cout << "What number do you want to add to the linked list?" << endl;
					 cin >> value;
					 object.insertAtHead(value);
					 break;

			case 2 : cout << "Where in the list would you like to place the value?" << endl;
					 cin >> position;
					 cout << "What number do you want to add to the linked list?" << endl;
					 cin >> value;
					 object.insertAtPosition(position,value);
					 break;

			case 3 : cout << "Where in the list would you like to delete a value?" << endl;
					 cin >> position;
					 object.removeFromPosition(position);
					 break;

			case 4 : object.displayContents();
					 break;

			case 5 : cout << "Goodbye" << endl;
					 return 0;
					 break;

			default: cout << choice << " is not a valid choice." << endl;
					 break;

		}
	}


return 1;
}
