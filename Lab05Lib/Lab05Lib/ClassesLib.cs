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
        Console.WriteLine("������: " + Model);
        Console.WriteLine("��������: " + Manufacturer);
        Console.WriteLine("��i����i���: " + Capacity);
        Console.WriteLine("����������� �����i���: " + CruiseSpeed + " ��/���");
        Console.WriteLine("������������ �i������: " + MaxRange + " ��");
        Console.WriteLine("�i��������������: " + Location);
        Console.WriteLine("����������� ��i��� ����: " + MaxWeight + " ��");
    }

    static void Main(string[] args)
    {
        Airplane airplane = new Airplane();

        Console.Write("����i�� ������ �i����: ");
        airplane.Model = Console.ReadLine();

        Console.Write("����i�� ���������: ");
        airplane.Manufacturer = Console.ReadLine();

        Console.Write("����i�� ��i����i���: ");
        airplane.Capacity = int.Parse(Console.ReadLine());

        Console.Write("����i�� ����������� �����i���, ��/���: ");
        airplane.CruiseSpeed = double.Parse(Console.ReadLine());

        Console.Write("����i�� ������������ �i������, ��: ");
        airplane.MaxRange = double.Parse(Console.ReadLine());

        Console.Write("����i�� �i��������������: ");
        airplane.Location = Console.ReadLine();

        Console.Write("����i�� ����������� ��i��� ����, ��: ");
        airplane.MaxWeight = int.Parse(Console.ReadLine());

        Console.WriteLine("\n�������������� �i����:");
        airplane.DisplayDetails();
    }
}
