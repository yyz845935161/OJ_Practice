/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* pre=head;
        ListNode* cur=head->next;
        while(cur)
        {
            if(pre->val==cur->val)
            {
                pre->next=cur->next;
                delete cur;
                cur=pre->next;
            }
            else
            {
                pre=pre->next;
                cur=pre->next;
            }
        }
        return head;

    }
};

链表删重，回文结构。伪装删除别

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #include<stack>
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        ListNode* temp=head;
        stack<int> s;
        //压栈
        while(temp)
        {
            s.push(temp->val);
            temp=temp->next;
        }

        temp=head;

        while(temp)
        {
            if(s.top()==temp->val)
            {
                temp=temp->next;
                s.pop();
            }
            else
            {
                return false;
            }
        }

        return true;
        


    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        ListNode* temp=node->next;
        node->next=temp->next;
        delete temp;

        
    }
};