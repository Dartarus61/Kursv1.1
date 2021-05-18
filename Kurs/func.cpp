#include "func.h"
TList* Head = 0, * Last = 0, * dhead = 0;
CharNum saveStr;
using namespace std;
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
        exit;
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
    char* buff = new char[sr+1];
    memcpy(buff, s.c_str(), s.length() + 2);
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
void VecFilling() { // заполнение вектора
    vector<CharNum> letters;
    VecAlphabet(letters);
    int l = 0;//size of char stroka
    char* cbuff = new char;
    memcpy(cbuff, TextInput(l), strlen(TextInput(l))+1);
    VecSotring(letters, cbuff, l);
    binary_tree(letters);
    string code="";
    cout << "tree" << endl;
    treeprint(Last);
    CreateCode(code,Last, letters);
    codeText(letters, cbuff);
    decodetext(letters);
    cout << '\n';
   Clear(); 
}
void VecSotring(vector<CharNum>& letters, char* buff, int& g) { // сортировка
    int vdl = letters.size();
    size_t dl = strlen(buff);
    auto iter = letters.begin();
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
}
void Clear() {
    //Если он вообще существует
    if (!Head) return;
    //В цикле пройдем последовательно по элементам
    for (Last = Head->Next; Last; Last = Last->Next) {
        delete Last->Prev;
        Head = Last;
    }
    delete Head;
}
TList AddListEl(vector<CharNum>& letters,int &k) {

    TList* r = new TList;
    r->Rec.leaf1st = letters[k]._count;
    r->Rec.sall = letters[k].letter;
    r->Rec.number = '\n';
    r->Next = 0;	r->Prev = 0;
    r->list1 = 0; r->list2 = 0;
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
void treeprint(TList* tree) {
   
    if (tree != 0) { //Пока не встретится пустой узел
       if (tree->list1 == 0 | tree->list2 == 0) exit;
       cout <<" " <<tree->Rec.leaf1st <<" " <<tree->Rec.sall<< endl; //Отображаем корень дерева
       treeprint(tree->list1); //Рекурсивная функция для левого поддерева
       treeprint(tree->list2); //Рекурсивная функция для правого поддерева
    }
}
void binary_tree(vector<CharNum>& letters) {
    int sizev = letters.size();
    int k = 0; //summa vseh chastot
    TList* p;
    TList* help; //вспомогательный указатель №1
    TList* helpme; //вспомогательный указатель №2
    help = Head;
    for (int i = 0; i < sizev; i++) {
        AddListEl(letters, i);
        k += letters[i]._count;
    }
    int leafhelp;
    for (int i = 0; i < sizev - 1; i++) {
        p= addtotree();
        p->Rec.leaf1st = Head->Rec.leaf1st + Head->Next->Rec.leaf1st;
        p->list1 = Head;
        p->list2 = Head->Next;
        helpme = Head;
        Head = Head->Next->Next;
        for (int r = 1; r < sizev - 1; r++)
        {
           
            help = Head;
            
            for (int g = 0; g < sizev - 1 - r; g++)
            {
                 if (help->Next != NULL) {
                    if (help->Rec.leaf1st > help->Next->Rec.leaf1st) {
                        p->list1 = 0; p->list2 = 0;
                        p = p->Prev;
                        p->list1 = helpme; p->list2 = helpme->Next;
                        help->Next->Rec.sall=help->Rec.sall;
                        help->Rec.sall = 0;
                        leafhelp = help->Next->Rec.leaf1st;
                        help->Next->Rec.leaf1st = help->Rec.leaf1st;
                        help->Rec.leaf1st = leafhelp;
                        
                    }
                   
                        help = help->Next;
                    }
                    
            }
        }
       
    }
 
}
void CreateCode(string& code, TList* root, vector<CharNum>& letters)
{
    if (root->list1) {
        code+="0";
        CreateCode(code, root->list1, letters);
   }
    if (root->list2) {
        code+="1";
        CreateCode(code, root->list2, letters);
    }
    if (root->Rec.sall) {
        for (int i = 0; i < letters.size(); i++)
        {
            if (root->Rec.sall == letters[i].letter) {
                root->Rec.number = code;
                letters[i].code = code;
                break;
            }
        }
    }
    if (code.size())
        code.erase(code.length()-1);
}
void codeText(vector<CharNum>& letters, char* info) {
    string testcode;
    for (int i = 0; i < strlen(info); i++) {
        for (int k = 0; k < letters.size(); k++) {
            if (info[i] == letters[k].letter) {
                testcode += letters[k].code;
                testcode += "?";
                break;
            }
        }
    }
    cout << testcode << endl;
    ofstream fout("test.txt");
    if (fout) {
        fout << testcode;
    }
    else {
        cout << "error" << endl;
        exit;
    }
    fout << "\n";
    for (int i = 0; i < letters.size(); i++) {
        fout << letters[i].letter << " " << letters[i].code << endl;
    }
    
    fout.close();
}
void decodetext(vector<CharNum>& letters) {
    ifstream fin("test.txt");
    string s,buf;
    getline(fin, s);
    fin.close();
    size_t sr = s.length();
    ofstream fout("finaltest.txt");
    string str = "?";
    int k =0;
    while (s.find(str)!=-1) {
        k = s.find(str);
        buf.append(s,0,k);
        for (int i = 0; i < letters.size(); i++) {
            if (buf == letters[i].code) {
                fout << letters[i].letter;
                break;
            }
        }
        buf = "";
        s.erase(0, k + 1);
        cout << s << endl;

    }
    fout.close();
}