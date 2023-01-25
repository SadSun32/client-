#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "console.h"

using namespace std;
struct VectData{
    uint64_t VecSize;///<размер вектора
    vector<uint64_t> *vec;///<вектор со значениями
};

class Filer
{
private:
    ifstream orFileName;///<Читаем исходный файл
    ifstream authFileName;//<Читаем файл с авторизационными данными
    ofstream resFileName;///<запись в конечный файл
    uint64_t amount;///<количество векторов
    vector<VectData>all_data;///<вектор с данными из структуры
    string login;///< Логин для авторизации
   	string pswd;///< Пароль для авторизации
    
public:
    Filer()=delete;///<запрет конструктора без параметров
    Filer(const console & a);
    ~Filer();///<дecтруктор
    void Write(uint64_t piece){resFileName<<' '<<piece; }///<Запись результатов в файл
    uint64_t getVectorSize(unsigned int numVec){return all_data[numVec].VecSize;}///<Размер одного вектора
    uint64_t* getVector(unsigned int numVec){return all_data[numVec].vec->data();}///<Номер вектора
    uint64_t getAmount(){return amount;}///<Логин для авторизации
    string getLogin()const {return login;}///<Колличество векторов
    string getPswd()const {return pswd;}///<Пароль для авторизации
};
