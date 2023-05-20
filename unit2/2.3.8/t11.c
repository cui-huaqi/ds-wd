//偶数个节点的带头节点链表L，将奇数位置的节点组成新链表oddHead，偶数位置的节点逆序组成新链表evenHead
void splitList(ListNode* head, ListNode** oddHead, ListNode** evenHead) {
    ListNode* oddTail = *oddHead = new ListNode(0);
    ListNode* evenTail = *evenHead = new ListNode(0);

    while (head) {
        oddTail = oddTail->next = head;
        head = head->next;

        if (head) {
            ListNode* next = head->next;
            head->next=evenTail->next;
            evenTail->next=head;
            head = next;
        }
    }

    oddTail->next = NULL;
    evenTail->next = NULL;
}


//chatgpt 版本


#include <iostream>

// 链表节点的结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 将奇数位置的节点组成新链表oddHead，偶数位置的节点逆序组成新链表evenHead
void splitList(ListNode* head, ListNode** oddHead, ListNode** evenHead) {
    if (head == nullptr || head->next == nullptr) {
        *oddHead = nullptr;
        *evenHead = nullptr;
        return;
    }
    
    *oddHead = new ListNode(0); // 奇数位置链表的头节点
    *evenHead = new ListNode(0); // 偶数位置链表的头节点
    
    ListNode* oddNode = *oddHead;
    ListNode* evenNode = *evenHead;
    ListNode* curr = head->next;
    bool isOdd = true;
    
    while (curr != nullptr) {
        if (isOdd) {
            oddNode->next = curr;
            oddNode = oddNode->next;
        } else {
            ListNode* nextNode = curr->next;
            curr->next = evenNode->next;
            evenNode->next = curr;
            curr = nextNode;
        }
        
        isOdd = !isOdd;
        curr = curr->next;
    }
    
    oddNode->next = nullptr;
    evenNode = evenNode->next;
    delete *evenHead;
    *evenHead = evenNode;
}

// 输出链表
void printList(ListNode* head) {
    ListNode* curr = head;
    
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    
    std::cout << std::endl;
}

int main() {
    // 创建测试链表：0 -> 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    
    // 分割链表
    ListNode* oddList = nullptr;
    ListNode* evenList = nullptr;
    splitList(head, &oddList, &evenList);
    
    // 输出奇数位置节点的新链表
    std::cout << "Odd Nodes List: ";
    printList(oddList);
    
    // 输出逆序偶数位置节点的新链表
    std::cout << "Reversed Even Nodes List: ";
    printList(evenList);
    
    return 0;
}




#include <stdio.h>
#include <stdlib.h>

// 链表节点的结构体
struct ListNode {
    int val;
    struct ListNode* next;
};

// 将奇数位置的节点组成新链表oddHead，偶数位置的节点逆序组成新链表evenHead
void splitList(struct ListNode* head, struct ListNode** oddHead, struct ListNode** evenHead) {
    if (head == NULL || head->next == NULL) {
        *oddHead = NULL;
        *evenHead = NULL;
        return;
    }
    
    *oddHead = head;
    *evenHead = head->next;
    
    struct ListNode* oddNode = *oddHead;
    struct ListNode* evenNode = *evenHead;
    struct ListNode* curr = head->next->next;
    int isOdd = 1;
    
    while (curr != NULL) {
        if (isOdd) {
            oddNode->next = curr;
            oddNode = oddNode->next;
        } else {
            evenNode->next = curr;
            evenNode = evenNode->next;
        }
        
        curr = curr->next;
        isOdd = !isOdd;
    }
    
    oddNode->next = NULL;
    evenNode->next = NULL;
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
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    
    printf("\n");
}

int main() {
    // 创建测试链表：0 -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct ListNode* head = createNode(0);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    
    // 分割链表
    struct ListNode* oddList = NULL;
    struct ListNode* evenList = NULL;
    splitList(head, &oddList, &evenList);
    
    // 输出奇数位置节点的新链表
    printf("Odd Nodes List: ");
    printList(oddList);
    
    // 输出逆序偶数位置节点的新链表
    printf("Reversed Even Nodes List: ");
    printList(evenList);
    
    return 0;
}
