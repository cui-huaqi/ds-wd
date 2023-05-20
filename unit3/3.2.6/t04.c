void EnQueue(Queue &Q,ElemType &x){
    if(Q.rear->next->tag==0){
        Q.rear->next->tag=1;
        Q.rear->next->val=x;
        Q.rear=Q.rear->next;
    }
}