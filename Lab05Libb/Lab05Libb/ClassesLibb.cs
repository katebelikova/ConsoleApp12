using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab05Libb
{
    public class Class1
    {
        class Airplane
        {
            public string Model;
            public string Manufacturer;
            public int Capacity;
            public double CruiseSpeed;
            public double MaxRange;
            public string Location;
            public int MaxWeight;

            public double yearIncomePerInhabitant
            {
                get
                {
                    return GetYearIncomePerInhabitant();
                }
            }
            public double GetYearIncomePerInhabitant()
            {
                return 0;
            }
            public void DisplayDetails()
            {
                Console.WriteLine("Модель: " + Model);
                Console.WriteLine("Вирoбник: " + Manufacturer);
                Console.WriteLine("Вмiстимiсть: " + Capacity);
                Console.WriteLine("Крейсерська швидкiсть: " + CruiseSpeed + " км/год");
                Console.WriteLine("Максимальний діапазон: " + MaxRange + " км");
                Console.WriteLine("Мiсцезнаходження: " + Location);
                Console.WriteLine("Максимальна злiтна вага: " + MaxWeight + " кг");
            }

            static void Main(string[] args)
            {
                Airplane airplane = new Airplane();

                Console.Write("Введiть модель лiтака: ");
                airplane.Model = Console.ReadLine();

                Console.Write("Введiть виробника: ");
                airplane.Manufacturer = Console.ReadLine();

                Console.Write("Введiть вмiстимiсть: ");
                airplane.Capacity = int.Parse(Console.ReadLine());

                Console.Write("Введiть крейсерську швидкiсть, км/год: ");
                airplane.CruiseSpeed = double.Parse(Console.ReadLine());

                Console.Write("Введiть максимальний дiапазон, км: ");
                airplane.MaxRange = double.Parse(Console.ReadLine());

                Console.Write("Введiть мiсцезнаходження: ");
                airplane.Location = Console.ReadLine();

                Console.Write("Введiть максимальну злiтну вагу, кг: ");
                airplane.MaxWeight = int.Parse(Console.ReadLine());

                Console.WriteLine("\nХарактеристики лiтака:");
                airplane.DisplayDetails();

            }
        }
    }
}
