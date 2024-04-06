using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Nathan Budzinski

namespace HashingLab
{
    internal class TestPlan3
    {
        public static void Main()
        {
            HashTable<Person> h = new HashTable<Person>(11);
            Person johnDoe = new Person("0000000001", "John Doe", 20);
            for (int i = 0; i < 11; i++)
            {
                h.addItem(johnDoe);
            }
            try
            {
                h.addItem(johnDoe);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            Person p = new Person("0000000001");
            h.retrieveItem(ref p);
            Console.WriteLine(p);
        }
    }
}
