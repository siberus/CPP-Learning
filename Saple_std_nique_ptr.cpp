#include <iostream>
#include <memory>

class Item
{  
    public:
    Item() {std::cout << "Item acquired" << std::endl;}
    ~Item() {std::cout << "Item destroyed" << std::endl;}
};

int main()
{
    // Выделяем объект класса Item и передаем право собственности на него std::unique_ptr
    std::unique_ptr<Item> item(new Item);

    return 0;
} // item выходит из области видимости здесь, соответственно, Item уничтожается также здесь
