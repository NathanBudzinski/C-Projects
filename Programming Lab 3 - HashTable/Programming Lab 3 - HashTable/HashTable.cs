using System.Collections;
using System.Runtime.CompilerServices;

// Nathan Budzinski

namespace HashingLab
{
    class HashTable<T>
    where T : IKeyed
    {
        private T[] items;
        private bool linearProbing;
        private bool[] occupied;

        public HashTable(int theSize, bool useLinearProbing = false)
        {
            if (theSize < 1) { throw new ArgumentOutOfRangeException("Cannot create HashTable of size less than 1!");}
            linearProbing = useLinearProbing;
            if (!linearProbing)
            {
                if (!isValidQuadProbeValue(theSize))
                {
                    getNextValidQuadProbeValue(ref theSize);
                }
            }
            items = new T[theSize];
            occupied = new bool[theSize];
        }

        public void addItem(T theItem)
        {
            int homePos = hashFunction(theItem.getKey()), probeIndex;
            for (int i = 0; i < items.Length; i++)
            {
                probeIndex = probe(homePos, i);
                if (!occupied[probeIndex]) 
                {
                    items[probeIndex] = theItem;
                    occupied[probeIndex] = true;
                    return;
                }
            }
            throw new Exception("The hashtable is full, couldn't add item.");
        }

        private int probe(int homePos, int i)
        {
            int probeIndex;
            if (!linearProbing)
            {
                probeIndex = probeQuadratic(homePos, i);
                return probeIndex;
            }
            probeIndex = probeLinear(homePos, i);
            return probeIndex;
        }

            
        private int probeLinear(int homePos, int i)
        {
            return mod((homePos + i), items.Length);
        }

        private int probeQuadratic(int homePos, int i)
        {
            if (i == 0) 
            { 
                return homePos;
            }
            int posOrNeg = (int)Math.Pow(-1, i + 1);
            int perfectSquare = (int)(Math.Pow((i + 1) / 2, 2));
            return mod((homePos + posOrNeg * perfectSquare), items.Length);
        }
            
        public bool retrieveItem(ref T theItem)
        {
            int homePos = hashFunction(theItem.getKey());
            bool retrieved = false;
            int probeIndex;
            for (int i = 0; i < items.Length; i++)
            {
                probeIndex = probe(homePos, i);
                if (occupied[probeIndex] && items[probeIndex].getKey() == theItem.getKey())
                {
                    theItem = items[probeIndex];
                    retrieved = true;
                    return retrieved;
                }
            }
            return retrieved;
        }

        private int hashFunction(int keyValue)
        {
            for (int i = 0; i < 3; i++)
            {
                int[] split = intSplit(keyValue);
                if (split[0] == 0) { split[0] = 17; }
                if (split[1] == 0) { split[1] = 17; }
                keyValue = (split[0] * split[1] + 9) % items.Length;

            }
            return keyValue;
        }

        private static int[] intSplit(int i)
        {
            int[] arr = new int[2];
            string iStr = i.ToString();
            if (iStr.Length == 1)
            {
                return new int[] { 0, i };
            }
            string left = iStr.Substring(0, iStr.Length / 2);
            arr[0] = Int32.Parse(left);
            string right = iStr.Substring(iStr.Length / 2);
            arr[1] = Int32.Parse(right);
            return arr;
        }
        private static bool isPrime(int p)
        {
            if (p < 2)
            {
                return false;
            }
            else if (p == 2)
            {
                return true;
            }
            else
            {
                for (int j = 2; j < p; j++)
                {
                    if (p % j == 0)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        private int mod(int x, int y)
        {
            int modulo = x % y;
            if (x % y >= 0) 
            {
                return modulo;
            }
            else
            {
                return y + modulo;
            }
        }
        private static bool isValidQuadProbeValue(int x)
        {
            if (x == 1 || x == 2) 
            { 
                return true; 
            }
            if (x % 2 == 0)
            {
                return (isPrime(x) && x % 4 == 3) || (isPrime(x / 2) && (x / 2) % 4 == 3);
            }
            return isPrime(x) && x % 4 == 3;
        }

        private static void getNextValidQuadProbeValue(ref int theSize)
        {
            theSize++;
            if (!isValidQuadProbeValue(theSize))
            {
                getNextValidQuadProbeValue(ref theSize);
            }
        }
    }
}

interface IKeyed
{
    int getKey();
}


