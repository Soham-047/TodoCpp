// To Do List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<list>
#include<ctime>

using namespace std;

class TodoItem
{
    int id;
    string description;
    bool completed;

    public:
        TodoItem() : id(0), description(""), completed(false) {}
        ~TodoItem() = default;

        void create(string desc)
        {
            id = rand() % 100 + 1;
            description = desc;
        }
        int getId()
        {
            return id;
        }
        string getDescription()
        {
            return description;
        }
        bool isCompleted()
        {
            return completed;
        }

        void setCompleted(bool bl)
        {
            completed = bl;
        }

};

int main()
{
    list<TodoItem> todoItems;
    srand(time(NULL));

    todoItems.clear();

    while (1)
    {
        system("cls");
        cout << "! TO-DO List Maker ~" << endl;
        cout << endl << endl;
        int id;
        string desc;
        char c;

        for (auto it = todoItems.begin(); it != todoItems.end(); it++)
        {
            cout << it->getId() << " | " << it->getDescription() << " | ";
            if (it->isCompleted()) cout << "Done";
            else cout << "Not Done";
            cout << endl;
        }

        if (todoItems.empty())
        {
            cout << "Your Todo List is empty" << endl;
        }

        cout << "[a]dd a new Todo" << endl;
        cout << "[c]omplete a Todo " << endl;
        cout << "[i]ncomplete a Todo " << endl;
        cout << "[q]uit" << endl;
        
        cout << "Choice: ";
        cin >> c;

        if (c == 'q') {
            cout << "Have a nice day!!" << endl;
            break;
        }
        else if (c == 'a')
        {
            cout << "Add a new Description: ";
            cin.clear();
            cin.ignore();
            getline(cin, desc);

            TodoItem newItem;
            newItem.create(desc);
            todoItems.push_back(newItem);
        }
        else if (c == 'c')
        {
            cout << "Enter id to mark completed: ";
            cin >> id;
            cout << endl;
            for (auto it = todoItems.begin(); it != todoItems.end(); it++)
            {
                if (id == it->getId())
                {
                    it->setCompleted(true);
                    break;
                }
                cout << endl;
            }
        }
        else if (c == 'i')
        {
            int id;
            cout << "Enter id to mark incomplete: ";
            cin >> id;
            cout << endl;
            for (auto it = todoItems.begin(); it != todoItems.end(); it++)
            {
                if (id == it->getId())
                {
                    it->setCompleted(false);
                    break;
                }
                cout << endl;
            }
        }

    }


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
