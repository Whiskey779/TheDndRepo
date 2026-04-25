#include "backend.h"

namespace Backend{
    Backend::Backend(): db("main.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE){
        db.exec("CREATE TABLE IF NOT EXISTS statBlocks(id INTEGER PRIMARY KEY, name TEXT, cr REAL, armorClass TINYINT, hitPoint TINYINT, str TINYINT, dex TINYINT, con TINYINT, int TINYINT, wis TINYINT, cha TINYINT)");
    }

    std::vector<StatBlock> Backend::GetAllStatBlocks(){
        SQLite::Statement getAll(db, "SELECT * FROM statBlocks ORDER BY name ASC");
        std::vector<StatBlock> list;
        StatBlock temp;
        try{
            while(getAll.executeStep()){
                temp.name = getAll.getColumn("name").getString();
                temp.cr = getAll.getColumn("cr").getDouble();
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
        }
        catch(SQLite::Exception e){
            std::cout << "SQLite error: " << e.what() << '\n';
        }
        return list;
    }

    std::vector<StatBlock> Backend::SeachByName(std::string nameSearch){
        SQLite::Statement seachName(db, "SELECT * FROM statBlocks WHERE name like ? ORDER BY name ASC");
        seachName.bind(1, "%" + nameSearch + "%");
        std::vector<StatBlock> list;
        StatBlock temp;
        try{
            while(seachName.executeStep()){
                temp.name = seachName.getColumn("name").getString();
                temp.cr = seachName.getColumn("cr").getDouble();
                temp.armorClass = seachName.getColumn("armorClass").getUInt();
                temp.hitPoint = seachName.getColumn("hitPoint").getUInt();
                temp.strength = seachName.getColumn("str").getUInt();
                temp.dexterity = seachName.getColumn("dex").getUInt();
                temp.constitution = seachName.getColumn("con").getUInt();
                temp.intellgence = seachName.getColumn("int").getUInt();
                temp.wisdom = seachName.getColumn("wis").getUInt();
                temp.charisma = seachName.getColumn("cha").getUInt();
                list.push_back(temp);
            }
        }
        catch(std::exception e){
            std::cout << "SQLite error: " << e.what() << '\n';
        }
        return list;
    }

    void Backend::AddStatBlock(StatBlock sb){
        SQLite::Statement allreadyExists(db, "SELECT 1 FROM statBlocks WHERE name = ? LIMIT 1");
        allreadyExists.bind(1, sb.name);
        if(allreadyExists.executeStep()){
            std::cerr << "ERROR: Stat Block all ready Exists\n";
            return;
        }

        SQLite::Statement addStatBlock(db, "INSERT INTO statBlocks(name, cr, armorClass, hitpoint, str, dex, con, int, wis, cha) VALUES(:name, :cr, :armorClass, :hitpoint, :str, :dex, :con, :int, :wis, :cha)");
        addStatBlock.bind(":name", sb.name);
        addStatBlock.bind(":cr", sb.cr);
        addStatBlock.bind(":armorClass", sb.armorClass);
        addStatBlock.bind(":hitpoint", sb.hitPoint);
        addStatBlock.bind(":str", sb.strength);
        addStatBlock.bind(":dex", sb.dexterity);
        addStatBlock.bind(":con", sb.constitution);
        addStatBlock.bind(":int", sb.intellgence);
        addStatBlock.bind(":wis", sb.wisdom);
        addStatBlock.bind(":cha", sb.charisma);
       try{
        addStatBlock.exec();
       } catch(const std::exception& e){
        std::cerr << "SQLite error: " << e.what() << '\n';
       }
    }
};