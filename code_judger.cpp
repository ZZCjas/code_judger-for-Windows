#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h> 
using namespace std;
void color(int x)
{
	if(x>=0 && x<=15)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}
char* File(char* filename)
{
	char* text;
	FILE *pf = freopen(filename,"r",stdin);
	fseek(pf,0,SEEK_END);
	long lSize = ftell(pf);
	text=(char*)malloc(lSize+1);
	rewind(pf); 
	fread(text,sizeof(char),lSize,pf);
	text[lSize] = '\0';
	freopen("CON","r",stdin);
	return text;
}
int main(int argc, char* argv[]) 
{
	if(argc!=4)
	{
		cout<<"Parameters error!\n";
		cout<<"Status: ";
		color(5);
		cout<<"RE\n";
		color(7);
		return 1;
	}
	cout<<"Start judging,wait please..."<<endl;
	system(argv[1]);
	char *store=File(argv[3]);
	if(strcmp(store,File(argv[2]))==0)
	{
		cout<<"Judge finish,outcome:\n";
		cout<<"Status: ";
		color(2);
		cout<<"AC\n";
		color(7);
		return 0;
	}
	else
	{
		cout<<"Judge finish,outcome:\n";
		cout<<"Status: ";
		color(4);
		cout<<"WA\n";
		color(7);
		return 0;
	}
	return 0;
}
