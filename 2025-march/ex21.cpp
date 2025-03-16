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
#include <iostream>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

/*

*/


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        // variable declarations

    ListNode* returned_list = new ListNode();
    ListNode* current_node = returned_list;

    while(list1 && list2){
        if (list1->val <= list2->val){
            current_node->next= list1;
            list1= list1->next;
        }
        else{
            current_node->next = list2;
            list2 = list2->next;
        }
        current_node = current_node->next;
    }

    if(list1){
        current_node->next = list1;
    }
    if(list2){
        current_node->next = list2;
    }
            
    return returned_list->next;
}

// Função auxiliar para imprimir a lista
void printList(ListNode* head){
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Teste
int main(){
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = mergeTwoLists(l1, l2);
    printList(result); // Output: 7 0 8

    return 0;
}
