#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* build(int *pre, int rootIdx, int *inorder, int end)
{
    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));


    int rootInInorder = rootIdx;
    while(rootInInorder <= end){
        if(pre[rootIdx] == inorder[rootInInorder])
            break;
        ++rootInInorder;
    }

    root->left = build(pre+1, ++rootIdx, inorder, rootInInorder);
    root->right = build(pre+rootInInorder+1, rootInInorder+1, inorder+rootInInorder+1, end);


    return root;
}

TreeNode* rebuild_tree(int *pre, int *inorder, int len)
{
    if(pre == NULL || inorder == NULL || len <= 0)
        return NULL;

    return build(pre, len, inorder, len);
}


