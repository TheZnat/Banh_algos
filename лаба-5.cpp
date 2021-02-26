#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct UzerId {
    string number;
    int id;
    int year;
    string Name;
    string  Surname;
    string MiddleName;
    UzerId *next;
    UzerId *previous;
} Uzer;

Uzer *head = 0;
ifstream inp;
ofstream outp;

void Info(string);

Uzer *add(string name, string surname, string мiddle_name, int year, string phone_number) {

    if (!head) {
        head = new Uzer{phone_number, 1, year, name, surname, мiddle_name, 0, 0};
        head -> next = head;
        head -> previous = head;
        return head;
    }
    Uzer *temp = head;
    while (temp -> next != head)
        temp = temp -> next;
    return head -> previous = (temp -> next = new Uzer{phone_number, temp -> id + 1, year, name, surname, мiddle_name ,head, temp});
}

Uzer *get(int id) {

    if (!head) {
        cout << "Пусто" << "\n";
        return 0;
    }
    Uzer *temp = head;
    while (temp -> next -> id != 1) {
        if (temp -> id != id)
            temp = temp -> next;
        else
            break;
    }
    if (!temp -> id != id) {
        return head;
    }
    else {
        return temp;
    }
}

void Del(int id) {

    if (!head) {
        cout << "Пусто" << endl;
        return;
    }
    Uzer *temp = head;
    do {
        if (temp -> id == id) {
            if (temp == head) {
                if (head -> next -> id == 1) {
                    head = 0;
                    break;
                } else {
                    Uzer *_temp = head;
                    head -> next -> previous = head -> previous;
                    head -> previous -> next = head -> next;
                    head = head -> next;
                    delete _temp;
                    break;
                }
            } else {
                temp -> next -> previous = temp -> previous;
                temp -> previous -> next = temp -> next;
                delete temp;
                break;
            }
        }
        temp = temp -> next;
    } while (temp != head);
    if (head) {
        temp = head;
        for (int i = 1;; i++) {
            temp -> id = i;
            if (temp -> next -> id == 1) {
                break;
            }
            temp = temp -> next;
        }
    }
}

void Edit(int id) {

    Uzer *temp = head;
    Uzer *to_change;

    if (!head) {
        cout << "Элемент " << id << " не найден" << endl;
        return;
    }

    while (temp -> next != head) {
        if (temp -> id == id) {
            break;
        }
        temp = temp -> next;
    }
    if (temp -> id != id) {
        cout << "Элемент " << id << " не найден" << endl;
        return;
    } else {
        int int_temp = -1;
        cout << "id элемента: " << temp -> id << endl;
        cout << "Изменить:" << endl;
        cout << " 1 ФИО 3 Номер  2 Год 8 Выйти" << endl <<" : ";
        cin >> int_temp;

        switch (int_temp) {
            case 8: {
                cout << endl;
                return;
            }
            case 1: {
                cout << " Имя: " << temp -> Name << endl;
                cout << " Фамилия: " << temp -> Surname << endl;
                cout << " Фамилия: " << temp -> MiddleName << endl;
                cout << " Новое имя: ";
                cin >> temp -> Name;
                cout << " Новая фамилия: ";
                cin >> temp -> Surname;
                cout << " Новое отчиство: ";
                cin >> temp -> MiddleName;
                break;
            }
            case 2: {
                cout << " Дата: " << temp -> year<< endl;
                cout << " Новая дата:";
                cin >> temp -> year;
                break;
            }
            case 3: {
                cout << " Номер: " << temp -> number << endl;
                cout << " Новый номер: >> ";
                cin >> temp -> number;
                break;
            }
        }
        cout << "Готово" << endl;
    }
}

void Save(string path) {

    if (!head) {
        cout << "Пусто" << endl;
        return;
    }
    outp.open(path);
    Uzer *temp = head;
    do {
        string temp_str;
        outp << temp -> id << "|" << temp -> Name << "|" << temp -> Surname << "|"<< temp -> MiddleName
        << "|" << temp -> year << "|" << temp -> number << ".";
        if (temp -> next != head) {
            outp << '\n';
        }
        temp = temp -> next;
    } while (temp != head);
    outp.close();
    cout << "Сохраненино" << endl;
}

void Load(string path) {

    string to_return;
    string temp;
    inp.open(path);
    if (inp.is_open()) {
        while (!inp.eof()) {
            inp >> temp;
            to_return += temp;
        }
        inp.close();
        Info(to_return);
    } else {
        cout << "Файл не найден" << endl;
    }
}

void Info(string input) {

    string **to_return;
    char separator = '|';
    int amount_of_strings = 0;
    for (int i = 0; i < strlen(input.c_str()); i++) {
        if (input[i] == '.') {
            amount_of_strings++;
        }
    }
    to_return = new string *[amount_of_strings];
    for (int i = 0; i < amount_of_strings; i++) {
        to_return[i] = new string[5];
    }
    for (int i = 0, j = 0, cur_string = 0; i < input.length(); i++) {
        if (input[i] == separator) {
            j++;
            continue;
        }
        if (input[i] == '.') {
            add(to_return[cur_string][4],to_return[cur_string][4], to_return[cur_string][4],stoi(to_return[cur_string][2]), to_return[cur_string][2]);
            if (amount_of_strings <= cur_string + 1)
                break;
            else cur_string++;
            j = 0;
        }
        to_return[cur_string][j] += input[i];
    }
    cout << "Загружено " << amount_of_strings << " элементов " << endl;
    delete[] to_return;
}
int main() {
    int Num_Operation = 0;

    while (true) {
        cout<<"______Все операции______\n"
              "1 Load - загрузить файл данных\n"
              "2 Save - сохранить файл данных с диска\n"
              "3 Edit – редактировать выбранную запись(узел)\n"
              "4 Add – добавить запись(узел)\n"
              "5 Delete – удалить запись(узел)\n"
              "6 Show  – показать все \n"
              "7 Find – поиск элемента\n"
              "8 Exit – выход из программы с очисткой памяти от списка\n"
              "------------------------- \n"
              "Ввидите номер операции \n";
        cin >>  Num_Operation;

        switch ( Num_Operation) {
            case 1: {
                Load("File.txt");
                break;
            }
            case 2: {
                Save("File.txt");
                break;
            }
            case 3: {
                int id = 0;
                cout << "id: ";
                cin >> id;
                Edit(id);
                break;
            }
            case 4: {
                string name;
                string surname;
                string phone_number;
                string мiddle_name;
                int year;

                cout << "Добавление элемента:" << endl;
                cout << "Имя:  ";
                cin >> name;
                cout << "Фамилия:  ";
                cin >> surname;
                cout << "Отчество:  ";
                cin >> мiddle_name;
                cout << "Год рождения: ";
                cin >> year;
                cout << "Номер телефона: ";
                cin >> phone_number;

                cout << "Элемент " << add(name, surname, мiddle_name, year, phone_number) -> id << " добавлен " << endl;
                break;
            }
            case 5: {
                int id = 1;
                cout << "id:  ";
                cin >> id;
                Del(id);
                cout << endl;
                break;
            }
            case 6: {
                if (!head) {
                    cout << "Нет элементов" << endl;
                    break;
                }
                Uzer *temp = head;
                do {
                    cout  << temp -> id << ") " << temp -> Name << " "<< temp -> Surname <<" "<< temp -> MiddleName
                           <<" "<< temp -> year<<" "<< temp -> number << endl;
                    temp = temp -> next;
                } while (temp != head);
                cout << endl;
                break;
            }
            case 7: {
                if (!head) {
                    cout << "Пусто" << "\n\n";
                    break;
                }
                Uzer *temp = head;
                int id = 0;
                cout << "id: ";
                cin >> id;
                do {
                    if (temp -> id == id) {
                        cout << endl << temp -> id  << ") " << temp -> Name << " " << temp -> Surname
                        <<" " << temp -> MiddleName << " " << temp -> year << " " << temp -> number  << endl;
                        break;
                    }
                    temp = temp -> next;
                } while (temp != head);
                if (temp -> id != id)
                    cout << "Элемент " << id << " не найден " << endl;
                break;
            }
            default:break;
        }
        if ( Num_Operation == 8) {
            cout << "Досвидания";
            break;
        }
    }
}
