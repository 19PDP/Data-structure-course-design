#ifndef EDITOR_H_
#define EDITOR_H_

#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <iomanip>
using namespace std;

/* �ǳ�Ա����-�������� */
// KMP�㷨
void getNext(const string& t, string::size_type next[]);
string::size_type KMP(const string& s, const string& t);

/* ���ݽṹ */
struct lineList {
public:
	lineList() {}

	using listType = list<string>;

	/* ��Ա����-�������� */

	// ��ձ༭��
	void clear() { L.clear(); line = 0; }
	// �༭���Ƿ�Ϊ��
	bool empty() { return L.empty(); }

	// �洢����
	istream& read(istream& in = cin);
	// �������
	ostream& print(ostream& out = cout);

	// ͳ��Ӣ����ĸ�������������ո�����������
	void word_count();
	// ͳ��ĳһ�ַ������ִ���
	unsigned string_count(const listType::value_type t,
		unordered_map<listType::size_type, string>& smatch);

	// ɾ��ĳһ�Ӵ������г���
	void remove_substr(listType::value_type remove_str);
	// ɾ��ĳһ�Ӵ���ָ�����еĳ���
	void remove_substr(listType::value_type remove_str,
		listType::size_type n);
	// ����ɾ��ָ������
	void remove_line(listType::size_type begin_line,
		listType::size_type end_line = 0);


	unsigned get_alpha() { return alpha; }
	unsigned get_digit() { return digit; }
	unsigned get_space() { return space; }
	unsigned get_word() { return word; }

private:
	listType L;
	listType::size_type line = 0;

	unsigned alpha = 0;
	unsigned digit = 0;
	unsigned space = 0;
	unsigned word = 0;

};

/* �û��������洦����-�������� */
void select();
// ��������
bool Input();
// ��ʾ��������
bool Display();
// ͳ����������
bool Statistic();
// �����ַ�������ͳ�Ƴ��ִ���
bool Lookup();
// ɾ���ַ���
bool Deletestr();
// ɾ����
bool Deletelin();
// �������
bool Clearup();
// ��������
bool Save();
// ��������
bool Reenter();
// ���������
void clear();


#endif // !EDITOR_H_