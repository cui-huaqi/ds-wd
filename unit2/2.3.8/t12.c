//将带头节点的非递减链表中重复元素剔除
void deleteDuplicates(ListNode* head) {
    if(head==NULL||head->next++NULL){
        return ;
    }
    ListNode *p=head;//前驱伴随指针
    ListNode *q=head->next;
    while(q!=NULL){
        if(p->val==q->val){
            p->next=q->next;
            free(q);
        }
        else{
            p=q;
        }
        q=q->next;
    }
}

// 尾插法
void deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    
    struct ListNode* curr = head->next;
    struct ListNode* tail = head->next;
    
    while (curr != NULL) {
        if (curr->val != tail->val) {
            tail->next = curr;
            tail = tail->next;
        }
        
        curr = curr->next;
    }
    
    tail->next = NULL;
}