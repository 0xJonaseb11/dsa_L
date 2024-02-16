


#include <iostream>
using namespace std;
struct Node{
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
int main(){
    Node *n1 = new Node(10);
    cout<<n1->data<<endl;
    Node *n2=new Node(20);
    cout<<n2->data<<endl;
    Node *n3 = new Node(30);
    cout<<n3->data<<endl;
    n1->next=n2;
    n2->next=n3;
    Node *head=n1;
    printList(head);
    return 0;
}







