#ifndef __TOKENIZER_H_
#define __TOKENIZER_H_


#include <string>
#include <vector>
# include <iostream>
# include <string>
# include <iterator>



using namespace std;

class tokenizer_t
{
	public:
	
	tokenizer_t(){};
       
    
    ~tokenizer_t(){};
	
	void Tokenize(const string& _str);

	
	size_t GetSize() const{return m_tokens.size();};
	vector<string> & getTokenVector(){return m_tokens;	}
	
	
	static string&  getTokensDelimiters(){return m_tokensDelimiters;}
	static void setTokensDelimiters(const string & del){
		m_tokensDelimiters=del;
	}

	private:
	
	tokenizer_t(const tokenizer_t& _t);
	tokenizer_t& operator=(const tokenizer_t& _t);
	static string m_tokensDelimiters;
	
	
		
	vector<string> m_tokens;
	vector<string>::iterator m_nextToken;	
};

#endif
