#include"editor.h"


/* ��Ա����-�������� */
// ��̬�洢����
istream& lineList::read(istream& in)
{
	listType::value_type temp;
	// ���뵱ǰ��
	while (getline(in, temp)) {
		L.push_back(temp);
		++line;
	}

	return in;
}

// �������
ostream& lineList::print(ostream& out)
{
	listType::size_type lcount = 0;
	listType::const_iterator it = L.cbegin();
	while (it != L.cend()) {
		//fprintf(out, "%3d. ", ++lcount);
		//if(out==cout)
		out << setw(2) << ++lcount << ". "; //�����ʾ�к��Ա����
		out << *it++ << endl;
	}
	return out;
}

void lineList::word_count() {

	listType::const_iterator it = L.cbegin();
	while (it != L.cend()) {
		// ͳ��Ӣ����ĸ�����ֺͿո�
		for (signed char i : *it) {
			if (isalpha(i))
				alpha++;
			else if (isdigit(i))
				digit++;
			else if (isspace(i))
				space++;
		}

		// ͳ������
		bool flag = false;
		for (signed char i : *it) {
			if (i == ' ')
				flag = false; //�����ǰ�ַ��ǿո���ʹflagΪfalse
			else if (!flag)
			{
				flag = true;
				word++;
			}
		}

		++it;
	}
}



// ͳ���ַ������ִ���
unsigned lineList::string_count(const listType::value_type t, 
	unordered_map<listType::size_type, string> &smatch) {

	unsigned scount = 0; // �ַ������ִ���
	listType::size_type lcount = 0; // ��ǰ��
	// unordered_map<int, string> smatch; // ƥ���Ӵ������е��кź������ݹ��ɵĹ�ϣmap

	listType::value_type s;
	string::size_type kmp_index;
	listType::const_iterator it = L.cbegin();
	while (it != L.cend()) {
		++lcount;
		//s = *it; // ��ǰ���ַ���
		//kmp_index = string::npos; // ƥ���Ӵ��������е�λ��
		//								 
		//// ��ǰ���п����ж���Ӵ�ƥ�䣬
		//// ÿ��ƥ��ɹ����������������ƥ��
		//while ((kmp_index = KMP(s, t)) != string::npos) {
		//	// ƥ�䵽���Ӵ���������һ
		//	++scount;
		//	// ����������ӵ���ϣmap��
		//	smatch.insert(make_pair(lcount, *it));

		//	// ��������
		//	if (kmp_index + t.length() < s.length()) 
		//		s = s.substr(kmp_index + t.length(), s.length() - (kmp_index + 1));
		//}

		kmp_index = 0; // ƥ���Ӵ��������е�λ��
		while ((kmp_index = (*it).find(t, kmp_index)) != string::npos) {
			// ƥ�䵽���Ӵ���������һ
			++scount;
			// ����������ӵ���ϣmap��
			smatch.insert(make_pair(lcount, *it));

			// �����´�ƥ��λ��
			if (kmp_index + t.length() < s.length())
				kmp_index += t.length();
			else
				break;
		}
		++it;
	}

	return scount;
}



// ɾ��ĳһ�Ӵ�
// ɾ���Ӵ���ȫ�ĵ�һ�г���
void lineList::remove_substr(listType::value_type remove_str)
{
	
	listType::value_type::size_type kmp_index;
	listType::iterator it = L.begin();
	while (it != L.end()) {

		if (*it == remove_str) {
			// ���Ҫɾ�����ַ����뵱ǰ����ͬ��ֱ��ɾ������
			L.erase(it);
		}
		else {
			// ����ӵ�ǰ��ƥ���Ӵ���ɾ��
			//kmp_index = string::npos; // ƥ���Ӵ��������е�λ��
			//while ((kmp_index = KMP(*it, remove_str)) != string::npos) {
			//	(*it).erase(kmp_index, remove_str.length());
			//}

			kmp_index = 0; // ƥ���Ӵ��������е�λ��
			while ((kmp_index = (*it).find(remove_str, kmp_index)) != string::npos) {
				(*it).erase(kmp_index, remove_str.length());
				kmp_index = 0;
			}

		}
		++it;
	}
}
// ���ذ汾��ɾ���Ӵ���ָ���еĳ���
void lineList::remove_substr(listType::value_type remove_str, 
	listType::size_type n)
{
	listType::size_type lcount = 0; // ��ǰ��

	listType::value_type::size_type kmp_index;
	listType::iterator it = L.begin();
	while (it != L.end()) {
		// �����ǰ�в���ָ���У���������
		if (++lcount != n)
			continue;

		if (*it == remove_str) {
			// ���Ҫɾ�����ַ����뵱ǰ����ͬ��ֱ��ɾ������
			L.erase(it);
		}
		else {
			// ����ӵ�ǰ��ƥ���Ӵ���ɾ��
			//kmp_index = string::npos; // ƥ���Ӵ��������е�λ��
			//while ((kmp_index = KMP(*it, remove_str)) != string::npos) {
			//	(*it).erase(kmp_index, remove_str.length());
			//}

			kmp_index = 0; // ƥ���Ӵ��������е�λ��
			while ((kmp_index = (*it).find(remove_str, kmp_index)) != string::npos) {
				(*it).erase(kmp_index, remove_str.length());
			}
		}
		// ������ϣ�����ѭ��
		if (lcount == n)
			break;

		++it;
	}
}

// ɾ��ĳһ��
// ���к�ɾ��
void lineList::remove_line(listType::size_type begin_line,
	listType::size_type end_line) {

	// ���ֻ��һ���кţ���ֻɾ��һ��
	if (end_line == 0)
		end_line = begin_line;
	listType::size_type lcount;
	listType::iterator it;
	for (it = L.begin(), lcount = 1; 
		it != L.end() && lcount <= end_line; ++lcount) {
		if (lcount >= begin_line)
			it = L.erase(it);
		else
			++it;
	}
}


/* �ǳ�Ա����-�������� */
// ����������KMP�㷨�����Ӵ�
void getNext(const string& t, string::size_type next[]) {
	string::size_type j = 0, k = string::npos;
	next[0] = string::npos;
	while (j < t.length()) {
		if (k == string::npos || t.at(j) == t.at(k)) {
			++j;
			++k;
			if (t.at(j) != t.at(k))
				next[j] = k;
			else
				next[j] = next[k];
		}
		else
			k = next[k];
	}
}
/* 
 * KMP ģʽƥ���Ӵ�
 * ��ƥ��ɹ������ص�һ��ƥ������λ��
 * ƥ��ʧ�ܣ����� string::npos
 */
string::size_type KMP(const string& s, const string& t) {
//	/*string::size_type*/ int const max_size = max(s.length(), t.length());
	string::size_type next[80];
	string::size_type i=0, j=0;
	getNext(t, next);
	while (i < s.length() && j < t.length()) {
		if (j == string::npos || s.at(i) == t.at(j)) {
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j >= t.length())
		return i - t.length();
	else
		return string::npos;
}



//void strcount(lineList*& lList, const string& str) {
//	// ͳ��Ӣ����ĸ�����ֺͿո�
//	for (const char& i : str) {
//		if (isalpha(i))
//			lList.alpha++;
//		else if (isdigit(i))
//			lList.digit++;
//		else if (isspace(i))
//			lList.space++;
//	}
//
//	// ͳ������
//	bool flag = false;
//	for (const char& i : str) {
//		if (i == ' ') 
//			flag = false; //�����ǰ�ַ��ǿո���ʹflagΪfalse
//		else if (!flag)
//		{
//			flag = true;
//			lList.word++;
//		}
//	}
//}