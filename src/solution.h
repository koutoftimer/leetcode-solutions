#pragma once

//
// "Library" section
//

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi2,mmx,sse2,sse3,sse4")

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <setjmp.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uthash.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define typeof __typeof
#define static_assert _Static_assert
#define da_append(array, value)                                             \
        do {                                                                \
                static_assert(_Generic(array.size, size_t: 1, default: 0)); \
                static_assert(                                              \
                    _Generic(array.capacity, size_t: 1, default: 0));       \
                static_assert(                                              \
                    _Generic(*array.items, typeof(value): 1, default: 0));  \
                if (array.items == NULL) {                                  \
                        array.size     = 0;                                 \
                        array.capacity = 10;                                \
                        array.items =                                       \
                            malloc(sizeof(*array.items) * array.capacity);  \
                }                                                           \
                if (array.size + 1 > array.capacity) {                      \
                        array.capacity *= 2;                                \
                        array.items =                                       \
                            reallocarray(array.items, array.capacity,       \
                                         sizeof(*array.items));             \
                }                                                           \
                array.items[array.size++] = value;                          \
        } while (0)

struct ListNode {
        int val;
        struct ListNode* next;
};

struct TreeNode {
        int val;
        struct TreeNode* left;
        struct TreeNode* right;
};

static struct TreeNode*
add_node_into_the_tree(struct TreeNode* root, int* value)
{
        (void)root;
        (void)value;
        return NULL;
}

[[gnu::unused]]
static struct TreeNode*
make_tree(int* values, int size)
{
        struct TreeNode* root = NULL;
        for (int i = 0; i < size; ++i) {
                add_node_into_the_tree(root, &values[i]);
        }
        return root;
}

//
// Leetcode declaration goes below
//

char* reverseStr(char* s, int k);
