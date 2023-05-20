//使循环队列中所有元素都可用，设置tag
int inputqueue(SqQueue &Q,ElemType x){
    if(Q.front==Q.rear&&tag==1){
        return 0;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%Q.Maxsize;
    Q.tag=1;
    return 1;
}
int DeQueue(SqQueue &Q,ElemType &x){
    if(Q.front==Q.rear&&Q.tag==0){
        return 0;
    }
    x=Q.data[Q.rear];
    Q.front=Q.front+1 % Q.Maxsize;
    Q.tag=0;
    return 1;
}