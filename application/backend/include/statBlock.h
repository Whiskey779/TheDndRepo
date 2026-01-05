#pragma once
#include <string>
namespace Backend{
    class StatBlock{
        public:
            std::string name;
            u_int32_t armorClass, hitPoint, strength, dexterity, constitution, intellgence, wisdom, charisma;
    };
};