/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil || head.Next.Next == nil {
        return head
    }

    firstEven := head.Next
    odd, even := head, firstEven
    for even != nil && even.Next != nil {
        odd.Next = odd.Next.Next
        odd = odd.Next

        even.Next = even.Next.Next
        even = even.Next
    }
    odd.Next = firstEven

    return head
}