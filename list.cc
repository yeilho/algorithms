nclude <iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
    node(int _data) {
        data = _data;
        next = NULL;
    }
};

void list_insert(node **head, int data)
{
    node *tmp = new node(data);
    tmp->next = *head;
    *head = tmp;
}

node *rec_reverse(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    node *second = head->next;
    node *rest = list_reverse(second);
    second->next = head;
    head->next = NULL;

    return rest;
}

node *iter_reverse(node **head)
{
    node *tmp;
    node *cur = *head;
    node *prev = NULL;

    if (cur == NULL) {
        return NULL;
    }
    if (cur->next == NULL) {
        return cur;
    }
    while (cur) {
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }

    return ;
}

int main(int argc, char *argv[])
{
    node *head = NULL;
    for (int i = 0; i < 10; i++) {
        list_insert(&head, i);
    }
    node *cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

    head = rec_reverse(head);
    cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}

