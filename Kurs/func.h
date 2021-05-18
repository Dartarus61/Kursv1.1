#include<fstream>
#include <iostream>
#include<string>
#include<vector>
#include<windows.h>
#include <string>
#include <cstring>
using namespace std;
struct CharNum
{
    char letter;
    int _count;
    string code;
};
struct BRecord {
    int leaf1st;
    char sall;
    string number;
    bool test;
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
void VecFilling();
CharNum VecAlphabet(vector<CharNum>& letters);
void VecSotring(vector<CharNum>& letters, char* buff, int &g);
void binary_tree(vector<CharNum>& letters);
TList AddListEl(vector<CharNum>& letters, int& k);
void Clear();
void treeprint(TList* tree);
void CreateCode(string &code,TList* root, vector<CharNum>& letters);
void codeText(vector<CharNum>& letters, char* info);
void decodetext(vector<CharNum>& letters);
