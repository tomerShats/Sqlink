#ifndef __ANALYZER_H_
#define __ANALYZER_H_


#include <set>
#include <string>
# include <iostream>
#include "tokenIzer.h"



using namespace std;

class analyzer_t
{
	public:
	
	analyzer_t(){}	
	
    virtual ~analyzer_t(){};
	
	void Init();

	void AnalizeLine(tokenizer_t& _t, size_t _lineNum);
	
	void Finish();

	private:
	
	analyzer_t(const analyzer_t& an);
	analyzer_t& operator=(const analyzer_t& an);
	

	
	static string m_predefinedTypesString[];
	static string m_keyWordsString[];
	static string m_operatorsString[];
	static string m_predefTokensString[];
	
	
	int m_roundBracCount; /* ( */
	int m_curlyBracCount; /* { */
	int m_squareBracCount; /* [ */
	int m_plusCount; /* + */
	int m_minusCount; /* - */
	bool m_if;
	bool m_programStarted;
	bool m_predefTypeEncountered;
	
	set<string> m_declaraionNames;
	static set<string> m_predefinedTypesSet;
	static set<string> m_keyWordsSet;
	static set<string> m_operatorsSet;
	static set<string> m_predefTokensSet;
	
	void PrintEnclErr(const char & brace,const int & countBrace);
	void AnalyzeToken(const string& _token,  size_t _lineNum);
	
	bool IsValidVarName(const string& _token)const;
	
	bool CheckEnclosure(const string& _token, const string& _open, const string& _close,  size_t _lineNum, int & count);
	
	bool CheckOperators(const string& _token, size_t _lineNum);

	bool CheckIf(const string& _token, const string& _if, const string& _else,  size_t _lineNum, bool & count);
	

};




#endif