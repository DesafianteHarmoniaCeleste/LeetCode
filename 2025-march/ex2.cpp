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

#include <stdio.h>
#include <stdlib.h>

//Definition of Singly-Linked list
struct ListNode{
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {} // constructor 
         ListNode(int x) : val(x), next(nullptr) {} // attributes a value to the node
         ListNode(int x, ListNode *next) : val(x), next(next) {} // attributes a value and a next value to the node
     };

/*
    This solution already considers the possibility of:
        - diferent lenghts of both lists
        - the last number being a carry
    i Had some help from Chatgpt, where i was using the construction fot returned_list wrong

    using Ifs inside the main while was a smart idea, instead of completing the rest of the list outside of the main while using 2 if's
    
    From this exercise i learned a little more about Simple-linkedLists in c++ ( i was more familiar with it in c ), and the CORRECT use of pointers.
*/
class Solution{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){

            int carry=0;
            ListNode* returned_list= new ListNode(0); // ignore the first entry, just for easy data manipulation
            ListNode* current_node= returned_list;

            while(l1|| l2|| carry){
                int sum= carry;
                if(l1){
                    sum+= l1->val;
                    l1= l1->next;
                }
                if(l2){
                    sum+= l2->val;
                    l2= l2->next;
                }
    
                carry= sum/10;
                current_node->next = new ListNode(sum%10);
                current_node= current_node->next;
            }

            return returned_list->next;
        }
    };