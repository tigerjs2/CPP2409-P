// Might be every enetities ancestor, or it will be thrown away
#pragma once

class Entity{
    private:
        char symbol;
    public:
        Entity(){symbol = ' ';}
        Entity(char s){symbol = s;}
        virtual ~Entity() = default;
        void setSymbol(char c) { symbol = c;}
        char const getSymbol() {return symbol;}
};