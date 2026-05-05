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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n=1;
        ListNode* tail=head;
        while(tail->next){
            tail=tail->next;
            n++;
        }
        int nk=k%n;
        if(nk==0 || n==1) return head;
        ListNode* rotPnt=head;
        for(int i=0;i<n-nk-1;i++){
            cout<<rotPnt->val;
            rotPnt=rotPnt->next;
        }
        ListNode* ans=rotPnt->next;
        rotPnt->next=NULL;
        tail->next=head;
        return ans; 
    }
};