#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

bool isIdentifier(string lexeme)
{
    return regex_match(lexeme, regex("[a-zA-Z][a-zA-Z0-9]*"));
}
bool isNumber(string lexeme)
{
    return regex_match(lexeme, regex("[0-9]+"));
}

bool isReal(string lexeme)
{
    return regex_match(lexeme, regex("[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?"));
}

int main()
{

    unordered_map<string, string> tokens{
        {"\"", "DQ"},
        {"BEGIN", "BEGIN"},
        {"PRINT", "PF"},
        {"INTEGER", "DATATYPE"},
        {"REAL", "DATATYPE"},
        {"STRING", "DATATYPE"},
        {"FOR", "FOR_LOOP"},
        {"[", "OPEN+SB"},
        {"]", "CLOSE_SB"},
        {"END", "END"},
        {",", "COMMA"},
        {":=", "ASSIGN_OP"},
        {"TO", "TO"}};

    // std::cout << "Enter the input filename: ";
    string inputFileName = "input.txt";
    // std::cin >> inputFileName;

    std::string string2 = "";

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open())
    {
        std::cout << "Error opening file: " << inputFileName << std::endl;
        return 1;
    }

    std::ofstream outputFile("tokens.txt");
    if (!outputFile.is_open())
    {
        std::cout << "Error opening output file: tokens.txt" << std::endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line))
    {
        string lexeme = "";
        int len = line.length();
        // cout << len;
        for (int i = 0; i < len; i++)
        {
            if (line[i] == '"')
            {
                outputFile << tokens["\""] << " ";
                cout << "''"<< " is dq" << endl;
                i=i+1;
                while(line[i] != '"'){
                    lexeme=lexeme+line[i];
                    i=i+1;
                }
                outputFile <<"STRING ";
                cout << lexeme<< " is string" << endl;
                lexeme = "";
                outputFile << tokens["\""] << " ";
                cout << "''"<< " is dq" << endl;
                continue;
            }
            if (line[i] == ' ' || line[i] == ',')
            {
                if (tokens.find(lexeme) != tokens.end())
                {
                    outputFile << tokens[lexeme];
                    outputFile << " ";
                    cout << lexeme << " is a " << tokens[lexeme] << endl;
                }
                else
                {
                    if (isIdentifier(lexeme))
                    {
                        outputFile << "IDEN ";
                        cout << lexeme << " is a iden" << endl;
                    }
                    else if (isNumber(lexeme))
                    {
                        outputFile << "NUM ";
                        cout << lexeme << " is a num" << endl;
                    }
                    else if (lexeme[0] == '[')
                    {
                        outputFile << "VAR ";
                        cout << lexeme << " is a var" << endl;
                    }
                }
                if (line[i] == ',')
                {
                    outputFile << tokens[","] << " ";
                }
                lexeme = "";
            }
            else
            {
                lexeme = lexeme + line[i];
            }
        }
        if (lexeme != "")
        {
            if (tokens.find(lexeme) != tokens.end())
            {
                outputFile << tokens[lexeme];
                outputFile << " ";
                cout << lexeme << " is a " << tokens[lexeme] << endl;
            }
            else
            {
                if (isIdentifier(lexeme))
                {
                    outputFile << "IDEN ";
                    cout << lexeme << " is a iden" << endl;
                }
                else if (isNumber(lexeme))
                {
                    outputFile << "NUM ";
                    cout << lexeme << " is a num" << endl;
                }
                else if (isReal(lexeme))
                {
                    outputFile << "REAL ";
                    cout << lexeme << " is a real" << endl;
                }
            }
            lexeme = "";
        }
        outputFile << endl;
    }
}
