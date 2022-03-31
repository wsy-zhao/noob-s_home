#include "../utils/utils.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        else if (head->next == nullptr || 0 == k){
            return head;
        }
        ListNode *point_to_tail = head, *point_to_last_n = head;
        int total_node = 0;
        for(int i = 0; i < k && point_to_tail->next != nullptr; ++i, ++total_node){
            point_to_tail = point_to_tail->next;
        }
        // whether tail node need to move
        // tail node doesnt need to move
        if(point_to_tail->next == nullptr){
            ++total_node;
            k %= total_node; // make k <= total
            if(0 == k){
                return head;
            }
            for(int i = 1; total_node - i > k; i++){
                point_to_last_n = point_to_last_n->next;
            }
        }
        // tail node need to move 
        else{
            while(point_to_tail->next != nullptr){
                point_to_last_n = point_to_last_n->next;
                point_to_tail = point_to_tail->next;
            }
        }
        ListNode * res = point_to_last_n->next;
        if (res == nullptr){
            res = head;
        }
        point_to_last_n->next = nullptr;
        point_to_tail->next = head;
        return res;
    }
};