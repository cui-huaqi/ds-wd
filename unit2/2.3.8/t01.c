void delX(LinkList *L,int x){
    if(LinkList==NULL )
        return ;
    if(L->data==x){
        LinkList *p;
        p=L;
        L=L->next;
        free(p);
        return delX(L,x);
    }
    else{
        return delX(L,x);
    }
}