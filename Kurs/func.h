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
struct TList {
    BRecord  Rec;
    TList* Next, * Prev, * l1st, * l2st;
};


char *TextInput(int &k);
void menu();
void output_money();
void entertext();
void code();
CharNum VecFilling();
CharNum VecAlphabet(vector<CharNum>& letters);
int VecSotring(vector<CharNum>& letters, char* buff, int &g);
int binary_tree(vector<CharNum>& letters);
void AddListEl(vector<CharNum>& letters, int& k);
void Write();
