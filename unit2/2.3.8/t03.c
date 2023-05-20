#include <stdio.h>
#include <stdlib.h>
typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode,LinkList;

void Init_list(LinkList *head)
{
    LinkList *L = head;
    int n = 6;
    while (n--)
    {
        int x;
        scanf("%d", &x);
        LinkList *p = (LinkList *)malloc(sizeof(LinkList));
        p->data = x;
        p->next=L->next;
        L->next = p;
        L = L->next;
    }
}
void Print(LinkList *head)
{
    LinkList *p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main()
{
    LinkList *head;
    head = (LinkList *)malloc(sizeof(LinkList));
    head->next = NULL;
    Init_list(head);
    Print(head);
}