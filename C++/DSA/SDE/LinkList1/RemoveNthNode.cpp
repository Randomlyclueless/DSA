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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // BRUTE FORCE
        //     if(head == NULL){
        //         return NULL;
        //     }
        //     int count = 0;
        //     ListNode* temp = head;
        //     while(temp!=NULL){
        //         count++;
        //         temp = temp->next;
        //     }
        //     if(count == n){
        //         ListNode* newHead = head->next;
        //         delete head;
        //         return newHead;
        //     }

        //     int res = count - n;
        //     temp=head;
        //     while(temp!=NULL){
        //         res--;
        //         if(res == 0){
        //             break;
        //         }
        //         temp=temp->next;
        //     }
        //     ListNode* delNode = temp->next;
        //     temp->next = temp->next->next;
        //     delete delNode;
        //     return head;
        // }

        // OPTIMAL SOlUTION
        // totoise and hare method

        ListNode *dummy = new ListNode(0, head);
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};