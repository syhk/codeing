package main.test.java.test;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * 题目：一些项目要占用一个会议室宣讲，
 * 会议室不能同时容纳两个项目宣讲。
 * 给每一个项目开始的时间和结束的时间安排宣讲的日程，
 * 要求会议室进行的宣讲的场次最多并返。
 */
public class Test2 {
	public static class Program {
		public int start;
		public int end;
	}

	public static class ProgramComparator implements Comparator<Program> {

		@Override
		public int compare(Program o1, Program o2) {
			// TODO Auto-generated method stub
			return o1.end - o2.end;
		}
	}

	// 安排会议 , 选择结束时间最早的
	public static int bestArrange(Program[] programs, int timePoint) {
		Arrays.sort(programs, new ProgramComparator());
		int result = 0;
		// 从左向右依次遍历所有的会议
		for (int i = 0; i < programs.length; i++) {
			if (timePoint <= programs[i].start) {
				result++;
				timePoint = programs[i].end;
			}
		}
		return result;
	}

	/**
	 * 题目：一块金条切成两半，需要花费和长度数值一样的铜板。
	 * eg: 长为 20 的金条，不管切成哪两半都需要花费 20 个铜板
	 * 问：一群人想切分整块金条，怎么分最省铜板？
	 * 
	 * @param arr arr 元素和是金条的长度。其中各个元素代表金条需要分成的 n 个部分
	 * @return 花的铜板数
	 */
	public static int lessMoney(int[] arr) {
		PriorityQueue<Integer> queue = new PriorityQueue<>();
		for (int i = 0; i < arr.length; i++) {
			queue.add(arr[i]);
		}
		int sum = 0;
		int cur = 0;
		while (queue.size() > 1) {
			cur = queue.poll() + queue.poll();
			sum += cur;
			queue.add(cur);
		}
		return sum;
	}

}
