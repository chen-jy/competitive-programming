using System;
using System.Collections.Generic;

public class Program
{
    static LessThan comp = new LessThan();
    static OrderStatisticTree<decimal, decimal> set = new OrderStatisticTree<decimal, decimal>(comp);

    static void Main()
    {
        int t = int.Parse(Console.ReadLine());
        long ranks = 0;
        for (int i = 0; i < t; i++)
        {
            decimal s = decimal.Parse(Console.ReadLine());
            while (!set.Add(-s, 0))
            {
                s += 0.00001m;
            }
            int r = set.IndexOf(-s) + 1;
            ranks += r;
        }
        Console.WriteLine(string.Format("{0:0.00}", ranks / (decimal)t));
    }
}

public class LessThan : IComparer<decimal>
{
    public int Compare(decimal a, decimal b)
    {
        return a.CompareTo(b);
    }
}

public class OrderStatisticTree<TKey, TValue>
{
    private int numberOfNodes;
    private RedBlackNode<TKey, TValue> rbTree;
    private static RedBlackNode<TKey, TValue> sentinelNode;

    private IComparer<TKey> comparer;
    private int BLACK = RedBlackNode<TKey, TValue>.BLACK;
    private int RED = RedBlackNode<TKey, TValue>.RED;

    public OrderStatisticTree(IComparer<TKey> keyComparer)
    {
        sentinelNode = new RedBlackNode<TKey, TValue>();
        sentinelNode.Left = null;
        sentinelNode.Right = null;
        sentinelNode.Parent = null;
        sentinelNode.Color = RedBlackNode<TKey, TValue>.BLACK;
        rbTree = sentinelNode;
        comparer = keyComparer;
    }

    public int IndexOf(TKey x)
    {
        return Rank(rbTree, x) - 1;
    }

    public int Size()
    {
        return numberOfNodes;
    }

    public bool IsEmpty()
    {
        return (rbTree == null);
    }

    public void Clear()
    {
        rbTree = sentinelNode;
        numberOfNodes = 0;
    }
    
    public bool Add(TKey key, TValue data)
    {
        int result = 0;
        RedBlackNode<TKey, TValue> node = new RedBlackNode<TKey, TValue>();
        RedBlackNode<TKey, TValue> temp = rbTree;

        while (temp != sentinelNode)
        {
            node.Parent = temp;
            temp.Count++;
            result = comparer.Compare(key, temp.Key);

            if (result == 0)
            {
                return false;
            }
            if (result > 0)
            {
                temp = temp.Right;
            }
            else
            {
                temp = temp.Left;
            }
        }
        
        node.Key = key;
        node.Data = data;
        node.Left = sentinelNode;
        node.Right = sentinelNode;
        node.Count = 1;

        if (node.Parent != null)
        {
            result = comparer.Compare(node.Key, node.Parent.Key);
            if (result > 0)
            {
                node.Parent.Right = node;
            }
            else
            {
                node.Parent.Left = node;
            }
        }
        else
        {
            rbTree = node;
        }

        RestoreAfterInsert(node);
        numberOfNodes++;
        return true;
    }

    private void RestoreAfterInsert(RedBlackNode<TKey, TValue> x)
    {
        RedBlackNode<TKey, TValue> y;
        
        while (x != rbTree && x.Parent.Color == RedBlackNode<TKey, TValue>.RED)
        {
            if (x.Parent == x.Parent.Parent.Left)		
            {
                y = x.Parent.Parent.Right;
                if (y != null && y.Color == RedBlackNode<TKey, TValue>.RED)
                {
                    x.Parent.Color = RedBlackNode<TKey, TValue>.BLACK;
                    y.Color = RedBlackNode<TKey, TValue>.BLACK;
                    x.Parent.Parent.Color = RedBlackNode<TKey, TValue>.RED;
                    x = x.Parent.Parent;
                }
                else
                {
                    if (x == x.Parent.Right)
                    {
                        x = x.Parent;
                        RotateLeft(x);
                    }

                    x.Parent.Color = RedBlackNode<TKey, TValue>.BLACK;
                    x.Parent.Parent.Color = RedBlackNode<TKey, TValue>.RED;
                    RotateRight(x.Parent.Parent);
                }
            }
            else
            {
                y = x.Parent.Parent.Left;
                if (y != null && y.Color == RedBlackNode<TKey, TValue>.RED)
                {
                    x.Parent.Color = RedBlackNode<TKey, TValue>.BLACK;
                    y.Color = RedBlackNode<TKey, TValue>.BLACK;
                    x.Parent.Parent.Color = RedBlackNode<TKey, TValue>.RED;
                    x = x.Parent.Parent;
                }
                else
                {
                    if (x == x.Parent.Left)
                    {
                        x = x.Parent;
                        RotateRight(x);
                    }

                    x.Parent.Color = RedBlackNode<TKey, TValue>.BLACK;
                    x.Parent.Parent.Color = RedBlackNode<TKey, TValue>.RED;
                    RotateLeft(x.Parent.Parent);
                }
            }
        }

        rbTree.Color = RedBlackNode<TKey, TValue>.BLACK;
    }
    
    private void RotateLeft(RedBlackNode<TKey, TValue> x)
    {
        RedBlackNode<TKey, TValue> y = x.Right;
        x.Right = y.Left;

        if (y.Left != sentinelNode)
        {
            y.Left.Parent = x;
        }
        if (y != sentinelNode)
        {
            y.Parent = x.Parent;
        }

        if (x.Parent != null)
        {
            if (x == x.Parent.Left)
            {
                x.Parent.Left = y;
            }
            else
            {
                x.Parent.Right = y;
            }
        }
        else
        {
            rbTree = y;
        }
        
        y.Left = x;
        if (x != sentinelNode)
        {
            x.Parent = y;
        }

        x.Count = x.Left.Count + x.Right.Count + 1;
        y.Count = y.Left.Count + y.Right.Count + 1;
    }

    private void RotateRight(RedBlackNode<TKey, TValue> x)
    {
        RedBlackNode<TKey, TValue> y = x.Left;
        x.Left = y.Right;

        if (y.Right != sentinelNode)
        {
            y.Right.Parent = x;
        }
        if (y != sentinelNode)
        {
            y.Parent = x.Parent;
        }

        if (x.Parent != null)
        {
            if (x == x.Parent.Right)
            {
                x.Parent.Right = y;
            }
            else
            {
                x.Parent.Left = y;
            }
        }
        else
        {
            rbTree = y;
        }
        
        y.Right = x;
        if (x != sentinelNode)
        {
            x.Parent = y;
        }

        x.Count = x.Left.Count + x.Right.Count + 1;
        y.Count = y.Left.Count + y.Right.Count + 1;
    }

    public void Delete(TKey key, TValue data)
    {
        RedBlackNode<TKey, TValue> node = new RedBlackNode<TKey, TValue>();
        node.Key = key;
        node.Data = data;
        Delete(node);
    }

    private void Delete(RedBlackNode<TKey, TValue> z)
    {
        RedBlackNode<TKey, TValue> x = new RedBlackNode<TKey, TValue>();
        RedBlackNode<TKey, TValue> y;

        if (z.Left == sentinelNode || z.Right == sentinelNode)
        {
            y = z;
        }
        else
        {
            y = z.Right;
            while (y.Left != sentinelNode)
            {
                y = y.Left;
            }
        }

        if (y.Left != sentinelNode)
        {
            x = y.Left;
        }
        else
        {
            x = y.Right;
        }
        
        x.Parent = y.Parent;
        if (y.Parent != null)
        {
            if (y == y.Parent.Left)
            {
                y.Parent.Left = x;
            }
            else
            {
                y.Parent.Right = x;
            }
        }
        else
        {
            rbTree = x;
        }
        
        if (y != z)
        {
            z.Key = y.Key;
            z.Data = y.Data;
        }
        if (y.Color == BLACK)
        {
            RestoreAfterDelete(x);
        }
    }
    
    private void RestoreAfterDelete(RedBlackNode<TKey, TValue> x)
    {
        RedBlackNode<TKey, TValue> y;
        
        while (x != rbTree && x.Color == BLACK)
        {
            if (x == x.Parent.Left)
            {
                y = x.Parent.Right;
                if (y.Color == RED)
                {
                    y.Color = BLACK;
                    x.Parent.Color = RED;
                    RotateLeft(x.Parent);
                    y = x.Parent.Right;
                }
                if (y.Left.Color == BLACK && y.Right.Color == BLACK)
                {
                    y.Color = RED;
                    x = x.Parent;
                }
                else
                {
                    if (y.Right.Color == BLACK)
                    {
                        y.Left.Color = BLACK;
                        y.Color = RED;
                        RotateRight(y);
                        y = x.Parent.Right;
                    }

                    y.Color = x.Parent.Color;
                    x.Parent.Color = BLACK;
                    y.Right.Color = BLACK;
                    RotateLeft(x.Parent);
                    x = rbTree;
                }
            }
            else
            {
                y = x.Parent.Left;
                if (y.Color == RED)
                {
                    y.Color = BLACK;
                    x.Parent.Color = RED;
                    RotateRight(x.Parent);
                    y = x.Parent.Left;
                }
                if (y.Right.Color == BLACK && y.Left.Color == BLACK)
                {
                    y.Color = RED;
                    x = x.Parent;
                }
                else
                {
                    if (y.Left.Color == BLACK)
                    {
                        y.Right.Color = BLACK;
                        y.Color = RED;
                        RotateLeft(y);
                        y = x.Parent.Left;
                    }

                    y.Color = x.Parent.Color;
                    x.Parent.Color = BLACK;
                    y.Left.Color = BLACK;
                    RotateRight(x.Parent);
                    x = rbTree;
                }
            }
        }

        x.Color = BLACK;
    }

    public object GetData(TKey key)
    {
        int result;
        RedBlackNode<TKey, TValue> treeNode = rbTree;

        while (treeNode != sentinelNode)
        {
            result = comparer.Compare(key, treeNode.Key);
            if (result == 0)
            {
                return treeNode.Data;
            }
            if (result < 0)
            {
                treeNode = treeNode.Left;
            }
            else
            {
                treeNode = treeNode.Right;
            }
        }

        Console.WriteLine(2);
        return 0;
    }

    public TKey GetMinKey()
    {
        RedBlackNode<TKey, TValue> treeNode = rbTree;

        if (treeNode == null || treeNode == sentinelNode)
        {
            Console.WriteLine(3);
        }

        while (treeNode.Left != sentinelNode)
        {
            treeNode = treeNode.Left;
        }
        
        return treeNode.Key;
    }

    private int Rank(RedBlackNode<TKey, TValue> root, TKey x)
    {
        if (comparer.Compare(x, root.Key) == -1)
        {
            return Rank(root.Left, x);
        }
        else if (comparer.Compare(x, root.Key) == 0)
        {
            if (root.Left.Key != null)
            {
                return root.Left.Count + 1;
            }
            else
            {
                return 1;
            }
        }
        else if (comparer.Compare(x, root.Key) == 1)
        {
            if (root.Left.Key != null)
            {
                return root.Left.Count + 1 + Rank(root.Right, x);
            }
            else
            {
                return 1 + Rank(root.Right, x);
            }
        }

        return -1;
    }

    private class RedBlackNode<NKey, NValue>
    {
        public static int RED = 0;
        public static int BLACK = 1;
        public int Count = 0;
        
        private NKey ordKey;
        private NValue objData;
        private int intColor;

        private RedBlackNode<NKey, NValue> rbnLeft;
        private RedBlackNode<NKey, NValue> rbnRight;
        private RedBlackNode<NKey, NValue> rbnParent;
        
        public NKey Key
        {
            get
            {
                return ordKey;
            }

            set
            {
                ordKey = value;
            }
        }

        public NValue Data
        {
            get
            {
                return objData;
            }

            set
            {
                objData = value;
            }
        }

        public int Color
        {
            get
            {
                return intColor;
            }

            set
            {
                intColor = value;
            }
        }

        public RedBlackNode<NKey, NValue> Left
        {
            get
            {
                return rbnLeft;
            }

            set
            {
                rbnLeft = value;
            }
        }

        public RedBlackNode<NKey, NValue> Right
        {
            get
            {
                return rbnRight;
            }

            set
            {
                rbnRight = value;
            }
        }
        public RedBlackNode<NKey, NValue> Parent
        {
            get
            {
                return rbnParent;
            }

            set
            {
                rbnParent = value;
            }
        }

        public RedBlackNode()
        {
            Color = RED;
        }
    }
}
