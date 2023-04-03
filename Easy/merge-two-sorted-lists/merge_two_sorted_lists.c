#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
	struct ListNode *merged = NULL;
	struct ListNode *mergedStart;

	if (!list1)
		return list2;
	if (!list2)
		return list1;
	while (list1 && list2)
	{
		struct ListNode *node = NULL;
		if (list1->val <= list2->val)
		{
			node = list1;
			list1 = list1->next;
		}
		else
		{
			node = list2;
			list2 = list2->next;
		}
		if (merged == NULL)
		{
			merged = node;
			mergedStart = merged;
		}
    else
		{
			merged->next = node;
			merged = merged->next;
    }
	}
	if (list1)
		merged->next = list1;
	if (list2)
		merged->next = list2;
	return (mergedStart);
}