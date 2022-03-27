#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//通讯录结构体
struct Addressbooks
{
	//通讯录中保存联系人的数组
	struct Person personArray[MAX];
	//通讯录中记录当前联系人个数
	int m_Size;
};

//1、添加联系人
void addPerson(Addressbooks * abs)
{
	//判断通讯录人数是否已满，如果满了就不能再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		while (true)
		{
			//如果输入的是正确值1或者2，可以退出循环。
			//如果输入有误，重新输入。
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入错误请重新输入！" << endl;
		}

		//年龄
		int age = 0;
		cout << "请输入用户年龄：" << endl;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 100) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入错误，请输入0-100之间的整数。" << endl;
		}

		//电话
		string phone;
		cout << "请输入用户电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		string addr;
		cout << "请输入用户住址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//更新通讯录人数
		abs->m_Size++;

		//提示用户添加成功
		cout << "添加成功" << endl;

		//系统命令
		system("pause"); //请安任意键继续
		system("cls"); //清屏
	}
}

//2、显示联系人
void showPerson(Addressbooks * abs)
{
	//判断通讯录中是否有人
	if (abs->m_Size==0)
	{
		cout << "通讯录中还没有联系人，请添加联系人。" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause"); //请安任意键继续
	system("cls"); //清屏
}

//根据姓名，检测联系人是否存在，如果存在返回联系人所在数组下标，若果不存在返回-1.
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//遍历寻找用户输入的姓名
		if (abs->personArray[i].m_Name == name)
		{
			return i; //寻找到返回联系人在数组的位置下标.
		}
    }
	return -1; //遍历结束还没有找到该联系人则返回-1。
}

//3、删除指定联系人
void deletePerson(Addressbooks * abs)
{
	cout << "请输入您要删除的联系人姓名" << endl;

	string name;
	cin >> name;
	
	//ret = -1 说明没有找到此人。
	//ret != -1 说明找到此人，此时i=联系人所在数组下标。
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//利用后一个人把前一个人覆盖的方式删除
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //更新通讯录中人数。
		cout << "删除" << name << "成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause"); //请安任意键继续
	system("cls"); //清屏
}

//4、查找指定联系人
void findPerson(Addressbooks* abs)
{
	cout << "输入你要查找联系人的姓名" << endl;
	string name;
	cin >> name;

	//ret = -1 说明没有找到此人。
	//ret != -1 说明找到此人，此时i=联系人所在数组下标。
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause"); //请安任意键继续
	system("cls"); //清屏
}

//5、修改指定联系人
void modifPerson(Addressbooks* abs)
{
	cout << "请输入要修改联系人的名字" << endl;
	string name;
	cin >> name;
	//ret = -1 说明没有找到此人。
	//ret != -1 说明找到此人，此时i=联系人所在数组下标。
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		while (true)
		{
			//如果输入的是正确值1或者2，可以退出循环。
			//如果输入有误，重新输入。
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入错误请重新输入！" << endl;
		}

		//年龄
		int age = 0;
		cout << "请输入用户年龄：" << endl;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 100) {
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入错误，请输入0-100之间的整数。" << endl;
		}

		//电话
		string phone;
		cout << "请输入用户电话：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		string addr;
		cout << "请输入用户住址：" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;

		//提示用户添加成功
		cout << "添加成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause"); //请安任意键继续
	system("cls"); //清屏
}

//6、清空联系人
void cleanPerson(Addressbooks* abs)
{
	int a = 0;
	cout << "是否要清空所有联系人" << endl << "\"是\"请输入:1,\"否\"请输入2。" << endl;
	while (true)
	{
		cin >> a;
		switch (a)
		{
		case 1:
			abs->m_Size = 0;
			cout << "清空成功" << endl;
			return;
			//break;
		case 2:
			cout << "取消成功" << endl;
			return;
			//break;
		default:
			cout << "输入错误请重新输入" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

//菜单页面
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

int main()
{

	//创建通讯录结构体变量
	Addressbooks abs;

	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0; //创建用户选择输入的变量

	while (true)
	{
		//菜单调用
		showMenu();

		cout << "请输入你要进行的操作:" << endl;

		cin >> select; //用户输入命令

		switch (select)
		{
		case 1: //1、添加联系人
			addPerson(&abs);
			break;
		case 2: //2、显示联系人
			showPerson(&abs);
			break;
		case 3: //3、删除联系人
			deletePerson(&abs);
			break;
		case 4: //4、查找联系人
			findPerson(&abs);
			break;
		case 5: //5、修改联系人
			modifPerson(&abs);
			break;
		case 6: //6、清空联系人
			cleanPerson(&abs);
			break;
		case 0: //0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause"); //请按任意键继续

	return 0;
}