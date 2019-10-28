#ifndef __PARSER_H__
#define __PARSER_H__
# include <string>
#include <fstream>
class tokenizer_t;
class analyzer_t;


class parser_t
{
	public:
	
	parser_t();

	virtual ~parser_t();
       
	void ParseFile(const std::string& _fileName);
	
	private:
	
	parser_t(const parser_t& _p);
	parser_t& operator=(const parser_t& _p);
	std::ifstream m_file;
	tokenizer_t* m_tokenizer;
	analyzer_t* m_analyzer;
};

#endif