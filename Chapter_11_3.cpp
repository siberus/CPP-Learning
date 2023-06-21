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

bool fightMonster()
{
    std::cout << "(R)un or (F)ight: ";
    char choice; 
    do 
    { 
        std::cin >> choice; 
    } while (choice != 'r' && choice != 'f'); 
    if (choice == 'f')
        return true;
    else
        return false;    
}

void attackPlayer(Player &p, Monster &m);

void attackMonster(Player &p, Monster &m)
{

    m.reduceHealth(p.getDamage());
    std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage." << std::endl;
            if(m.isDead())
            {
                std::cout << "You killed the " << m.getName() << "." << std::endl;
                p.levelUp();
                p.addGold(m.getGold());
                std::cout << "You are now level " << p.getLevel() << "." << std::endl;
                std::cout << "You found " << m.getGold() << " gold." << std::endl;
            }
            else
            {
                attackPlayer(p, m);
            }
}

void attackPlayer(Player &p, Monster &m)
{
    p.reduceHealth(m.getDamage());
    std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage." << std::endl;
}


int main()
{
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
    rand(); // сбрасываем первый результат

    std::string name;
    std::cout << "Enter your name: " ; 
    std::cin >> name;
    Player p(name);
    std::cout << "Welcom, " << name << "."  << std::endl;
    std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold." << std::endl;
    
    while (!p.isDead() && !p.hasWon()) 
    {

        Monster m = Monster::getRandomMonster(); 
        std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ")." << std::endl;
        while (fightMonster()) // (fightMonster() && !m.isDead())
        {
            attackMonster(p, m);
            if(m.isDead() || p.isDead())
                break;
        }
        if (!m.isDead() && !p.isDead())
        {
            if (getRandomNumber(0, 1))
            {
                std::cout << getRandomNumber(0, 1) << std::endl;
                attackPlayer(p, m);
            }
            else
            {
                std::cout << "You successfully fled." << std::endl;
            }
        }  
    }
    if (p.isDead())
    {
        std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold." << std::endl;
        std::cout << "Too bad you can't take it with you!" << std::endl;
    }
    else
    {
        std::cout << "You won with " << p.getGold() << " gold." << std::endl;    
    }
    
    std::cin.clear(); 
    std::cin.ignore(32767, '\n'); 
    std::cin.get();

    return 0;
}