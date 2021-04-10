#include<fstream>
#include <iostream>
#include<string>
#include<vector>
#include<windows.h>
#include <string>
using namespace std;
struct CharNum
{
    char letter;
    int _count;
};

char *TextInput(int &k);
void menu();
void output_money();
void output();
void input();
CharNum fvec();
CharNum abcvec(vector<CharNum>& letters);
int fcount(vector<CharNum>& letters, char* buff, int &g);
