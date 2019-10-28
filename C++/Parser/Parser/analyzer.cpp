# include <iostream>
# include <string>
# include <set>
# include <iterator>
# include <algorithm>
# include <vector>
#include "analyzer.h"

using namespace std;


string analyzer_t::m_predefinedTypesString[] =
	{"char", "short", "int", "long", "float", "double", "void"};
string analyzer_t::m_keyWordsString[] =
	{"if", "else", "for" , "while", "class", 
		"private", "public", "protected", "main", "const", "virtual"};
string analyzer_t::m_operatorsString[] =
	{"++", "--", "==", "->" , "=", "+", "-", "*", "&", "<<", ">>"};
string analyzer_t::m_predefTokensString[] =
	{"(", ")", "[", "]" , "{" , "}", ";", "<", ">" , "=", "+", "-", "*", "&"};

#define NUMOFELEM(ARR) (sizeof(ARR)/sizeof((ARR)[0]))

set<string> analyzer_t::m_predefinedTypesSet
	(m_predefinedTypesString, m_predefinedTypesString + NUMOFELEM(m_predefinedTypesString));
set<string> analyzer_t::m_keyWordsSet
	(m_keyWordsString, m_keyWordsString + NUMOFELEM(m_keyWordsString));
set<string> analyzer_t::m_operatorsSet
	(m_operatorsString, m_operatorsString + NUMOFELEM(m_operatorsString));
set<string> analyzer_t::m_predefTokensSet
	(m_predefTokensString, m_predefTokensString + NUMOFELEM(m_predefTokensString));

void analyzer_t::Init()
{
	m_programStarted = false;
	m_predefTypeEncountered = false;
    this->m_roundBracCount=0;
    this->m_curlyBracCount=0;
    this->m_squareBracCount=0;
    this->m_plusCount=0;
    this->m_minusCount=0;
    this->m_if=false;

	
}

void analyzer_t::PrintEnclErr(const char & brace,const int & countBrace)
{
	if(countBrace > 0)
	{
		cout<<"error - "<<countBrace<<" '"<<brace<<"' not closed"<<endl;
	}
}

void analyzer_t::Finish()
{   m_if=false;
	PrintEnclErr('(', this->m_roundBracCount);
	PrintEnclErr('{', this->m_curlyBracCount);
	PrintEnclErr('[', this->m_squareBracCount);
	
}

bool analyzer_t::IsValidVarName(const string& _token) const
{
	return (isalpha(_token[0]) || _token[0] == '_');
}

void analyzer_t::AnalizeLine(tokenizer_t& _t, size_t _lineNum)
{
	vector<string>::iterator m_nextToken;	
	m_nextToken=_t.getTokenVector().begin();
	

	
	while (m_nextToken!=_t.getTokenVector().end())
	{
		AnalyzeToken(*m_nextToken,_lineNum);
		
		m_nextToken++;
	}
}

bool analyzer_t::CheckEnclosure(const string& _token, const string& _open, const string& _close,  size_t _lineNum, int & count)
{

	
	if(_close == _token)
	{
	    if(this->m_predefTypeEncountered==true){
			cout<<"line "<<_lineNum<<": error - illegal variable name\n"<<endl;
			this->m_predefTypeEncountered=false;
		}	
		if(0 < count)
		{
			count--;
		}else
		{
			cout<<"line "<<_lineNum<<": error - "<<_close<<" without "<<_open<<"\n"<<endl;
		}
		return true;
	}
	if(_open == _token)
	{
		 if(this->m_predefTypeEncountered==true){
			cout<<"line "<<_lineNum<<": error - illegal variable name\n"<<endl;
			this->m_predefTypeEncountered=false;
		}
		count++;
		
		return true;
	}
	return false;	
} 
bool analyzer_t::CheckIf(const string& _token, const string& _if, const string& _else,  size_t _lineNum, bool & count){
  if(_if==_token){
	  if(this->m_predefTypeEncountered==true){
			cout<<"line "<<_lineNum<<": error - illegal variable name\n"<<endl;
			this->m_predefTypeEncountered=false;
		}
	  count=true;
	  return true;
  }else if(_else==_token){
	  if(this->m_predefTypeEncountered==true){
			cout<<"line "<<_lineNum<<": error - illegal variable name\n"<<endl;
			this->m_predefTypeEncountered=false;
		}
	  
	  if(count==false){
		  cout<<"line "<<_lineNum<<": error - "<<_else<<" without "<<_if<<"\n"<<endl;
		  return true;
	  }
	  return true;
  }

  return false;
}

bool analyzer_t::CheckOperators(const string& _token, size_t _lineNum)
{
	
	
	if(_token=="+"){
		if(this->m_predefTypeEncountered==true){
			cout<<"line "<<_lineNum<<": error - illegal variable name\n"<<endl;
			this->m_predefTypeEncountered=false;
		}
		if(this->m_plusCount==2){
			cout<<"line "<<_lineNum<<": error - no operator";
			cout<<_token<<_token<<_token<<"\n"<<endl;
			this->m_plusCount=0;
	        
			return true;
		}else{
			this->m_plusCount++;
			this->m_minusCount=0;
			return true;
		}
	}else if(_token=="-"){
		if(this->m_predefTypeEncountered==true){
			cout<<"line "<<_lineNum<<": error - illegal variable name\n"<<endl;
			this->m_predefTypeEncountered=false;
		}
		if(this->m_minusCount==2){
			cout<<"line "<<_lineNum<<": error - no operator";
			cout<<_token<<_token<<_token<<"\n"<<endl;
			this->m_plusCount=0;
	       
			return true;
		}else{
			this->m_minusCount++;
			this->m_plusCount=0;
			return true;
		}
	}
	this->m_plusCount=0;
	this->m_minusCount=0;
	return false;
	
	
	
}

void analyzer_t::AnalyzeToken(const string& _token,  size_t _lineNum)
{
		
	if(!m_programStarted)
	{
		if(_token != "main")
		{
			cout<<"line "<<_lineNum<<": error - the program doesn't start with 'main'\n"<<endl;
		}
		m_programStarted = true;
	}

		if (CheckOperators(_token,_lineNum))
	{
		return;
	}

	if (CheckEnclosure(_token,"(",")",_lineNum,this->m_roundBracCount) ||
		CheckEnclosure(_token,"[","]",_lineNum,this->m_squareBracCount) ||
		CheckEnclosure(_token,"{","}",_lineNum,this->m_curlyBracCount) ||
		CheckIf(_token,"if","else",_lineNum,this->m_if))
	{
		return;
	}
	

	
	if (m_predefinedTypesSet.find(_token) != m_predefinedTypesSet.end())
	{
		if(m_predefTypeEncountered)
		{
			cout<<"line "<<_lineNum<<": error - multiple type declaration\n"<<endl;
			m_predefTypeEncountered = false;
		}else
		{
			m_predefTypeEncountered = true;
		}
		return;
	}
	
	if(m_predefTypeEncountered)
	{
		if (m_keyWordsSet.find(_token) != m_keyWordsSet.end() ||
			m_operatorsSet.find(_token) !=m_operatorsSet.end()  ||
			m_predefTokensSet.find(_token) !=m_predefTokensSet.end())
		{
			cout<<"line "<<_lineNum<<": error - illegal variable name\n"<<endl;
		}else
		{
			if(m_declaraionNames.find(_token) != m_declaraionNames.end())
			{
				cout<<"line "<<_lineNum<<": error - variable '"<<_token<<"' already declared\n"<<endl;			
			}else
			{
				if(IsValidVarName(_token))
				{
					m_declaraionNames.insert(_token);
				}else
				{
					cout<<"line "<<_lineNum<<": error - illegal variable name\n"<<endl;
				}
			}
		}
		m_predefTypeEncountered = false;
	}else
	{    
		if ((m_keyWordsSet.find(_token) == m_keyWordsSet.end() &&
			m_operatorsSet.find(_token) ==m_operatorsSet.end()  &&
			m_predefTokensSet.find(_token) ==m_predefTokensSet.end() &&
			m_declaraionNames.find(_token) == m_declaraionNames.end()))
		{
			cout<<"line "<<_lineNum<<": error - "<<_token<<" is not declared\n"<<endl;
		}
	}
}
