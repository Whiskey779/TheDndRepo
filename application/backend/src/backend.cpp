#include "backend.h"

namespace Backend{
    Backend::Backend(): db("main.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE){
        db.exec("CREATE TABLE IF NOT EXISTS statBlocks(name TEXT, armorClass INTEGER, hitPoint INTEGER, str INTEGER, dex INTEGER, con INTEGER, int INTEGER, wis INTEGER, cha INTEGER)");
    }

    std::vector<StatBlock> Backend::GetAllStatBlocks(){
        SQLite::Statement getAll(db, "SELECT * FROM statBlocks");
        std::vector<StatBlock> list;
        StatBlock temp;
        while(getAll.executeStep()){
            temp.name = getAll.getColumn("name").getString();
            temp.armorClass = getAll.getColumn("armorClass").getInt();
            temp.hitPoint = getAll.getColumn("hitPoint").getInt();
            temp.strength = getAll.getColumn("str").getInt();
            temp.dexterity = getAll.getColumn("dex").getInt();
            temp.constitution = getAll.getColumn("con").getInt();
            temp.intellgence = getAll.getColumn("int").getInt();
            temp.wisdom = getAll.getColumn("wis").getInt();
            temp.charisma = getAll.getColumn("cha").getInt();
            list.push_back(temp);
        }
        return list;
    }
};