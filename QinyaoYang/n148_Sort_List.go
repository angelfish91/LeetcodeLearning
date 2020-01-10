package main

import . "LeetcodeLearning/utils"

//方法一: 快排：Time：O(nlogn)，Space:O(n)
func sortList(head *ListNode) *ListNode {
	quickSort(head, nil)
	return head
}

func quickSort(head, end *ListNode) {
	if head == end || head.Next == end {
		return
	}

	pivot := head.Val
	slow, fast := head, head.Next
	for fast != end {
		if fast.Val <= pivot {
			slow = slow.Next
			slow.Val, fast.Val = fast.Val, slow.Val
		}
		fast = fast.Next
	}

	slow.Val, head.Val = head.Val, slow.Val

	quickSort(head, slow)
	quickSort(slow.Next, end)
}

//方法二：归并排序：Time：O(nlogn)，Space:O(logn)
func sortList1(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head //注意递归的终止条件，返回的是head不是nil
	}

	slow, fast := head, head
	for fast.Next != nil && fast.Next.Next != nil { //注意此处的条件判定！！！！！
		slow = slow.Next
		fast = fast.Next.Next
	}

	right := sortList1(slow.Next)
	slow.Next = nil
	left := sortList1(head)
	return mergeTwoList(left, right)
}

func mergeTwoList(l1, l2 *ListNode) *ListNode {
	res := &ListNode{}
	cur := res

	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			cur.Next = l1
			l1 = l1.Next
		} else {
			cur.Next = l2
			l2 = l2.Next
		}
		cur = cur.Next
	}

	if l1 != nil {
		cur.Next = l1
	}

	if l2 != nil {
		cur.Next = l2
	}

	return res.Next
}
