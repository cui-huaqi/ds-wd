//寻找两个链表的公共交叉节点
LinkList* findY(LinkList *L1,LinkList *L2){
    LinkList*p=L1;
    int len1=0;
    while(p->next=NULL){
        p=p->next;
        len1++;
    }
    int len2=0;
    p=L2;
    while(p->next!=null){
        p=p->next;
        len2++;
    }
    if(len1>len2){
        return find(L1,L2,len1-len2);
    }
    else{
        return find(L2,L1,len2-len1);
    }

}
LinkList* find(LinkList*L1,LinkList*L2,k){
    LinkList*fast=L1;
    LinkList *low=L2;
    while(k--){
        fast=fast->next;
    }
    while(fast&&low){
        if(fast->data==low->data){//易错点，如果两链表元素没有重复可以这么写，判断是否是同一节点：找他们的地址。
            return fast;
        }
        fast=fast->next;
        low=low->next;
    }
    return NULL;
}