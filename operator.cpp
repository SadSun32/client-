#include "operator.h"
using namespace std;

Filer::Filer(const Console & a):resFileName(), amount(0),
                                all_data(), login(), pswd() 
{ // открыть файлы
    
    std::ifstream orFileName;
    std::ifstream authFileName;
    
    orFileName.open(a.getOriginal());
    
    if (!orFileName) 
    {
        cerr<<"No open original file\n";
        exit(1);
    }

    orFileName >> amount;

    for(int i = 0; i < amount; ++i)
    {
        size_t VecSize;
        orFileName >> VecSize;
        all_data.push_back(std::vector<uint64_t>(VecSize));
        for(size_t g = 0; g < VecSize; ++g) 
        {
            if (orFileName.eof())
            {
                cerr << "There is no data in origin file\n";
                exit(1);
            }
            orFileName >> all_data[all_data.size() - 1]->at(g);
        }
    }
    orFileName.close();

    resFileName.open(a.getResult());
   
    resFileName << amount;
    
    authFileName.open(a.getAuth());
     
    if (!authFileName) 
    {
        cerr<<"No open auth file\n";
        exit(1);
    }

    authFileName >> login >> pswd;
    authFileName.close();    
}

Filer::~Filer() 
{
    resFileName.close();
}