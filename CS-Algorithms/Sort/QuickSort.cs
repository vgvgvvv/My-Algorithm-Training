

using System;
using System.Data.Common;
using NUnit.Framework;

public partial class Sort
{
    public void QuickSort(ref int[] arr)
    {
        QuickSort(ref arr, 0, arr.Length - 1);
    }

    private void QuickSort(ref int[] arr, int start, int end)
    {
        if(end - start < 2) return;
        //进行分割操作
        int mid = FindMid(ref arr, start, end);
        PrintArr(arr);
        //对更小的数组进行分割操作
        QuickSort(ref arr, start, mid);
        QuickSort(ref arr, mid+1, end);
    }

    private int FindMid(ref int[] arr, int start, int end)
    {
        int midValue = arr[start];
        while (start < end)
        {
            //从右往左压缩，找到比开头大的就进行交换
            while (start < end)
            {
                //往左压缩
                if (midValue < arr[end])
                {
                    end--;
                }
                else
                {
                    //进行交换
                    arr[start] = arr[end];
                    start++;
                    break;
                }
            }
            //从左往右压缩，找到比结尾小的，再次进行交换
            while (start < end)
            {
                //进行压缩
                if (midValue > arr[start])
                {
                    start++;
                }
                else
                {
                    //进行交换
                    arr[end] = arr[start];
                    end--;
                    break;
                }
            }
        }
        //最后把中间值写上，左右分割完毕
        arr[start] = midValue;
        return start;
    }
    
    [Test]
    public void TestQuickSort()
    {
        var arr = new int[]{1, 9, 6, 2, 4, 5};
        QuickSort(ref arr);
        /*
         * 1 9 6 2 4 5 
         * 1 5 6 2 4 9 
         * 1 4 2 5 6 9 
         * 1 2 4 5 6 9
         */
        Assert.AreEqual(arr, new int[] {1, 2, 4, 5, 6, 9});
    }
}