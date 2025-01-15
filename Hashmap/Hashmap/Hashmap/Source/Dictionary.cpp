#include <iostream>
#include "../Header/Dictionary.h"

Dictionary::Dictionary(size_t initialSize, double loadFactor)
    : _dictionary(initialSize, loadFactor) {}

void Dictionary::Add(const std::string& key, const std::string& value)
{
    size_t index = _dictionary.GetIndex(key);

    for (Node* current = _dictionary.GetBucket(index); current != nullptr; current = current->next)
    {
        if (current->key == key)
        {
            return;
        }
    }

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

size_t Dictionary::GetSize()
{
    return _dictionary.GetSize();
}

Node* Dictionary::GetBucket(size_t index) const
{
    return _dictionary.GetBucket(index);
}

