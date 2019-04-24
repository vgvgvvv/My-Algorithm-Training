/*
 * @lc app=leetcode id=703 lang=csharp
 *
 * [703] Kth Largest Element in a Stream
 *
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
 *
 * algorithms
 * Easy (46.09%)
 * Total Accepted:    28.3K
 * Total Submissions: 61.4K
 * Testcase Example:  '["KthLargest","add","add","add","add","add"]\n[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
 *
 * Design a class to find the kth largest element in a stream. Note that it is
 * the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Your KthLargest class will have a constructor which accepts an integer k and
 * an integer array nums, which contains initial elements from the stream. For
 * each call to the method KthLargest.add, return the element representing the
 * kth largest element in the stream.
 * 
 * Example:
 * 
 * 
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
 * 
 * 
 * Note: 
 * You may assume that nums' length ≥ k-1 and k ≥ 1.
 * 
 */
public class KthLargest {
    /**
        第k大问题:
        solution1 :
        二分排序，只排一半，对大的那一部分进行排序，最后获取前k个大数。但是如果数据量太大，同时读入内存则会有问题。
        solution2 :
        维护数组，把前k大的数据放在里面，新数据来的时候如果比最小的还小，就不管，
        不然就把最小的去除，把新数据加进数组并进行一次排序，输出最小值 O(Klogk),这种方案如果数据量太大的话可以走文件流
        solution3
        将上述方法改成小顶堆。O(logk)
     */
    List<int> list = new List<int>();
    int max;
    public KthLargest(int k, int[] nums) {
        max = k;
        for(int i = 0; i < nums.Length; i ++){
            list.Add(nums[i]);
        }
        list.Sort();
        while(list.Count > k){
            (0);
        }
    }
    
    public int Add(int val) {
        list.Add(val);
        list.Sort();
        if(list.Count > max){
            list.RemoveAt(0);
        }
        return list[0];
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.Add(val);
 */

