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

	// ���� �Լ� �߰�.
	virtual int GetPay() const
	{
		return 0;
	}
	// ���� �Լ� �߰�.
	virtual void ShowSalaryInfo() const
	{ }
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
		return PermanentWorker::GetPay() // PermanentWorker�� GetPay �Լ� ȣ��
			+ (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl; // SalesWorker�� GetPay �Լ��� ȣ���
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
		// �ּ� ó�� �κ� ����
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}

	void ShowTotalSalary() const
	{
		int sum = 0;
		// �ּ� ó�� �κ� ����
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
	//���������� �������� ����� ��Ʈ�� Ŭ������ ��ü ����
	EmployeeHandler handler;

	// ���� ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// �ӽ��� ���
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5); // 5�ð� ���� ��� ���
	handler.AddEmployee(alba);

	// ������ ���
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000); // �������� 7000
	handler.AddEmployee(seller);

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0;
}