struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *headAStart = headA;
    struct ListNode *headBStart = headB;

    while (headA != headB)
    {
        if (!headA)
            headA = headBStart;
        else
            headA = headA->next;
        if (!headB)
            headB = headAStart;
        else
            headB = headB->next;
    }
    return (headA);
}
