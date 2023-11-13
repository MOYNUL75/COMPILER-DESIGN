//Read a program input and detected all tokens (valid & Invalid identifier, keyword, operator) from a given text file
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <iterator>

using namespace std;

    void token(string str, vector<string> *vec);
    bool isPunctuation(char s);
    bool isKeyword(string s);
    bool isConstant(string s);
    bool isOperator(string s);
    bool isIdentifier(string s);

 int main(){

     ifstream file("Source_code.txt");
     string temp;
     string str;
     vector<string> vec;

     while (getline(file, temp)){

        str = str + temp;

     }

       token(str, &vec);

       for(int i=0; i<vec.size(); i++){

        if (isKeyword(vec[i])){
            cout <<"\ '" <<vec[i] << "\ '" " -KEYWORD\n";
            }

        else if (isConstant(vec[i])){
            cout << "\'" << vec[i] << "\'" " - CONSTANT\n";
            }

        else if (isOperator(vec[i])){
            cout << "\'" << vec[i] << "\'"<< " - OPERATOR\n";
            }

        else if (isIdentifier(vec[i])){
            cout << "\'" << vec[i] << "\'"" - VALID IDENTIFIER\n";
            }

        else if (!isIdentifier(vec[i])){
            cout << "\'" << vec[i] << "\'"" - INVALID IDENTIFIER\n";
            }

        }

}



    bool isPunctuation(char s){
        char punc[] = {'(', ')', '{', '}', '[', ']', ';', ','};

        int len = sizeof(punc) / sizeof(punc[0]);


        for (int i = 0; i < len; i++){

         if (punc[i] == s){
            return true;
            }
        }


        return false;
     }



    void token(string str, vector<string> *vec){

        string temp;

        for (int i = 0; i < str.length(); i++){
        string s(1, str[i]);


        if (!isPunctuation(str[i]) && (str[i] != '<' && str[i + 1] != '<') && (str[i] != '>' && str[i + 1] != '>') && str[i] != ' '){
                //++i

            if ((str[i] == '+' && str[i + 1] == '+') || (str[i] == '-' && str[i + 1] == '-')){
            temp.push_back(str[i]);
            temp.push_back(str[i + 1]);
            vector<string>::iterator it = find(vec->begin(), vec->end(), temp);

                if (it == vec->end()){
                vec->push_back(temp);
                }

                temp.clear();
                i = i + 2;
                }


                // i++

            if ((str[i + 1] == '+' && str[i + 2] == '+') || (str[i + 1] == '-' && str[i + 2] == '-')){
            vec->push_back(s);
            temp.push_back(str[i + 1]);
            temp.push_back(str[i + 2]);
            vector<string>::iterator it = find(vec->begin(), vec->end(), temp);

                if (it == vec->end()){
                vec->push_back(temp);
                }

                temp.clear();
                i = i + 2;

                }

            else{
            temp.push_back(str[i]);
            }

    }

       else{
        vector<string>::iterator it = find(vec->begin(), vec->end(), temp);

        if (it == vec->end()){

        vec->push_back(temp);

        }

        temp.clear();

        }

  }

    vec->erase(remove(vec->begin(), vec->end(), ""), vec->end());

}



    bool isKeyword(string s){

        string keyword[] = {"int", "float", "double", "cout", "cin", "endl", "using", "namespace", "vector", "array", "include", "string", "char", "ifstream", "fstream", "while", "for", "do", "if", "else", "else if", "std", "true", "false"};

        int len = sizeof(keyword) / sizeof(keyword[0]);

        for (int i = 0; i < len; i++){

            if (s == keyword[i]){

            return true;

            }
        }

     return false;
}



    bool isConstant(string s){

        for (int i = 0; i < s.length(); i++){

            if (s[0] == '"' && s[s.length() - 1] == '"' && s.length() != 1){

                return true;
                }

            if (s[0] == '\'' && s[s.length() - 1] == '\'' && s.length() != 1){

                return true;
                }

            if (s[i] >= '0' && s[i] <= '9'){

                }

            else{

                return false;
                }

    }

    return true;
}



    bool isOperator(string s){

        string opr[] = {"+", "-", "/", "*", "%", "--", "++", "=", "+=", "-=", "*=", "/=", "%=", "==", "!=", ">", "<", "<=", ">=", "&&", "||", "!", "&", "|", "^", "~", "sizeof", "?:", ".", "->"};

        int len = sizeof(opr) / sizeof(opr[0]);


        for (int i = 0; i < len; i++){

            if (s == opr[i]){

                return true;
                }
        }

    return false;
}



    bool isIdentifier(string s){

        string sym[] = {"!", "#", "%", " "};
        int len = sizeof(sym) / sizeof(sym[0]);

        if (s[0] == '_' || (s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')){

            for (int i = 0; i < len; i++){

                size_t found = s.find(sym[i]);

                    if (found != string ::npos){

                        return false;
                        }
                    }

                return true;
            }

        else{

            return false;
        }

}

