//带头节点的单链表,递增输出元素
void printList(LinkList L)
{
    LNode *p = L->next;
    while (p)
    {
        Node *q=q->next;
        int minNow=p->data;
        while (q)
        {
            
            if(q->data<p->data){
                swap(p->data,q->data);
            }
            q=q->data;

        }
        
        printf("%d ", p->data);
        p = p->next;
    }
}

//也可以不使用插入排序，找到最小的节点后，输出后直接删除。