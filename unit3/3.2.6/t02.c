void inverser(Stack &S,Queue &Q){
    while(!Q.empty()){
        x=DeQueue(Q);
        Push(S,x);
    }
    while(!empty(S)){
        x=POP(S);
        EnQueue(Q,x)
;    }
}