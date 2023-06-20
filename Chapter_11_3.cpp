#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Генерируем рандомное число между min и max 
int getRandomNumber(int min, int max) 
{ 
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    // Равномерно распределяем генерацию значения из диапазона 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;

    public:
    Creature(std::string name, char symbol, int health, int damage, int gold)
        : m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold) {}

    void setName(std::string name) {m_name = name;}
    std::string getName() {return m_name;}

    void setSymbol(char symbol) {m_name = symbol;}
    char getSymbol() {return m_symbol;}

    void setHealth(int health) {m_damage = health;}
    int getHealth() {return m_health;}

    void setDamage(int damage) {m_damage = damage;}
    int getDamage() {return m_damage;}

    void setGold(int gold) {m_gold = gold;}
    int getGold() {return m_gold;}

    void reduceHealth(int damage) {m_health-=damage;}
    bool isDead() 
    {
        if (m_health<=0)
            return true;
        else
            return false;
    }

    void addGold(int gold) {m_gold+=gold;}
};

class Player : public Creature
{
    int m_level = 1;

    public:
    Player(std::string name)
        : Creature(name, '@', 10, 1, 0) {}
    
    void levelUp()
    {
        ++m_level; 
        setDamage(getDamage()+1);
    }

    void setLevel(int level) {m_level = level;}
    int getLevel() {return m_level;}

    bool hasWon()
    {
        if (m_level == 20)
            return true;
        else    
            return false;
    }
};

class Monster : public Creature
{
     
    public:
    enum Type
    {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES
    };

    struct MonsterData 
    { 
        const char* name; 
        char symbol; 
        int health; 
        int damage; 
        int gold; 
    };

    static MonsterData monsterData[MAX_TYPES];

    Monster(Type type) 
     : Creature(monsterData[type].name, monsterData[type].symbol, 
        monsterData[type].health, monsterData[type].damage, monsterData[type].gold) {}

    static Type  getRandomMonster()
    {
        return static_cast<Type>(getRandomNumber(0, MAX_TYPES-1));
    }

};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES] 
{ 
    { "dragon", 'D', 20, 4, 100 }, 
    { "orc", 'o', 4, 2, 25 }, 
    { "slime", 's', 1, 1, 10 } 
};

int main()
{
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
    rand(); // сбрасываем первый результат

    Creature o("orc", 'o', 4, 2, 10); 
    o.addGold(5); 
    o.reduceHealth(1); 
    std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold." << std::endl;

    std::string name;
    std::cout << "Enter your name: " ; 
    std::cin >> name;
    Player p(name);
    std::cout << "Welcom, " << name << "."  << std::endl;
    std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold." << std::endl;
    Monster m(Monster::ORC);
    std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

    for (int i = 0; i < 10; ++i) 
    {
        Monster m = Monster::getRandomMonster(); 
        std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
    }

    return 0;
}