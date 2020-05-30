#include<iostream>

using namespace std;

struct NODE{
	int data;
	struct NODE *next;
};


typedef struct NODE Node;


typedef struct{
	Node *Head;
	Node *Tail;
    int size;
}List;

// Create a node
Node* makeNode(int data){
    Node *p = new Node;
	
	if (p == NULL){
		cout << "\nKhong du bo nho!";
	}
	
	p->data = data;
	p->next = NULL;
	return p;
}


// Linked List method

void makeNull(List &l){
    l.size = 0;
	l.Head = l.Tail = NULL;
	return;
}

bool isEmpty(List l){
	if (l.Head == NULL){
		return true;
	}
	return false;
}

// Insert element to the end of the list
void addTail(int x, List &l){
    l.size ++;
	Node* p = makeNode(x);
	if (isEmpty(l) == true){
		l.Head = l.Tail = p;
		return;
	}
	
	l.Tail->next = p;
	l.Tail = p;
}

// Insert element to the head of the list
void addHead(int x, List &l){
    l.size ++;
	Node* p = makeNode(x);
	if (isEmpty(l) == true){
		l.Head = l.Tail = p;
		return;
	}
	
	p->next = l.Head;
	l.Head = p;
}

// Insert element at a particular index
void addAt(int x, int index, List &l){
	Node* p = makeNode(x);
	if (isEmpty(l) == true || index == l.size){
		addTail(x, l);
        return;
	}

    if (index == 0){
        addHead(x, l);
        return;
    }
	
	Node* tmp = l.Head;
    for (int i=0; i<index-1; i++)
        tmp = tmp->next;
    
    p->next = tmp->next;
    tmp->next = p;
    l.size ++;
}

// Print out all the element of the list 
void printList(List l){
	for (Node *i = l.Head; i != NULL; i = i->next){
		cout << i->data << " ";
	}
	cout << endl;
}

int main(){
    freopen("testInput.txt", "r", stdin);
    List l;
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
    cout << l.size;
}