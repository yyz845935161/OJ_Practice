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
    void invertT(TreeNode* root)
    {
        if(!root)return;
        TreeNode* temp=NULL;
        temp=root->right;
        root->right=root->left;
        root->left=temp;
        invertT(root->right);
        invertT(root->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        invertT(root);
        return root;
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero=0;
        int size=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zero++;
            }
            else
            {
                nums[i-zero]=nums[i];
            }
        }

        for(int i=0;i<zero;i++)
        {
            nums[size-i-1]=0;
        }

    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        v.push_back(0);
        for(int i=1;i<=n;i++)
        {
            v.push_back(v[(i&(i-1))]+1);

        }
        return v;
    }
};