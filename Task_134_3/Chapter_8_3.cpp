#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Monster
{
    public:
    enum MonsterType
    {
        Dragon, 
        Goblin, 
        Ogre, 
        Orc, 
        Skeleton, 
        Troll, 
        Vampire,
        Zombie,
        MAX_MONSTER_TYPES
    };

    private:
    enum MonsterType m_type;
    std::string m_name;
    int m_health;

    public:
    Monster(MonsterType type, std::string name, int health)
        : m_type(type), m_name(name), m_health(health) {}

    std::string getTypeString()
    {
        switch (m_type)
        {
        case Dragon: return "dragon";
        case Goblin: return "goblin";
        case Ogre: return "ogre";
        case Orc: return "orc";
        case Skeleton: return "skeleton";
        case Troll: return "troll";
        case Vampire: return "vampire";
        case Zombie: return "zombie";
        } 
        
        return "Error!";
    }
    
    void print()
    {
        std::cout << m_name << " is the " << getTypeString() << " that has " << m_health << " health points." <<std::endl;
    }
};

class MonsterGenerator
{
    public:
    // Генерируем случайное число между min и max (включительно). 
    // Предполагается, что srand() уже был вызван 
    static int getRandomNumber(int min, int max) 
    { 
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
        // используем static, так как это значение нужно вычислить единожды 
        // Равномерно распределяем вычисление значения из нашего диапазона 
        return static_cast<int>(rand() * fraction * (max - min + 1) + min); 
    }

    static Monster generateMonster()
    {
        
        static std::string s_names[] {"Jack", "Dilan", "Petr", "Bob", "Sid", "Luck"};
        Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES-1));
        int health = getRandomNumber(0, 100);
        std::string name = s_names[getRandomNumber(0, 5)];

        return Monster(type, name, health);
    }
};

int main() 
{
    srand(static_cast<unsigned int>(time(0)));
    rand(); // пользователям Visual Studio: делаем сброс первого случайного числа

    Monster m = MonsterGenerator::generateMonster();
    m.print();
    return 0; 
}