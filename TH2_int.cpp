#include <iostream>

typedef int elementType;

using namespace std;

struct Node{
    int Data;
    Node *pNext;
};

typedef Node NODE;

struct List
{
    Node *pHead;
    Node *pTail;
};


// typedef Node* List;
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

void input(LIST &l){
    int n;
    cout << "HOW MANY ELEMENT DO YOU WANT TO ADD? ";
    cin >> n;
    init(l);
    for(int i = 0; i < n; i++){
    	cout << "ELEMENT NO." << i+1 << ": "; 
        elementType k;
        cin >> k;
        NODE* x = getNode(k);
//        addHead(l, x);
        addLast(l, x);
    }
}

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

//Them 1 phan tu vao danh sach co thu tu
void insert(LIST &l){
    int n;
    cout << "TYPE IN NEW ELEMENT: ";
    cin >> n;
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
            // cout << p->Data << " 000 " << q->Data << endl;
            q = p;
            // cout << p->Data << " " << q->Data << endl;
        }
    }
}

/*
void insertPos(LIST &l){
	int position;
	cout << "Nhap vi tri muon them: ";
	cin >> position;
    elementType n;
    cout << "Nhap 1 phan tu muon them vao: ";
    cin >> n;
    NODE *current = l.pHead->pNext;
    NODE **prev = &current;
    while(pos--){

        if(pos == 0){
            NODE *x = getNode(n);
            x->pNext = *prev;
            *prev = x;
        }
        prev = &(*prev)->pNext;
    }
}
*/

void searchAndDelete(LIST &l){
	elementType n;
	cout << "WHICH ELEMENT DO YOU WANT TO DELETE? ";
	cin >> n;
	
    if(l.pHead->pNext == NULL)
        cout << endl <<  "[ERROR] EMPTY LIST." << endl;
    else{
        NODE *p = l.pHead;
		while(p != NULL){
			if(p->pNext->Data == n){
				deleteList(p, l);
				return;
			}
			p = p->pNext;
		}

	    if(p == NULL)
	        cout << endl << "[ERROR] CANNOT FIND ELEMENT: " << n << endl;
	}
}

void deleteDouble(LIST &l){
    NODE* current = l.pHead;
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

void insertListIntoOrderedList(LIST &l){
	int n;
	elementType new_ele;
	cout << "HOW MANY ELEMENT DO YOU WANT TO INSERT? ";
	cin >> n;
//	cin.ignore();
	for(int i = 0; i < n; i++){
		cout << "INPUT ELEMENT NO." << i+1 << ": " << endl;
////		getline(cin, new_ele);
//		cin >> new_ele;
		insert(l);
	}
}

int main(){
    LIST l;
    int n, size;
    
    cout << "------- REQ. 2 -------" << endl;
	input(l);
    output(l);

    cout << endl << "------- REQ. 3B -------" << endl;
    sort(l);
    output(l);

    cout << endl << "------- REQ. 4 -------" << endl;
    insert(l);
    output(l);

	
//    insertPos(l);
//    cout << endl << "Danh sach sau khi them ngau nhien " << endl;
//    output(l);  
	
	
    cout << endl << "------- REQ. 5 -------" << endl;
    searchAndDelete(l);
    cout << endl << "LIST 1 AFTER SEARCH AND DELETE" << endl;
    output(l);
    
    cout << endl << "------- REQ. 6 -------" << endl;
    insertListIntoOrderedList(l);
    cout << endl << "LIST 1 AFTER INSERT ANOTHER LIST" << endl;
    output(l);
    
    cout << endl << "------- REQ. 7 -------" << endl;
    deleteDouble(l);
    cout << endl << "--- LIST 1 AFTER DELETE DUPLICATED ELEMENTS ---" << endl;
    output(l);


    giaiphong(l);
    return 0;
}
