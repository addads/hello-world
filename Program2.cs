using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;

namespace ConsoleApp1
{
    delegate void Procedure();


    class Program
    {
        static Procedure what = null;

        public static void Method1()
        {
            Console.WriteLine("Method 1");
        }

        public static void Method2()
        {
            Console.WriteLine("Method 2");
        }

        public void Method3()
        {
            Console.WriteLine("Method 3");
        }

        public void Method4()
        {
            Console.WriteLine("Method 3");
        }

        public void Method5()
        {
            Console.WriteLine("Method 3");
        }

        private static void AddProc()
        {
            int var = 100;
            what += new Procedure(delegate { Console.WriteLine(var); });


        }

        static void Main()
        {
            Procedure someProcs = null;

            someProcs += new Procedure(Program.Method1);
            someProcs += new Procedure(Method2);  
            Program demo = new Program();

            someProcs += new Procedure(demo.Method3);
            someProcs -= Program.Method2;
            someProcs();

            what += new Procedure(delegate { Console.WriteLine("f"); });
            what();
            AddProc();
            what();

            Console.WriteLine("{0:HH:mm:ss}", DateTime.Now);
            Timer timer = new Timer(5000);
            timer.Elapsed += OnTimedEvent2;
            timer.AutoReset = true;
            timer.Enabled = true;
            Console.WriteLine("Hello World!");
            Console.ReadKey();

        }

        private static void OnTimedEvent2(Object source, ElapsedEventArgs e)
        {
            Console.WriteLine("{0:HH:mm:ss}", e.SignalTime);
        }
    }
}
