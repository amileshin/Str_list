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
	Str_list();//Конструктор создаёт пустой список
	~Str_list();//Деструктор для "красоты" и удаления пустого списка
	bool empty();//Проверка на пустоту
	int index(struct elem* E);//Возвращает индекс элемента. Если нет в данном списке, возвращает -1
	void push_back(const char* el);//Кладёт 1 элемент в конец
	void push_back(Str_list S);//Копирует другой список в конец этого
	void push_elem(const char* el, int i);//Кладёт элемент с указанным индексом
	void pop_elem(int i);//Удаляет элемент по индексу. Если такого элемента нет ничего не делает
	void pop_elem(struct elem *e);//Удаляет элемент из списка по ссылке. Если его нет в списке ничего не делает
	int size();//Возвращает длинну списка
	void clear();//Очищает список
	void sort(bool (*s)(struct elem *E1, struct elem* E2));//сортирует массви по функции s

	struct elem* begin();//Возвращает начало списка
	struct elem* end();//Возвращает конец списка

	char* operator[](int i);//получает элемент по индексу
};

class Str_listIterator
{
private:
	struct elem* el;
public:
	Str_listIterator(struct elem *e);

	void next();//перехд на следущий элемент в списке
	void prev();//перехд на предидущий элемент в списке

	operator bool();//преобразование в bool для проверки на существования ссылки
	operator struct elem* ();//преобразование в elem* для проверки на равенство с ними
	char* operator*();//Получение элемента по ссылке на него. Возвращает пустую строку если ссылается на 0
	bool operator==(struct elem* e);
	bool operator==(Str_listIterator I);
	bool operator!=(struct elem* e);
	bool operator!=(Str_listIterator I);
	struct elem* operator=(struct elem* e);
	struct elem* operator=(Str_listIterator I);
	struct elem* operator++();//переход на следущий инкрементом
	struct elem* operator--();//переход на предидущий декрементом
};