package main.test.java.test;

import org.w3c.dom.Node;

public class Test1 {

	public static void main(String[] args) {

	}

	// morris 先序遍历
	public static void morris(Node head) {
		if (head == null) {
			return;
		}
		Node cur = head;
		Node mostRight = null;
		while (cur != null) {
			mostRight = cur.left; // mostRight 是 cur 左孩子
			if (mostRight != null) {// 有左孩子
				while (mostRight.right != null && mostRight.right != cur) {
					mostRight = mostRight.right;
				}
				// mostRight 变成 cur 左子树上最右的节点
				if (mostRight.right == null)// 这是第一次来到 cur
				{
					mostRight.right = cur;
					cur = cur.left;
					continue;
				} else {// mostRight.right == cur
					mostRight.right = null;
				}
			} else { // 没有左子树的情况,先序遍历就加了这里
				// 替换为自己想要的操作
				System.out.println(cur.value);
			}
			cur = cur.right;
		}
	}

	// morris 中序遍历
	// 只能到达一次的结点直接打印（处理）；能到达两次的结点第二次打印
	public static void morris(Node head) {
		if (head == null) {
			return;
		}
		Node cur = head;
		Node mostRight = null;
		while (cur != null) {
			mostRight = cur.left; // mostRight 是 cur 左孩子
			if (mostRight != null) {// 有左孩子
				while (mostRight.right != null && mostRight.right != cur) {
					mostRight = mostRight.right;
				}
				// mostRight 变成 cur 左子树上最右的节点
				if (mostRight.right == null)// 这是第一次来到 cur
				{
					mostRight.right = cur;
					cur = cur.left;
					continue;
				} else {// mostRight.right == cur
					mostRight.right = null;
				}
			}
			// 中序遍历处理逻辑在这里
			// 替换为自己想要的操作
			System.out.println(cur.value);
			cur = cur.right;
		}
	}

	static class Node {
		int data;
		Node left;
		Node right;
	}

	// morris 后序遍历
	// 只能来到一次什么也不做
	// 第二次回到某结点的时候逆序打印左树右边界
	// 最后单独逆序打印整个树的右边界
	public static void morris(Node head) {
		if (head == null) {
			return;
		}
		Node cur = head;
		Node mostRight = null;
		while (cur != null) {
			mostRight = cur.left; // mostRight 是 cur 左孩子
			if (mostRight != null) {// 有左孩子
				while (mostRight.right != null && mostRight.right != cur) {
					mostRight = mostRight.right;
				}
				// mostRight 变成 cur 左子树上最右的节点
				if (mostRight.right == null)// 这是第一次来到 cur
				{
					mostRight.right = cur;
					cur = cur.left;
					continue;
				} else {// mostRight.right == cur
					mostRight.right = null;
					// printEdge 逆序打印方法 , 可以理解为单链表的逆序操作
					printEdge(cur.left);
				}
			}
			cur = cur.right;
		}
		printEdge(head);
		System.out.println();
	}

	// morris 遍历方式判断是否是 BST
	// 树的中序遍历是升序的
	public static Boolean isBST(Node head) {
		if (head == null) {
			return true;
		}
		Node cur = head;
		Node mostRight = null;
		int preValue = Integer.MIN_VALUE;
		while (cur != null) {
			mostRight = cur.left; // mostRight 是 cur 左孩子
			if (mostRight != null) {// 有左孩子
				while (mostRight.right != null && mostRight.right != cur) {
					mostRight = mostRight.right;
				}
				// mostRight 变成 cur 左子树上最右的节点
				if (mostRight.right == null)// 这是第一次来到 cur
				{
					mostRight.right = cur;
					cur = cur.left;
					continue;
				} else {// mostRight.right == cur
					mostRight.right = null;
				}
			}
			// 中序遍历处理逻辑在这里
			if (cur.data <= preValue) {
				return false;
			}
			preValue = cur.data;
			cur = cur.right;
		}
		return true;
	}

	
	



};