#include <iostream>
#include <cstring>
using namespace std;

class Employee // ������� �ǹ��ϴ� Employee Ŭ������ �߰��Ǿ���. ��� ������� �̸��� �����Ƿ�, �̿� ���õ� ������� ������� �����Ͽ���.
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
};

class PermanentWorker : public Employee // ������ Ŭ�������� �������� Employee Ŭ������ ����Ѵٴ� ���̴�. ������ �̸��� ���õ� ����� ��� �����Ͽ���.
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

class EmployeeHandler // ������ ����� PermanentWorker ��ü���� Employee ��ü�� ����Ǿ���. �׷��� PermanentWorker ��ü ���� Employee ��ü�� �����̹Ƿ� ������ �����ϴ�.
{
private:
	Employee* empList[50]; // Employee ��ü�� �ּ� ���� �����ϴ� ������� ��ü�� �����Ѵ�. ���� Employee Ŭ������ ����ϴ� Ŭ������ ��ü�� �� �迭�� �Բ� ������ �����ϴ�.
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }

	void AddEmployee(Employee* emp) // AddEmployee �Լ��� ���ڷ� Employee ��ü�� �ּ� ���� �����ؾ� �Ѵ�. ���� Employee Ŭ������ ����ϴ� PermanentWorker ��ü�� �ּ� ���� ������ �����ϴ�.
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const
	{

	}

	void ShowTotalSalary() const
	{
		int sum = 0;
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
	//���������� �������� ����� ��Ʈ�� Ŭ������ ��ü ����
	EmployeeHandler handler;

	// ���� ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0;
}