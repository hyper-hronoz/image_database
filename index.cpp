#include<iostream>
#include<vector>
#include<functional>

using namespace std;

template<class T>
class AbstractFactory {
    virtual T create() = 0; 
};

class MenuItem {
    string title;
    function<void()> callback;

 public:
    MenuItem(string title) {
        this->title = title;
    }

    MenuItem(string title, function<void()> callback) : MenuItem(title) {
        this->callback = callback;
    }

    string getTitle() {
        return this->title;
    }

    void executeCallback() {
        callback();
    }

    ~MenuItem() {}
};

class MenuItemFactory : public AbstractFactory<MenuItem>{
 public:
    MenuItem *create(string title, function<void()> callback) {
        int itemId; //  soon will be done
        return new MenuItem{title, callback};
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
            cout << menuItem.getTitle() << endl;
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

    menu.append(*(menuItemFactory->create("Ведение базы фотографий", []() {
        Fucker fucker;
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("╰─Добавить фотку", []() {
        Fucker fucker;
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("╰─Удалить фотку", []() {
        Fucker fucker;
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("╰─Редиктировать фотку", []() {
        Fucker fucker;
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("╰─Сортировать фотки", []() {
        Fucker fucker;
        fucker.doStuff();
    })));


    menu.append(*(menuItemFactory->create("Ведение базы отмеченных людей на фото", []() {
        Fucker fucker;
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("История/Состояние", []() {
        Fucker fucker;
        fucker.doStuff();
    })));

    menu.append(*(menuItemFactory->create("Войти/Зарегаться", []() {
        Fucker fucker;
        fucker.doStuff();
    })));

    menu.print();

    return 0;
}
