#include<iostream>
#include<vector>
#include<functional>

using namespace std;

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
        this->id = id;
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

class MenuItemFactory {
 private:
    int id = 0;

 public:
    MenuItem *create(string title, function<void()> callback) {

        MenuItem *menuItem = new MenuItem{id, title, callback};
        id++;
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

    MenuItemFactory *menuItemFactory = new MenuItemFactory{};

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

    delete menuItemFactory;

    return 0;
}
