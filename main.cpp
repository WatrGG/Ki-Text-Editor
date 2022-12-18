#include "Header.hpp"
/*
Credit to Romero Schwarz on Replit for the Read file, edit file and key press ideas
Link to his Replit here: https://replit.com/@RomeroSchwarz/text-editor#main.cpp
*/

/*
Credt to w3resource for the detect capitals in string algorythi
link to website here: https://www.w3resource.com/cpp-exercises/string/cpp-string-exercise-27.php
*/
std::string new_str = "";

std::string lookForCaps(std::string text)
{

    for (int i = 0; i < (text.length() - 1); i++)
    {
        new_str += text[i];
        if (isupper(text[i + 1]))
        {
            new_str += " ";
        }
    }

    new_str += text.back();
    return new_str;
}

void readFile()
{

    //inputs the text into the buffer and formats it before outputing it to the user
    bool view = true;
    std::string text;
    std::ifstream userFile(fileName);
    userFile.seekg(0, std::ios::end);

    size_t size = userFile.tellg();
    std::string buffer(size, ' ');
    userFile.seekg(0);
    userFile.read(&buffer[0], size);
    userFile.close();

    std::cout << buffer << std::endl;

    std::cout << "Press Enter to exit..." << std::endl;

    while (getline(userFile, text))
    {
        std::cout << text << "\n";
    }
    std::cin.ignore();
    std::cin.ignore(); // wait for keypress

    std::cout << "\033[2J\033[1;1H";
}

void editFile()
{
    std::string textFromUser;

    std::cout << "Welcome to the editing file submenu" << std::endl;
    std::cout << "To begin, please enter the name of the file you would like to write to:\t";

    std::cin >> fileName;
    std::ofstream userFile(fileName);

    std::cout << "To save and exit the file, simply hit the CAPS-LOCK key on your keyboard\n";
    std::cout << "Don't worry about putting spaces in \n Wherever you might need a space just capitalise the letter next to it and we will handle the rest!" << std::endl;
    std::cin >> textFromUser;

    lookForCaps(textFromUser);

    while (true)
    { //will not work on Linux systems, only on windows due to inclusion of windows.h
        if (GetAsyncKeyState(20))
        {
            userFile << new_str;
            userFile.close();
            break;
        }
    }
    std::cout << "Press enter to exit..." << std::endl;
    std::cin.ignore();//waiting for keypress
    std::cin.ignore();
            std::cout << "\033[2J\033[1;1H"; //prints code to clear the console
}

int main()
{
    std::string input;

    std::cout << "Welcome to the Ki text Editor" << std::endl;
    std::cout << "Input 'Read' to enter read mode\nInput 'Write' to eter write mode" << std::endl;

    std::cin >> input;

    while (true)
    {
        if (input == "Read")
        {
            std::cout << "Enter the name of the File:\t";
            std::cin >> fileName;
            readFile();
            break;
        }
        else if (input == "Write")
        {
            editFile();
            break;
        }
        else
        {
            std::cout << "wrong input, please try again later..." << std::endl;
            break;
        }
    }
}