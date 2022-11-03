#include <iostream>
using namespace std;

class SinvelCap //  �๰ ĸ��
{
public:
	void Take() const { cout << "�๰�� �� ���´�." << endl; }
};

class SneezeCap // ��ä�� ĸ��
{
public:
	void Take() const { cout << "��ä�� �� ���´�." << endl; }
};

class SnuffleCap // �ڸ��� ĸ��
{
public:
	void Take() const { cout << "�ڰ� ��" << endl; }
};

class ColdPatient
{
public:
	void TakeSinivelCap(const SinvelCap& cap) const { cap.Take(); }
	void TakeSneezeCap(const SneezeCap& cap) const { cap.Take(); }
	void TakeSnuffleCap(const SnuffleCap& cap) const { cap.Take(); }
};

int main()
{
	SinvelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);
	return 0;
}