#include "Dictionary.h"
#include <iostream>

Dictionary::Dictionary(size_t initialSize, double loadFactor)
    : _dictionary(initialSize, loadFactor) {}

void Dictionary::Add(const std::string& key, const std::string& value)
{
    _dictionary.Insert(key, value);
}

void Dictionary::Remove(const std::string& key)
{
    _dictionary.Remove(key);
}

std::string Dictionary::Find(const std::string& key)
{
    return _dictionary.Find(key);
}

void Dictionary::PrintState() const
{
    // TODO: работа с пользователем не должна быть в логике...
    // Вы можете вынести в Main, но отвязать от класса и добавить аргумент в виде словаря,
    // чтобы решить эту проблему
    std::cout << "������� ��������� ���-�������:" << std::endl;
    for (size_t i = 0; i < _dictionary.GetSize(); ++i)
    {
        std::cout << i << ": ";
        Node *current = _dictionary.GetBucket(i);
        if (current == nullptr)
        {
            std::cout << "�����";
        }
        else
        {
            while (current)
            {
                std::cout << "[" << current->key << ": " << current->value << "]";
                if (current->next)
                    std::cout << " -> ";
                current = current->next;
            }
        }
        std::cout << std::endl;
    }

    std::cout << "������� (����� � ��������):" << std::endl;
    for (size_t i = 0; i < _dictionary.GetSize(); ++i)
    {
        Node *current = _dictionary.GetBucket(i);
        while (current)
        {
            std::cout << current->key << ": " << current->value << std::endl;
            current = current->next;
        }
    }
}
