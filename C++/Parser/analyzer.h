#ifndef __ANALYZER_H_
#define __ANALYZER_H_

#include <vector>
#include <map>
#include <string>
# include <iostream>
#include "tokenIzer.h"



using namespace std;

class analyzer_t
{
	public:
	
	analyzer_t():m_predefinedTypesString[]({"char", "short", "int", "long", "float", "double", "void"}),
	m_keyWordsString[]({"if", "else", "for" , "while", "class", "private", "public", "protected", "main", "const", "virtual"}),
	m_operatorsString[]({"++", "--", "==", "->" , "=", "+", "-", "*", "&", "<<", ">>"}),
	m_predefTokensString[]({"(", ")", "[", "]" , "{" , "}", ";", "<", ">" , "=", "+", "-", "*", "&"})
	{
     
	};
    ~analyzer_t(){};
	
	
	void Init();

	void AnalizeLine(tokenizer_t& _t, size_t _lineNum);
	
	
	void Finish();

	private:
	
	analyzer_t(const analyzer_t& an);
	analyzer_t& operator=(const analyzer_t& an);
	
	

	vector<string> m_predefinedTypes;
	vector<string> m_keyWords;
	vector<string> m_operators;
	vector<string> m_predefTokens;
	
	const string m_predefinedTypesString[];
	const string m_keyWordsString[];
	const string m_operatorsString[];
	const string m_predefTokensString[];
	
	
	map<string,int> m_enclosuresCounters;
	map<string,int> m_operatorChecker;
	
	set<string> m_symbolTable;
	
	bool m_programStarted;
	
	bool m_predefTypeEncountered;
	
	void AnalyzeToken(const string& _token,  size_t _lineNum);
	
	bool IsValidVarName(const string& _token)const;
	
	bool CheckEnclosure(const string& _token, const string& _open, const string& _close,  size_t _lineNum);
	
	bool CheckOperators(const string& _token, size_t _lineNum);
	

};




#endif