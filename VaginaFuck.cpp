/*
###################################################################
# Original Source: https://github.com/texus/Brainfuck-interpreter #
###################################################################
*/

#include <locale>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>

std::string inputFile(const std::string& filename)
{
    std::string commands;
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Failed to open '" + filename + "'.");

    while (file.good()) {
        commands.push_back(file.get());
    }
	
    /*
    bug error, only output ASCII char if I use this code with Unicode;
    uncomment if you want to compile this just for ASCII code
    
    std::cout << "File interpreted!" << std::endl;
    
    long fin_size = file.tellg();
    file.seekg(0,file.beg);
    std::cout << "File Size: "<<fin_size<<"B\n";
    std::cout << " " << std::endl;
    */

    return commands;
}

void interpretCode(const std::string& commands)
{
    std::locale::global(std::locale(""));

    std::cin.imbue(std::locale());
    std::cout.imbue(std::locale());
    std::cerr.imbue(std::locale());
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());
    std::wcerr.imbue(std::locale());

    std::ofstream outfile;
    outfile.open("out.vfto");
    
    std::vector<int> data(1, 0);
    std::vector<int>::iterator dataPtr = data.begin();

    std::string::const_iterator instructionPtr = commands.begin();
    std::stack<std::string::const_iterator> instructionStack;

    while (instructionPtr != commands.end())
    {
        switch (*instructionPtr)
        {
        case '<':
        {
            dataPtr--;
            break;
        }
        case '>':
        {
            dataPtr++;
            if (dataPtr == data.end()) {
                data.push_back(0);
                dataPtr = data.end()-1;
            }
            break;
        }
        case '+':
        {
            (*dataPtr) += 1;
            break;
        }
        case '-':
        {
            (*dataPtr) -= 1;
            break;
        }
        case '*':
        {
	        (*dataPtr) *= 4;
		// (*dataPtr) *= 2;
		// uncomment if you want the ASCII function
	        break;
        }
        case '.':
        {
            std::wcout << wchar_t(*dataPtr);
            break;
        }
        case '@':
        {
            outfile << char(*dataPtr);
            break;
        }
        case ',':
        {
            char input;
            std::cin >> input;
            *dataPtr = input;
        }
        case '[':
        {
            instructionStack.push(instructionPtr);

            if (*dataPtr == 0)
            {
                auto startInstructionPtr = instructionPtr;
                while (++instructionPtr != commands.end())
                {
                    if (*instructionPtr == '[')
                        instructionStack.push(instructionPtr);
                    else if (*instructionPtr == ']')
                    {
                        if (instructionStack.empty())
                            throw std::runtime_error("error at syntax ']': syntax '[' expected!");

                        auto tempInstructionPtr = instructionStack.top();
                        instructionStack.pop();

                        if (startInstructionPtr == tempInstructionPtr)
                            break;
                    }
                }
            }
            break;
        }
        case ']':
        {
            if (instructionStack.empty())
                throw std::runtime_error("error at syntax ']': syntax '[' expected!");

            if (*dataPtr != 0)
                instructionPtr = instructionStack.top();
            else
                instructionStack.pop();

            break;
        }
        default:
            break;
        }

        instructionPtr++;
    }

    if (!instructionStack.empty())
        throw std::runtime_error("error at syntax '[': syntax ']' expected!");
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "VaginaFuck Interpreter 2.0" << std::endl;
        std::cout << " " << std::endl;
        std::cout << "Usage: ./VaginaFuck filename.bf" << std::endl;
        return 1;
    }

    try
    {
        std::string commands = inputFile(argv[1]);
        interpretCode(commands);
    }
    catch (const std::exception& e)
    {
        std::cout << std::endl << e.what() << std::endl;
    }

    return 0;
}
