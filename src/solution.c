#include "solution.h"

static int
get_size(struct Node* root)
{
        if (!root) return 0;
        int sum = 1;
        for (int i = 0; i < root->numChildren; ++i) {
                sum += get_size(root->children[i]);
        }
        return sum;
}

static void
traverse(struct Node* root, int* res, int* size)
{
        if (!root) return;
        for (int i = 0; i < root->numChildren; ++i) {
                traverse(root->children[i], res, size);
        }
        res[(*size)++] = root->val;
}

int*
postorder(struct Node* root, int* returnSize)
{
        int* res = malloc(get_size(root) * sizeof(*res));
        int size = 0;
        traverse(root, res, &size);
        *returnSize = size;
        return res;
}
