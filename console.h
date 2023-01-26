#pragma once
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
using namespace std;

class Console
{
public:
    Сonsole (int argc,char **argv);
    // "геттеры" с результатами разбора параметров
    std::string getIP() const {return ip_;}  ///<Адресс, на котором работает сервер
    uint16_t    getPort() const {return port_;} ///<Порт, на котором работает сервер
    std::string getAuth() const {return auth_;} ///<Возвращает путь к файлу для авторизации
    std::string getOriginal() const {return original_;} ///<Возвращает путь к файлу с исходными данными 
    std::string getResult() const {return result;}///<Возвращает путь к файлу с результатами

private:
	// атрибуты
    int portLen;///<Длина порта
    uint16_t port_ = 33333;///< Порт, на котором работает сервер

    std::string auth_ = "vclient.conf";///< Путь к файлу с данными для авторизации
    std::string ip_;///< Адрес, на котором работает сервер
    std::string original_;///< Путь к файлу с исходными данными 
    std::string result_;///< Путь к файлу с результатами 
};
