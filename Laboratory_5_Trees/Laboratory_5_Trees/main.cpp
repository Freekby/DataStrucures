#include <iostream>
#include <cstdlib> // Для rand()
#include <ctime>
#include "BinaryTree.h"
#include "Treap.h"

int CheckValue()
{
    std::cout << "Your choose: ";

    int value;
    while (true)
    {
        if (std::cin >> value)
        {
            return value;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid value. Try again: ";
        }
    }
}

void Menu() 
{
    std::cout << "====== Меню ======" << std::endl;
    std::cout << "1. Добавить элемент в BinaryTree" << std::endl;
    std::cout << "2. Удалить элемент из BinaryTree" << std::endl;
    std::cout << "3. Найти элемент в BinaryTree" << std::endl;
    std::cout << "4. Найти минимум в BinaryTree" << std::endl;
    std::cout << "5. Найти максимум в BinaryTree" << std::endl;
    std::cout << "6. Добавить элемент в Treap" << std::endl;
    std::cout << "7. Удалить элемент из Treap" << std::endl;
    std::cout << "8. Показать элементы Treap (Inorder)" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "===================" << std::endl;
    
}

int main() 
{
    BinaryTree *binaryTree = new BinaryTree(50); 
    Treap *treap = new Treap();
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(static_cast<unsigned>(time(0))); 

    int choice, key;

    do {
        Menu();
        std::cout << "Элементы бинарного дерева:";
        binaryTree->InorderTraversal();
        std::cout << "Введите ваш выбор: ";
        choice = CheckValue();


        try {
            switch (choice) {
            case 1:
                std::cout << "Введите ключ для добавления в BinaryTree: ";
                key = CheckValue();
                binaryTree->AddElement(key, binaryTree->_root);
                std::cout << "Элемент добавлен в BinaryTree." << std::endl;
                break;

            case 2:
                std::cout << "Введите ключ для удаления из BinaryTree: ";
                key = CheckValue();
                {
                    BinaryTreeNode* node = binaryTree->Find(key, binaryTree->_root);
                    if (node) 
                    {
                        binaryTree->RemoveElement(node);
                        std::cout << "Элемент удалён из BinaryTree." << std::endl;
                    }
                    else 
{
                        std::cout << "Элемент не найден." << std::endl;
                    }
                }

                break;

            case 3:
                std::cout << "Введите ключ для поиска в BinaryTree: ";
                key = CheckValue();
                if (binaryTree->Find(key, binaryTree->_root)) 
                {
                    std::cout << "Элемент найден в BinaryTree." << std::endl;
                }
                else 
                {
                    std::cout << "Элемент не найден в BinaryTree." << std::endl;
                }
                    
                break;

            case 4:
            {
                BinaryTreeNode* minNode = binaryTree->FindMin(binaryTree->_root);
                if (minNode) 
                {
                    std::cout << "Минимальный элемент в BinaryTree: " << minNode->data << std::endl;
                } 
                else 
                {
                    std::cout << "Дерево пустое." << std::endl;
                }
                    
            }

            break;

            case 5:
            {
                BinaryTreeNode* maxNode = binaryTree->FindMax(binaryTree->_root);
                if (maxNode) 
                {
                    std::cout << "Максимальный элемент в BinaryTree: " << maxNode->data << std::endl;
                }  
                else 
                {
                    std::cout << "Дерево пустое." << std::endl;
                }
                    
            }

            break;

            case 6:
                std::cout << "Введите ключ для добавления в Treap: ";
                std::cin >> key;
                treap->Insert(key);
                std::cout << "Элемент добавлен в Treap." << std::endl;
                break;

            case 7:
                std::cout << "Введите ключ для удаления из Treap: ";
                std::cin >> key;
                treap->Remove(key);
                std::cout << "Элемент удалён из Treap." << std::endl;
                break;

            case 8:
                std::cout << "Элементы Treap (Inorder): ";
                treap->Inorder();
                break;

            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;

            default:
                std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
                break;
            }
        }
        catch (const char* err) {
            std::cout << "Ошибка: " << err << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 0);

    return 0;
}
