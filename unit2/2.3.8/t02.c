void delX(LinkList &L,L int x){
    Lnode *p=L->next,*pre=L,*q;
    while(p!=NULL){
        if(p->data==x){
            q=p;
            p=p->next;
            pre->next=p;
            free(q);
        }
    }
}