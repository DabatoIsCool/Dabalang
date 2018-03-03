#include "util.h"

using namespace std;

string remove_extra_spaces(const string input)
{
	string output;

	unique_copy(input.begin(), input.end(), back_insert_iterator<string>(output), [](char a, char b) { return isspace(a) && isspace(b);});
	return output;
}

string read_file(const char *file_location)
{
	char character_list[] = {'\n', '\t'};

	string file_content;
	ifstream file(file_location, ios::in | ios::binary);
	if(file)
	{
		file.seekg(0, ios::end);
		file_content.resize(file.tellg());
		file.seekg(0, ios::beg);
		file.read(&file_content[0], file_content.size());
		file.close();
		
		for(unsigned int i = 0; i < sizeof(character_list) / sizeof(character_list[0]); i++)
		{
			file_content.erase(remove(file_content.begin(), file_content.end(), character_list[i]), file_content.end());
		}
		file_content = remove_extra_spaces(file_content);
		return file_content;
	}

	return NULL;
}
