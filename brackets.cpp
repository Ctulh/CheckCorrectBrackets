// ConsoleApplication28.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;



//truct stack {
	//int inf;
	//stack* next;
//};
//void build(stack*& NEXT) {
	//NEXT->next = NULL;
//}
class stack {
private:
	char inf;
	stack* next;
public:
	stack() {
		next = NULL;
	}

	void push(const char VALUE)
	{
		stack* tmpstack = new stack;
		tmpstack->inf = VALUE;
		tmpstack->next = next;
		next = tmpstack;
	}
	int pop()
	{
		if (next != NULL) {
			int temp = next->inf;
			stack* MyStack = next;
			next = next->next;
			delete MyStack;
			//std::cout << temp;
			return temp;
		}
		else {
			//cout << "Стек пуст" << endl;
		}
	}
	void show() {
		stack* tmpstack = new stack;
		tmpstack = next;
		if (next != NULL) {
			cout << next->inf << " ";
			while (tmpstack->next != NULL) {
				tmpstack = tmpstack->next;
				cout << tmpstack->inf << " ";
			}
		}
		else {
			cout << "Стек пуст" << endl;
		}
	}

	void delamount(char numb) {
		stack* tmpstack = new stack;
		tmpstack->next = next;
		if ((next->inf == '(')|| (next->inf == '[')|| (next->inf == '{'))
		{
			next = next->next;
		}
		else if (next != NULL)
		{
			for (int i = 0;i < kolvo();i++) 
			{
				if (tmpstack->inf != numb) {
					tmpstack = tmpstack->next;
				}
				else {
					tmpstack = tmpstack->next;
					break;
				}
			}
			
		}
		else
		{
			cout << "Стек пуст" << endl;
		}
	}


	bool empty()
	{
		stack* tmpstack = new stack;
		tmpstack->next = next;
		if (tmpstack == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	int kolvo()
	{
		stack* tmpstack = new stack;
		tmpstack->next = next;
		int i = 0;
		while (tmpstack->next != NULL)
		{
			tmpstack = tmpstack->next;
			i++;
		}
		return i;
	}



	bool search(char ch)
	{
		stack* tmpstack = new stack;
		tmpstack->next = next;
		bool isit = false;
		//cout << endl << "kolvo: " << kolvo() << endl;
		for (int i = 0; i <= kolvo(); i++) {
			if (tmpstack->inf == ch)
			{
				isit = true;
				break;
			}
			else {
				tmpstack = tmpstack->next;
			}
		}
			if (isit == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		
	}
};



	void pushsear(stack& f, char ch)
	{
		if (((ch == ')')&&(f.search('(')>0))|| ((ch == ']') && (f.search('[') > 0))|| ((ch == '}') && (f.search('{') > 0)))
		{
			//cout << "pusher:   f.search=" << f.search('(')<<endl;
			if (f.search('('))
			{
				f.delamount('(');
			}
			else if (f.search('['))
			{
				f.delamount('[');
			}
			else if(f.search('{'))
			{
				f.delamount('{');
			}
		}
		else if (((ch == ')') && (f.search('(') == 0)) || ((ch == ']') && (f.search('[') == 0)) || ((ch == '}') && (f.search('{') == 0)))
		{
			f.push(ch);
		}
		else if((ch=='(')||(ch=='[')||ch=='{')
		{
			f.push(ch);
		}
	}

	bool PENTESTNEPROIDET(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if ((str[i] != '[') && (str[i] != ']') && (str[i] != '(') && (str[i] != ')') && (str[i] != '{') && (str[i] != '}'))
			{
				cout << "You can enter only brackets";
				return false;
			}
			return true;
		}
	}
	


	int main()
	{
		stack* f = new stack;
		string str;
		setlocale(LC_ALL, "Russian");
		cin >> str;
		if (PENTESTNEPROIDET(str)) {
			for (int i = 0; i < str.length(); i++)
			{
				pushsear(*f, str[i]);
			}
			//cout<<"kolvo: " << f->kolvo()<<endl;
			if (f->kolvo() > 0) {
				cout << "wrong count open and close bracktes";
			}
			else {
				cout << "good count open and close bracktes";
			}
		}

	}

