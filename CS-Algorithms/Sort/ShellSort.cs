

using NUnit.Framework;

public partial class Sort
{
    public void ShellSort(int[] arr)
    {
//        int len = arr.Length;
//        int h = 1;
//        // 获取我们数组三分之一的长度
//        while (h < len / 3)
//        {
//            h = h * 3 + 1;
//        }
//        while (h >= 1)
//        {
//            //插入排序，使数组在h间隔下的数组有序
//            for (int i = h; i < len; i++)
//            {
//                //
//                for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h)
//                {
//                    int temp = arr[j];
//                    arr[j] = arr[j - h];
//                    arr[j - h] = temp;
//                    PrintArr(arr);
//                }
//                h = h / 3;
//            }
//        }
    }
    
    [Test]
    public void TestShellSort()
    {
        var arr = new int[]{1, 9, 6, 2, 4, 5};
        ShellSort(arr);
        Assert.AreEqual(arr, new int[] {1, 2, 4, 5, 6, 9});
    }
}