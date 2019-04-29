

using System;
using System.Text;
using NUnit.Framework;

namespace Algorithms
{
    class LinkedListNode
    {
        public LinkedListNode next;
        public int val;
    
        public LinkedListNode(int val)
        {
            this.val = val;
        }
    }
    
    class LinkedList
    {
        private LinkedListNode head = new LinkedListNode(0);
        public int Length { get; private set; } = 0;
    
        public bool Insert(int pos, int val)
        {
            if (pos > Length)
            {
                return false;
            }
            int curpos = 0;
            var curNode = head;
            while (curNode != null)
            {
                if (curpos == pos)
                {
                    var node = new LinkedListNode(val);
                    var next = curNode.next;
                    curNode.next = node;
                    node.next = next;
                    Length++;
                    return true;
                }
                curpos++;
                curNode = curNode.next;
            }
            return false;
        }
    
        public bool Remove(int pos)
        {
            if (pos >= Length)
            {
                return false;
            }
            int curPos = 0;
            var prev = head;
            var curNode = prev.next;
            while (curNode != null)
            {
                if (curPos == pos)
                {
                    prev.next = curNode.next;
                    Length--;
                    return true;
                }
                curPos++;
                prev = curNode;
                curNode = curNode.next;
            }
            return false;
        }
    
        public int Find(int val)
        {
            var curNode = head.next;
            int pos = 0;
            while (curNode != null)
            {
                if (curNode.val == val)
                {
                    return pos;
                }
                pos++;
                curNode = curNode.next;
            }
            return -1;
        }
    
        public void Print()
        {
            var curNode = head.next;
            StringBuilder builder = new StringBuilder();
            builder.Append("list:");
            while (curNode != null)
            {
                builder.Append(curNode.val).Append(" ");
                curNode = curNode.next;
            }
            Console.WriteLine(builder.ToString());
        }
    
        [Test]
        public void TestLinkList1()
        {
            LinkedList list = new LinkedList();
            list.Insert(0, 1);
            list.Insert(0, 2);
            list.Insert(0, 3);
            list.Insert(0, 4);
    
            list.Print();
    
            Console.WriteLine(list.Find(3));
    
        }
    
        [Test]
        public void TestLinkList2()
        {
            LinkedList list = new LinkedList();
            list.Insert(0, 1);
            list.Insert(0, 2);
            list.Insert(0, 3);
            list.Insert(0, 4);
    
            list.Print();
    
            list.Insert(3, 5);
    
            list.Print();
        }
        
        [Test]
        public void TestLinkList3()
        {
            LinkedList list = new LinkedList();
            list.Insert(0, 1);
            list.Insert(0, 2);
            list.Insert(0, 3);
            list.Insert(0, 4);
    
            list.Print();
    
            list.Remove(2);
    
            list.Print();
        }
    
    }

}
