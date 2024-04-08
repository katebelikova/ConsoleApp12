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
        airplane.Model = "Tecnam P2008";
        airplane.Manufacturer = "Iталiйське виробництво";
        airplane.Capacity = 2;
        airplane.CruiseSpeed = 215;
        airplane.MaxRange = 1065;
        airplane.Location = "Польща";
        airplane.MaxWeight = 600;

        Console.WriteLine("\nХарактеристики лiтака:");
        airplane.DisplayDetails();
    }
}



