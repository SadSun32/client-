#pragma once
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
using namespace std;

class console{
private:
	// атрибуты
    int portLen;///<Длина порта
    int ipLen;///<Длина адреса
    int NameLen;///<Длина имени файла
    bool useIp = false; // использование адреса сервера 
	bool useOriginal = false; // использование имени файла с исходными данными
	bool useResult = false; //  использование файла для записи результатов
    void help(const char *progName);///<вывод подсказки и остановка программы
public:
	unsigned short int port=33333;///< Порт, на котором работает сервер
	string auth="vclient.conf";///< Путь к файлу с данными для авторизации
    string ip;///< Адрес, на котором работает сервер
    string original;///< Путь к файлу с исходными данными 
    string Result;///< Путь к файлу с результатами 
    console()=delete;///<запрет конструктора без параметров

    console (int argc,char **argv);
    // "геттеры" с результатами разбора параметров
    string getIP() const {return ip;}  ///<Адресс, на котором работает сервер
    unsigned short int getPort() const {return port;} ///<Порт, на котором работает сервер
    string getAuth() const {return auth;} ///<Возвращает путь к файлу для авторизации
    string getOriginal() const {return original;} ///<Возвращает путь к файлу с исходными данными 
    string getResult() const {return Result;}///<Возвращает путь к файлу с результатами
    bool isIp() {return useIp;} // использование адресса сервера 
	bool isOriginal() {return useIp;} // использование имени файла с исходными данными
	bool isResult() {return useResult;} // использование файла для записи результатов
};
