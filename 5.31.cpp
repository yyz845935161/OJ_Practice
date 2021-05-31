class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for(int i =0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        return v;
        }
    };


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            int temp=0;
            for(int j=i;j<nums.size();j++)
            {
                temp+=nums[j];
                if(temp>max) max=temp;
            }
        }
        return max;

    }
};


class Solution {
public:
    int climbStairs(int n) {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        for(int i=2;i<n;i++)
        {
            v.push_back(v[i-1]+v[i-2]);
        }
        return v[n-1];

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
    void InOrder(TreeNode* root,vector<int>& v)
    {
        if(root==NULL)
        {
            return;
        }
        InOrder(root->left,v);
        v.push_back(root->val);
        InOrder(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        InOrder(root,v);
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
    bool isSymmetric(TreeNode* root) {
       return ismMirror(root,root);
    }
    bool ismMirror(TreeNode* l,TreeNode*r)
    {
        if(!l&&!r)return true;
        if(!l||!r)return false;
        if(l->val==r->val)
            return ismMirror(l->left,r->right)&&ismMirror(l->right,r->left);
        return false;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        for(int i=0;i<prices.size();i++)
        {
            int temp=0;
            for(int j=i+1;j<prices.size();j++)
            {
                temp=prices[j]-prices[i];
                if(temp>max)max=temp;
            }
        }
        return max;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        int min=0;
        if(!prices.empty()) min=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            min = min<prices[i]?min:prices[i];
            max= max>(prices[i]-min)?max:(prices[i]-min);
        }
        return max;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        for(int i=1;i<nums.size();i++)
        {
            nums[i]=nums[i-1]^nums[i];
        }
        return nums.back();
    }
};

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> s_min;
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        if(s.empty())
        {s_min.push(val);}
        else{
        if(val>s_min.top())s_min.push(val);}
    }
    
    void pop() {
        if(s.top()==s_min.top())s_min.pop();
        s.pop();

    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s_min.top();

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1)return nums.back();
        int t=nums[0];
        int index=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==t)
            {
                index++;
            }
            else {
                index--;
                if(index<0){
                    t=nums[i]; index=0;}
            }
        }
        return t;
    }
};