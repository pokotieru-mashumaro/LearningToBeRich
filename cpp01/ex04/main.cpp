#include <iostream>
#include <fstream>
#include <sstream>

#define ARGS_ERROR 0
#define NOT_OPEN_FILE 1
#define INPUT_ERROR 2

int	error(int err);
std::string read_file_content(const std::string &file_name);
std::string replace_string(std::string content, const std::string& s1, const std::string& s2);
void output_replacefile(std::string result, std::string filename);

int main(int ac, char **av) 
{
    std::string file_name;
    std::string s1;
	std::string s2;
    std::string file_content;
    std::string result;

    if (ac != 4)
        return error(ARGS_ERROR);
    file_name = av[1];
    s1 = av[2];
    s2 = av[3];

    try 
    {
        file_content = read_file_content(file_name);
        result = replace_string(file_content, s1, s2);
        output_replacefile(result, file_name + ".replace");
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

int	error(int err)
{
	if (err == ARGS_ERROR)
		std::cerr << "引数の数は4つなんです😡" << std::endl;
	return (1);
}

std::string read_file_content(const std::string &file_name)
{
    std::ifstream file(file_name);
    std::stringstream buffer;

    if (!file.is_open())
        throw std::runtime_error("既存のファイルが開けません");

    buffer << file.rdbuf();
    return buffer.str();
}

std::string replace_string(std::string content, const std::string &s1, const std::string &s2)
{
    std::string result;
    size_t pos;
    size_t prevPos;


    if (s1.empty())
        throw std::runtime_error("s1には文字を入力してください😡");
    
    pos = 0;
    prevPos = 0;
    while ((pos = content.find(s1, prevPos)) != std::string::npos) {
        result.append(content, prevPos, pos - prevPos);
        result.append(s2);
        prevPos = pos + s1.length();
    }
    result.append(content, prevPos, std::string::npos);    
    return result;
}

void output_replacefile(std::string result, std::string filename)
{
    std::ofstream outfile(filename);

    if (!outfile) 
        throw std::runtime_error("作ったファイルが開けません");

    outfile << result;
    outfile.close();
}
