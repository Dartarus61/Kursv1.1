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
struct BRecord {
    int leaf1st;
    int leaf2st;
    string sall;
};
struct Blist {
    BRecord  rec;
    Blist* next, * prev, * l1st, * l2st;
};


char *TextInput(int &k);
void menu();
void output_money();
void output();
void input();
CharNum fvec();
CharNum abcvec(vector<CharNum>& letters);
int fcount(vector<CharNum>& letters, char* buff, int &g);
