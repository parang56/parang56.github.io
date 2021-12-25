#include <iostream>
using namespace std;

class Car //기본 연료 자동차
{
private:
	int gasolineGauge;
public:
	Car(int gasoline): gasolineGauge(gasoline)
	{ }
	
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car //하이브리드 자동차
{
private:
	int electricGauge;
public:
	HybridCar(int gasoline, int electric): Car(gasoline), electricGauge(electric)
	{ }
		
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar //하이브리드 워터카
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gasoline, int electric, int water): HybridCar(gasoline,electric), waterGauge(water)
	{ }
	
	void ShowCurrentGauge()
	{
		cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
		cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
		cout<<"잔여 워터량: "<<waterGauge<<endl;
	}
};

int main(void)
{
	int gasoline=5,electric=10,water=15;
	HybridWaterCar car(gasoline,electric,water);
	car.ShowCurrentGauge();
	return 0;
}