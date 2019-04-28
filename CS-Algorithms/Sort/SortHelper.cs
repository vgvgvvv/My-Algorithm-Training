

using System;
using System.Text;

public partial class Sort
{
    void PrintArr(int[] arr)
    {
        var builder = new StringBuilder();
        for (int i = 0; i < arr.Length; i++)
        {
            builder.Append(arr[i]).Append(" ");
        }
        Console.WriteLine(builder);
    }        
}