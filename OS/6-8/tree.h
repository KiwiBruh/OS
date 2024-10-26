#include <stdio.h>
#include <dlfcn.h>

void usage(){
	printf("0. Переключение реализации контрактов\n\n");

	printf("1. Рассчет интеграла функции sin(x) на отрезке [A, B] с шагом e\n");
	printf("USAGE: Float SinIntegral(float A, float B, float e)\n\n");

	printf("2. Подсчёт количества простых чисел на отрезке [A, B] (A, B - натуральные)\n");
	printf("USAGE: Int PrimeCount(int A, int B)\n\n");
}



int main(){
	usage();

	int command;
	int version = 0;

	float (*SinIntegral)(float, float, float);
	int (*PrimeCount)(int, int);

	void *lib1_handler = dlopen("./lib1.so", RTLD_LAZY);
	void *lib2_handler = dlopen("./lib2.so", RTLD_LAZY);

	if (!lib1_handler || !lib2_handler){
	    fprintf(stderr,"dlopen() error: %s\n", dlerror());
	    return -1;
#pragma once
#include <vector>

struct Node {
    int id;
    Node* left;
    Node* right; 
};

class Tree {
public:
    void push(int);
    void kill(int);
    std::vector<int> get_nodes();
    ~Tree();
private:
    Node* root = NULL;
    Node* push(Node* t, int);
    Node* kill(Node* t, int);
    void get_nodes(Node*, std::vector<int>&);
    void delete_node(Node*);
};
