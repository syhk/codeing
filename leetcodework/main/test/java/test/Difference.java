package main.test.java.test;

// 差分数组工具类
public class Difference {
	// 差分数组
	private int[] diff;

	// 输入一个初始数组，区间操作将在这个数组上进行
	public Difference(int[] nums) {
		assert nums.length > 0;
		diff = new int[nums.length];
		// 构造差分数组
		diff[0] = nums[0];
		for (int i = 1; i < nums.length; i++) {
			diff[i] = nums[i] - nums[i - 1];
		}
	}

	// 给闭区间 [i,j] 增加 value
	public void increment(int i, int j, int value) {
		diff[i] += value;
		if (j + 1 < diff.length) {
			diff[j + 1] -= value;
		}
	}

	// 返回结果数组
	public int[] result() {
		int[] res = new int[diff.length];
		// 根据差分数组构造结果数组
		res[0] = diff[0];
		for (int i = 1; i < diff.length; i++) {
			res[i] = res[i - 1] + diff[i];
		}
		return res;
	}

	public static void main(String args[]) {
		int[] arr = new int[] { 1, 4, 5, 7, 9, 80 };
		Difference difference = new Difference(arr);
		difference.increment(2, 4, 100);
		difference.increment(1, 3, -1000);
		int[] res = difference.result();
		for (var i : res) {
			System.out.println(i);
		}

	}
}
