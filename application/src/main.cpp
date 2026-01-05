#include <iostream>
#include <string>
#include <sstream>
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
        else if(cmd.cmd == "add"){
            Backend::StatBlock temp;
            std::vector<std::string> input;
            std::stringstream ss(cmd.arg);
            std::string arg;
            while(std::getline(ss, arg, ' ')){
                input.push_back(arg);
            }
            temp.name = input[0];
            temp.armorClass = std::stoi(input[1]);
            temp.hitPoint = std::stoi(input[2]);
            temp.strength = std::stoi(input[3]);
            temp.dexterity = std::stoi(input[4]);            
            temp.constitution = std::stoi(input[5]);
            temp.intellgence = std::stoi(input[6]);
            temp.wisdom = std::stoi(input[7]);
            temp.charisma = std::stoi(input[8]);
            backend.AddStatBlock(temp);
        }
        else if(cmd.cmd == "modify"){

        }
    }
    return 0;
}