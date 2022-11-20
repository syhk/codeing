package main.test.java.Trie;

// 前缀树
public class TrTree {

	public static class TrieNode {
		public int pass;// 经过当前节点就加 1
		public int end; // 标记一个单词一结尾
		public TrieNode[] nexts;

		public TrieNode() {
			pass = 0;
			end = 0;
			nexts = new TrieNode[26]; // 一共只会 26 条路
		}
	}

	public static class Trie {

		private TrieNode root;

		public Trie() {
			root = new TrieNode();
		}

		public void insert(String word) {
			if (word == null) {
				return;
			}
			char[] chs = word.toCharArray();
			TrieNode node = root;
			node.pass++;
			int index = 0;
			for (int i = 0; i < chs.length; i++)// 从左往左遍历字符
			{
				// index 的结果会在范围 0-25 之间
				index = chs[i] - 'a'; // 由字符，对应成走向哪条路
				if (node.nexts[index] == null) { // 没有节点
					node.nexts[index] = new TrieNode();
				}
				node = node.nexts[index]; // 如果有直接复用
				node.pass++;
			}
			node.end++;
		}

		public int search(String word) {
			if (word == null)
				return 0;
			char[] chs = word.toCharArray();
			TrieNode node = root;
			int index = 0;
			for (int i = 0; i < chs.length; i++) {
				index = chs[i] - 'a';
				if (node.nexts[index] == null) {
					return 0;
				}
				node = node.nexts[index];
			}
			return node.end;
		}

	}

}
