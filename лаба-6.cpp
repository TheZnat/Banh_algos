#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Data {
    int year;
    string group;
    string Name;
    string Surname;
    string MiddleName;
    string phone_number;
};

struct Gr {
    Data d;
    Gr* next;
};

struct Tree {
    Data d;
    Tree* left;
    Tree* right;
};
void findElement(Data l, Tree** p);

Gr* Read(string g);

int list_size(Gr* t);

void list_group(string g);

Tree* head_1;
Tree* head_2;
Tree** returnHead_1(){
    return &head_1;
}
void Tree_1(Gr* gr);
void Print(Gr* gr, string g);
Tree** returnHead_2(){
    return &head_2;
}
Gr* Tree_2(int n, Tree** p, Gr* gr);
void PrintTreeUniversal(Tree** p, int n);

void list_group(string g) {

    Gr* group = Read(g);
    Print(group, g);
    cout << "Дерево простого поиска:" << endl;
    Tree_1(group); PrintTreeUniversal(returnHead_1(), 0);
    cout << "Идеально сбалансированное дерево:" << endl;
    int length = list_size(group);
    Tree_2(length, returnHead_2(), group);
    PrintTreeUniversal(returnHead_2(), 0);
}

Gr* Read(string g) {

    ifstream file("spisok.txt");
    bool f = true;
    string temp;
    Gr* head = NULL;
    Gr* list = NULL;

    while (!file.eof()){
        file >> temp;
        if (temp == g) {
            if (f) {
                list = new Gr;
                list -> next = NULL;
                file >> list -> d.Surname >> list -> d.Name >> list -> d.MiddleName >> list -> d.year >> list -> d.phone_number;
                head = list;
                f = false;
            }
            else {
                list -> next = new Gr; list = list -> next; list -> next = NULL;
                file >> list -> d.Surname >> list -> d.Name >> list -> d.MiddleName >> list -> d.year >> list -> d.phone_number;

            }
        }
        else{
            for(int i = 0; i < 5; i++) {
                file >> temp;
            }
        }
    }
    file.close();
    return head;
}

void Print(Gr* gr, string g) {
    cout << "____________________________________";
    cout << endl << g << endl;
    Gr* list = gr; int count = 0;
    while (list) {
        cout << setw(6) << ++count << setw(10) << list -> d.group << setw(12) << list -> d.Surname<< setw(4)
        << list -> d.Name << setw(4) << list -> d.MiddleName << setw(5) << list -> d.year
        << setw(20) << list -> d.phone_number << endl;
        list = list -> next;
    }
}

int list_size(Gr* t) {
    Gr* p = t;
    int k = 0;
    while (p) {
        k++;
        p = p -> next;
    }
    return k;
}

void Tree_1(Gr* gr) {
    head_1 = NULL;
    Gr* list = gr; Data p;
    while (list){
        p = list -> d;
        findElement(p, &head_1);
        list = list -> next;
    }
}

void findElement(Data l, Tree** p) {
    if (*p == NULL) {
        *p = new Tree; (**p).d = l; (**p).left = NULL; (**p).right = NULL;
    }
    else {
        if (l.Surname < (**p).d.Surname) {
            findElement(l, &((**p).left));
        }else {
            findElement(l, &((**p).right));
        }
    }
}

Gr* Tree_2(int n, Tree** p, Gr* gr) {
    Gr* list = gr; Tree* cur;
    int nl, nr; cur = *p;
    if (n == 0) {
        *p = NULL;
    }else {
        nl = n / 2;
        nr = n - nl - 1;
        cur = new Tree;
        (*cur).d = list->d;
        list = Tree_2(nl, &((*cur).left), list -> next);
        list = Tree_2(nr, &((*cur).right), list);
        *p = cur;
    }
    return list;
}

void PrintTreeUniversal(Tree** p, int n) {
    if (*p != NULL){
        PrintTreeUniversal(&((**p).right), n + 1);
        for (int i = 1; i <= n; i++)
            cout << "    ";
        cout << (**p).d.Surname << endl;
        PrintTreeUniversal(&((**p).left), n + 1);
    }
}

int main(){
    string gr1 = "ИСТ-913";
    list_group(gr1);

    string gr2 = "ИСТ-921";
    list_group(gr2);

    string gr3 = "ИСТ-922";
    list_group(gr3);

    string gr4 = "ИСТ-933";
    list_group(gr4);
}