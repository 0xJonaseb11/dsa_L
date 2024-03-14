
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(){};
    Node(int d){
        data = d;
        next=NULL;
    }
};
void printList(Node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int countElements(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
int main(){
    Node *n1 = new Node(10);
    Node *n2=new Node(20);
    Node *n3 = new Node(30);
    n1->next=n2;
    n2->next=n3;
    Node *head=n1;
    int numElements = countElements(head);
    cout << "The linked list has " << numElements << " elements." << endl;
    printList(head);
    return 0;
}









