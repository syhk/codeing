import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PrimitiveIterator;
import java.util.Queue;
import java.util.Stack;

import javax.swing.text.html.HTMLDocument.RunElement;

public class Tree1 {
	// 非递归版本遍历
	// 先序
	/*
	 * 根节点入栈，终止条件：栈不为空
	 * 1.每次从栈中弹出一个节点 car
	 * 2.打印（处理） cat
	 * 3.先右再左依次压入栈
	 * 4.重复以上操作
	 */
	public static void posOrderUnRecur1(Node head) {
		if (head == null) {
			return;
		}
		Stack<Node> nodestack = new Stack<Node>();
		nodestack.add(head);
		while (nodestack.isEmpty()) {
			head = nodestack.pop();
			System.out.println(head.value + '\t');
			if (head.right != null)
				nodestack.add(head.right);
			if (head.left != null)
				nodestack.add(head.left);
		}
	}

	// 后序
	/*
	 * 两个栈：
	 * 1.弹栈 car
	 * 2.cur放入收集栈
	 * 3.先左再右依次压入栈
	 * 4.循环执行以上操作
	 */
	public static void posOrderUnRecur2(Node head) {
		if (head == null)
			return;
		Stack<Node> s1 = new Stack<>();
		Stack<Node> s2 = new Stack<>();
		s1.push(head);
		while (!s1.isEmpty()) {
			head = s1.pop();
			s2.push(head);
			if (head.left != null)
				s1.push(head.left);
			if (head.right != null)
				s1.push(head.right);
		}
		// 打印收集栈里面的所有元素
		while (!s2.isEmpty()) {
			System.out.println(s2.pop().value + '\t');
		}
	}

	// 中序
	/*
	 * 思路：从根节点开始，一路向左走并入栈，直到走到 null
	 * 打印，把当前弹出节点的右孩子入栈，重复以上过程
	 */
	public static void posOrderUnRecur3(Node head) {
		if (head == null)
			return;
		Stack<Node> stack = new Stack<>();
		while (!stack.isEmpty() || head != null) {
			if (head != null) {
				stack.push(head);
				head = head.left; // 往左走
			} else {
				head = stack.pop();// 出栈打印
				System.out.println(head.value + '\t');
				head = head.right;// 再走到弹出节点的右孩子上
			}
		}
	}

	// 层序：利用一个队列实现
	public static void Width(Node head) {
		if (head == null)
			return;
		Queue<Node> queue = new LinkedList<>();
		// 头入队
		queue.add(head);
		while (!queue.isEmpty()) {
			Node cur = queue.poll();
			System.out.println(cur.value);
			// 先入左
			if (cur.left != null)
				queue.add(cur.left);
			// 后入右
			if (cur.right != null)
				queue.add(cur.right);
		}
	}

	// 求树的最大宽度
	public static int maxwidth(Node head) {
		if (head == null)
			return 0;
		Queue<Node> queue = new LinkedList<>();
		queue.add(head);
		HashMap<Node, Integer> levelMap = new HashMap<>();// 记录节点与对应的层次
		levelMap.put(head, 1);
		int curLevel = 1; // 当前所在层
		int curLevelNodes = 0;// 当前层的结点总数
		int max = Integer.MIN_VALUE;// Integer 的最小值 -2147483648
		while (!queue.isEmpty()) {
			Node cur = queue.poll();
			int curNodeLevel = levelMap.get(cur);
			if (curNodeLevel == curLevel) {
				curLevelNodes++;
			} else {
				max = Math.max(max, curLevelNodes);
				curLevel++;
				curLevelNodes = 1;
			}
			if (cur.left != null) {
				levelMap.put(cur.left, curNodeLevel + 1);
				queue.add(cur.left);
			}
			if (cur.right != null) {
				levelMap.put(cur.right, curNodeLevel + 1);
				queue.add(cur.right);
			}
		}
		return max;
	}

	// 如何判断一颗是否搜索二叉树 BST
	// 中序遍历的结果一定是升序的
	// 就是把中序遍历的过程中打印值的代码替换成判断是否符合条件的过程
	public static int preValue = Integer.MIN_VALUE;

	public static boolean isBST(Node head) {
		if (head == null)
			return true;
		boolean isLeftBst = isBST(head.left);
		if (!isLeftBst)
			return false;
		if (head.value <= preValue)
			return false;
		else
			preValue = head.value;
		return isBST(head.right);
	}

	// 判断一颗二叉树是否完全二叉树
	// 层序遍历：判断条件：1.任一节点有右无左 ->false
	// 2. 在满足1的条件下，如果遇到了第一个左右孩子不全，那么后面遇到的全部节点必须全部是叶子节点
	public static boolean isCBT(Node head) {
		if (head == null)
			return true;
		LinkedList<Node> queue = new LinkedList<>();
		// 是否遇到过左右两个孩子不全的节点
		boolean leaf = false;
		Node Lchild = null;
		Node Rchild = null;
		queue.add(head);
		while (!queue.isEmpty()) {
			head = queue.poll();
			Lchild = head.left;
			Rchild = head.right;
			// 进行判断
			if ((leaf && (Rchild != null && Lchild != null))// 已经发第一个孩子不双全的节点之后当前节点不是叶子节点
					|| (Lchild == null && Rchild != null)) {
				return false;
			}
		}
		// 左孩子入队
		if (Lchild != null)
			queue.add(Lchild);
		// 右孩子入队
		if (Rchild != null)
			queue.add(Rchild);
		// 判断双孩子不全
		if (Lchild == null || Rchild == null)
			leaf = true;
		return true;
	}

	// 判断一颗是否是满二叉树
	public static boolean isFull(Node head) {
		if (head == null)
			return true;
		Info data = process3(head);
		return data.nodes == ((1 << data.height) - 1);
	}

	public static Info process3(Node x) {
		if (x == null) {
			return new Info(0, 0);
		}
		Info leftData = process3(x.left);
		Info rightData = process3(x.right);
		int height;
		int nodes;
		height = Math.max(leftData.height, rightData.height) + 1;
		nodes = leftData.nodes + rightData.nodes + 1;
		return new Info(height, nodes);
	}

	public static class Info {
		public int height;
		public int nodes;

		public Info(int height, int nodes) {
			this.height = height;
			this.nodes = nodes;
		}
	}

	// 判断一颗树是否是平衡二叉树
	public static boolean isBalanced(Node head) {
		return process(head).isBalanced;
	}

	public static class ReturnType {
		public boolean isBalanced;
		public int height;

		public ReturnType(boolean b, int i) {
			isBalanced = b;
			height = i;
		}
	}

	public static ReturnType process(Node x) {
		if (x == null)
			return new ReturnType(true, 0);
		ReturnType leftData = process(x.left);
		ReturnType rightData = process(x.right);
		int height = Math.max(leftData.height, rightData.height);
		boolean isBalanced = leftData.isBalanced && rightData.isBalanced
				&& Math.abs(leftData.height - rightData.height) < 2;
		return new ReturnType(isBalanced, height);
	}

	public static class ReturnData {
		public boolean isBST;
		public int min;
		public int max;

		public ReturnData(boolean isBST, int min, int max) {
			this.isBST = isBST;
			this.min = min;
			this.max = max;
		}
	}

	public static ReturnData process2(Node x) {
		if (x == null)
			return null;
		ReturnData leftData = process2(x.left);
		ReturnData rightData = process2(x.right);
		int min = x.value;
		int max = x.value;
		if (leftData != null) {
			min = Math.min(min, leftData.min);
			max = Math.max(max, leftData.max);
		}
		if (rightData != null) {
			min = Math.min(min, rightData.min);
			max = Math.max(max, rightData.max);
		}
		boolean isBST = true;
		if (leftData != null && (!leftData.isBST || leftData.max >= x.value)) {
			isBST = false;
		}
		if (rightData != null && (!rightData.isBST || x.value >= rightData.min)) {
			isBST = false;
		}
		return new ReturnData(isBST, min, max);
	}

	// o1 和 o2 一定属于 head 为头的树
	// 返回 o1 和 o2 的最低公共祖先
	public static Node lca(Node head, Node o1, Node o2) {// Lower Common Ancestor lCA
		/**
		 * 情况： o1 和 o2 的 LCA or o2 是 o1 的 LCA or o1 与 o2 不互为 LCA 需要汇聚才能找到
		 */
		if (head == null || head == o1 || head == o2)
			return head;
		Node left = lca(head.left, o1, o2); // 遇到 o1 or o2 or null 会直接返回
		Node right = lca(head.right, o1, o2);// 遇到 o1 or o2 or null 会直接返回
		if (left != null && right != null) {
			return head;
		}
		return left != null ? left : right;
	}

	// 在二叉树中找到一个节点的后继节点(中序遍历中一个节点的后一个节点)
	public static Node getSuccessorNode(Node node) {
		if (node == null)
			return node;
		if (node.right != null) {
			return getLeftMost(node.right);
		} else { // 无右子树
			Node parent = node.parent;
			while (parent != null && parent.left != node) // 当前节点是其父亲节点右孩子
			{
				node = parent;
				parent = node.parent;
			}
			return parent;
		}
	}

	public static Node getLeftMost(Node node) {
		if (node == null)
			return node;
		while (node.left != null) {
			node = node.left;
		}
		return node;
	}

	// 二叉树的序列化和反序列化
	// 内存里面的一棵树如何变成字符串形式，如何从字符串变成内存里的树
	// 以 head 为头的树，序列化成字符串返回
	public static String serialByPre(Node head) {
		if (head == null)
			return "#_"; // #代表当前节点为 null
		String res = head.value + "_";
		res += serialByPre(head.left);
		res += serialByPre(head.right);
		return res;
	}

	// 反序列化
	public static Node reconByPreString(String preStr) {
		String[] values = preStr.split("_");
		Queue<String> queue = new LinkedList<>();
		for (var i : values) {
			queue.add(i);
		}
		return reconPreOrder(queue);
	}

	public static Node reconPreOrder(Queue<String> queue) {
		String value = queue.poll();
		if (value.equals("#"))
			return null;
		Node head = new Node(Integer.valueOf(value));
		head.left = reconPreOrder(queue);
		head.right = reconPreOrder(queue);
		return head;
	}

	/**
	 * 折纸问题：把一段纸条竖着放在桌子上，然后从纸条的下边向上方对折 1 次，压出折痕后展开
	 * 此时折痕是凹下去的，折痕突起的方向指向纸条的背面
	 * 如果从纸条的下边向上方连续对折 2 次，奉献出折痕后展开，有三条折痕
	 * 从下到下依次是下折痕，下折痕和上折痕
	 * 给定参数 N 输出从上到下打印所有折痕的方向。
	 * 
	 * @param N 纸条对折 N 次
	 */
	public static void printAllFolds(int N) {
		printProcess(1, N, true);
	}

	public static void printProcess(int i, int N, boolean down) {
		if (i > N)
			return;
		printProcess(i + 1, N, true);
		System.out.println(down ? "凹" : "凸");
		printProcess(i + 1, N, false);

	}

}

	// Morris 遍历 时间复杂度为 O(N) 额外空间复杂度为 O(1)
	public static void morris(Node head) {
		if (head == null) {
			return;
		}
		Node cur = head;
		Node mostRight = null;
		while (cur != null) {
			mostRight = cur.left;
			if (mostRight != null) {
				while (mostRight.right != null && mostRight.right != cur) {
					mostRight = mostRight.right;
				}
				// mostRight 变成了 cur 左子树上 , 最右的节点
				if (mostRight.right == null) {
					mostRight.right = cur;
					cur = cur.left;
					continue;
				} else {
					mostRight.right = null;
				}
			}
			cur = cur.right;
		}
	}
	// 特化 int
	class Node {
		int value;
		Node left;
		Node parent;
		Node right;
		public Node(Integer integer) {
			value = integer;
		}
}