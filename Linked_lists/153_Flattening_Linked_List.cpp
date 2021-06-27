#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
	int data;
	Node* next;
	Node* bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}
    
Node* merge(Node *a, Node *b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    
    Node* result;
    if(a->data<b->data){
        result = a;
        result->bottom = merge(a->bottom, b);
    }else{
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}

Node *flatten(Node *root)
{
    if(root == NULL || root->next == NULL)
        return root;
    
    return merge(root, flatten(root->next));
  
}

int main(void) {

    int n,m,flag=1,flag1=1;
    Node * temp=NULL;
	Node * head=NULL;
	Node * pre=NULL;
	Node * tempB=NULL;
	Node * preB=NULL;

	cin>>n;
    int work[n];
	for(int i=0;i<n;i++)
        cin>>work[i];
	for(int i=0;i<n;i++){
		m=work[i];
		--m;
		int data;
		cin>>data;
		temp = new Node(data);
		temp->next = NULL;
		temp->bottom = NULL;
		
		if(flag){
			head = temp;
			pre = temp;
			flag = 0;
			flag1 = 1;
		}
		else{
			pre->next = temp;
			pre = temp;
			flag1 = 1;
		}
		for(int j=0;j<m;j++){
			
			int temp_data;
			scanf("%d",&temp_data);
			tempB = new Node(temp_data);
				if(flag1){
				temp->bottom=tempB;
				preB=tempB;
				flag1=0;
			}
			else{
				preB->bottom=tempB;
				preB=tempB;
			}
		}
	}
	Node *fun = head;
    Node *fun2=head;
    Node* root = flatten(head);
    printList(root);
    cout<<endl;

	
	return 0;
}

