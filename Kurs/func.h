#include<fstream>
#include <iostream>
#include<string>
#include<vector>
#include<windows.h>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;
struct CharNum
{
    char letter;
    int _count;
    string code;
};
struct BRecord {
    int leaf1st;
    int leaf2st;
    char sall;
    string number;
};
struct TList {
    BRecord  Rec;
    TList* Next, * Prev, * list1, * list2;
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
//void preOrderTravers(TTable* root, void(*visit)(TTable*, void*), void* params);
TList AddListEl(vector<CharNum>& letters, int& k);
void Write();
TList *SaveABC(int& ss);
void treeprint(TList* tree);
void CreateCode(char* info, TList* root, vector<CharNum>& letters);
