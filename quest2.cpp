/*
	链表构造
	使用的算法，有点归并排序的味道
	
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        int c = 0;
        ListNode* head = new ListNode((l1->val + l2->val) % 10);
        ListNode* tail = head;
        c = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 && l2) {
        	ListNode* node = new ListNode((l1->val + l2->val + c) % 10);
        	tail->next = node;
        	tail = node;
        	c = (l1->val + l2->val + c) / 10;
        	l1 = l1->next;
        	l2 = l2->next;
        }
        while(l1) {
        	ListNode* node = new ListNode((l1->val + c) % 10);
        	tail->next = node;
        	tail = node;
        	c = (l1->val + c) / 10;
        	l1 = l1->next;
        }
        while(l2) {
        	ListNode* node = new ListNode((l2->val + c) % 10);
        	tail->next = node;
        	tail = node;
        	c = (l2->val + c) / 10;
        	l2 = l2->next;
        }
        if(c) tail->next = new ListNode(c);
        return head;
    }
};

int main(int argc, char* argv[])
{
	Solution s;

	return 0;
}