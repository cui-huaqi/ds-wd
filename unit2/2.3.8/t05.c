//逆转链表 空间O(1)
//递归反转
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* newL=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newL;
    }
};


 //双指针，快指针把指针给满指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur=NULL,*pre=head;
        while (pre != NULL) {
            ListNode* p=pre->next;//保存下一个节点
            pre->next=cur; //将指向下一个节点的指针指向后方
            cur=pre;  //满指针向后移动
            pre=p;    //快指针向后移动
        }
        return cur;

    }
};


//正常遍历，头插反转
