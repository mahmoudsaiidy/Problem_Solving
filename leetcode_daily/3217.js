/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {number[]} nums
 * @param {ListNode} head
 * @return {ListNode}
 */
var modifiedList = function(nums, head) {
    const numSet = new Set(nums);

    let dummy = new ListNode(0);
    dummy.next = head;
    let cur = dummy;

    while (cur.next !== null) {
        if (numSet.has(cur.next.val)) {
            cur.next = cur.next.next;
        } else {
            cur = cur.next;
        }
    }
    return dummy.next;
};
