

using System;
using System.Text;
using NUnit.Framework;

public partial class Sort
{
    /// <summary>
    /// 每一个数字从0开始进行上浮
    /// </summary>
    /// <param name="arr"></param>
    public void BubbleSort(int[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            for (int j = 0; j < arr.Length; j++)
            {
                if (arr[j] > arr[i])
                {
                    var temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                    PrintArr(arr);
                }
            }
        }
    }

    [Test]
    public void TestBubbleSort()
    {
        var arr = new int[]{1, 9, 6, 2, 4, 5};
        BubbleSort(arr);
        
        /**
         * 1 9 6 2 4 5
         * 9 1 6 2 4 5 
         * 1 9 6 2 4 5 
         * 1 6 9 2 4 5 
         * 1 2 9 6 4 5 
         * 1 2 6 9 4 5 
         * 1 2 4 9 6 5 
         * 1 2 4 6 9 5 
         * 1 2 4 5 9 6 
         * 1 2 4 5 6 9
         */
        Assert.AreEqual(arr, new int[] {1, 2, 4, 5, 6, 9});
    }
    
}