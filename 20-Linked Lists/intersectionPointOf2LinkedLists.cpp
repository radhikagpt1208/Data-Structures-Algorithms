#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// This function gets two arguments - the head pointers of the two linked lists
// Return the node which is the intersection point of these linked lists
// It is assured that the two lists intersect

int getCount(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

Node* _intersectionOfTwoLinkedLists(int d,Node* l1, Node* l2){
    //Stand at the starting of the bigger list
    Node* current1 = l1;
    Node* current2 = l2;
    //move d nodes in the longer linked list
    for(int i = 0 ; i < d; i++){
        current1 = current1->next;
    }
    //move step by step in both linked lists till the intersection point is not found out
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2){
            return current1;
        }
        // Move both the pointers forward
        current1 = current1->next;
        current2 = current2->next;
    }
    return NULL;
}

Node* intersectionOfTwoLinkedLists(Node *l1, Node *l2)
{
    //1.Calculate the length of both the lists
    int cnt1 = getCount(l1);
    int cnt2 = getCount(l2);
    //2.calculate the difference of counts
    int d;
    if(cnt1 > cnt2){
        d = cnt1-cnt2;
        return _intersectionOfTwoLinkedLists(d, l1, l2);
    }
    else{
        d = cnt2-cnt1;
        return _intersectionOfTwoLinkedLists(d, l2, l1);
    }
}

/*
*
*
*   You do not need to refer or modify any code below this.
*   Only modify the above function definition.
*	Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
*	You do not even need to read or know about the code below.
*
*
*
*/

Node *buildList(unordered_map<int, Node *> &hash)
{
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *current = head;
    hash[x] = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        Node *n = new Node(x);
        hash[x] = n;
        current->next = n;
        current = n;
    }
    current->next = NULL;
    return head;
}

void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    unordered_map<int, Node *> hash;
    Node *l1 = buildList(hash);

    Node *l2 = NULL;
    int x;
    cin >> x;
    l2 = new Node(x);
    Node *temp = l2;

    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            temp->next = hash[x];
            break;
        }
        Node *n = new Node(x);
        temp->next = n;
        temp = n;
    }

    cout << "L1 - ";
    printLinkedList(l1);
    cout << "L2 - ";
    printLinkedList(l2);

    Node *intersectionPoint = intersectionOfTwoLinkedLists(l1, l2);
    cout << "Intersection at node with data = " << intersectionPoint->data << endl;

    return 0;
}
