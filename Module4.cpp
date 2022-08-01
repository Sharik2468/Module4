#include <iostream>
#include <vector>
#include <string>

class Wheel
{
public:
	Wheel() { diametr = 0; }
	Wheel(int diam)
	{
		diametr = diam;
	}
	int GetDiametr() { return diametr; }
private:
	int diametr;
};

class Engine
{
public:
	Engine() { power = 0; }
	Engine(int pow)
	{
		power = pow;
	}
	int GetPower() { return power; }
private:
	int power;
};

class Vehicle
{
public:
	virtual std::ostream& print(std::ostream& out) = 0;
	friend std::ostream& operator<< (std::ostream& out, Vehicle& p)
	{
		return p.print(out);
	}

	virtual int GetPower1() = 0;
};

class WaterVehicle : public Vehicle
{
public:
	std::ostream& print(std::ostream& out) override
	{
		out << "WaterVehicle Draft:" << draft;
		return out;
	}

	WaterVehicle(float dr)
	{
		draft = dr;
	}

	int GetPower1() override { return 0; }
private:
	float draft;
};

class RoadVehicle : public Vehicle
{
public:
	std::ostream& print(std::ostream& out) override
	{
		out << "vrumvrum";
		return out;
	}
	int GetPower1() override { return 0; }
private:
	float ground_clearance;
};

class Bicycle : public RoadVehicle
{
public:
	Bicycle(Wheel wh0, Wheel wh1, int Ride)
	{
		BicycleWheel0 = wh0;
		BicycleWheel1 = wh1;
		Ride_Height = Ride;
	}

	std::ostream& print(std::ostream& out) override
	{
		out << "Bicycle Wheels: " << BicycleWheel0.GetDiametr() << " " << BicycleWheel1.GetDiametr() << " Ride Height: " << Ride_Height;
		return out;
	}

	int GetPower1() override { return 0; }
private:
	Wheel BicycleWheel0;
	Wheel BicycleWheel1;
	int Ride_Height;
};

class Car : public RoadVehicle
{
public:
	Car(Engine eng, Wheel wh0, Wheel wh1, Wheel wh2, Wheel wh3, int ride)
	{
		CarEngine = eng;
		CarWheel0 = wh0;
		CarWheel1 = wh1;
		CarWheel2 = wh2;
		CarWheel3 = wh3;
		Ride_Height = ride;
	}

	std::ostream& print(std::ostream& out) override
	{
		out << "Car Engine: " << CarEngine.GetPower() << " Wheels: " << CarWheel0.GetDiametr() << " " << CarWheel1.GetDiametr() << " " << CarWheel2.GetDiametr() << " " << CarWheel3.GetDiametr() << " Ride Height: " << Ride_Height;
		return out;
	}

	int GetPower1() override { return CarEngine.GetPower(); }
private:
	Engine CarEngine;
	Wheel CarWheel0;
	Wheel CarWheel1;
	Wheel CarWheel2;
	Wheel CarWheel3;
	int Ride_Height;
};

class Point
{
public:
	Point(int f, int s, int t)
	{
		FirstPoint = f;
		SecondPoint = s;
		ThirdPoint = t;
	}
	Point() {}

	std::string GetPoints()
	{
		return std::to_string(FirstPoint) + " " + std::to_string(SecondPoint) + " " + std::to_string(ThirdPoint);
	}

private:
	int FirstPoint;
	int SecondPoint;
	int ThirdPoint;
};

class Circle : public Vehicle
{
public:
	Circle(Point p, int rad)
	{
		CirclePoint = p;
		Radius = rad;
	}

	std::ostream& print(std::ostream& out) override
	{
		out << "Circle Points: " << CirclePoint.GetPoints() << " Radius: " << Radius;
		return out;
	}

	int GetPower1() override { return 0; }
private:
	Point CirclePoint;
	int Radius;
};

float getHighestPower(std::vector<Vehicle*>& v1)
{
	int Max=-999, Curr;
	for (int i = 0; i < v1.size(); i++)
	{
		Curr = v1[i]->GetPower1();
		if (Curr > Max)
			Max = Curr;
	}
	return Max;
}

int main()
{
	std::vector<Vehicle*> v;
	v.push_back(new Car(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 250));
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Car(Engine(200), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 130));
	v.push_back(new WaterVehicle(5000));

	//TODO: Вывод элементов вектора v здесь
	for (int i = 0; i < v.size(); i++)
		std::cout << *v[i] << "\n";

	std::cout << "The highest power is " << getHighestPower(v) << '\n'; // реализуйте эту функцию

	//TODO: Удаление элементов вектора v здесь
	for (int i = 0; i < v.size(); i++)
	{
		v.erase(v.begin() + i);
		std::vector<Vehicle*>(v).swap(v);
	}
}

//int main()
//{
//	Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150);
//
//	std::cout << c << '\n';
//
//	Bicycle t(Wheel(20), Wheel(20), 300);
//	std::cout << t << '\n';
//
//	return 0;
//}