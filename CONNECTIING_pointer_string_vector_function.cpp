#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdbool.h>
using namespace std;

int i;

string vector_sum (vector <string>* v1, vector <string>* v2, int* sit1, int* sit2);
void vector_sum_antistoixa (vector <string>* v1, vector <string>* v2, vector <string>* v_sum);
vector <string>* vector_sum_antistoixa_new (vector <string>* v1, vector <string>* v2);

int main()
{
system("color f1");
	
	vector <string> v1;
	vector <string> v2;
	vector <string> v3;
	int sit1,sit2;
	string a;
	
	cout<<"8eseis vectora 1: ";
	cin>>sit1;
	
	cout<<"8eseis vectora 2: ";
	cin>>sit2;
	
	for (i=0; i<sit1; ++i)
	{
		cout<<"Dwse stoixeio "<<(i+1)<<" tou vectora 1: ";
		cin>>a;
		v1.push_back(a);
	}
	
	for (i=0; i<sit2; ++i)
	{
		cout<<"Dwse stoixeio "<<(i+1)<<" tou vectora 2: ";
		cin>>a;
		v2.push_back(a);
	}
	
	//askhsh 1
	
	string all_are_one=vector_sum(&v1, &v2, &sit1, &sit2);
	cout<<endl<<all_are_one<<endl<<endl;
	
	//askhsh 2 tropos 1
	
	vector_sum_antistoixa(&v1, &v2, &v3);
	for (i=0; i<v3.size(); ++i)
	{
		cout<<v3[i]<<endl;
	}
	cout<<endl;
	
	//askhsh 2 tropos 2

	vector <string> v4=*(vector_sum_antistoixa_new(&v1, &v2));
	for (i=0; i<v4.size(); ++i)
	{
		cout<<v4[i]<<endl;
	}

system("pause");
}

//askhsh1 function
string vector_sum (vector <string>* v1, vector <string>* v2, int* sit1, int* sit2)
{
	string all_are_one=(*v1)[0];
	
	for(i=1; i<(*sit1); ++i)
	{
        all_are_one+=(*v1)[i];
	}
	
	for(i=0; i<(*sit2); ++i)
	{
        all_are_one+=(*v2)[i];
	}

	return all_are_one;
}

//askhsh 2 tropos 1 function
void vector_sum_antistoixa (vector <string>* v1, vector <string>* v2, vector <string>* v_sum)
{
	int min,diference;
	_Bool flag=0;

	if ((*v1).size()<(*v2).size())
	{
		min=(*v1).size();
		diference=(*v2).size()-(*v1).size();
		flag=0;
	}else{
		min=(*v2).size();
		diference=(*v1).size()-(*v2).size();
		flag=1;
	}

	for(i=0; i<min; ++i)
	{
        (*v_sum).push_back((*v1)[i]+(*v2)[i]);
	}

	if (flag)
	{
		for (i=min; i<(min+diference); ++i)
		{
			(*v_sum).push_back((*v1)[i]);
		}
	}else{
		for (i=min; i<(min+diference); ++i)
		{
			(*v_sum).push_back((*v2)[i]);
		}
	}
}

//askhsh 2 tropos 2 function
vector <string>* vector_sum_antistoixa_new (vector <string>* v1, vector <string>* v2)
{
	int min,diference;
	vector <string>* v_sum;
	_Bool flag=0;

	if ((*v1).size()<(*v2).size())
	{
		min=(*v1).size();
		diference=(*v2).size()-(*v1).size();
		flag=0;
	}else{
		min=(*v2).size();
		diference=(*v1).size()-(*v2).size();
		flag=1;
	}

	for(i=0; i<min; ++i)
	{
        (*v_sum).push_back((*v1)[i]+(*v2)[i]);
	}

	if (flag)
	{
		for (i=min; i<(min+diference); ++i)
		{
			(*v_sum).push_back((*v1)[i]);
		}
	}else{
		for (i=min; i<(min+diference); ++i)
		{
			(*v_sum).push_back((*v2)[i]);
		}
	}
	return &(*v_sum);
}
