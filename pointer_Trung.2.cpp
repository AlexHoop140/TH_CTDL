

#include <iostream>
//#include <string>

using namespace std;

typedef string elementType;

struct Node{
    elementType Data;
    Node *pNext;
};

typedef Node NODE;

struct List
{
    Node *pHead;
    Node *pTail;
};

typedef List LIST;

void init(LIST &l){
	l.pHead = new NODE;
  l.pHead->pNext = l.pTail = NULL;
}

void deleteList(NODE *position, LIST &l){
	NODE *temp;
	if(position->pNext != NULL){
		temp = position->pNext;
		position->pNext = temp->pNext;
		delete temp;
	}
}

NODE* getNode(elementType n){
    NODE* x = new NODE;
    if(x == NULL)
        return NULL;
    x->Data = n;
    x->pNext = NULL;
    return x;
}

void addHead(LIST &l, NODE *new_ele){
    if(l.pHead->pNext == NULL){
        l.pHead->pNext = l.pTail = new_ele;
    }
    else{
        new_ele->pNext = l.pHead->pNext;
        l.pHead->pNext = new_ele;
    }
}

void addLast(LIST &l, NODE* new_ele){
    if(l.pTail == NULL){
        l.pHead->pNext = new_ele;
        l.pTail = new_ele;
    }
    else{
        l.pTail->pNext = new_ele;
        new_ele->pNext = NULL;
        l.pTail = new_ele;
    }
}

// REQ. 2
void input(LIST &l){
    int n;
    cout << "HOW MANY ELEMENT DO YOU WANT TO ADD? ";
    cin >> n;
    cin.ignore();
    init(l);
    for(int i = 0; i < n; i++){
    	cout << "ELEMENT NO." << i+1 << ": "; 
        elementType k;
        getline(cin, k);
        NODE* x = getNode(k);
        addLast(l, x);
    }
}

//REQ. 2
void input_reverse(LIST &l){
    int n;
    cout << "HOW MANY ELEMENT DO YOU WANT TO ADD? ";
    cin >> n;
    cin.ignore();
    init(l);
    for(int i = 0; i < n; i++){
    	cout << "ELEMENT NO." << i+1 << ": "; 
        elementType k;
        getline(cin, k);
        NODE* x = getNode(k);
        addHead(l, x);
    }
}

//REQ. 2
void output(LIST l){
	cout << " <--- PRINT LIST ---> " << endl;
	int i = 1;
  for(NODE* p = l.pHead->pNext; p != NULL; p = p->pNext){
      cout << "ELEMENT NO." << i << ": " << p->Data << endl;
      i++;
  }
}

void giaiphong(LIST &l){
	NODE* temp;
	while(l.pHead != NULL){
		temp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete temp;
	}
}

//REQ. 3
void sort(LIST &l){
    elementType temp;
    for(NODE *p = l.pHead->pNext; p != NULL; p = p->pNext){
        for(NODE *q = p->pNext; q != NULL; q = q->pNext){
            if(q->Data < p->Data){
                temp = q->Data;
                q->Data = p->Data;
                p->Data = temp;
            }
        }
    }
}

//REQ. 4
//Them 1 phan tu vao danh sach co thu tu
void insert(LIST &l){
    elementType n;
    cout << "TYPE IN NEW ELEMENT: ";
    getline(cin, n);
    NODE *x = getNode(n);
    NODE *p = l.pHead->pNext;
    NODE *q = p;
    if(x->Data <= p->Data)
        addHead(l, x);
    else if(x->Data >= l.pTail->Data)
        addLast(l, x);
    else{
        while(p != NULL){
            p = p->pNext;
            if((x->Data > q->Data) && (x->Data <= p->Data)){
                x->pNext = q->pNext;
                q->pNext = x;
            }
            q = p;
        }
    }
}

//REQ. 5
void searchAndDelete(LIST &l){
	elementType n;
	cout << "WHICH ELEMENT DO YOU WANT TO DELETE? ";
//	cin >> n;
  getline(cin, n);
  
    if(l.pHead->pNext == NULL)
        cout << endl <<  "[ERROR] EMPTY LIST." << endl;
    else{
        NODE *p = l.pHead;
		while(p->pNext != NULL){
			if(p->pNext->Data == n){
				deleteList(p, l);
				return;
			}
			p = p->pNext;
		}

	    if(p == l.pTail)
	        cout << endl << "[ERROR] CANNOT FIND ELEMENT: " << n << endl;
	}
}

//REQ. 7
void deleteDouble(LIST &l){
    NODE* current = l.pHead->pNext;
    NODE* next_next;

    if (current == NULL)
        return;

    while (current->pNext != NULL){
        if (current->Data == current->pNext->Data){
            next_next = current->pNext->pNext;
            delete(current->pNext);
            current->pNext = next_next;
        }
        else
        {
        	current = current->pNext;
        }
    }
}

//REQ. 6
void insertListIntoOrderedList(LIST &l){
	int n;
	elementType new_ele;
	cout << "HOW MANY ELEMENT DO YOU WANT TO INSERT? ";
	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; i++){
		cout << "INPUT ELEMENT NO." << i+1 << ": " << endl;

		insert(l);
	}
}

int main(){
    LIST l;
    LIST l2;
    int n, size;
    
    cout << "------- REQ. 2 -------" << endl;
	  input(l);
    output(l);

    cout << "[WARNING] ALL REQ. IN THIS PROGRAM WILL NOT BE APPLIED TO THIS LIST" << endl;
    cout << "------- REQ. 2 INSERT IN REVERSED ORDER LIST 2 -------" << endl;
	  input_reverse(l2);
    output(l2);

    cout << endl << "------- REQ. 3B LIST 1 -------" << endl;
    sort(l);
    output(l);

    cout << endl << "------- REQ. 4 LIST 1 -------" << endl;
    insert(l);
    output(l);

    cout << endl << "------- REQ. 5 LIST 1 -------" << endl;
    searchAndDelete(l);
    cout << endl << "LIST 1 AFTER SEARCH AND DELETE" << endl;
    output(l);
    
    cout << endl << "------- REQ. 6 LIST 1 -------" << endl;
    insertListIntoOrderedList(l);
    cout << endl << "LIST 1 AFTER INSERT ANOTHER LIST" << endl;
    output(l);
    
    cout << endl << "------- REQ. 7 LIST 1 -------" << endl;
    deleteDouble(l);
    cout << endl << "--- LIST 1 AFTER DELETE DUPLICATED ELEMENTS ---" << endl;
    output(l);

    giaiphong(l);
    giaiphong(l2);
    return 0;
}

