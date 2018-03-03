#include <iostream>
#include <string>
#include <vector>
#include "util.h"

using namespace std;

vector<string> tokens = {"entry", "stream", "in", "out", "write", "->", "(", ")", ";", "{", "}"};

void lexer(string source)
{
	vector<string> token_list;
	string token = "";
	
	string str = "";
	bool in_string = false;

	for(char& current_char : source)
	{	
		token += current_char;
	
		if(current_char == '\"')
		{
			if(!in_string)
			{
				in_string = true;
			}
			else
			{
				str += current_char;
				in_string = false;
				token_list.push_back(str);
				token = "";
				continue;
			}
		}
		if(in_string)
		{
			str += current_char;
			continue;
		}
		if(token == " ")
		{
			token = "";
		}

		for(auto &current_token : tokens)
		{
			if(current_token == token)
			{
				token_list.push_back(token);
				token = "";
			}
		}
	}

	for(string current_string : token_list)
	{
		cout << current_string << std::endl;
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "Error: Please enter a file name" << endl;
		return 1;
	}

	string source = read_file(argv[1]);
	
	lexer(source);
	
	return 0;
}
