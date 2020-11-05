#include <cstring>
#include <iostream>
#include "str_list.h"

void swap(struct elem* E1, struct elem* E2)
{
	if (!(E1 && E2))
	{
		return ;
	}
	else if (!E1)
	{
		E1 = E2;
		E2 = nullptr;
	}
	else if (!E2)
	{
		E2 = E1;
		E1 = nullptr;
	}
	else
	{
		char a[255];
		strcpy_s(a, 255, (E1->el));
		strcpy_s((E1->el), 255, (E2->el));
		strcpy_s((E2->el), 255, a);
	}
}

long long Str_list::size()
{
	return s;
}

int Str_list::index(struct elem* E)
{
	int i = 0;
	if (!E)
		return -1;
	struct elem* e = Lbegin;
	while (e != E)
	{
		if (e == Lend)
			return -1;
		e = e->next;
		i++;
	}
	return i;
}

bool Str_list::empty()
{
	if (Lbegin == nullptr)
		return true;
	return false;
}

void Str_list::push_back(const char* el)
{
	if (this->empty())
	{
		Lend = new struct elem;
		Lend->next = nullptr;
		Lend->prev = nullptr;
		strcpy_s(Lend->el, 255, el);
		Lbegin = Lend;
	}
	else
	{
		Lend->next = new struct elem;
		Lend->next->prev = Lend;
		Lend = Lend->next;
		Lend->next = nullptr;
		strcpy_s(Lend->el, 255, el);
	}
	s++;
}

void Str_list::push_back(Str_list *S)
{
	struct elem* el = (*S).Lbegin;
	while (el != (*S).Lend)
	{
		this->push_back(el->el);
		el = el->next;
	}
	this->push_back((*S).Lend->el);
}

void Str_list::push_elem(const char* el, int i)
{
	if (i < 0 || i > s)
		return ;
	else if (this->empty())
	{
		Lend = new struct elem;
		Lend->next = nullptr;
		Lend->prev = nullptr;
		strcpy_s(Lend->el, 255, el);
		Lbegin = Lend;
	}
	else
	{
		struct elem *E = new struct elem;
		strcpy_s(E->el, 255, el);
		if (i == 0)
		{
			Lbegin->prev = E;
			E->next = Lbegin;
			E->prev = nullptr;
			Lbegin = E;
		}
		else if (i == s)
		{
			Lend->next = E;
			E->prev = Lend;
			E->next = nullptr;
			Lend = E;
		}
		else
		{
			struct elem* Ep,* En;
			for (Ep = Lbegin; i > 1; i--, Ep = Ep->next);
			En = Ep->next;
			E->next = En;
			E->prev = Ep;
			En->prev = E;
			Ep->next = E;
		}
	}
	s++;
}

void Str_list::pop_elem(int i)
{
	if (i < 0 || i >= s || this->empty())
		return ;
	else if (s == 1)
	{
		delete Lbegin;
		Lbegin = nullptr;
		Lend = nullptr;
	}
	else if (i == 0)
	{
		Lbegin = Lbegin->next;
		delete Lbegin->prev;
		Lbegin->prev = nullptr;
	}
	else if (i == s - 1)
	{
		Lend = Lend->prev;
		delete Lend->next;
		Lend->next = nullptr;
	}
	else
	{
		struct elem *E;
		for (E = Lbegin; i > 0; i--, E = E->next);
		E->prev->next = E->next;
		E->next->prev = E->prev;
		delete E;
	}
	s--;
}

void Str_list::pop_elem(struct elem *E)
{
	if (!E || this->empty() || (this->index(E) == -1))
		return;
	else if (s == 1)
	{
		delete Lbegin;
		Lbegin = nullptr;
		Lend = nullptr;
	}
	else if (E == Lbegin)
	{
		Lbegin = Lbegin->next;
		delete Lbegin->prev;
		Lbegin->prev = nullptr;
	}
	else if (E == Lend)
	{
		Lend = Lend->prev;
		delete Lend->next;
		Lend->next = nullptr;
	}
	else
	{
		E->prev->next = E->next;
		E->next->prev = E->prev;
		delete E;
	}
	s--;
}

struct elem* Str_list::begin()
{
	Str_listIterator I = Str_listIterator(Lbegin);
	return Lbegin;
}

struct elem* Str_list::end()
{
	Str_listIterator I = Str_listIterator(Lend);
	return Lend;
}

void Str_list::clear()
{
	while (s > 0)
		pop_elem(0);
}

char* Str_list::operator[](int i)
{
	if (i < 0 || i >= s)
	{
		char el[1] = "";
		return el;
	}
	struct elem* r;
	for (r = Lbegin; i > 0; r = r->next, i--);
	return r->el;
}

Str_list::Str_list()
{
	Lbegin = nullptr;
	Lend = nullptr;
	s = 0;
}

Str_list::~Str_list()
{
	if (!this->empty())
	{
		this->clear();
	}
}

void Str_list::sort(bool (*s)(struct elem* E1, struct elem* E2))
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		struct elem *E = Lbegin;
		while (E != Lend)
		{
			if (s(E, E->next))
			{
				flag = true;
				break;
			}
			E = E->next;
		}
		if (flag)
		{
			while (s(E, E->next))
			{
				swap(E, E->next);
				E = E->next;
				if (E == Lend)
					break;
			}
		}
	}
}



Str_listIterator::Str_listIterator(struct elem* e = nullptr)
{
	el = e;
}

void Str_listIterator::next()
{
	if (el)
		el = el->next;
}

void Str_listIterator::prev()
{
	if (el)
		el = el->prev;
}

Str_listIterator::operator bool()
{
	return el;
}

Str_listIterator::operator struct elem*()
{
	return el;
}

char* Str_listIterator::operator*()
{
	if (el)
		return el->el;
	else
	{
		char i[1] = "";
		return i;
	}
}

bool Str_listIterator::operator==(struct elem* e)
{
	return el == e;
}

bool Str_listIterator::operator==(Str_listIterator I)
{
	return el == I.el;
}

bool Str_listIterator::operator!=(struct elem* e)
{
	return el != e;
}

bool Str_listIterator::operator!=(Str_listIterator I)
{
	return el != I.el;
}

struct elem* Str_listIterator::operator=(struct elem* e)
{
	return el = e;
}

struct elem* Str_listIterator::operator=(Str_listIterator I)
{
	return el = I.el;
}

struct elem* Str_listIterator::operator++()
{
	this->next();
	return el;
}

struct elem* Str_listIterator::operator--()
{
	this->prev();
	return el;
}