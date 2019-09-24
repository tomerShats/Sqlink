# include <iostream>
# include <string.h>
#include "String_t.h"
using namespace std;

void defCtor();
void ctorChar();
void cpyCtor();
void length();
void getStr();
void setStr();
void compareStr();
void toLow();
void toUp();
void app();
void prep();
void ops();
void isContains();
void findChar();
void numOfStr();
void curCaseSens();
void setCaseSens();
void getDefCap();
void setDefCap();
void findIndexOfChar();
void getSub();

int main()
{
    int cont = 1;
    int option =0;

    while (cont)
    {
        cout << "Please choose an option: (1 to 21)"<< endl;
        cout << "1 >>>      Default constructor "<< endl;
        cout << "2 >>>      Constructor From char*"<< endl;
        cout << "3 >>>      Copy Constructor"<< endl;        
        cout << "4 >>>      Get Length"<< endl;
        cout << "5 >>>      Get String"<< endl;
        cout << "6 >>>      Set String"<< endl;
        cout << "7 >>>      Compare Strings"<< endl;
        cout << "8 >>>      To Lower Case"<< endl;
        cout << "9 >>>      To Upper Case"<< endl;
        cout << "10 >>>     Append"<< endl;
        cout << "11 >>>     Prepend"<< endl;
        cout << "12 >>>     Operators"<< endl;
        cout << "13 >>>     Check if contains"<< endl;
        cout << "14 >>>     Find char by Index"<< endl;
        cout << "15 >>>     Number of Strings"<< endl;
        cout << "16 >>>     Current Case Sensitive flag"<< endl;
        cout << "17 >>>     Set On/Off Case sensitive"<< endl;
        cout << "18 >>>     Get default capacity"<< endl;
        cout << "19 >>>     Set default capactiy"<< endl;
        cout << "20 >>>     Find index of char"<< endl;
        cout << "21 >>>     Get Substring"<< endl;
        cout << "other>>>   Exit"<< endl;

        cin >> option;

        switch(option)
        {
            case 1:     defCtor();
                break;
            case 2:     ctorChar();
                break;
            case 3:     cpyCtor();
                break;
            case 4:     length();
                break;
            case 5:     getStr();
                break;
            case 6:     setStr();
                break;
            case 7:     compareStr();
                break;
            case 8:     toLow();
                break;
            case 9:     toUp();
                break;
            case 10:    app();
                break;
            case 11:    prep();
                break;
            case 12:    ops();
                break;
            case 13:    isContains();
                break;
            case 14:    findChar();
                break;
            case 15:    numOfStr();
                break;
            case 16:    curCaseSens();
                break;
            case 17:    setCaseSens();
                break;
            case 18:    getDefCap();
                break;
            case 19:    setDefCap();
                break;
            case 20:    findIndexOfChar();
                break;
            case 21:    getSub();
                break;
           // case 22:    destroy();
           //     break;
            default:    cont=0;
                break;
        }
    }
}

void defCtor()
{
    String_t s;
}
void ctorChar()
{
    char str[64];
    cout << "Enter string:"<< endl;
    cin >> str;
    String_t s(str);
}
void cpyCtor(){}
void length()
{
    char str[64];
    cout << "Enter string:"<< endl;
    cin >> str;
    String_t s(str);
    cout << s.length() << endl;
}
void getStr()
{
    char str[64];
    cout << "Enter string:"<< endl;
    cin >> str;
    String_t s(str);
    cout << s.getString() << endl;
}
void setStr()
{
    char str[64];
    cout << "Enter string:"<< endl;
    cin >> str;
    String_t s(str);
    cout << "Enter new string:"<< endl;
    cin >> str;
    s.setString(str);
    s.print();
}
void compareStr()
{
    char str[64], str2[64];
    cout << "Enter first string:"<< endl;
    cin >> str;
    String_t s1(str);
    cout << "Enter second string:"<< endl;
    cin >> str2;
    String_t s2(str2);
    cout << "ANSWER: " <<s1.compare(s2) << endl;
}
void toLow()
{
    char str[64];
    cout << "Enter string:"<< endl;
    cin >> str;
    String_t s(str);
    s.lowCase();
    s.print();
}
void toUp()
{
    char str[64];
    cout << "Enter string:"<< endl;
    cin >> str;
    String_t s(str);
    s.upCase();
    s.print();
}
void app()
{
    char str[64], str2[64];
    cout << "Enter first string:"<< endl;
    cin >> str;
    String_t s1(str);
    cout << "Enter second string:"<< endl;
    cin >> str2;
    String_t s2(str2);
    s1+=s2;
    s1.print();
}
void prep()
{
    char str[64], str2[64];
    cout << "Enter first string:"<< endl;
    cin >> str;
    String_t s1(str);
    cout << "Enter second string:"<< endl;
    cin >> str2;
    String_t s2(str2);
    s1.prepend(s2);
    s1.print();
}
void ops()
{
    char str[64], str2[64];
    cout << "Enter first string:"<< endl;
    cin >> str;
    String_t s1(str);
    cout << "Enter second string:"<< endl;
    cin >> str2;
    String_t s2(str2);
    cout << "S1 < S2 "<< (s1<s2)<<endl;
    cout << "S1 > S2 "<< (s1>s2)<<endl;
    cout << "S1 <= S2 "<< (s1<=s2)<<endl;
    cout << "S1 >= S2 "<< (s1>=s2)<<endl;
    cout << "S1 != S2 "<< (s1!=s2)<<endl;
    cout << "S1 == S2 "<< (s1==s2)<<endl;
}

void isContains()
{
    char str[64], str2[64];
    cout << "Enter first string:"<< endl;
    cin >> str;
    String_t s1(str);
    cout << "Enter sub string:"<< endl;
    cin >> str2;
    cout << s1.contains(str2)<< endl;
}
void findChar()
{
    char str[64];
    int i=0;
    cout << "Enter first string:"<< endl;
    cin >> str;
    String_t s1(str);
    cout << "Enter index" << endl;
    cin >> i;
    cout << str[i] << endl;
}
void numOfStr()
{
    String_t s;
    cout << s.getNumItems() << endl;
}
void curCaseSens()
{
    String_t s;
    cout << s.getSensFlag() << endl;
}
void setCaseSens()
{
    String_t s;
    int onoff=0;
    cout << "Enter 1 for On, 0 for Off" << endl;
    cin >> onoff;
    s.setSensFlag(onoff);  
}
void getDefCap()
{
    String_t s;
    cout << s.getCap() << endl;
}
void setDefCap()
{
    String_t s;
    cout <<"Current:" << s.getCap() << endl;
    cout << "Enter new default Capacity" << endl;
    int cap;
    cin >> cap;
    s.setDefCapcFlag(cap);
    cout <<"Current:" << s.getCap() << endl;
}
void findIndexOfChar()
{
    char str[64];
    char i;
    cout << "Enter first string:"<< endl;
    cin >> str;
    String_t s1(str);
    cout << "Enter char:"<< endl;
    cin >> i;
    cout << "First occurence: "<< s1.firstOcc(i) << endl << 
            "Last occurence: "<< s1.lastOcc(i)<< endl; 
    
}
void getSub()
{
    char str[64];
    int startIndex, userLength;
    cout << "Enter string:"<< endl;
    cin >> str;
    String_t s1(str);
    cout << "Enter start index and length :"<< endl;
    cin >> startIndex;
    cin >> userLength;

    cout << s1(startIndex,userLength) << endl;
}
/*
int main()
{   
    
    int func=0;

    while(func!=-1){
         
        cout<<"enter 1- default const"<<endl;
        cout<<"enter 2- char const"<<endl;
        cout<<"enter 3- copy const"<<endl;
        cout<<"enter 4- cin  String_t"<<endl;
        cout<<"enter 5- cout String_t"<<endl;
        cout<<"enter 6- op = "<<endl;
        cout<<"enter 7- len"<<endl;
        cout<<"enter 8- setString"<<endl;
        cout<<"enter 9- getString"<<endl;
        cout<<"enter 10- compare"<<endl;
        cout<<"enter 11- upcase"<<endl;
        cout<<"enter 12- lowcase"<<endl;
        cout<<"enter 13- prepend const"<<endl;
        cout<<"enter 14- op +="<<endl;
        cout<<"enter 15- op <"<<endl;
        cout<<"enter 16- op >"<<endl;
        cout<<"enter 17- op =="<<endl;
        cout<<"enter 18- contains"<<endl;
        cout<<"enter 19- op []"<<endl;
        cout<<"enter 20- op ()"<<endl;
        cout<<"enter 21- getSenseFlag"<<endl;
        cout<<"enter 22- setSenseFlag"<<endl;
        cout<<"enter 23- getCapacity"<<endl;
        cout<<"enter 24- set capacity"<<endl;
        cout<<"enter 25- first occ"<<endl;
        cout<<"enter 26- last occ"<<endl;
        cout<<"enter 27- getNumOfStr"<<endl;
        cout<<"enter -1- exit"<<endl;
        
        cin>>func;
        switch(func){

        }

    }
   
    
        
   
    
    const char str [10]="abc";
    char str2[20];
    char c;
    String_t temp(str);
    int comp;
    String_t st(str);
    st.print();
    cout<<st;
    cin>>temp;
    cout<<temp;
     if(temp<st){
        cout<<"small"<<endl;
    }else if(temp>st){
        cout<<"big"<<endl;
    }else if(temp==st){
        cout<<"equal"<<endl;
    }
    st.setString("knfg");
    strcpy(str2,st.getString());
    cout<<"after set :"<<str2<<endl;
    cout<<"len after set :"<<st.length()<<endl;
    comp=st.compare("kNfg");
    cout<<"the winner is:"<<comp<<endl;
    cout<<"contains: "<<st.contains ("kN")<<endl;
   
    st.prepend("yana");
    cout<<st;
    st.prepend(temp);
    cout<<st;
    temp+=temp;
    cout<<temp;
    temp+="abc";
    cout<<temp;
    st.upCase();
    cout<<st;
    st.lowCase();
    cout<<st;
    temp[0]='z';
    cout<<temp;
    c=temp[0];
    cout<<"c="<<c<<endl;
    
    return 0;
}*/