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

// Delete first member of the list
void deleteHead(List &l){
	Node* p = l.Head;
	l.Head = l.Head->next;
    l.size --;
	delete p;
}


// Delete last member of the list
void deleteTail(List &l){
	for (Node* i = l.Head; i != l.Tail; i = i->next){
		if (i->next == l.Tail){
			Node* p = l.Tail;
			l.Tail = i;
			l.Tail->next = NULL;
			delete p;
            l.size --;
			return;
		}
	}
}

// Delete a node at a particular index
void deleteAt(int index, List &l){
	if (index == 0){
		deleteHead(l);
	}
	else if(index == l.size - 1){
		deleteTail(l);
	}
	else{
		Node* tmp = l.Head;

        for (int i=0; i < index-1; i++)
            tmp = tmp->next;
        
        Node* p = tmp->next;
        tmp->next = p->next;
        delete(p);
        l.size --;
	}
}

// return how many element with value of x 
// exists in the list
// return -1 if the list is empty
int locateAndCount(int x, List &l){
	if (isEmpty(l) == true){
		return -1;
	}
	else{
		int count=0;
		for (Node* i = l.Head; i != NULL; i = i->next){
			if (i->data == x){
				++count;
			}
		}
		return count;
	}
}

// return element at index k
Node* getNode(int k, List l){
    Node* p = l.Head;
    for (int i=0; i < k; i++)
        p = p->next;
    
    return p;
}

// Print out all the element of the list 
void printList(List l){
	for (Node *i = l.Head; i != NULL; i = i->next){
		cout << i->data << " ";
	}
	cout << endl;
}


// Excercise
void changeElement(List &l){
    int changeFrom, changeTo;
    cin >> changeFrom >> changeTo;

    Node* p = l.Head;

    for (int i=0; i<l.size; i++){
        if (p->data == changeFrom){
            p->data = changeTo;
        }
        p = p->next;
    }
}

int main(){
    // freopen("testInput.txt", "r", stdin);
    List l;
    makeNull(l);

    int size, element;
    cin >> size;

    for (int i=0; i<size; i++){
        cin >> element;
        addTail(element, l);
    }

    changeElement(l);
    
    printList(l);
    // cout << l.size;
    return 0;
}