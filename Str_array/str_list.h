#pragma once

struct elem
{
	char el[255];
	struct elem* next;
	struct elem* prev;
};

class Str_list
{
private:
	struct elem* Lbegin;
	struct elem* Lend;
	int s;
public:
	Str_list();//����������� ������ ������ ������
	~Str_list();//���������� ��� "�������" � �������� ������� ������
	bool empty();//�������� �� �������
	int index(struct elem* E);//���������� ������ ��������. ���� ��� � ������ ������, ���������� -1
	void push_back(const char* el);//����� 1 ������� � �����
	void push_back(Str_list S);//�������� ������ ������ � ����� �����
	void push_elem(const char* el, int i);//����� ������� � ��������� ��������
	void pop_elem(int i);//������� ������� �� �������. ���� ������ �������� ��� ������ �� ������
	void pop_elem(struct elem *e);//������� ������� �� ������ �� ������. ���� ��� ��� � ������ ������ �� ������
	int size();//���������� ������ ������
	void clear();//������� ������
	void sort(bool (*s)(struct elem *E1, struct elem* E2));//��������� ������ �� ������� s

	struct elem* begin();//���������� ������ ������
	struct elem* end();//���������� ����� ������

	char* operator[](int i);//�������� ������� �� �������
};

class Str_listIterator
{
private:
	struct elem* el;
public:
	Str_listIterator(struct elem *e);

	void next();//������ �� �������� ������� � ������
	void prev();//������ �� ���������� ������� � ������

	operator bool();//�������������� � bool ��� �������� �� ������������� ������
	operator struct elem* ();//�������������� � elem* ��� �������� �� ��������� � ����
	char* operator*();//��������� �������� �� ������ �� ����. ���������� ������ ������ ���� ��������� �� 0
	bool operator==(struct elem* e);
	bool operator==(Str_listIterator I);
	bool operator!=(struct elem* e);
	bool operator!=(Str_listIterator I);
	struct elem* operator=(struct elem* e);
	struct elem* operator=(Str_listIterator I);
	struct elem* operator++();//������� �� �������� �����������
	struct elem* operator--();//������� �� ���������� �����������
};