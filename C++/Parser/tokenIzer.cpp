# include <iostream>
# include <string>
#include "tokenIzer.h"

using namespace std;

void tokenizer_t::Tokenize(const string& _str)
{
	size_t pos, next, len = _str.length();
	m_tokens.clear();
	for(pos = 0, next = 0; next <= len ; ++next)
	{
		if(m_blankDelimiters.find(_str[next]) != string::npos)
		{
			if(next > pos)
			{
				m_tokens.push_back(_str.substr(pos,next-pos));
			}
			pos = next+1;
		}
		else if(m_tokensDelimiters.find(_str[next]) != string::npos)
		{
			if(next > pos)
			{
				m_tokens.push_back(_str.substr(pos,next-pos));
			}
			
			m_tokens.push_back(_str.substr(_str[next],1));
			pos = next+1;
		}
	}
	
	 m_nextToken = m_tokens.begin();
}


/*const string& tokenizer_t::GetNextToken()
{	
	if(m_nextToken == m_tokens.end())
	{
		return s_emptyString;
	}
	
	return *(m_nextToken++);
}
*/