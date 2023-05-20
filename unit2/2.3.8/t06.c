//递增排序链表
//插入排序思想
void sort(LinkList *L){
    LinkList*p=L->next,*pre;
    LinkList* r=p->next;
    p->next=NULL;
    p=r;
    //以上构造一个原链表L为头结点+a1,新链表p a2,a3.....an

    while(p!=NULL){
        r=p->next;
        pre=L;
        while(  pre->next!=NULL&&pre->next->data<p->data){
            pre=pre->next;
        }
        p->next=pre->next;
        pre->next=p;
        p=r;
    }
}