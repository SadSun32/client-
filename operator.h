#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "console.h"

/// @brief Ха-ха, вот это doxygen
class Filer
{
public:
    Filer(const Console & a);
    ~Filer();
    void Write(uint64_t piece){ resFileName << ' ' << piece; }///<Запись результатов в файл
    size_t getVectorSize(size_t numVec)///<Размер numVec вектора
    {
        if(numVec < all_data.size()) 
            return all_data[numVec].size();
    }
    
    std::vector<uint64_t>& getVector(size_t numVec){ return all_data[numVec]; }///<Номер вектора
    uint64_t getAmount() { return amount; }///<Логин для авторизации
    const std::string& getLogin() const {return login;}///<Колличество векторов
    const std::string& getPswd() const {return pswd;}///<Пароль для авторизации

private:
    /// @brief Результирующий файл
    std::ofstream resFileName;
    uint64_t amount;///<количество векторов
    std::vector<std::vector<uint64_t>> all_data;///<вектор с данными из структуры
    std::string login;///< Логин для авторизации
   	std::string pswd;///< Пароль для авторизации
};
