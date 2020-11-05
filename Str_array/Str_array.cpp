#include <iostream>
#include "str_list.h"

#define clс "\033[2J\033[0;0H"

using namespace std;

bool s1(struct elem* E1, struct elem* E2)
{
	if (!E1 && !E2)
	{
		return true;
	}
	else if ((!E1 && E2) || (E1 && !E2))
	{
		return false;
	}
	return strlen(E1->el) > strlen(E2->el);
}

bool s2(struct elem* E1, struct elem* E2)
{
	if (!E1 && !E2)
	{
		return true;
	}
	else if ((!E1 && E2) || (E1 && !E2))
	{
		return false;
	}
	return strlen(E1->el) < strlen(E2->el);
}

int main()
{
	Str_list S;
	string com = "";
	while (com != "exit")
	{
		if (S.size() > 1)
		{
			Str_listIterator P = S.begin();
			while (P != S.end())
			{
				cout << *P << "\n";
				P.next();
			} 
			cout << *P << "\n\n";
		}
		else if (!S.empty())
		{
			Str_listIterator P = S.begin();
			cout << *P << "\n\n";
		}
		cout << "Print:\n-push to add string(char*) to back;\n-add to add string(char*) to Str_list by index;\n-pop to delete element from Str_list by index;\n-iterator to create Iterator;\n-clear to clean list;\n-sort to sort list;\n-exit to exit by program;\n";
		cin >> com;
		if (com == "iterator" && S.empty())
		{

			string a;
			cout << "S is empty.\nWrite anything to continue: ";
			cin >> a;
		}
		else if (com == "iterator" && !S.empty())
		{
			cout << clс;
			Str_listIterator I = nullptr;
			while (com != "exit")
			{
				if (I == nullptr)
				{
					cout << "	I is NullPointer Iterator. Paste its to begin or end?\n		(begin/end): ";
					cin >> com;
					if (com == "begin")
						I = S.begin();
					else if (com == "end")
						I = S.end();
				}
				else
				{

					Str_listIterator P = S.begin();
					while (P != S.end())
					{
						cout << ((I == P) ? '>' : ' ') << *P << ((I == P) ? "<\n" : "\n");
						P.next();
					}
					cout << ((I == P) ? '>' : ' ') << *P << ((I == P) ? "<\n" : "\n") << "	Print:\n	-next to next element;\n	-prev to prev element\n	-begin to begin\n	-end to end\n	-value to get value\n	-index to get index\n	-pop to erase elem in this position\n	-exit ot exit\n";
					cin >> com;
					if (com == "next")
						I.next();
					else if (com == "prev")
						I.prev();
					else if (com == "value")
						cout << *I << endl;
					else if (com == "index")
						cout << S.index(I) << endl;
					else if (com == "pop")
					{
						char a[255];
						cout << "Print string(char*): ";
						cin >> a;
						S.pop_elem((struct elem*)I);
					}
					else if (com != "exit")
					{
						string a;
						cout << "Wrong command\nWrite anything to continue: ";
						cin >> a;
					}
				}
				cout << clс;
			}
			com = "";
		}
		else if (com == "add")
		{
			char a[255];
			int i;
			cout << "Print string(char*)(no more than 255 characters): ";
			cin >> a;
			cout << "and index:";
			cin >> i;
			S.push_elem(a, i);
		}
		else if (com == "push")
		{
			char a[255];
			cout << "Print string(char*)(no more than 255 characters): ";
			cin >> a;
			S.push_back(a);
		}
		else if (com == "clear")
			S.clear();
		else if (com == "pop")
		{
			int i;
			cout << "Print index: ";
			cin >> i;
			S.pop_elem(i);
		}
		else if (com == "sort")
		{
			int i;
			cout << "Select function:\n1-more len\n2-less len\n";
			cin >> i;
			switch (i)
			{
			case (1):
				S.sort(&s1);
				break;
			case (2):
				S.sort(&s2);
				break;
			default:
				string a;
				cout << "Wrong number\nWrite anything to continue: ";
				cin >> a;
				break;
			}
		}
		else if (com != "exit")
		{
			string a;
			cout << "Wrong command\nWrite anything to continue: ";
			cin >> a;
		}
		cout << clс;
	}
	return 0;
}
