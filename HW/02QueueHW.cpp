#include<iostream>

using namespace std;



//step1: conceptually define a node. We'll build a queue of node

class node{

public:

    int value;

    node *next;



    node(){

        value = 0;

        next = NULL;

    }

};



class queue{

public:

    node *head;



    queue(){

        head = NULL;

    }



    void enqueue(int value){

        node *temp;

        temp = new node;

        temp->value = value;



        //knit it into the structure

        if(head==NULL){

            head = temp;

        }

        else{

            temp->next = head;

            head = temp;

        }

    }



    void dequeue(){

        if(head == NULL){

            cout << "Empty queue, nothing to delete" << endl;

        }

        else if(head->next == NULL){

            cout << "About to delete: " << head->value << endl;

            delete head;

            head = NULL;

        }

        else{

            node *chase, *follow;

            chase = follow = head;

            while(chase->next != NULL){

                follow = chase;

                chase = chase->next;

            }



            follow->next = NULL;

            cout << "About to delete: " << chase->value << endl;

            delete chase;

        }

    }



    void display(){

        node *temp;

        if(head == NULL){

            cout << "Empty queue, nothing to display" << endl;

        }

        else{

            temp = head;

            while(temp != NULL){

                cout << temp->value << " --> " << endl;

                temp = temp->next;

            }

        }

    }

};



int main(){



    queue ourQueue;

    int choice = 0;



    while(1){

        cout << "Press 1 to add to queue" << endl;

        cout << "Press 2 to delete from queue" << endl;

        cout << "Press 3 to display" << endl;

        cout << "Anything else to quit" << endl;

        cin >> choice;



        switch(choice){

            case 1: cout << "Add what?" << endl;

                int value;

                cin >> value;

                ourQueue.enqueue(value);

                break;

            case 2: ourQueue.dequeue();

                break;

            case 3: ourQueue.display();

                break;

            default: exit(1);

        }

    }



}
