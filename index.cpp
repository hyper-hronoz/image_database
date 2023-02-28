#include<iostream>
#include<vector>
#include<functional>

using namespace std;

template<class T>
class AbstractFactory {
    virtual T create() = 0; 
};

class MenuItem {
 private:
    string title;
    int id;
    function<void()> callback;

 public:
    MenuItem(int id, string title) {
        this->title = title;
        this->id = id;
    }

    MenuItem(int id, string title, function<void()> callback) : MenuItem(id, title) {
        this->callback = callback;
    }

    string getTitle() {
        return this->title;
    }

    int getId() {
        return this->id;
    }

    void executeCallback() {
        callback();
    }

    ~MenuItem() {}
};

class MenuItemFactory : public AbstractFactory<MenuItem>{
 private:
     int id = 0;
 public:
    MenuItem *create(string title, function<void()> callback) {
        MenuItem *menuItem = new MenuItem{this->id, title, callback};
        this->id++;
        return menuItem;
    }
};

class Menu {
 private:
    vector<MenuItem> menuItems;

 public:
    Menu() {
        menuItems = {};
    }

    ~Menu() {

    }

    void append(MenuItem menuItem) {
        menuItems.push_back(menuItem);
    }

    void print() {
        for (MenuItem menuItem : menuItems) {
            cout << menuItem.getId() << ") "
            << menuItem.getTitle() << endl;
        }
    }
};

class Fucker {

    public:
        void doStuff() {
            cout << "Ebash" << endl;
        };
};

int main() {
    Menu menu;

    MenuItemFactory *menuItemFactory;

    Fucker fucker;

    menu.append(*(menuItemFactory->create("Ведение базы фотографий", [&fucker]() {
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("╰─Добавить фотку", [&fucker]() {
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("╰─Удалить фотку", [&fucker]() {
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("╰─Редиктировать фотку", [&fucker]() {
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("╰─Сортировать фотки", [&fucker]() {
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("Ведение базы отмеченных людей на фото", [&fucker]() {
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("История/Состояние", [&fucker]() {
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("Войти/Зарегаться", [&fucker]() {
        fucker.doStuff();
    })));

    menu.print();

    return 0;
}
