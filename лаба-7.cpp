#include <iostream>
#include <string>

#define V 5
#define INT_MAX 2147483647

using namespace std;

template <typename T>
class My_vector{
private:
    T* data;
    int length;
    int size;
public:
    My_vector(){
        data = new T[1];
        length = 0;
        size = 1;
    }
    My_vector(int n){
        data = new T[n];
        length = 0;
        size = n;
    }
    void push_back(int value){

        if(length == size){
            throw new exception;
        }
        data[length] = value;
        ++length;
    }
    T pop_back(){
        if(length == 0){
            throw new exception;
        }
        --length;
        return data[length + 1];
    }
    void print(){
        for(int i = 0; i < length; ++i){
            cout<< data[i] << " ";
        }
        cout << "\n";
    }
    string toString(){
        string str = "";
        for(int i = 0; i < length; ++i){
            str += to_string(data[i]) + " ";
        }
        return str;
    }
    int get_size(){
        return size;
    }
    int get_length(){
        return length;
    }
    T& operator[] (const int index){
        if(index >= size){
            throw new exception;
        }
        return data[index];
    };
    const T& operator[] (const int index) const{
        if(index >= size){
            throw new exception;
        }
        return data[index];
    };
};

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int min(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

bool next_permutation(My_vector<int> vertex){

    int j = vertex.get_length() - 2;
    while (j != -1 && vertex[j] >= vertex[j + 1]){
        j--;
    }
    if (j == -1){
        return false;
    }
    int k = vertex.get_length() - 1;
    while (vertex[j] >= vertex[k]){
        k--;
    }
    swap(vertex[j], vertex[k]);
    int l = j + 1, r = vertex.get_length() - 1;
    while (l<r){
        swap(vertex[l++], vertex[r--]);
    }
    return true;
}
string travllingSalesmanProblem(int graph[][V], int s){

    string way = "";
    ::My_vector<int> vertex(V);
    for (int i = 0; i < V; i++){
        if (i != s){
            vertex.push_back(i);
        }
    }
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.get_length(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        if(min_path > current_pathweight){
            min_path = current_pathweight;
            way = vertex.toString();
        }
    } while (next_permutation(vertex));
    cout << "Minimal path: " << min_path<<"\n";
    return way;
}
int main(){
    int graph[][V] = { { 0, 5, 3, 4, 4 },
                       { 5, 0, 3, 5, 6 },
                       { 3, 3, 0, 4, 7 },
                       { 4, 5, 4, 0, 7 },
                       { 4, 6, 7, 7, 0} };
    int s = 0;
    cout << "_________________" << endl;
    cout <<"Way is: " << s << endl << travllingSalesmanProblem(graph, s) << s;
}