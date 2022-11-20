#include <iostream>
using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char * fname,int fage)
		: age(fage)
	{
		name = new char[strlen(fname) + 1];
		strcpy(name, fname);
	}
	 
	void ShowMyFriendInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이 : " << age << endl;
	}
	
	~MyFriendInfo()
	{
		delete[]name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char * fname,int fage, const char * adr, const char * pnum)
		: MyFriendInfo(fname,fage)
	{
		addr = new char[strlen(adr) + 1];
		phone = new char[strlen(pnum) + 1];
		strcpy(addr, adr);
		strcpy(phone, pnum);
	}

	void ShowMyFrienDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << endl << endl;
	}

	~MyFriendDetailInfo()
	{
		delete[]addr;
		delete[]phone;
	}
};

int main()
{
	MyFriendDetailInfo fren1("김진성", 22, "충남 아산", "010-22-222");
	MyFriendDetailInfo fren2("이주성", 19, "경기 인천", "010-222-111");
	fren1.ShowMyFrienDetailInfo();
	fren2.ShowMyFrienDetailInfo();
	return 0;
}