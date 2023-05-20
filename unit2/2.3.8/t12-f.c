#include <stdio.h>
#include <stdlib.h>

// 链表节点的结构体
struct ListNode {
    int val;
    struct ListNode* next;
};

// 删除带头节点的非递减链表中的重复元素
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

// 创建链表节点
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 输出链表
void printList(struct ListNode* head) {
    struct ListNode* curr = head->next;
    
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    
    printf("\n");
}

int main() {
    // 创建测试链表：0 -> 1 -> 1 -> 2 -> 3 -> 3 -> 4 -> NULL
    struct ListNode* head = createNode(0);
    head->next = createNode(1);
    head->next->next = createNode(1);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(3);
    head->next->next->next->next->next->next = createNode(4);
    
    // 删除重复元素
    deleteDuplicates(head);
    
    // 输出链表
    printList(head);
    
    return 0;
}
