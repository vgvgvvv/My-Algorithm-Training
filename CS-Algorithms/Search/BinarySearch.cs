

using System;
using NUnit.Framework;

public partial class Search{

    //使用递归的二分查找
    public int BinarySearch1(int[] arr, int target){
        return BinarySearch1(arr, target, 0, arr.Length-1);
    }

    private int BinarySearch1(int[] arr, int target, int begin, int end){
        if(begin > end){
            return -1;
        }
        int mid = (begin + end) / 2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] > target){
            return BinarySearch1(arr, target, begin, mid-1);
        }else{
            return BinarySearch1(arr, target, mid+1, end);
        }
    }

    //使用循环进行二分查找
    public int BinarySearch2(int[] arr, int target){
        int b = 0;
        int e = arr.Length-1;
        int mid = (b+e)/2;
        while(mid <= e && mid >= b){
            if(arr[mid] == target){
                return mid;
            }else if(arr[mid] > target){
                e = mid-1;
            }else{
                b = mid+1;
            }
            mid = (b+e)/2;
        }
        return -1;
    }

    [Test]
    public void TestBinarySearch1()
    {
        int[] a = new[] {1, 5, 4, 3, 6, 2, 8};
        Assert.AreEqual(BinarySearch1(a, 1), 0);
    }
    
    
    [Test]
    public void TestBinarySearch2()
    {
        int[] a = new[] {1, 5, 4, 3, 6, 2, 8};
        Assert.AreEqual(BinarySearch2(a, 1), 0);
    }

}