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

// Insert element at a particular index
void addAt(int x, int index, DoublyList &l){
	Node* p = makeNode(x);
	if (isEmpty(l) == true || index == l.size){
		addTail(x, l);
        return;
	}

    if (index == 0){
        addHead(x, l);
        return;
    }
	
	Node* tmp = l.head;
    for (int i=0; i<index-1; i++)
        tmp = tmp->next;
    
    p->next = tmp->next;
    p->prev = tmp;

    tmp->next->prev = p;
    tmp->next = p;
    l.size ++;
}


// Print out all the element of the list 
void printList(DoublyList l){
	for (Node *i = l.head; i != NULL; i = i->next){
		cout << i->data << " ";
	}
	cout << endl;
}

// Print out all the element of the list in reverse
void printListReverse(DoublyList l){
	for (Node *i = l.tail; i != NULL; i = i->prev){
		cout << i->data << " ";
	}
	cout << endl;
}

int main(){
    freopen("testInput.txt", "r", stdin);
    DoublyList l;
    makeNull(l);


    int size, element;
    cin >> size;

    for (int i=0; i<size; i++){
        cin >> element;
        addTail(element, l);
    }

    int index;
    cin >> index >> element;

    addAt(element, index, l);

	printList(l);
	// printListReverse(l);
	// cout << l.size;
}