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

// Insert element to the end of the list
// Return the new element because it is now the last member of the list
Node* insertElement(Node* p , int data){
    Node* newNode = makeNode(data);
    p->next = newNode;
    return newNode;
}

// Print out all the element of the list 
// by passing the first element of that list
void printList(Node* head){
    Node* p = head;
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    freopen("testInput.txt", "r", stdin);
    int n, x;
	cin >> n;
	cin >> x;
	Node *l = makeNode(x);
	Node *p = l;
    for (int i=1; i<n; i++){
        cin >> x;
        p = insertElement(p, x);
    }
    printList(l);
    return 0;
}