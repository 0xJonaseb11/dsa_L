#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(){};
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int countElements(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
Node *addHead(Node *head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    return head;
}
Node *addTail(Node *head, int value)
{
    Node *temp=head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode=new Node(value);
    temp->next = newNode;
    return head;
}
Node* UserData(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data != -1){
        Node *n=new Node(data);
        if(head==NULL){
            head=n;
            tail=n;
        }else{
            n -> next = head;
            head =n;
        }
        cin>>data;
    }
    return head;
}
int main()
{
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    n1->next = n2;
    n2->next = n3;
    Node *head = n1;
    int numElements = countElements(head);
    cout << "The linked list has " << numElements << " elements." << endl;
    addTail(n1, 100);
    printList(head);

    // Node *head=UserData();
    // print(head);
    return 0;
}











