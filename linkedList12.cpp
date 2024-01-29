#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    Node *next;
};

void deleteNext(Node* p) {
    Node* next = p->next;
    p->next = next->next;  // noi tat , bo qua nut tiep theo
    delete next;
}

bool duplicate(Node *head, Node *ptr)  //ptr co lap hay khong
{
    for (Node* p = head; p!=NULL && p!= ptr; p = p->next)
        if (p->value == ptr->value) return true;
    return false;
}

Node* deleteDuplicates(Node* head) {
    Node* p = head;
    while (p->next != NULL) {
        if (duplicate(head, p->next)) deleteNext(p);
        else p = p->next;
    }
}

int main()
{
    int* p = new int[10];
    delete (p+1);
}
