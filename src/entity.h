#pragma once

class Entity{
    private:
        char symbol;
    public:
        Entity(){symbol = ' ';}
        Entity(char s){symbol = s;}
        virtual ~Entity() = default;
        void SetSymbol(char c) { symbol = c;}
        char const GetSymbol() {return symbol;}
};