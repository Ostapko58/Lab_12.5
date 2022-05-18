#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;

struct Elem{
	Elem* link;
	int info;
};

void Push(Elem*& top, int value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = top; // 3
	top = tmp; // 4
}

void ReadFromFile(Elem*& top, char* fname)
{
	ifstream f(fname);
	int start = 0, end,value;
	string data;
	getline(f, data);
	while (data.find_first_of("0123456789",start)!=-1)
	{
		start = data.find_first_of("0123456789", start);
		end = data.find_first_of(" ,.",start);
		value = stoi(data.substr(start, end - start));
		Push(top, value);
		start = end+1;
	}

}

void Print(Elem* top)
{
	while (top!=NULL)
	{
		cout << top->info<<"\t";
		top = top->link;
	}
	cout << endl;
}

bool AreTheSame(Elem* top1,Elem* top2)
{
	while (top1!=NULL&&top2!=NULL)
	{
		if (top1->info!=top2->info)
		{
			return false;
		}
		top1 = top1->link;
		top2 = top2->link;
	}
	if (top1==NULL&&top2!=NULL|| top1 != NULL && top2 == NULL)
	{
		return false;
	}
	return true;
}


void New(Elem* top1,Elem * top2,Elem*& top)
{
	while (top1!=NULL)
	{
		if (top1->info<0)
		{
			Push(top, top1->info);
		}
		top1 = top1->link;
	}
	while (top2 != NULL)
	{
		if (top2->info < 0)
		{
			Push(top, top2->info);
		}
		top2 = top2->link;
	}
}

int pop(Elem*& top)
{
	Elem* tmp = top->link; // 1
	int value = top->info; // 2
	delete top; // 3
	top = tmp; // 4
	return value; // 5
}

//void Inverse(Elem* top)
//{
//
//	while (top!=NULL)
//	{
//		top->info = -top->info;
//		top = top->link;
//	}
//}

void Invert1(Elem*& top)
{
	Elem* tmp=NULL;
	while (top != NULL)
	{
		Push(tmp,pop(top));
	}
	top = tmp;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int value,N, menu;
	Elem* top1 = NULL,
		* top2 = NULL,
		* top_new=NULL;
	char fname[] = "data.txt";
	//cout << "¬вед≥ть к≥льк≥сть елемент≥в стеку:"; cin >> N;
	cout << "1 - заповнити 1 файл вручну" << endl;
	cout << "2 - заповнити 1 файл з файлу" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
		cout << "¬вед≥ть к≥льк≥сть елемент≥в стеку:"; cin >> N;
		for (int i = 0; i < N; i++)
		{
			cout << "¬вед≥ть число дл€ ≥нформац≥йного пол€ першого стеку: "; cin >> value;
			Push(top1, value);
			
		}
		break;
	case 2:
		ReadFromFile(top1, fname);
		break;
	default:
		break;
	}
	/*for (int i = 0; i < N; i++)
	{
		cout << "¬вед≥ть число дл€ ≥нформац≥йного пол€ першого стеку: "; cin >> value;
		Push(top1, value);
	}*/

	//cout << "¬вед≥ть к≥льк≥сть елемент≥в стеку:"; cin >> N;
	cout << "1 - заповнити 2 файл вручну" << endl;
	cout << "2 - заповнити 2 файл з файлу" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
		cout << "¬вед≥ть к≥льк≥сть елемент≥в стеку:"; cin >> N;
		for (int i = 0; i < N; i++)
		{
			cout << "¬вед≥ть число дл€ ≥нформац≥йного пол€ першого стеку: "; cin >> value;
			Push(top2, value);

		}
		break;
	case 2:
		ReadFromFile(top2, fname);
		break;
	default:
		break;
	}
	cout << endl;
	//ReadFromFile(top2, fname);

	Print(top1);
	Print(top2);

	AreTheSame(top1, top2);
	if (!AreTheSame(top1, top2))
	{
		New(top1, top2, top_new);
		Print(top_new);
	}
	else
	{
		Invert1(top1);
		Print(top1);
	}
	



	return 0;
}