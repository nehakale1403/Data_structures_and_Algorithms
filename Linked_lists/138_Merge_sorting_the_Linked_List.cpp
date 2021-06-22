#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution{
  public:
    void findMiddle(Node* curr, Node** first, Node** second){
        Node* fast, *slow;
        slow = curr;
        fast = curr->next;
    
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                slow = slow->next;
                fast = fast->next;
            }       
        }
        
        *first = curr;
        *second = slow->next;
        slow->next=NULL;
    }
  
    Node* mergeBoth(Node* &first, Node* &second){
        Node* answer = NULL;
        if(!first)
            return second;
        if(!second)
            return first;
        
        if(first->data <= second->data){
            answer = first;
            answer->next = mergeBoth(first->next, second);
        }else{
            answer = second;
            answer->next = mergeBoth(first, second->next);
        }
        
        return answer;
    }
    void mergeSorting(Node** head){
        
        Node* curr=*head;
        Node* first, *second;
        if(!curr || !curr->next){
            return;
        }
    
        findMiddle(curr, &first, &second);
    
        mergeSorting(&first);
        mergeSorting(&second);
        *head = mergeBoth(first, second);
        
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        mergeSorting(&head);
        return head;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
} 