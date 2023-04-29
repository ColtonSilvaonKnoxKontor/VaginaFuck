#include <locale>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>

std::string inputFile(const std::string& filename)
{
    std::string commands;
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Failed to open '" + filename + "'. Please check your filename and try again."); //added

    while (file.good()) {
        commands.push_back(file.get());
    }
   
    return commands;
}

void displayCell(const std::vector<int>& inVec)
{
    for (auto element = inVec.cbegin();
         element != inVec.cend();
              ++ element )
         std::cout << *element << ' ';
    
    std::cout << std::endl;
}

void interpretCode(const std::string& commands)
{
    std::locale::global(std::locale(""));

    std::cin.imbue(std::locale());
    std::cout.imbue(std::locale());
    std::cerr.imbue(std::locale());       // locales
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());
    std::wcerr.imbue(std::locale());
    
    std::ofstream outfile;
    outfile.open("out");
    
    // instantiate a vector with 1 cell (element) which the initial value of one cell is 0
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
	    (*dataPtr) *= 4;  // custom, may increase the multiplier from 3 to 5 if I implement unicode characters
	    break;
        }
       case '/':
        {
            (*dataPtr) /= 4;   // custom, for navigating backwards
        }
        case '.':
        {
            std::wcout << wchar_t(*dataPtr); 
            break;
        }
        
        
        case '@':   // Custom brainfuck command, but cannot display the unicode char in output file because the fact that filestream is not a member of std, so maybe create a new rule for this
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
    
    // I added this feature to see the value stored in each cell.
    displayCell(data);
    std::wcout << std::endl;
     std::wcout << "Legend: " << std::endl;
        std::wcout << "no" << std::setw(7) << "dec" << std::setw(8) << "char" << std::setw(6) << "hex" << std::endl;

        for (size_t index = 0; index < data.size (); ++index)
            {

        	std::wcout << "$" << index << std::setw(9) ;
	        std::wcout << data[index] << std::setw(4) << wchar_t(data[index]) << std::setw(5);
            char hexadecimalNum[50], i=0, rem;
            while(data[index] != 0) {
                rem = data[index] % 16;
                if (rem < 10) {
                    rem = rem + 48;
                }
                else {
                    rem = rem + 55;
                }
                hexadecimalNum [i] = rem;
                i++;
                data[index] = data[index] / 16;
            }
            
            for (i=i-1; i>=0; i--) {
            std::wcout << hexadecimalNum[i];
            }

            std::wcout << " " << std::endl;

            }    
    
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
    	std::cout << "\n░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n░█░█░█▀█░█▀▀░▀█▀░█▀█░█▀█░█▀▀░█░█░█▀▀░█░█░\n░▀▄▀░█▀█░█░█░░█░░█░█░█▀█░█▀▀░█░█░█░░░█▀▄░\n░░▀░░▀░▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀░░░▀▀▀░▀▀▀░▀░▀░\n░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n" << std::endl;

// added nice logo

        std::cout << "VaginaFuck Interpreter 2.0 UNICODE\nModified by Colton Silva\n\nUsage: ./VaginaFuck-2.x filename" << std::endl;
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
