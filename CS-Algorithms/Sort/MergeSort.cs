

public partial class Sort
{
    public void MergeSort(ref int[] arr)
    {
        
        
    }

    private void MergeSort(ref int[] arr, int start, int end)
    {
        if (start >= end)
        {
            return;
        }
        int mid = (start + end) / 2;
        MergeSort(ref arr, start, mid);
        MergeSort(ref arr, mid+1, end);
        Merge(ref arr, start, mid, end);
    }
    
    //合并两个有序数组
    private void Merge(ref int[] arr, int start, int mid, int end)
    {
        if (start == end)
        {
            return;
        }
        
        
    }
    
}