#ifndef __PARSER_H__
#define __PARSER_H__
# include <iostream>
# include <string>
#include <fstream>
#include "tokenIzer.h"
#include "analyzer.h"

using namespace std;

class parser_t
{
	public:
	
	parser_t():m_tokenizer(new tokenizer_t) ,m_analyzer(new analyzer_t){};
	virtual ~parser_t(){
        delete m_tokenizer;
	    delete m_analyzer;
     };
	
	void ParseFile(const string& _fileName);
	
	private:
	
	parser_t(const parser_t& _p);
	parser_t& operator=(const parser_t& _p);
	ifstream m_file;
	tokenizer_t* m_tokenizer;
	analyzer_t* m_analyzer;
};

#endif