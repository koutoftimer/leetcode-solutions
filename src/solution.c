#include "solution.h"

struct Stack {
        struct TreeNode* items[200];
        int size;
};
#define stack_push(stack, value) (stack)->items[(stack)->size++] = (value);
#define stack_pop(stack) (stack)->items[--(stack)->size]

#define is_leaf(root) (!(root)->left && !(root)->right)

static int
traverse(struct Stack* stack)
{
        for (;;) {
                struct TreeNode* root = stack_pop(stack);
                if (root->right) stack_push(stack, root->right);
                if (root->left) stack_push(stack, root->left);
                if (is_leaf(root)) return root->val;
        }
}

bool
leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
        struct Stack stack1 = {0}, stack2 = {0};
        stack_push(&stack1, root1);
        stack_push(&stack2, root2);
        while (stack1.size && stack2.size) {
                int const leaf1 = traverse(&stack1);
                int const leaf2 = traverse(&stack2);
                if (leaf1 != leaf2) return false;
        }
        return !stack1.size && !stack2.size;
}
