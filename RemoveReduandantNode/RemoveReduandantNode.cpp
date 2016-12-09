// RemoveReduandantNode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

class LinkedListNode {
public:
	int val;
	LinkedListNode* next;

	LinkedListNode(int value) {
		val = value;
		next = NULL;
	}
};

LinkedListNode* insert_node_into_singly_linked_list(LinkedListNode* head, int val) {
	if (head == NULL) {
		head = new LinkedListNode(val);
	}
	else {
		LinkedListNode* iter = head;
		while (iter->next != NULL) {
			iter = iter->next;
		}
		LinkedListNode* node = new LinkedListNode(val);
		iter->next = node;
	}

	return head;
}

LinkedListNode* removeNodeWithValue(LinkedListNode* node, int value) {
	if (node == NULL)
		return node;
	else {
		if (node->val == value) {
			LinkedListNode* nodeToDelete = node;
			node = node->next;
			delete nodeToDelete;
			return removeNodeWithValue(node, value);
		}
		else {
			node->next = removeNodeWithValue(node->next, value);
			return node;
		}
	}
}

/*
* For reference:
* LinkedListNode {
*     int val;
*     LinkedListNode* next;
* };
*
* Write your code below.
*/
LinkedListNode* optimal(LinkedListNode* head) {
	LinkedListNode* node = head;
	while (node != NULL) {
		int val = node->val;
		node->next = removeNodeWithValue(node->next, val);
		node = node->next;
	}
	return head;
}

int main() {
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	int value;
	LinkedListNode* head = NULL;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> value;
		head = insert_node_into_singly_linked_list(head, value);
	}

	LinkedListNode* res = optimal(head);
	while (res != NULL) {
		fout << res->val << endl;

		res = res->next;
	}

	fout.close();
	return 0;
}