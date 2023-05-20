//从右下开始的层序遍历
//出兑的时候入栈
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    // 创建队列
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
    int front = 0, rear = 0;
    // 根结点入队
    queue[rear++] = root;
    while (front < rear) {
        // 取出队首结点
        struct TreeNode* node = queue[front++];
        // 访问结点值
        printf("%d ", node->val);

        stack[front-1]=node;


        // 将左右子结点入队
        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }

    while(!empty(stack)){
        printf("%d",stack[i--]);
    }
    free(queue); // 释放队列空间
}
