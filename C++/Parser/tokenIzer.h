#ifndef __TOKENIZER_H_
#define __TOKENIZER_H_


#include <string>
#include <vector>
#include <set>
# include <iostream>
# include <string>



using namespace std;

class tokenizer_t
{
	public:
	
	tokenizer_t(): m_tokensDelimiters("()[]{};<>=+-*&"),m_blankDelimiters(" \t\n\r\v\f"){
       
    };
    ~tokenizer_t(){};
	
	void Tokenize(const string& _str);

	
	size_t GetSize() const{return m_tokens.size();};
	
	const string& GetNextToken(); 

	private:
	
	tokenizer_t(const tokenizer_t& _t);
	tokenizer_t& operator=(const tokenizer_t& _t);
	const string m_tokensDelimiters;
	const string m_blankDelimiters;
	const string m_emptyString;
	
		
	vector<string> m_tokens;
	vector<string>::iterator m_nextToken;	
};

#endif
