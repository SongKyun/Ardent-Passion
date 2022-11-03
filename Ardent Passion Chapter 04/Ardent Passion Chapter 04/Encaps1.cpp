#include <iostream>
using namespace std;

class SinvelCap //  Äà¹° Ä¸½¶
{
public:
	void Take() const { cout << "Äà¹°ÀÌ ½Ï ³´´Â´Ù." << endl; }
};

class SneezeCap // ÀçÃ¤±â Ä¸½¶
{
public:
	void Take() const { cout << "ÀçÃ¤±â ½Ï ³´´Â´Ù." << endl; }
};

class SnuffleCap // ÄÚ¸·Èû Ä¸½¶
{
public:
	void Take() const { cout << "ÄÚ°¡ »½" << endl; }
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