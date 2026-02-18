#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sstream>
using namespace std;

bool isOperator(char c)
{
    string ops = "+-*<>&.@/:=˜|$!#%ˆ_[]{}\"'`?<";
    return ops.find(c) != string::npos;
}

bool isKeyword(string str)
{
    string keywords[] = {"let", "where", "true", "false", "not", "fn", "ls", "gr", "ge", "aug", "le", "nil", "dummy", "or", "in", "eq", "ne", "and", "rec", "within"};
    for (string keyword : keywords)
    {
        if (str == keyword)
        {
            return true;
        }
    }
    return false;
}

bool isPunctuation(char c)
{
    string punctuations = "();,";
    return punctuations.find(c) != string::npos;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage:./a.out <filename>" << endl;
        return 1;
    }

    ifstream file(argv[1]);

    if (!file)
    {
        cout << "File not found!\n";
        return 0;
    };

    string text = "";
    string line;
    while (getline(file, line))
    {
        text += line + "\n";
    }
    file.close();

    char c;
    istringstream iss(text);

    while (iss.get(c))
    {
        if (isspace(c))
        {
            continue;
            ;
        };

        if (c == '/')
        {
            char next = file.peek();

            if (next == '/')
            {
                while (file.get(c) && c != '\n')
                {
                    continue;
                }
            }
        }

        if (isalpha(c))
        {
            string word = "";
            word += c;

            while (file.peek() != EOF && (isalnum(file.peek()) || file.peek() == '_'))
            {
                file.get(c);
                word += c;
            }

            if (isKeyword(word))
            {
                cout << "<KEYWORD, \"" << word << "\">" << endl;
            }
            else
            {
                cout << "<IDENTIFIER, \"" << word << "\">" << endl;
            }
            continue;
        }

        if (isdigit(c))
        {
            string number = "";
            number += c;

            while (file.peek() != EOF && isdigit(file.peek()))
            {
                file.get(c);
                number += c;
            }

            cout << "<INTEGER, \"" << number << "\">" << endl;
            continue;
        }

        /////To check string
        if (c == '\'')
        {
            string str = "";
            bool closed = false;

            while (file.get(c))
            {
                if (c == '\'')
                {
                    closed = true;
                    break;
                }
                str += c;
            }

            if (closed)
            {
                cout << "<STRING, \"" << str << "\">" << endl;
            }
        }

        /////To check punctuations
        if (isPunctuation(c))
        {
            cout << "<PUNCTUATION, \"" << c << "\">" << endl;
        }

        //////To check operators
        if (isOperator(c))
        {
            cout << "<OPERATOR,\"" << c << "\">" << endl;
        }
    }

    return 0;
}