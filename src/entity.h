// Might be every enetities ancestor, or it will be thrown away

class Entity{
    private:
        char symbol;
    public:
        Entity(){symbol = ' ';}
        Entity(char s){symbol = s;}
        char const getSymbol() {return symbol;}
};