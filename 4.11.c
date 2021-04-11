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
    ListNode* insertionSortList(ListNode* head) {
       
        if(head==NULL)return NULL;
        ListNode* p1=head->next;
        ListNode* p2Head=new ListNode;
        p2Head->next=head;
        p2Head->next->next=NULL;
        ListNode* p2=p2Head;


        while(p1)
        {
            if(p2->next)
            {
            while(p2->next)
            {
                if(p1->val<=p2->next->val)
                {
                    ListNode* temp=p2->next;
                    p2->next=p1;
                    p1=p1->next;
                    p2->next->next=temp;
                    p2=p2Head;
                    break;
                }
                else if((p1->val>p2->next->val)&&(!p2->next->next))
                {
                    p2=p2->next;
                    ListNode* temp=p2->next;
                    p2->next=p1;
                    p1=p1->next;
                    p2->next->next=temp;
                    p2=p2Head;
                    break;
                }
                else p2=p2->next;
            }
            
            }
            else
            {
                p1=p1->next;
            }
        }
        return p2Head->next;

    }
};


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        
        if((pHead&&pHead->next)&&pHead->val==pHead->next->val)
        {
            while(pHead->val==pHead->next->val)
            {
                if(pHead->next->next==NULL)
                {
                    free(pHead->next);
                    free(pHead);
                    pHead=NULL;
                    return pHead;
                }
                ListNode* temp = pHead->next;
                //delete pHead->next;
                delete pHead;
                pHead=temp;
            }
            ListNode* temp = pHead->next;
            delete pHead;
            pHead=temp;
            
        }
        if((!pHead)||!(pHead->next)) return pHead;
        ListNode* p1=pHead;
        ListNode* p2=pHead->next;
        ListNode* p3=p2->next;
        while(p3)
        {
            if(p3->val==p2->val)
            {
                
                p1->next=p3->next;
                free(p2);
                free(p3);
                p2=p1->next;
                if(p2)p3=p2->next;
                else p3=p2;
            }
            else
            {
                p1=p2;
                p2=p2->next;
                p3=p3->next;
            }
        }
        return pHead;

    }
};

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        
//         if((pHead&&pHead->next)&&pHead->val==pHead->next->val)
//         {
//             while(pHead->val==pHead->next->val)
//             {
//                 if(pHead->next->next==NULL)
//                 {
//                     free(pHead->next);
//                     free(pHead);
//                     pHead=NULL;
//                     return pHead;
//                 }
//                 ListNode* temp = pHead->next;
//                 //delete pHead->next;
//                 delete pHead;
//                 pHead=temp;
//             }
//             ListNode* temp = pHead->next;
//             delete pHead;
//             pHead=temp;
            
//         }
//         if((!pHead)||!(pHead->next)) return pHead;
//         ListNode* p1=pHead;
//         ListNode* p2=pHead->next;
//         ListNode* p3=p2->next;
//         while(p3)
//         {
//             if(p3->val==p2->val)
//             {
                
//                 p1->next=p3->next;
//                 free(p2);
//                 free(p3);
//                 p2=p1->next;
//                 if(p2)p3=p2->next;
//                 else p3=p2;
//             }
//             else
//             {
//                 p1=p2;
//                 p2=p2->next;
//                 p3=p3->next;
//             }
//         }
//         return pHead;
        if((!pHead)||!(pHead->next)) return pHead;
        ListNode* newHead =(ListNode*)malloc(sizeof(ListNode));
        newHead->next=pHead;
        ListNode* p1=newHead;
        ListNode* p2=p1->next;
        ListNode* loc=p2;
        while(p2&&p2->next)
        {

                if(p2->val==p2->next->val)
                {
                    
                    p2=p2->next;
                    loc = p2->next;
                }
            
                else
                {
                    while(p1->next!=loc)
                    {
                        ListNode* temp = p1->next->next;
                        delete p1->next;
                        p1->next=temp;
                    }
                    //p1=p2;
                    //p1=p1->next;
                    p2=p2->next;
                    loc=p2;
                }
        }
        while(p1->next!=loc)
                    {
                        ListNode* temp = p1->next->next;
                        delete p1->next;
                        p1->next=temp;
                    }
        return newHead->next;
    }
};


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
         if((!pHead)||!(pHead->next)) return pHead;
        ListNode* newHead =(ListNode*)malloc(sizeof(ListNode));
        newHead->next=pHead;
        ListNode* p1=newHead;
        
        while(p1->next)
        {
            ListNode* p2=p1->next;
            int is_change=0;
            ListNode* loc =p1->next;
            while(loc&&loc->next&&(loc->val==loc->next->val))
            {
                if(loc->val==loc->next->val)
                {
                    
                    is_change=1;
                }
                loc=loc->next;
            }
            if(is_change==1)p2=loc->next;
            
            while(p1->next!=p2)
            {
                ListNode*temp=p1->next->next;
                delete p1->next;
                p1->next=temp;
            }
            if(is_change==1)continue;
            p1=p1->next;
        }
        return newHead->next;
        

    }
};