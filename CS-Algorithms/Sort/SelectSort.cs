

using NUnit.Framework;

public partial class Sort
{
    public void SelectSort(int[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            //找到最小的然后插入到左边
            int min = i;
            for (int j = i + 1; j < arr.Length; j++)
            {
                if (arr[min] > arr[j])
                {
                    min = j;
                }
            }
            //搜索结束，开始交换位置
            var temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
            //PrintArr(arr);
        }
    }
    
    [Test]
    public void TestSelectSort()
    {
        var arr = new int[]{1, 9, 6, 2, 4, 5};
        SelectSort(arr);
        /**
         * 1 9 6 2 4 5
         * 1 9 6 2 4 5 
         * 1 2 6 9 4 5 
         * 1 2 4 9 6 5 
         * 1 2 4 5 6 9 
         * 1 2 4 5 6 9 
         * 1 2 4 5 6 9
         */
        Assert.AreEqual(arr, new int[] {1, 2, 4, 5, 6, 9});
    }
}