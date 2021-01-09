#include <iostream>
#include <algorithm>

#include "set.h"
using namespace std;


// ���ؼ��ϵ���������
ostream& operator<<(ostream& output, List& L) {
	printList(L);
	return output;
}
void inputSet(List& set);
void select();


int main() {
	printf("\t                              ��������                 \n");
	printf("\t                              ʹ��˵��                 \n");
	select();

	while (true) {
	Lab:	List set1;
		List set2;
		List set3;
		CreateSet(set3);
		cout << "   �����뼯�ϣ�����ʾ��: {1,2,3,4,8}��{\"word\",\"ppt\",\"append\"}��{'a','b','c','f'}\n\n";
		cout << "�����뼯��A:";
		inputSet(set1);
		cout << "�����뼯��B:";
		inputSet(set2);
		cout << "\n����������ɣ����������\n";

		//select();
		while (true) {
			cout << "\n��ѡ�������";
			int ch;
			cin >> ch;
			switch (ch) {
			case 1:
				Intersection(set1, set2, set3); 
				cout << set3; ClearList(set3); 
				break;//���� 
			case 2:
				Union(set1, set2, set3); 
				cout << set3; ClearList(set3); 
				break;//���� 
			case 3:
				Complement(set1, set2, set3); 
				cout << set3; ClearList(set3); 
				break;//!A��AUBΪȫ����
			case 4:
				Complement(set2, set1, set3); 
				cout << set3; ClearList(set3); 
				break;//!B��AUBΪȫ���� 
			case 5:
				Difference(set1, set2, set3); 
				cout << set3; ClearList(set3); 
				break;//A-B
			case 6:
				Difference(set2, set1, set3); 
				cout << set3; ClearList(set3); 
				break;//B-A
			case 7:
				DestroySet(set1); 
				DestroySet(set2); 
				DestroySet(set3);
				cout << endl;
				goto Lab;//�������뼯�� 
			case 8:
				DestroySet(set1); 
				DestroySet(set2); 
				DestroySet(set3); 
				return 0;//�˳� 
			default:
				cout << "��������!"; 
				break;
			}
		}
	}

	return 0;
}


void select() {
	printf("\t***------------------------------------------------------------***\n");
	printf("\t###  ��ѡ��: 1.����:A��B                2.����:AUB             ###\n");
	printf("\t###          3.����:!A��AUBΪȫ����    4.����:!B��AUBΪȫ����  ###\n");
	printf("\t###          5.�:A-B                6.�:B-A               ###\n");
	printf("\t###          7.�������뼯��            8.�˳�                  ###\n");
	printf("\t***------------------------------------------------------------***\n");
}

void inputSet(List& set) {
	ElemType* deal;
	int length;
	while (1) {
		string str;
		cin >> str;

		if (str.length() == 2) {
			deal = new string[0];
			length = 0;
			break;
		}

		int former = str.find("{");
		int later = str.find("}");
		int count_former = count(str.begin(), str.end(), '{');
		int count_later = count(str.begin(), str.end(), '}');
		int count_Elem = count(str.begin(), str.end(), ',') + 1;
		//�������Ϸ���
		if (former != 0 || later != str.length() - 1 || count_former != 1 || count_later != 1) {
			cout << "��������:����������:";
		}
		else {
			deal = new string[count_Elem];

			str[0] = ',';
			str[str.length() - 1] = ',';
			//��ȡԪ�� 
			for (unsigned current = 0, next, i = 0; current < str.length() && i < count_Elem; i++) {
				next = str.find_first_of(',', current + 1);
				deal[i] = str.substr(current + 1, next - current - 1);
				current = next;
			}
			length = count_Elem;

			break;
		}
	}

	CreateSet(set, deal, length);
	delete[] deal;// 
}