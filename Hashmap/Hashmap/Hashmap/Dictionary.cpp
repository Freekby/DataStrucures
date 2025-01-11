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

// TODO: реализуемый метод наодится не в том cpp файле*
void Dictionary::PrintState() const
{
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
