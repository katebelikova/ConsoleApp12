using System;
using System.Text;
using MySql.Data.MySqlClient;

namespace Lab3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Class1 db = new Class1();
            db.Connect();

            while (true)
            {
                Console.WriteLine("\n1. Показати всі матеріали");
                Console.WriteLine("2. Для кожного замовлення розрахувати вартість і суму до сплати");
                Console.WriteLine("3. Для певного виробника збільшити вартість продукції на 15%");
                Console.WriteLine("4. Які матеріали зовсім не використовувались під час будівництва (замовлення відсутні)");
                Console.WriteLine("5. Добавити матеріал");
                Console.WriteLine("6. Вихід\n");
                Console.Write("Ваш вибір: ");
                string choice = Console.ReadLine();

                switch (choice)
                {
                    case "1": db.ShowMaterials(); break;
                    case "2": db.SummaSplatyOrders(); break;
                    case "3":
                        Console.Write("Введіть виробника: ");
                        string sth = Console.ReadLine();
                        db.MorePrice(sth);
                        break;
                    case "4": db.NonMaterials(); break;
                    case "5": db.AddMaterial(); break;
                    case "6": return;
                    default: Console.WriteLine("Невірно."); break;
                }
            }
        }
    }
}
