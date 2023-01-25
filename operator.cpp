#include "operator.h"
using namespace std;

Filer::Filer(const console & a):orFileName(), authFileName(), resFileName(), amount(0), all_data(), login(), pswd() { // открыть файлы
    orFileName.open(a.getOriginal());
    if (!orFileName) {
        cerr<<"No open original file\n";
        exit(1);
    }
    orFileName >> amount;
    for(int i=0; i<amount; ++i) {
        VectData tmp{0, nullptr};
        orFileName >> tmp.VecSize;
        tmp.vec = new vector<uint64_t>(tmp.VecSize);
        for(int g=0; g<tmp.VecSize; ++g) {
            if (orFileName.eof()) {
                cerr<<"No open file\n";
                exit(1);
            }
            orFileName >> tmp.vec->at(g);
        }
        all_data.push_back(tmp);
    }
    orFileName.close();

    resFileName.open(a.getResult());
   
    resFileName<<amount;
    
    authFileName.open(a.getAuth());
    if (!authFileName) {
        cerr<<"No open auth file\n";
        exit(1);
    }
    authFileName>> login >> pswd;  
    authFileName.close();   
}

Filer::~Filer() {
    resFileName.close();
}
