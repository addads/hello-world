using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data.Common;
using System.Configuration;

namespace ConsoleApp1
{
    class Program
    {

        static void Main(string[] args)
        {
            string provider = ConfigurationManager.AppSettings["provider"];
            string connectionString = ConfigurationManager.AppSettings["connectionString"];

            DbProviderFactory factory = DbProviderFactories.GetFactory(provider);

            using (DbConnection connection = factory.CreateConnection())
            {
                if (connection == null)
                {
                    Console.WriteLine("Connection Error");
                    Console.ReadLine();
                    return;
                }

                connection.ConnectionString = connectionString;
                connection.Open();

                DbCommand command = factory.CreateCommand();
                if (command == null)
                {
                    Console.WriteLine("Command Error");
                    Console.ReadLine();
                    return;
                }

                command.Connection = connection;
                command.CommandText = "Select * From Products";

                using (DbDataReader dataReader = command.ExecuteReader())
                {
                    while (dataReader.Read())
                    {
                        Console.WriteLine($"{dataReader["ProdId"]} " + $"{dataReader["Product"]}");
                    }
                }

                Console.ReadLine();

                command.Connection = connection;

                command.CommandText = "INSERT INTO [dbo].[Products] ([ProdId], [Product], [Price], [Code]) VALUES (55, N'Pisici                                            ', CAST(3.6800 AS Money), N'PISI                ')";
                command.ExecuteNonQuery();


                Console.ReadLine();


                command.Connection = connection;
                command.CommandText = "Select * From Products";

                using (DbDataReader dataReader = command.ExecuteReader())
                {
                    while (dataReader.Read())
                    {
                        Console.WriteLine($"{dataReader["ProdId"]} " + $"{dataReader["Product"]}");
                    }
                }

                Console.ReadLine();

                command.Connection = connection;

                command.CommandText = "Delete Products where ProdId = 55";
                command.ExecuteNonQuery();
                Console.ReadLine();


                command.Connection = connection;
                command.CommandText = "Select * From Products";

                using (DbDataReader dataReader = command.ExecuteReader())
                {
                    while (dataReader.Read())
                    {
                        Console.WriteLine($"{dataReader["ProdId"]} " + $"{dataReader["Product"]}");
                    }
                }

                Console.ReadLine();

                command.Connection = connection;

                command.CommandText = "Update Products set Product='hey', Price='2.050' where ProdId = 50";
                command.ExecuteNonQuery();
                Console.ReadLine();


                command.Connection = connection;
                command.CommandText = "Select * From Products";

                using (DbDataReader dataReader = command.ExecuteReader())
                {
                    while (dataReader.Read())
                    {
                        Console.WriteLine($"{dataReader["ProdId"]} " + $"{dataReader["Product"]}" + $"{dataReader["Price"]}");
                    }
                }

                Console.ReadLine();

                connection.Close();

            }
        }
    }
}
