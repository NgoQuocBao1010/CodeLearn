#include<iostream>

using namespace std;

struct NODE{
	int data;
	struct NODE *next;
	struct NODE *prev;
};


typedef struct NODE Node;


typedef struct{
	Node *head;
	Node *tail;
    int size;
}DoublyList;

// Create a node
Node* makeNode(int data){
    Node *p = new Node;
	
	if (p == NULL){
		cout << "\nKhong du bo nho!";
	}
	
	p->data = data;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

// Doubly Linked List Method

// Initialize an empty Doubly list
void makeNull(DoublyList &l){
    l.size = 0;
	l.head = l.tail = NULL;
	return;
}

// Check whether the list is empty or not
bool isEmpty(DoublyList l){
	if (l.head == NULL){
		return true;
	}
	return false;
}

// Insert element to the end of the list
void addTail(int x, DoublyList &l){
    l.size ++;
	Node* p = makeNode(x);
	if (isEmpty(l) == true){
		l.head = l.tail = p;
		return;
	}
	
	l.tail->next = p;
    p->prev = l.tail;
	l.tail = p;
}

// Insert element to the head of the list
void addHead(int x, DoublyList &l){
    l.size ++;
	Node* p = makeNode(x);
	if (isEmpty(l) == true){
		l.head = l.tail = p;
		return;
	}
	
	p->next = l.head;
    l.head->prev = p;
	l.head = p;
}

// Print out all the element of the list 
void printList(DoublyList l){
	for (Node *i = l.head; i != NULL; i = i->next){
		cout << i->data << " ";
	}
	cout << endl;
}

int main(){
    freopen("testInput.txt", "r", stdin);
    DoublyList l;
    makeNull(l);

    int dumpNumber;
    cin >> dumpNumber;

	addTail(1, l);

    for (int i=2; i<=dumpNumber; i++){
        addTail(i, l);
        addHead(i, l);
    }

	printList(l);
	cout << l.size;
}