#include "solution.h"

int
findSecondMinimumValue(struct TreeNode* root)
{
        int min    = root->val;
        int second = -1;
        void traverse(struct TreeNode * root)
        {
                if (!root) return;
                if (root->val > min) {
                        if (second == -1 || root->val < second) {
                                second = root->val;
                        }
                        return;
                }
                traverse(root->left);
                traverse(root->right);
        }
        traverse(root);
        return second;
}
