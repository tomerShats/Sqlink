# include <iostream>
# include <string>
# include <iterator>
# include <vector>
#include "tokenIzer.h"

using namespace std;


string tokenizer_t::m_tokensDelimiters = "()[]{};<>=+-*&";


void tokenizer_t::Tokenize(const string& _str)
{
	size_t pos, next, len = _str.length();
	m_tokens.clear();
	for(pos = 0, next = 0; next < len ; ++next)
	{
		if(isspace(_str[next]))
		{
			if(next > pos)
			{
				m_tokens.push_back(string(_str,pos,next-pos));
				
			}
			pos = next+1;
		}
		else if(m_tokensDelimiters.find(_str[next]) != string::npos)
		{
			if(next > pos)
			{
				m_tokens.push_back(string(_str,pos,next-pos));
				
			}
			
			m_tokens.push_back(string(1,_str[next]));
			pos = next+1;
		}
	}
	if(pos<next){
		m_tokens.push_back(string(_str,pos,next-pos));
	}
	
	m_nextToken = m_tokens.begin();
}





