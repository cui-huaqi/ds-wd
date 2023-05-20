//将带头节点的链表分解为两个链表，一个链表中含有原链表中序号为奇数的元素，另一个链表中含有原链表中序号为偶数的元素，且保持原有顺序。
//例如，原链表为：1 2 3 4 5 6 7 8 9 10，分解后的两个链表分别为：1 3 5 7 9 和 2 4 6 8 10。
//要求：分解后的两个链表均带头节点，且利用原链表中的节点空间，即不另外申请存储空间。
//函数原型：void split(LinkList &L, LinkList &L1, LinkList &L2);
//思路:遍历链表，每个周期第一次next给L1,如果L1当前节点next不为空（L还有后余),将第二次的next给L2

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void splitList(ListNode* head, ListNode** oddHead, ListNode** evenHead) {
    ListNode* oddTail = *oddHead = new ListNode(0);
    ListNode* evenTail = *evenHead = new ListNode(0);

    int i = 1;
    while (head) {
        if (i % 2 == 1) {
            oddTail = oddTail->next = head;
        }
        else {
            evenTail = evenTail->next = head;
        }

        head = head->next;
        i++;
    }

    oddTail->next = NULL;
    evenTail->next = NULL;
}

// 测试代码
int main() {
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for (int i = 1; i <= 10; i++) {
        p = p->next = new ListNode(i);
    }

    ListNode* oddHead, * evenHead;
    splitList(head, &oddHead, &evenHead);

    cout << "Odd: ";
    for (p = oddHead->next; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;

    cout << "Even: ";
    for (p = evenHead->next; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;

    return 0;
}
/*解释一下上面的代码，splitList() 函数接收一个带头节点的链表 head，以及两个指向 ListNode* 的指针 oddHead 和 evenHead，分别指向存储奇数元素的链表头节点和存储偶数元素的链表头节点。函数的实现过程如下：

用 oddTail 和 evenTail 分别指向两个新建的空的链表头节点 oddHead 和 evenHead。
遍历链表 head，记录当前节点的序号 i。
如果 i 是奇数，则将当前节点插入到 oddTail 的尾部，并将 oddTail 指向插入的节点。
如果 i 是偶数，则将当前节点插入到 evenTail 的尾部，并将 evenTail 指向插入的节点。
遍历完成后，将 oddTail 和 evenTail 的 next 指针设为 NULL，分别断开两个链表的尾部。
最后，我们在 main() 函数中创建一个带头节点的链表，并调用 splitList() 函数将其分解为奇偶两个链表，然后遍历输出两个链表的元素。

注意，在以上代码中，我们使用了指向指针的指针（即 ListNode** 类型），这是因为我们需要修改 oddHead 和 evenHead 的指向，以便将其指向新建的链表头节点。


不使用模2判断奇偶，在每次循环的时候第一次next*/

//
//你可以在循环中每次向前移动两个节点，这样第一次next会指向奇数位置，第二次next会指向偶数位置。这种方法无需使用模2操作判断奇偶。

void splitList(ListNode* head, ListNode** oddHead, ListNode** evenHead) {
    ListNode* oddTail = *oddHead = new ListNode(0);
    ListNode* evenTail = *evenHead = new ListNode(0);

    bool isOdd = true;
    while (head) {
        if (isOdd) {
            oddTail = oddTail->next = head;
        }
        else {
            evenTail = evenTail->next = head;
        }

        head = head->next;
        isOdd = !isOdd;
    }

    oddTail->next = NULL;
    evenTail->next = NULL;
}
//在这个实现中，我们用 isOdd 记录当前节点是否为奇数位置，每次循环结束后将其取反，以此保证下一个节点被插入到正确的链表中。


//你可以在循环中每次向前移动两个节点，这样第一次next会指向奇数位置，第二次next会指向偶数位置。这种方法无需使用模2操作判断奇偶。
void splitList(ListNode* head, ListNode** oddHead, ListNode** evenHead) {
    ListNode* oddTail = *oddHead = new ListNode(0);
    ListNode* evenTail = *evenHead = new ListNode(0);

    while (head) {
        oddTail = oddTail->next = head;
        head = head->next;

        if (head) {
            evenTail = evenTail->next = head;
            head = head->next;
        }
    }

    oddTail->next = NULL;
    evenTail->next = NULL;
}
//在这个实现中，我们同时维护奇数链表的尾指针 oddTail 和偶数链表的尾指针 evenTail，每次循环时先将当前节点插入到奇数链表中，然后再判断下一个节点是否存在，如果存在就将其插入到偶数链表中。这样可以保证每次循环时插入节点的位置正确。