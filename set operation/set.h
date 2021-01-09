/* set.h -- �������͵�ͷ�ļ� */
#ifndef SET_H_
#define SET_H_

#include <string>

/* �ض���������� */
#define ERROR false
#define	OK true
#define TRUE true
#define	FALSE false
using namespace std;

/* һ�����Ͷ��� */
typedef string ElemType;

typedef struct Node {
	ElemType data;//����Ԫ�� 
	struct Node* next;//��һ���ڵ�ĵ�ַ
}Node, * PNode;//�����ڵ�Ľṹ�� 

typedef struct List {
	PNode head;//���ϵ�ͷ�ڵ�
	PNode tail;//�����е����һ��Ԫ�����ڽڵ� 
	int length;//������Ԫ�صĸ���
}List, * PList;


/* ����ԭ�� */

/* �������� */
bool CreateSet(List& L);
/* ��������_���� */
bool CreateSet(List& L, ElemType* s, int length);

/* ���ټ��� */
bool DestroySet(List& L);

/* ���� */
bool Union(List L1, List L2, List& L3);

/* ���� */
bool Intersection(List L1, List L2, List& L3);

/* ���� */
bool Complement(List L1, List L2, List& L3);

/* � */
bool Difference(List L1, List L2, List& L3);



/* �������Ա� */
bool Copy(List L1, List& L2);

/* �����Ա��� */
bool ListLength(List L, int& index);

/* ��ʼ�����Ա� */
bool InitList(List& L);//��ʼ�����Ա� 

/* �������Ա� */
bool DestroyList(List& L);//�������Ա� 	

/* ������Ա� */
bool ClearList(List& L);//������Ա�


/* ������		��ȡ���Ա�indexλ�õ�Ԫ��					*/
/* 				L ָ��һ���ѳ�ʼ��������				*/
/*				index Ϊ����λ��							*/
/*				e ���ص�i��λ��Ԫ�ص�ֵ				*/
/* ����������	���ҳɹ�����true������ʧ�ܷ���false	*/
bool GetElem(List L, int index, ElemType& e);//��ȡ���Ա�indexλ�õ�Ԫ�� 

/* ������		�������Ա���ֵΪe��Ԫ��				*/
/* 				L ָ��һ���ѳ�ʼ��������				*/
/*				e ΪҪ���ҵ�ֵ						*/
/* ����������	���ҳɹ�����Ԫ��λ�ã�����ʧ�ܷ��� 0	*/
bool LocateElem(List L, ElemType e);//�ж�e�Ƿ���L�У� ���ڷ���false     

/* ������		���e�����Ա�ĩβ				*/
/* 				L ָ��һ���ѳ�ʼ��������				*/
/*				e ΪҪ���ҵ�ֵ						*/
/* ����������	���ҳɹ�����Ԫ��λ�ã�����ʧ�ܷ��� 0	*/
bool Append(List& L, ElemType e);//���e�����Ա�ĩβ               

/* ������		�����Ա��i��λ�ò���Ԫ��				*/
/* 				L ָ��һ���ѳ�ʼ��������				*/
/*				index ΪҪ�����λ��						*/
/*				e ΪҪ�����ֵ						*/
/* ����������	����ɹ�����true������ʧ�ܷ���false	*/
bool InsertElem(List& L, int index, ElemType e);//����e��indexλ��      

/* ������		ɾ�����Ա���ֵΪe��Ԫ��					*/
/* 				L ָ��һ���ѳ�ʼ��������				*/
/*				e ΪҪɾ����Ԫ��ֵ						*/
/* ����������	ɾ���ɹ�����true��ɾ��ʧ�ܷ���false	*/
bool removeElem(List& L, ElemType e);//ɾ�����Ա���eԪ��               

/* ������		ɾ�����Ա��е�i��Ԫ��					*/
/* 				L ָ��һ���ѳ�ʼ��������				*/
/*				index ΪҪɾ����λ��						*/
/* ����������	ɾ���ɹ�����true��ɾ��ʧ�ܷ���false	*/
bool removeIndex(List& L, int index);//ɾ�����Ա���index��Ԫ��         

/* ������		������Ԫ������						*/
/* 				L ָ��һ���ѳ�ʼ���ļ���				*/
/* ����������	����Ԫ�ص�������						*/
bool sort(List& L);//�����Ա�����Ĭ������  

/* ������� */
bool printList(List L);

/* ������		�жϼ�����Ԫ���Ƿ�������				*/
/* 				L Ϊ��Ҫ�жϵļ���					*/
/* ����������	�����֣�����true�����򷵻�false		*/
bool isNum(string str);


#endif