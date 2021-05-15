#include "func.h"
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<windows.h>
TList* Head = 0, * Last = 0, * dhead = 0;
CharNum saveStr;
using namespace std;

//TFreq  Freq[256];
//TOpcode  Opcodes[256];
//FILE* in, * out, * assemb;

void entertext() {
    cout << "Enter the text:";
    ofstream fout("inside.txt");
    string gs;
    if (fout) {
        cin.ignore();
        getline(cin, gs);
    }
    else {
        cout << "error" << endl;
    }
    cout << "s=" << gs << endl;
    fout<< gs;
    fout.close();


}

void output_money() {
    cout << "something";
}

void menu() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    void (*Fun_list[3])() = { code, entertext, output_money };
    int num;
    cout << "welcome to programm of coding by Huffman.\n Enter the comand, what you want:" << endl;
    for (;;) {
        cout << "Coding text - 1\nenter text - 2\nsomething else #2 - 3\nlogout - 0" << endl;
        cin >> num;
        //system("cls");
        if (num == 0) {
            cout << "thanks for using my programm" << endl;
            break;
        }
        if (num > 3) {
            cout << "comand was not found" << endl;
            continue;
        }
        Fun_list[num - 1]();
    }
}

void code() {
    VecFilling();
}

char* TextInput(int& k) { //считывание текста и запись в бафф
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "rus");
    ifstream fin("inside.txt");
    string s;
    getline(fin, s);
    fin.close();
    size_t sr = s.length();
    cout << "s=" << s << endl;
    cout << "size of string=" << sr << endl;
    char* buff = new char[sr+1];
    memcpy(buff, s.c_str(), s.length() + 2);
    for (int i = 0; i < sr + 1; i++)
        cout << *(buff + i);
    cout << "\n";
    int rt = strlen(buff);
    cout << "Длина строки из файла " << rt << endl;
    k = strlen(buff);//передать рандом число чтоб записать туда длину 
    return buff;
}
CharNum VecAlphabet(vector<CharNum>& letters) { // заполнение вектора алфавитом и цифрами
    CharNum data;
    const int n = 26;
    char j = 'a';
    char s = 'а';
    char bj = 'A';
    char bs = 'А';
    for (int i = 0; i < n; i++)
    {
        data.letter = j;
        data._count = 0;
        data.code ='\n';
        letters.push_back(data);
        j++;
        if (j > 'z')
            break;
    }
    for (int i = 0; i < n; i++)
    {
        data.letter = bj;
        data._count = 0;
        data.code = '\n';
        letters.push_back(data);
        bj++;
        if (bj > 'Z')
            break;
    }
    for (int i = 0; i < 33; i++)
    {
        data.letter = s;
        data._count = 0;
        data.code = '\n';
        letters.push_back(data);
        s++;
        if (s > 'я')
            break;
    }
    for (int i = 0; i < 33; i++)
    {
        data.letter = bs;
        data._count = 0;
        data.code = '\n';
        letters.push_back(data);
        bs++;
        if (bs > 'Я')
            break;
    }
    for (int i = 0; i < 10; i++)
    {
        data.letter = '0' + i;
        data._count = 0;
        data.code = '\n';
        letters.push_back(data);
    }
    data.letter = ' ';
    data._count = 0;
    data.code = '\n';
    letters.push_back(data);
    return(data);
}
CharNum VecFilling() { // заполнение вектора
    vector<CharNum> letters;
    
    VecAlphabet(letters);
    CharNum data;
    data.letter = 'out';
    data._count = 12345;
    int l = 0;
    char* cbuff = new char;
    int w = 0;
    memcpy(cbuff, TextInput(l), strlen(TextInput(l))+1);
    cout << "неправильно: " << cbuff << endl;
    cout << "L=" << l << endl;
    VecSotring(letters, cbuff, l);
    binary_tree(letters);
    //CreateCode(cbuff, Last, letters);
    /*for (int i = 0; i < letters.size(); i++) {
        cout << letters[i].letter << " " << letters[i].code << endl;
    }*/
    treeprint(Last);
    return (data);
}
int VecSotring(vector<CharNum>& letters, char* buff, int& g) { // сортировка
    int vdl = letters.size();
    size_t dl = strlen(buff);
    auto iter = letters.begin();
    cout << vdl << "<-Длина вектора, длина строки-> " << dl << " " << buff << " dl#2=" << g << endl;
    for (int k = 0; k < vdl; k++)
    {
        for (int i = 0; i < g; i++)
        {
            if (*(buff + i) == letters[k].letter)
            {
                letters[k]._count += 1;
            }
        }
    }
    cout << endl;
    for (int r = 1; r < vdl; r++)
    {
        for (int k = 0; k < vdl - r; k++)
        {
            if (letters[k]._count > letters[k + 1]._count)
            {
                swap(letters[k], letters[k + 1]);
            }
        }
    }
    letters.erase(
        remove_if(
            letters.begin(),
            letters.end(), 
            [](CharNum const& p) {return p._count == 0; }), 
        letters.end());
     vdl = letters.size();
    for (int i = 0; i < vdl; i++)
    {
        cout << letters[i].letter << " " << letters[i]._count << endl;
    }
    
    return 0;
}
TList AddListEl(vector<CharNum>& letters,int &k) {

    TList* r = new TList;
    r->Rec.leaf1st = letters[k]._count;
    r->Rec.sall = letters[k].letter;
    r->Next = 0;	r->Prev = 0;
    if (Last) { Last->Next = r; r->Prev = Last; }
    if (!Head) Head = r;
    Last = r;
    return *r;
}
TList *addtotree() {
    TList* l = new TList;
    l->Rec.leaf1st = 0;
    l->Rec.number = '\n';
    l->Next = 0;	l->Prev = 0;
    if (Last) { Last->Next = l; l->Prev = Last; }
    if (!Head) Head = l;
    Last = l;
 
    
    return l;
}
void Write() {
    //Так же в цикле
    for (Last = Head; Last; Last = Last->Next) {
        //выводим на экран элементы списка
        cout.width(10);
        cout << Last->Rec.leaf1st << "       " << Last->Rec.sall << endl;
    }
}
void Clear() {
    //Если он вообще существует
    if (!Head) return;
    //В цикле пройдем последовательно по элементам
    for (Last = Head->Next; Last; Last = Last->Next) {
        //Освобождая их соседей сзади.
        //т.е. убирая предыдущие
        delete Last->Prev;
        Head = Last;
    }
    delete Head;
}
void treeprint(TList* tree) {
    if (tree != NULL) { //Пока не встретится пустой узел
        cout << tree->Rec.leaf1st << " " << tree->Rec.number << endl;; //Отображаем корень дерева
        treeprint(tree->list1); //Рекурсивная функция для левого поддерева
        treeprint(tree->list2); //Рекурсивная функция для правого поддерева
    }
}
int binary_tree(vector<CharNum>& letters) {
    int sizev = letters.size();
    int k = 0; //summa vseh chastot
    TList* p;
    TList* help;
    for (int i = 0; i < sizev; i++) {
        AddListEl(letters, i);
        k += letters[i]._count;
    }
    int leafhelp;
    for (int i = 0; i < sizev - 1; i++) {
        addtotree();
        p= addtotree();
        p->Rec.leaf1st = Head->Rec.leaf1st + Head->Next->Rec.leaf1st;
        p->list1 = Head;
        p->list2 = Head->Next;
        Head = Head->Next->Next;
        help = Head;
        for (int r = 1; r < sizev - 1; r++)
        {
            help = Head;
            for (int k = 0; k < sizev - 1 - r; k++)
            {
                if (help->Rec.leaf1st > help->Next->Rec.leaf1st) {
                    leafhelp = help->Next->Rec.leaf1st;
                    help->Next->Rec.leaf1st = help->Rec.leaf1st;
                    help->Rec.leaf1st = leafhelp;
                }
                help = help->Next;
            }
        }
    }
    cout << "count of count=" << k << endl;

    return 0;
}
void CreateCode(char* info,  TList* root, vector<CharNum>& letters)
{
    string code;
    if (root->list1 != NULL)
    {
        code += "0";
        CreateCode(info, root->list1,letters);
    }
    if (root->list2 != NULL)
    {
        code += "1";
        CreateCode(info, root->list2,letters);
    }
    else
    {
        for (int i = 0; i < letters.size(); i++)
        {
            if (root->Rec.sall == letters[i].letter)
                letters[i].code = code;
        }
    }
    code.erase(code.length() - 1);
}