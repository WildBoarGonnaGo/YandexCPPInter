//
//  addTwoNumbers.cpp
//  inter
//
//  Created by WildBoarGonnaGo on 11.05.2023.
//

#include <iostream>
#include <list>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void DeleteList(ListNode **src) {
	while ((*src)->next) {
		ListNode *del = *src;
		(*src) = (*src)->next;
		delete del;
		del = nullptr;
	}
	delete *src;
	*src = nullptr;
}

ListNode *newLst(const list<int> &src) {
	ListNode *res = nullptr;
	ListNode *prev;

	for (auto var : src) {
		if (!res) {
			res = new ListNode(var);
			prev = res;
		} else {
			prev->next = new ListNode(var);;
			prev = prev->next;
		}
	}
	return res;
}

void ListOutput(ListNode *src) {
	cout << "[";
	while (src) {
		cout << src->val << ((src->next != nullptr) ? "," : "");
		src = src->next;
	}
	cout << "]" << endl;
}

class Solution {
	void ListPush(ListNode **res, ListNode **prev, const int &val) {
		if (!*res) {
			*res = new ListNode(val);
			*prev = *res;
		} else {
			(*prev)->next = new ListNode(val);
			(*prev) = (*prev)->next;
		}
	}
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		list<int> f, s;
		ListNode *res = nullptr;
		ListNode *prev;
		int sum;

		bool add = false;
		while (l1 || l2 || add) {
			sum = ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0) + add;
			add = sum / 10;
			ListPush(&res, &prev, sum % 10);
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		return res;
	}
};

void AddTwoNumbersTest(const list<int> &f, const list<int> &s) {
	Solution sol;

	ListNode *l1 = newLst(f);
	ListNode *l2 = newLst(s);
	cout << "List 1 (test 1): "; ListOutput(l1);
	cout << "List 2 (test 1): "; ListOutput(l2);
	ListNode *res = sol.addTwoNumbers(l1, l2);
	cout << "Result list: "; ListOutput(res);
	DeleteList(&l1); DeleteList(&l2); DeleteList(&res);
	cout << endl;
}

int main(void) {
	AddTwoNumbersTest({2,4,3}, {5,6,4});
	AddTwoNumbersTest({0}, {0});
	AddTwoNumbersTest({9,9,9,9,9,9,9}, {9,9,9,9});
	AddTwoNumbersTest({9}, {1,9,9,9,9,9,9,9,9,9});
	AddTwoNumbersTest({1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, {5,6,4});
	return 0;
}
