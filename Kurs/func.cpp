#include "func.h"
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<windows.h>
using namespace std;



void output() {
    cout << "Gjiksad";
}

void output_money() {
    cout << "something";
}

void menu() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    void (*Fun_list[3])() = { input, output, output_money };
    int num;
    cout << "welcome to programm of coding by Huffman.\n Enter the comand, what you want:" << endl;
    for (;;) {
        cout << "Coding text - 1\nsomething else #1 - 2\nsomething else #2 - 3\nlogout - 0" << endl;
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

void input() {
    fvec();
}

char* TextInput(int& k) { //считывание текста и запись в бафф
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "rus");
    ifstream fin("inside.txt");
    string s;
    getline(fin, s);
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
CharNum abcvec(vector<CharNum>& letters) { // заполнение вектора алфавитом и цифрами
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
        letters.push_back(data);
        j++;
        if (j > 'z')
            break;
    }
    for (int i = 0; i < n; i++)
    {
        data.letter = bj;
        data._count = 0;
        letters.push_back(data);
        bj++;
        if (bj > 'Z')
            break;
    }
    for (int i = 0; i < 33; i++)
    {
        data.letter = s;
        data._count = 0;
        letters.push_back(data);
        s++;
        if (s > 'я')
            break;
    }
    for (int i = 0; i < 33; i++)
    {
        data.letter = bs;
        data._count = 0;
        letters.push_back(data);
        bs++;
        if (bs > 'Я')
            break;
    }
    for (int i = 0; i < 10; i++)
    {
        data.letter = '0' + i;
        data._count = 0;
        letters.push_back(data);
    }
    data.letter = ' ';
    data._count = 0;
    letters.push_back(data);
    return(data);
}
CharNum fvec() { // заполнение вектора
    vector<CharNum> letters;
    
    abcvec(letters);
    CharNum data;
    data.letter = 'out';
    data._count = 12345;
    int l = 0;
    char* cbuff = new char;
    int w = 0;
    memcpy(cbuff, TextInput(l), strlen(TextInput(l))+1);
    cout << "неправильно: " << cbuff << endl;
    cout << "L=" << l << endl;
    fcount(letters, cbuff, l);
    return (data);
}
int fcount(vector<CharNum>& letters, char* buff, int& g) { // сортировка
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