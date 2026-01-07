#include "solution.h"

enum { MOD = (int)1e9 + 7 };

static int
build_partial_sum(struct TreeNode* root)
{
        if (!root) return 0;
        return root->val +=
               build_partial_sum(root->left) + build_partial_sum(root->right);
}

int
maxProduct(struct TreeNode* root)
{
        build_partial_sum(root);
        int const total = root->val;
        long max        = LONG_MIN;
        printf("total: %d\n", total);
        void traverse(struct TreeNode * root)
        {
                if (!root) return;
                if (root->left) {
                        long const left    = (long)root->left->val;
                        long const rest    = total - left;
                        long const product = left * rest;
                        printf(
                            "left subtree:   left=%ld, rest=%ld, "
                            "product=%ld\n",
                            left, rest, product);
                        if (product > max) max = product;
                        traverse(root->left);
                }
                if (root->right) {
                        long const right   = (long)root->right->val;
                        long const rest    = total - right;
                        long const product = right * rest;
                        printf(
                            "right subtree: right=%ld, rest=%ld, "
                            "product=%ld\n",
                            right, rest, product);
                        if (product > max) max = product;
                        traverse(root->right);
                }
        }
        traverse(root);
        return max % MOD;
}
