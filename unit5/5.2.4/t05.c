//求顺序存储的二叉树编号为i,j的两节点最近的公共祖先节点的值
#include <stdio.h>

#define MAX_SIZE 100

// 求编号为i,j的两个节点的最近公共祖先节点的值
int getLowestCommonAncestor(int tree[], int n, int i, int j) {
    int path_i[MAX_SIZE], path_j[MAX_SIZE];
    int index_i = 0, index_j = 0;
    int p = i, q = j;
    
    while (p != 1) { // 构造i的路径
        path_i[index_i++] = p;
        p /= 2;
    }
    path_i[index_i++] = 1;
    
    while (q != 1) { // 构造j的路径
        path_j[index_j++] = q;
        q /= 2;
    }
    path_j[index_j++] = 1;
    
    // 从下往上找最近公共祖先节点
    while (index_i >= 0 && index_j >= 0) {
        if (path_i[index_i] == path_j[index_j]) {
            return tree[path_i[index_i]];
        } else if (path_i[index_i] > path_j[index_j]) {
            index_i--;
        } else {
            index_j--;
        }
    }
    
    return -1; // 未找到公共祖先节点
}

int main() {
    int tree[] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // 顺序存储的二叉树
    int n = 10; // 节点数
    int i = 6, j = 9; // 节点编号
    
    int result = getLowestCommonAncestor(tree, n, i, j);
    if (result != -1) {
        printf("节点%d和节点%d的最近公共祖先节点为%d\n", i, j, result);
    } else {
        printf("节点%d和节点%d没有公共祖先节点\n", i, j);
    }
    
    return 0;
}




//常用递归求解

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;



// 递归求解二叉树中两个节点的最近公共祖先节点
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
    
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    
    if (left != NULL && right != NULL) {
        return root;
    } else if (left != NULL) {
        return left;
    } else {
        return right;
    }
}

// 创建二叉树节点
TreeNode* createTreeNode(int val) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    TreeNode *root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right(TreeNode*)malloc(sizeof(TreeNode));
    root->left->right->val = 5;
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(7);
    TreeNode *p = root->left->left;
    TreeNode *q = root->left->right;
    
    TreeNode *result = lowestCommonAncestor(root, p, q);
    if (result != NULL) {
        printf("节点%d和节点%d的最近公共祖先节点为%d\n", p->val, q->val, result->val);
    } else {
        printf("节点%d和节点%d没有公共祖先节点\n", p->val, q->val);
    }
    
    return 0;
}