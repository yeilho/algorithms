#include <iostream>
using namespace std;

struct node {
    char data;
    struct node *next;
    node(char _data) {
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

void print_list(node *head)
{
    node *cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int palindrome(node **head, node *cur)
{
    int ret = 1;
    if (cur) {
        ret = palindrome(head, cur->next);
        if (cur->data != (*head)->data) {
            cout << cur->data << "-" << (*head)->data << ": not a palindrome" << endl;
            ret = 0;
        }
        *head = (*head)->next;
    }
    return ret;
}

int main(int argc, char *argv[])
{
    node *head = NULL;
    for (int i = 0; i < 10; i++) {
        list_insert(&head, 'a' + i);
    }
    for (int i = 9; i >= 0; i--) {
        list_insert(&head, 'a' + i);
    }
    print_list(head);

    node *tmp = head;
    int ret = palindrome(&tmp, head);

    cout << "palindrom result: " << ret << endl;
    print_list(head);

    return 0;
}

