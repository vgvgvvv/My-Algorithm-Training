
using System;
using NUnit.Framework;

public class SimpleSearch
{
      public int Search(string src, string target)
      {
            if (target.Length > src.Length)
            {
                  return -1;
            }
            for (int i = 0; i <= src.Length - target.Length; i++)
            {
                  bool good = true;
                  for (int j = 0; j < target.Length; j++)
                  {
                        if (src[i + j] != target[j])
                        {
                              good = false;
                              break;
                        }
                  }
                  if (good)
                  {
                        return i;
                  }
            }
            return -1;
      }

      [Test]
      public void TestSimpleSearch()
      {
            int test = Search("aaaiuo", "iuo");
            Console.WriteLine(test);
      }
}