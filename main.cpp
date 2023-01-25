#include "console.h"
#include "operator.h"
using namespace std;

int main(int argc, char **argv)
{
console a(argc,argv);
Filer op(a);
cout<<op.getAmount()<<endl;
for (int i=0; i < op.getAmount(); i++)
{
	uint64_t * v = op.getVector(i);
	uint64_t s = op.getVectorSize(i);
	cout<<s<<endl;
	for (int i=0; i < s; i++)
	    cout<<'\t'<<v[i]<<endl;
	    }
cout<<"login: "<<op.getLogin()<<endl;	
cout<<"pswd: "<<op.getPswd()<<endl;	   
return 0;
}
