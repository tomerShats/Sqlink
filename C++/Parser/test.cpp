#include <iostream>
#include "tokenIzer.h"
#include "parser.h"
#include "analyzer.h"


using namespace std;
int main(int argc, char *argv[])
{
	
	parser_t pars;

	for(int i=1 ; i < argc ; ++i)
	{   try{
            pars.ParseFile(argv[i]);
        }catch(int i){
            cout<<"error";
        }
		
	}

	return 0;
}


