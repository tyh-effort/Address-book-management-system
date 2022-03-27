#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//��ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա�
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б�����ϵ�˵�����
	struct Person personArray[MAX];
	//ͨѶ¼�м�¼��ǰ��ϵ�˸���
	int m_Size;
};

//1�������ϵ��
void addPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�����Ƿ�������������˾Ͳ��������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		while (true)
		{
			//������������ȷֵ1����2�������˳�ѭ����
			//������������������롣
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "����������������룡" << endl;
		}

		//����
		int age = 0;
		cout << "�������û����䣺" << endl;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 100) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "�������������0-100֮���������" << endl;
		}

		//�绰
		string phone;
		cout << "�������û��绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		string addr;
		cout << "�������û�סַ��" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//����ͨѶ¼����
		abs->m_Size++;

		//��ʾ�û���ӳɹ�
		cout << "��ӳɹ�" << endl;

		//ϵͳ����
		system("pause"); //�밲���������
		system("cls"); //����
	}
}

//2����ʾ��ϵ��
void showPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼���Ƿ�����
	if (abs->m_Size==0)
	{
		cout << "ͨѶ¼�л�û����ϵ�ˣ��������ϵ�ˡ�" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause"); //�밲���������
	system("cls"); //����
}

//���������������ϵ���Ƿ���ڣ�������ڷ�����ϵ�����������±꣬���������ڷ���-1.
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//����Ѱ���û����������
		if (abs->personArray[i].m_Name == name)
		{
			return i; //Ѱ�ҵ�������ϵ���������λ���±�.
		}
    }
	return -1; //����������û���ҵ�����ϵ���򷵻�-1��
}

//3��ɾ��ָ����ϵ��
void deletePerson(Addressbooks * abs)
{
	cout << "��������Ҫɾ������ϵ������" << endl;

	string name;
	cin >> name;
	
	//ret = -1 ˵��û���ҵ����ˡ�
	//ret != -1 ˵���ҵ����ˣ���ʱi=��ϵ�����������±ꡣ
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//���ú�һ���˰�ǰһ���˸��ǵķ�ʽɾ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //����ͨѶ¼��������
		cout << "ɾ��" << name << "�ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause"); //�밲���������
	system("cls"); //����
}

//4������ָ����ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "������Ҫ������ϵ�˵�����" << endl;
	string name;
	cin >> name;

	//ret = -1 ˵��û���ҵ����ˡ�
	//ret != -1 ˵���ҵ����ˣ���ʱi=��ϵ�����������±ꡣ
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause"); //�밲���������
	system("cls"); //����
}

//5���޸�ָ����ϵ��
void modifPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸���ϵ�˵�����" << endl;
	string name;
	cin >> name;
	//ret = -1 ˵��û���ҵ����ˡ�
	//ret != -1 ˵���ҵ����ˣ���ʱi=��ϵ�����������±ꡣ
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		while (true)
		{
			//������������ȷֵ1����2�������˳�ѭ����
			//������������������롣
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "����������������룡" << endl;
		}

		//����
		int age = 0;
		cout << "�������û����䣺" << endl;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 100) {
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "�������������0-100֮���������" << endl;
		}

		//�绰
		string phone;
		cout << "�������û��绰��" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//סַ
		string addr;
		cout << "�������û�סַ��" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;

		//��ʾ�û���ӳɹ�
		cout << "��ӳɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause"); //�밲���������
	system("cls"); //����
}

//6�������ϵ��
void cleanPerson(Addressbooks* abs)
{
	int a = 0;
	cout << "�Ƿ�Ҫ���������ϵ��" << endl << "\"��\"������:1,\"��\"������2��" << endl;
	while (true)
	{
		cin >> a;
		switch (a)
		{
		case 1:
			abs->m_Size = 0;
			cout << "��ճɹ�" << endl;
			return;
			//break;
		case 2:
			cout << "ȡ���ɹ�" << endl;
			return;
			//break;
		default:
			cout << "�����������������" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

//�˵�ҳ��
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

int main()
{

	//����ͨѶ¼�ṹ�����
	Addressbooks abs;

	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0; //�����û�ѡ������ı���

	while (true)
	{
		//�˵�����
		showMenu();

		cout << "��������Ҫ���еĲ���:" << endl;

		cin >> select; //�û���������

		switch (select)
		{
		case 1: //1�������ϵ��
			addPerson(&abs);
			break;
		case 2: //2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: //3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4: //4��������ϵ��
			findPerson(&abs);
			break;
		case 5: //5���޸���ϵ��
			modifPerson(&abs);
			break;
		case 6: //6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0: //0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause"); //�밴���������

	return 0;
}