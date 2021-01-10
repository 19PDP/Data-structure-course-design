#define _CRT_SECURE_NO_WARNINGS
#include "editor.h"
#include <fstream>
#include <cstdio>

using namespace std;

lineList line_editor;

int main() {

	printf("\t                   ���б༭��               \n");
	printf("\t                    ʹ��˵��                 \n");

	//select();
	int choose = 1;
	//cin >> choose;
	while (choose) {
		select();
		cin >> choose; 
		//clear();
		if (choose >= 2 && choose <= 8 && line_editor.empty()) {
			cout << "\n�����������£�\n";
			continue;
		}

		switch (choose)
		{
		case 1:
			if (Input()) {
				cout << "\n����������ɣ������������\n";
				//select();
				//cin >> choose; clear();
			}
			else{
				cout << "\n����ʧ�ܣ������²���:\n";
				line_editor.clear();
				//select();
				//cin >> choose; clear();
			}
			break;

		case 2:
			if (!line_editor.empty() && Display()) {
				cout << "\n�����ɣ����������: \n";
				//select();
			}
			break;

		case 3:
			if (!line_editor.empty() && Statistic()) {
				cout << "\nͳ����ɣ����������: \n";
				//select();
			}
			break;

		case 4:
			if (Lookup()) {
				cout << "\n������ɣ����������:\n";
			}
			else
				cout << "\n����ʧ�ܣ������²���\n";
			break;

		case 5:
			if (Deletestr()) {
				cout << "\nɾ����ɣ����������\n";
			}
			else
				cout << "\nɾ��ʧ�ܣ������²���\n";
			break;

		case 6:
			if (Deletelin()) {
				cout << "\nɾ����ɣ����������\n";
			}
			else
				cerr << "\nɾ��ʧ�ܣ������²���\n";
			break;

		case 7:
			if (Clearup()) {
				cout << "\n�����ɣ����������\n";
			}
			break;

		case 8:
			if (Save()) {
				cout << "\n������ɣ����������\n";
			}
			else
				cout << "\n����ʧ�ܣ������²���\n";
			break;

		case 9:
			if (Reenter()) {
				cout << "\n����ձ༭������������������: \n";
				if (Input()) {
					cout << "\n����������ɣ������������\n";
				}
				else {
					cout << "\n����ʧ�ܣ������²���:\n";
				}
			}
			break;
		case 0:
			break;
		default:
			cerr << "\n����ָ������� 0~9 ��������\n";
			break;
		}
		
	}

	cout << "\nллʹ��!" << endl;
	return 0;
}

/* �û��������洦�����-�������� */

void select() {
	printf("\t***---------------------------------------------***\n");
	printf("\t###  ��ѡ��: 1.��������         2.��ʾ��������  ###\n");
	printf("\t###          3.ͳ����������     4.�����ַ���    ###\n");
	printf("\t###          5.ɾ���ַ���       6.ɾ����        ###\n");
	printf("\t###          7.�������         8.��������      ###\n");
	printf("\t###          9.��������         0.�˳�          ###\n");
	printf("\t***---------------------------------------------***\n");
}


// ��������
bool Input() {
	int choose;
	string file_way;
	ifstream infile;
	cout 
		<< "-->�������£���ѡ��" << endl
		<< "---->1. ��������" << endl
		<< "---->2. �ļ�����" << endl;
	cin >> choose;
	clear();
	switch (choose)
	{
	case 1:
		cout << "-->���������� ���� <Ctrl+Z> �Խ������룺" << endl;
		line_editor.read();
		cin.clear();
		cin.eof();
		break;
	case 2:
		cout << "-->�������ļ������� <readme.txt> ��";
		cin >> file_way;
		infile.open(file_way);
		if (!infile) {
			cerr << "\n��⣡û�гɹ����ļ��������ļ�����·���Ƿ���ȷ��\n";
			return false;
		}
		else {
			cout << "\n�ɹ����ļ��������ļ��ж�ȡ����....." << endl;
			line_editor.read(infile);
		}
		break;
	default:
		cerr << "\n�������룡���������� 1 �� 2 ��" << endl;
		return false;
		break;
	}
	//cout << "����������ɣ������������\n";
	return true;
}

// ��ʾ��������
bool Display() {
	line_editor.print();
	return true;
}

// ͳ����������
bool Statistic() {
	int choose;
	line_editor.word_count();

	cout 
		<< "-->ͳ���������ݣ���ѡ��" << endl
		<< "---->1. ͳ��ȫ����ĸ��" << endl
		<< "---->2. ͳ�����ָ���" << endl
		<< "---->3. ͳ�ƿո����" << endl
		<< "---->4. ͳ������������" << endl
		<< "---->5. ͳ������ȫ��" << endl;
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "\n��ƪ�����У�ȫ����ĸ��Ϊ: " << line_editor.get_alpha() << endl;
		break;
	case 2:
		cout << "\n��ƪ�����У����ָ���Ϊ: " << line_editor.get_digit() << endl;
		break;
	case 3:
		cout << "\n��ƪ�����У��ո����Ϊ: " << line_editor.get_space() << endl;
		break;
	case 4:
		cout << "\n��ƪ�����У�������Ϊ: " << line_editor.get_word() << endl;
		break;
	case 5:
		cout 
			<< "\n��ƪ�����У�ȫ����ĸ��Ϊ: " << line_editor.get_alpha() << endl
			<< "              ���ָ���Ϊ: " << line_editor.get_digit() << endl
			<< "              �ո����Ϊ: " << line_editor.get_space() << endl
			<< "                ������Ϊ: " << line_editor.get_word() << endl;
		break;
	default:
		cerr << "\n�������룡���������� 1 ~ 5 ��" << endl;
		return false;
		break;
	}
	return true;
}

// �����ַ�������ͳ�Ƴ��ִ���
bool Lookup() {
	string str;
	unsigned scount = 0;
	char choose;
	unordered_map<list<string>::size_type, 
		string> smatch; // ƥ���Ӵ������е��кź������ݹ��ɵĹ�ϣmap
	
	cout << "-->������Ҫ���ҵ��ַ���: " << endl;
	cin >> str;
	if (str.length() > 80) {
		cerr << "\n��⣡���ҵ��ַ���̫������";
		return false;
	}

	scount = line_editor.string_count(str, smatch);
	cout << "\n�ַ��� " + str + " ����ƪ�����г�����" << scount << "�Σ�" << endl;

	cout << "\n������ʾ���ǵľ���λ����(y/n): ";
	cin >> choose; clear();

	while (choose != 'y' && choose != 'n' && choose != 'Y' && choose != 'N') {
		cerr << "-->������ y/Y �� n/N : ";
	}

	if (choose == 'y' || choose == 'Y') {
		cout << "\n�ַ��� " + str + " ������" << scount << "�Σ�����: " << endl;
		unordered_map<list<string>::size_type, string>::const_iterator it
			= smatch.cbegin();
		while (it != smatch.cend()) {
			cout << "   ��" << it->first << "��: " + it->second << endl;
			++it;
		}
	}
	return true;
}

// ɾ���ַ���
bool Deletestr() {
	int choose;
	string delestr;
	list<string>::size_type lin;

	cout
		<< "-->ɾ���ַ�������ѡ��" << endl
		<< "---->1. ɾ�����������г���" << endl
		<< "---->2. ɾ��ָ�����еĳ���" << endl;
	cin >> choose; clear();
	cout << "\n������Ҫɾ�����ַ���: ";
	cin >> delestr;

	switch (choose)
	{
	case 1:
		line_editor.remove_substr(delestr);
		break;
	case 2:
		cout << "-->�������к�: ";
		cin >> lin;
		line_editor.remove_substr(delestr, lin);
		break;
	default:
		cerr << "\n�������룬���������� 1 �� 2 ! " << endl;
		return false;
		break;
	}
	return true;
}

// ɾ����
bool Deletelin() {
	list<string>::size_type beg, end=0;

	cout << "-->������Ҫɾ����������[m,n]��m ����С�ڵ��� n������ <4,5> <6,6> : ";
	if (scanf("%lu,%lu", &beg, &end) != 2) {
		cerr << "\n�������룬����������[m,n]��mС�ڵ���n ! " << endl;
		clear();
		return false;
	}

	line_editor.remove_line(beg, end);
	return true;
}

// �������
bool Clearup() {
	line_editor.clear();
	return true;
}

// ��������
bool Save() {
	string file_way;

	cout << "-->�����뱣���ļ��� ��<writeme.txt> ��";
	cin >> file_way;
	ofstream outfile(file_way);
	if (!outfile) {
		cerr << "\n��⣡û�гɹ����ļ��������ļ�����·���Ƿ���ȷ��\n";
		return false;
	}
	else {
		cout << "\n�ɹ����ļ������ڽ����±��浽�ļ�....." << endl;
		line_editor.print(outfile);
	}
	return true;
}

// ��������
bool Reenter() {
	line_editor.clear();
	return true;
}


// ��ϴ������
void clear() {
	while (getchar() != '\n')
		continue;
}