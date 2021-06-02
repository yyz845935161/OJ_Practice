class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        int v[100000]={0};
        vector<int>vr;
        for(int i=1;i<=nums.size();i++)
        {
            v[i]=i;
        }

        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++)
        {
            v[*it]=0;
        }

        for(int i=1;i<nums.size()+1;i++)
        {
            if(v[i]!=0)vr.push_back(v[i]);
        }
        
        return vr;
    }
};


class Solution {
public:
    int OneNum(int n)
    {
        int x=0;
        while(n)
        {
            n=n&(n-1);
            x++;
        }
        return x;
    }
    int hammingDistance(int x, int y) {
        int temp=x^y;
        return OneNum(temp);

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
    int max=0;
    int diameterOfBinaryTree(TreeNode* root) {
        deep(root);
        return max;

    }
    int deep(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int left=deep(root->left);
        int right=deep(root->right);
        if(left+right>max)
        {
            max=left+right;
        }
        return left>right?left+1:right+1;
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
   
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)return root2;
        if(!root2)return root1;
        TreeNode* nTree= new TreeNode(root1->val+root2->val);
        nTree->left=mergeTrees(root1->left,root2->left);
        nTree->right=mergeTrees(root1->right,root2->right);
        return nTree;

    }
};