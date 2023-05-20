//递归求二叉树高度

int high(Tree &root){
    if(root==NULL){
        return 0;
    }
    int lefthigh=high(root->left);
    int righthigh=high(root->right);
    if(lefthigh>righthigh){
        return lefthigh+1;
    }
    else{
        return righthigh+1;
    }
}

//非递归
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

// 层序遍历计算二叉树层数
int level_order(Node* root) {
    if (!root) {
        return 0;
    }
    Node* queue[1000]; // 假设二叉树节点数不超过1000
    int front = 0, rear = 0, depth = 0;
    queue[rear++] = root;
    while (front != rear) {
        depth++; // 每遍历完一层节点，深度加1
        int level_size = rear - front; // 当前层节点数
        for (int i = 0; i < level_size; i++) {
            Node* node = queue[front++];
            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }
    }
    return depth;
}

int main() {
    // 构造一棵二叉树并计算层数
    Node* root = (Node*)malloc(sizeof(Node));
    root->val = 1;
    root->left = (Node*)malloc(sizeof(Node));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (Node*)malloc(sizeof(Node));
    root->right->val = 3;
    root->right->left = (Node*)malloc(sizeof(Node));
    root->right->left->val = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (Node*)malloc(sizeof(Node));
    root->right->right->val = 5;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    int depth = level_order(root);
    printf("The depth of the binary tree is %d\n", depth);

    return 0;
}