#pragma once
#include <iostream>
#include <vector>
#include "SQLiteCpp/Database.h"
#include "statBlock.h"

namespace Backend{
    class Backend{
        public:
            Backend();
            std::vector<StatBlock> GetAllStatBlocks();
            void AddStatBlock(StatBlock);
        private:
            SQLite::Database db;


    };

};