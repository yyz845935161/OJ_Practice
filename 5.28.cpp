/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>v;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
        {
            return v;
        }
        v.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return v;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int left=maxDepth(root->left)+1;
        int right=maxDepth(root->right)+1;
        return left>right ? left:right;

    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int absolute(int v1,int v2)
    {
        if(v1>v2)
        {
            return v1-v2;
        }
        else
        {
            return v2-v1;
        }
    }

    int hight(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=hight(root->left)+1;
        int right=hight(root->right)+1;
        return left>right ? left:right;

    }


    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        int left=hight(root->left);
        int right=hight(root->right);
        if (absolute(left,right)>1)  
        {
            return false;
        }
        if(isBalanced(root->left)==false||isBalanced(root->right)==false)
        {
            return false;
        }
        return true;
    }




};

#include<stdio.h>
#include<stdlib.h>


typedef struct TreeNode 
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}TNode;

void InOrder(TNode* root)
{
    if(root==NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%C ",root->val);
    InOrder(root->right);
}

TNode* CreateTree(char* a,int *pi)
{
    if(a[*pi]=='#')
    {
        ++(*pi);
        return NULL;
    }
    
    TreeNode* root=(TNode*)malloc(sizeof(TNode));
    if(root==NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    root->val=a[*pi];
    ++(*pi);
    root->left=CreateTree(a, pi);
    root->right=CreateTree(a,pi);
    return root;
}

int main()
{
    char str[100];
    scanf("%s",str);
    int i =0;
    TNode* root = CreateTree(str,&i);
    InOrder(root);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)
        {
            return v;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int currentSize = q.size();
            vector<int>vv;
            for(int i =0;i<currentSize;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                vv.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            v.push_back(vv);
            vv.clear();   
        }
        return v;

    }
};