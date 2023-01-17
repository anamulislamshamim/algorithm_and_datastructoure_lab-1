/*
Take the linked-list class that we created in our Week 3 Lab Lecture. Add the following functions to the linked list.
int getSize() -> This function will return the number of elements in the linked-list. This function should work in O(1). For this keep track of a size variable and update it when we insert a new value in the linked-list.
int getValue(index) -> This function will return the value present in the input index. If the index is greater or equal to the size of the linked-list return -1.
void printReverse() -> This function will print the linked list in reverse order. You don’t need to reverse the linked list. Just need to print it in reverse order. You need to do this recursively. You cannot just take the elements in an array or vector and then print them in reverse order.
void swapFirst() -> This function will swap the first two nodes in the linked list. If the linked-list contains less than 2 elements then just do nothing and return.
*/
#include<bits/stdc++.h>

using namespace std;

// create a Node Class
class Node
{
public:
    int data;
    Node* next;
};
// create LinkList class
class LinkedList
{
private:
    void ReverseOrder(Node* h)
    {
        if(h==NULL)
            return;
        ReverseOrder(h->next);
        cout << h->data << " ";
    };
public:
    // create head;
    Node* head;
    // create newNodeFunction
    Node* createNewNode(int value)
    {
        Node* newNode= new Node();
        // insert value;
        newNode->data=value;
        // insert the next node address
        newNode->next=NULL;
        return newNode;
    };
    // create a LinkList constructor
    LinkedList ()
    {
        // define default value for head;
        head=NULL;
    };
    void InsertAtHead(int value)
    {
        Node* a=createNewNode(value);
        if(head==NULL)
        {
            head=a;
        }
        else
        {
            a->next=head;
            head=a;
        }
    };
    void  Traverse()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp= temp->next;
        }
    };
    void getValue(int idx){
        int sz=getSize();
        Node* gv=head;
        for(int i=0;i<sz;i++){
            if(i==idx){
                cout << head->data << "\n";
                return;
            }else{
                head=head->next;
            };
        };
        cout << "The index is out of range!" << "\n";
        return;
    };
    void printReverse()
    {
        ReverseOrder(head);
    };
    int getSize(){
        int c=0;
        Node* cNode=head;
        while(cNode!=NULL){
            c++;
            cNode=cNode->next;
        };
        return c;
    };
    void swapFirst()
    {
      if(getSize() <= 2)
            return;
      Node* one = head;
      Node* two = one->next;
      Node* two_next=two->next;
      head=two;
      two->next=one;
      one->next=two_next;
    };
};

int main()
{
    LinkedList l;
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(30);
    l.InsertAtHead(40);
    l.Traverse();
    cout << "\n";
    l.printReverse();
    cout << "\n" << l.getSize() << "\n";
    l.swapFirst();
    cout << "\n";
    l.Traverse();
    return 0;
}
