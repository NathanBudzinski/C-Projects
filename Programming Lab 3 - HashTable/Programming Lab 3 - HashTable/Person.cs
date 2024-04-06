using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Nathan Budzinski

namespace HashingLab
{
    internal class Person : IKeyed
    {
        private string name;
        private string ssn;
        private int age;

        public Person(string theSSN, string theName = "", int theAge = -1)
        {
            name = theName;
            ssn = theSSN;
            age = theAge;
        }
        
        public int getKey()
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < ssn.Length; i++)
            {
                if (ssn.ElementAt(i) != '-')
                {
                    sb.Append(ssn.ElementAt(i));
                }
            }
            return Int32.Parse(sb.ToString());
        }

        public override string ToString() 
        {
            return String.Format("{0} is {1} years old.", name, age);
        }
    }
}
