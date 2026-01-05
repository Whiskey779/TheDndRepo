#include "backend.h"

namespace Backend{
    Backend::Backend(): db("main.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE){
        db.exec("CREATE TABLE IF NOT EXISTS statBlocks(name TEXT, armorClass TINYINT, hitPoint TINYINT, str TINYINT, dex TINYINT, con TINYINT, int TINYINT, wis TINYINT, cha TINYINT)");
    }

    std::vector<StatBlock> Backend::GetAllStatBlocks(){
        SQLite::Statement getAll(db, "SELECT * FROM statBlocks");
        std::vector<StatBlock> list;
        StatBlock temp;
        while(getAll.executeStep()){
            temp.name = getAll.getColumn("name").getString();
            temp.armorClass = getAll.getColumn("armorClass").getUInt();
            temp.hitPoint = getAll.getColumn("hitPoint").getUInt();
            temp.strength = getAll.getColumn("str").getUInt();
            temp.dexterity = getAll.getColumn("dex").getUInt();
            temp.constitution = getAll.getColumn("con").getUInt();
            temp.intellgence = getAll.getColumn("int").getUInt();
            temp.wisdom = getAll.getColumn("wis").getUInt();
            temp.charisma = getAll.getColumn("cha").getUInt();
            list.push_back(temp);
        }
        return list;
    }
};