using System;

class Airplane
{
    public string Model;
    public string Manufacturer;
    public int Capacity;
    public double CruiseSpeed;
    public double MaxRange;
    public string Location;
    public int MaxWeight;

    public double YearIncomePerInhabitant
    {
        get
        {
            return GetYearIncomePerInhabitant();
        }
    }

    private double GetYearIncomePerInhabitant()
    {
        return 0;
    }

    public void DisplayDetails()
    {
        Console.WriteLine("Модель: " + Model);
        Console.WriteLine("Виробник: " + Manufacturer);
        Console.WriteLine("Вмiстимiсть: " + Capacity);
        Console.WriteLine("Крейсерська швидкiсть: " + CruiseSpeed + " км/год");
        Console.WriteLine("Максимальний дiапазон: " + MaxRange + " км");
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
