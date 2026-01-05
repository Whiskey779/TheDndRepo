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

    void Backend::AddStatBlock(StatBlock sb){
        /*
        SQLite::Statement addStatBlock(db, "INSERT INTO statBlocks(name, armorClass, hitpoint, str, dex, con, int, wis, cha) VALUES(:name, :armorClass, :hitpoint, :str, :dex, :con, :int, :wis, :cha)");
        addStatBlock.bind(":name", sb.name);
        addStatBlock.bind(":armorClass", sb.armorClass);
        addStatBlock.bind(":hitpoint", sb.hitPoint);
        addStatBlock.bind(":str", sb.strength);
        addStatBlock.bind(":dex", sb.dexterity);
        addStatBlock.bind(":con", sb.constitution);
        addStatBlock.bind(":int", sb.intellgence);
        addStatBlock.bind(":wis", sb.wisdom);
        addStatBlock.bind(":cha", sb.charisma);
        addStatBlock.exec();
        */
       SQLite::Statement addStatBlock(db, "INSERT INTO statBlocks VALUES ('Weasel', 13, 1, 3, 16, 8, 2, 12, 3)");
       try{
        addStatBlock.exec();
       } catch(const std::exception& e){
        std::cerr << "SQLite error: " << e.what() << '\n';
       }
    }
};