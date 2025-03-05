/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    if (head === null) return null;

    const len = getLength(head);
    if (n === len) return head.next;

    let curr = head, prev = null;
    for (let i = 1; i < len - n + 1; i++) {
        prev = curr;
        curr = curr.next;
    }
    prev.next = curr.next;

    return head;
};

function getLength(head) {
    let len = 0;
    let node = head;
    while (node != null) {
        len++;
        node = node.next;
    }
    return len;
}