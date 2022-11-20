package main.test.java.graph;

import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;

public class Test1 {

	// BFS
	/**
	 * 1.利用队列实现
	 * 2.从 node 开始依次按照宽度进队列，然后弹出
	 * 3.每弹出一个点，把该节点所有没有进过队列的邻接点放入队列
	 * 4.直到队列为空
	 * 
	 * @param node
	 */
	public static void bfs(Node node) {
		if (node == null)
			return;
		Queue<Node> queue = new LinkedList<>();
		HashSet<Node> set = new HashSet<>();// 已经访问过的结点集合
		queue.add(node);
		set.add(node);
		while (!queue.isEmpty()) {
			Node cur = queue.poll();
			System.out.println(cur.value);
			for (Node next : cur.nexts)// 访问直接相关联的结点
			{
				if (!set.contains(next)) {
					set.add(next);
					queue.add(next);
				}
			}
		}
	}

	/**
	 * 1.利用栈实现
	 * 2.从 node 开始把节点按照深度放入栈，然后弹出
	 * 3.每弹出一个点，把该节点下一个没有进过栈的邻接点入栈
	 * 4.直到栈为空
	 * 
	 * @param node
	 */
	public static void dfs(Node node) {
		if (node == null)
			return;
		Stack<Node> stack = new Stack<>();
		HashSet<Node> set = new HashSet<>();
		stack.add(node);
		set.add(node);
		System.out.println(node.value);
		while (!stack.isEmpty()) {
			Node cur = stack.pop();
			for (Node next : cur.nexts) {
				if (!set.contains(next)) {
					stack.push(cur);
					stack.push(next);
					set.add(next);
					System.out.println(next.value);
					break;
				}
			}
		}

	}

	// 拓扑排序算法:找到第一个入度为 0 的结点加入到队列，然后擦除这个节点的影响，继承寻找其他结点
	// 图的要求： directed graph (有向图) and no loop
	public static List<Node> sortedTopology(Graph graph) {
		// key 某个 node value 剩余的入度
		HashMap<Node, Integer> inMap = new HashMap<>();
		// 入度为 0 的点，才能进入队列
		Queue<Node> queue = new LinkedList<>();
		for (Node node : graph.nodes.values()) {
			inMap.put(node, node.in);
			if (node.in == 0) {
				queue.add(node);
			}
		}
		// 拓扑排序结果
		List<Node> result = new ArrayList<>();
		while (!queue.isEmpty()) {
			Node cur = queue.poll();
			result.add(cur);
			// 擦除当前节点的影响
			for (Node next : cur.nexts) {
				inMap.put(next, inMap.get(next) - 1);
				if (inMap.get(next) == 0) {
					queue.add(next);
				}
			}
		}
		return result;
	}

	// 算法要求：无向图 求最小生成树
	// Kruskal : 使用并查集结构 （从边的角度）
	// 下面只满足功能要求（模拟并查集）并不是并查集结构
	public static class MySets {
		public HashMap<Node, List<Node>> setMap;

		public MySets(List<Node> nodes) {
			for (Node cur : nodes) {
				List<Node> set = new ArrayList<>();
				set.add(cur);
				setMap.put(cur, set);
			}
		}

		public boolean isSameSet(Node from, Node to) {
			List<Node> fromSet = setMap.get(from);
			List<Node> toSet = setMap.get(to);
			return fromSet == toSet;
		}

		public void union(Node from, Node to) {// 把两个集合并为一个集合
			List<Node> fromSet = setMap.get(from);
			List<Node> toSet = setMap.get(to);

			for (Node tNode : toSet) {
				fromSet.add(tNode);
				setMap.put(tNode, fromSet);
			}

		}

	}

	// 把边按照从小到大的次序考虑，看加上这条边是否形成环
	// 没有形成环则添加到结果中，并合并结果集中的结点，形成环就不加入到结果集中
	public static Set<Edge> KruskalMST(Graph graph) {
		UnionFind union = new UnionFind();
		union.makeSets(graph.nodes.values());
		PriorityQueue priorityQueue = new PriorityQueue<>(new EdgeComparator());
		for (Edge edge : graph.edges) {
			priorityQueue.add(edge);
		}
		Set<Edge> result = new HashSet<>();
		while (!priorityQueue.isEmpty()) {
			Edge edge = priorityQueue.poll(); // 每次取出边权值最小的边
			if (!union.isSameSet(edge.from, edge.to)) {
				result.add(edge);
				union.union(edge.from, edge.to);
			}
		}
		return result;
	}

	// Prim 算法 要求无向图（从点的角度）
	// 剪枝策略加贪心
	// 在每次解锁的边中选择权值最小的
	public static Set<Edge> primMST(Graph graph) {
		// 解锁的边进入小根堆
		PriorityQueue<Edge> priorityQueue = new PriorityQueue<>(new EdgeComparator());
		HashSet<Node> set = new HashSet<>();
		Set<Edge> result = new HashSet<>(); // 挑选好的边放入 result 里
		for (Node node : graph.nodes.values()) // 随便挑一个点
		{
			// node 开始
			if (!set.contains(node)) {
				set.add(node);
				for (Edge edge : node.edges) // 一个点，解锁所有相连的边
				{
					priorityQueue.add(edge);
				}
				while (!priorityQueue.isEmpty()) {
					Edge edge = priorityQueue.poll(); // 弹出已解锁边中最小的边
					Node tNode = edge.to; // 可能的一个新点
					if (!set.contains(tNode)) {
						set.add(tNode);
						result.add(edge);
						for (Edge nextEdge : tNode.edges) {
							priorityQueue.add(nextEdge);// 相关联的边进行解锁
						}
					}
				}
			}
		}
	}

	// Dijkstra 算法 (单元最短路径算法)
	// 图：可以有负权值的边,但不能有累加和为负数的环
	// 规定出发点：到图中所有点的最短路径

	public static HashMap<Node, Integer> dijkstra1(Node head) {
		// 从 head 出发到所有点的最小距离
		// key 从 head 出发到达 key
		// value 从 head 出发到达 key 的最小距离
		// 如果在表中，没有 T 的记录，含义是从 head 出发到 T 这个点的距离为正无穷
		HashMap<Node, Integer> distanceMap = new HashMap<>();
		distanceMap.put(head, 0);
		// 记录求过距离的节点，存在 selectedNode 中
		HashSet<Node> selectedNodes = new HashSet<>();
		Node minNode = getMinDistanceAndselectedNode(distanceMap, selectedNodes);

		while (minNode != null) {
			int distance = distanceMap.get(minNode);
			for (Edge edge : minNode.edges) {
				Node toNode = edge.to;
				if (!distanceMap.containsKey(toNode)) {
					distanceMap.put(toNode, distance + edge.weight);
				}
				distanceMap.put(edge.to, Math.min(distanceMap.get(toNode), distance + edge.weight));
			}
			selectedNodes.add(minNode);
			minNode = getMinDistanceAndselectedNode(distanceMap, selectedNodes);

		}
		return distanceMap;
	}

	public static Node getMinDistanceAndselectedNode(
			HashMap<Node, Integer> distanceMap,
			HashSet<Node> touchedNodes) {
		Node minNode = null;
		int minDistance = Integer.MAX_VALUE;
		for (java.util.Map.Entry<Node, Integer> entry : distanceMap.entrySet()) {
			Node node = entry.getKey();
			int distance = entry.getValue();
			if (!touchedNodes.contains(node) && distance < minDistance) {
				minNode = node;
				minDistance = distance;
			}
		}
		return minNode;
	}

}
