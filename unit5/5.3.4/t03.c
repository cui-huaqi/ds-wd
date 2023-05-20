//后续遍历非递归
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct StackNode {
    struct TreeNode* node;
    struct StackNode* next;
};

typedef struct StackNode StackNode;
typedef struct TreeNode TreeNode;

void push(StackNode** top, TreeNode* node) {
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->node = node;
    new_node->next = *top;
    *top = new_node;
}

TreeNode* pop(StackNode** top) {
    if (*top == NULL) {
        return NULL;
    }
    StackNode* temp = *top;
    TreeNode* node = (*top)->node;
    *top = (*top)->next;
    free(temp);
    return node;
}

void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    StackNode* stack = NULL;
    push(&stack, root);
    TreeNode* last_visited = NULL;
    while (stack != NULL) {
        TreeNode* node = stack->node;
        if ((node->left == NULL && node->right == NULL) ||
            (、、 != NULL && (last_visited == node->left || last_visited == node->right))) {
            printf("%d ", node->val);
            pop(&stack);
            last_visited = node;
        } else {
            if (node->right != NULL) {
                push(&stack, node->right);
            }
            if (node->left != NULL) {
                push(&stack, node->left);
            }
        }
    }
}