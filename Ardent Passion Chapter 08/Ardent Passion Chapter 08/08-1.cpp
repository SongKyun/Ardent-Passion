#include <iostream>
#include <cstring>
using namespace std;

class Employee // 고용인을 의미하는 Employee 클래스가 추가되었다. 모든 고용인은 이름이 있으므로, 이와 관련된 멤버들을 기반으로 정의하였다.
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy_s(this->name, name);
	}

	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}

	// 가상 함수 추가. // 순수 가상 함수
	virtual int GetPay() const = 0;
	// 가상 함수 추가. // 순수 가상 함수
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee // 이전의 클래스와의 차이점은 Employee 클래스를 상속한다는 점이다. 때문에 이름과 관련된 멤버는 모두 제거하였다.
{
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money)
	{ }

	int GetPay() const
	{
		return salary;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }

	void AddWorkTime(int time)
	{
		workTime += time;
	}

	int GetPay() const
	{
		return workTime * payPerHour;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }

	void AddSalesResult(int value)
	{
		salesResult += value;
	}

	int GetPay() const
	{
		return PermanentWorker::GetPay() // PermanentWorker의 GetPay 함수 호출
			+ (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl; // SalesWorker의 GetPay 함수가 호출됨
	}
};

namespace RISK_LEVEL
{
	enum { RISK_A = 30, RISK_B = 20, RISK_C = 10 };
}

class ForeignSalesWorker : public SalesWorker
{
private:
	const int riskLevel;
public:
	ForeignSalesWorker(const char * name, int money, double ratio, int risk)
		: SalesWorker(name, money, ratio), riskLevel(risk)
	{ }

	int GetRiskPay() const
	{
		return (int)(SalesWorker::GetPay() * (riskLevel/100.0));
	}

	int GetPay() const
	{
		return SalesWorker::GetPay() + GetRiskPay();
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl << endl;
	}

};
class EmployeeHandler // 저장의 대상이 PermanentWorker 객체에서 Employee 객체로 변경되었다. 그러나 PermanentWorker 객체 역시 Employee 객체의 일종이므로 저장이 가능하다.
{
private:
	Employee* empList[50]; // Employee 객체의 주소 값을 저장하는 방식으로 객체를 저장한다. 따라서 Employee 클래스를 상속하는 클래스의 객체도 이 배열에 함께 저장이 가능하다.
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }

	void AddEmployee(Employee* emp) // AddEmployee 함수의 인자로 Employee 객체의 주소 값을 전달해야 한다. 따라서 Employee 클래스를 상속하는 PermanentWorker 객체의 주소 값도 전달이 가능하다.
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const
	{
		// 주석 처리 부분 해제
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}

	void ShowTotalSalary() const
	{
		int sum = 0;
		// 주석 처리 부분 해제
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}

	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main()
{
	//직원관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
	EmployeeHandler handler;

	//해외 영업직 등록
	ForeignSalesWorker* fseller1
		= new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000); // 영업실적 7000
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2
		= new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000); // 영업실적 7000
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3
		= new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000); // 영업실적 7000
	handler.AddEmployee(fseller3);


	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();
	return 0;
}