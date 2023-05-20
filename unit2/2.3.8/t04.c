//删除带头结点链表L中的元素最小值
LinkList Delte_Min(LinkList &L){
    LNode *pre=L,*p=L->next;
    LNode *minpre=pre,minp=p;
    while(p){
        if(p->data<minp->data){
            minpre=pre;
            minp=p;
            
        }
        pre=p;
        p=p->next;
    }
    minpre->next=minp->next;
    free(minp);
    return L;
}