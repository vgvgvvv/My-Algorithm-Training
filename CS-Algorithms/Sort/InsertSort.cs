

using NUnit.Framework;

public partial class Sort
{
    public void InsertSort(int[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            //从第i个开始数，把最小的数字往左移
            for (int j = i; j > 0 && arr[j] < arr[j-1]; j--)
            {
                var temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                //PrintArr(arr);
            }
        }
    }
    
    [Test]
    public void TestInsertSort()
    {
        var arr = new int[]{1, 9, 6, 2, 4, 5};
        InsertSort(arr);
        
        /**
         * 1 9 6 2 4 5
         * 1 6 9 2 4 5 
         * 1 6 2 9 4 5 
         * 1 2 6 9 4 5 
         * 1 2 6 4 9 5 
         * 1 2 4 6 9 5 
         * 1 2 4 6 5 9 
         * 1 2 4 5 6 9
         */
        
        Assert.AreEqual(arr, new int[] {1, 2, 4, 5, 6, 9});
    }
    
}