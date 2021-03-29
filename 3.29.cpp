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