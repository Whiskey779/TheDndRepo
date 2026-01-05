#include <iostream>
#include <string>
#include "backend.h"

struct Command{
    std::string cmd, arg;
};

Command GetInput(){
    std::string input;
    std::cout << "TheDndRepo> ";
    std::getline(std::cin, input);
    auto space = input.find_first_of(' ');
    if(space != std::string::npos){
        Command cmd;
        cmd.cmd = input.substr(0, space - 1);
        cmd.arg = input.substr(space + 1);
        return cmd;
    }
    return Command{input, ""};
}

int main(){
    Backend::Backend backend;
    Command cmd;
    while(true){
        cmd = GetInput();
        
        if(cmd.cmd == "exit"){
            break;
        }

        if(cmd.cmd == "list"){
            std::vector<Backend::StatBlock> list = backend.GetAllStatBlocks();
            for(auto statBlock = list.begin(); statBlock != list.end(); ++statBlock){
                std::cout << statBlock->name << ") AC: " << statBlock->armorClass << " HP: " << statBlock->hitPoint << '\n';
            }
        }
    }
    return 0;
}