# include <iostream>
# include <string>
#include "parser.h"
#include "tokenIzer.h"
#include "analyzer.h"


using namespace std;

void parser_t::ParseFile(const string& _fileName)
{ int i=5;
   
	m_file.open(_fileName);

	if(!m_file.good())
	{
		throw i;
	}
	
	m_analyzer->Init();
	string nextLine;
	size_t lineNum = 1;

	while(1)
	{
		getline(m_file,nextLine);
		if(!m_file.good())
		{
			break;
		}
		m_tokenizer->Tokenize(nextLine);
		
		if(0 < m_tokenizer->GetSize())
		{
			m_analyzer->AnalizeLine(*m_tokenizer,lineNum);
		}
		
		++lineNum;
	}
	
	m_analyzer->Finish();
	
	m_file.close();
}