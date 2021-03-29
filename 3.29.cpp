#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

struct ListNode {
    int val;
    struct ListNode *next;
  //  ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        // write code here
        if (pHead == NULL) return pHead;
        if ((pHead->next) == NULL) return pHead;


        struct ListNode* pp = (struct ListNode*)malloc(sizeof(struct ListNode));
        pp->next = pHead;
        pHead = pp;
        struct ListNode* p2 = pHead->next;
        struct ListNode* p1 = pHead;

        while (p2)
        {
            if (p2->val < x)
            {
                if (p1 == pp)
                {
                    pp = pp->next;
                    p1 = p1->next;
                    p2 = p2->next;
                }
                else {
                    p1->next = p2->next;
                    p2->next = pp->next;
                    pp->next = p2;
                    p2 = p1->next;
                    pp = pp->next;
                }
            }
            else {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return pHead->next;
    }
};


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        if (!A) return true;

        ListNode* slow = A;
        ListNode* fast = A;
        ListNode* pre = NULL;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* n1 = pre->next;
        pre->next = NULL;
        while (n1)
        {
            ListNode* temp = n1->next;
            n1->next = pre->next;
            pre->next = n1;
            n1 = temp;
        }

        //pre=pre->next;
        slow = pre->next;
        pre->next = NULL;
        while (A)
        {
            if (A->val != slow->val)
            {
                return false;
            }
            else
            {
                A = A->next;
                slow = slow->next;
            }
        }

        return true;
    }
};