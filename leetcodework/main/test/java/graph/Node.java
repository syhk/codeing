package main.test.java.graph;

import java.util.ArrayList;

public class Node {
	public int value;
	public int in;
	public int out;
	public ArrayList<Node> nexts;// 从自己出发直接关联的点
	public ArrayList<Edge> edges;// 一个自己所拥有的边

	public Node(int value) {
		this.value = value;
		in = 0;
		out = 0;
		nexts = new ArrayList<>();
		edges = new ArrayList<>();
	}
}
