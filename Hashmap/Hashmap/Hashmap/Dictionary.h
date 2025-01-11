#pragma once

#include <string>
#include <iostream>
// TODO: Полетела кодировка
/// <summary>
/// ��������� ��� �������� ���� ����-��������.
/// </summary>
// TODO: один файл - один класс/структура
struct Node 
{
    std::string key; ///< ����.
    std::string value; ///< ��������.
    Node* next; ///< ��������� �� ��������� ����.

    /// <summary>
    /// ����������� �������� ���-�������.
    /// </summary>
    /// <param name="k">����.</param>
    /// <param name="v">��������.</param>
    Node(const std::string& k, const std::string& v) : key(k), value(v), next(nullptr) {}
};

/// <summary>
/// ����� HashTable ��������� ���-�������.
/// </summary>
class HashTable 
{
private:
    // TODO: Комментарии над комментируемом коде. Тоже можно использовать summary
    Node** _table; ///< ������ ���������� �� ������.
    size_t _size; ///< ������ �������.
    double _maxLoadFactor; ///< ������������ ����������� ����������.
    size_t _count; ///< ������� ���������� ���������.

    /// <summary>
    /// �������������� � ������ �������.
    /// </summary>
    /// <param name="key">����.</param>
    /// <returns>������ �������.</returns>
    size_t GetIndex(const std::string& key) const;

    /// <summary>
    /// ���������������.
    /// </summary>
    void Rehash();

public:
    /// <summary>
    /// ����������� ���-�������.
    /// </summary>
    /// <param name="initialSize">��������� ������.</param>
    /// <param name="loadFactor">������������ ����������� ����������.</param>
    HashTable(size_t initialSize = 10, double loadFactor = 0.75);

    /// <summary>
    /// ���������� ���-�������.
    /// </summary>
    ~HashTable();

    /// <summary>
    /// ��������� ������� � ���-�������.
    /// </summary>
    /// <param name="key">����.</param>
    /// <param name="value">��������.</param>
    void Insert(const std::string& key, const std::string& value);

    /// <summary>
    /// ������� ������� �� �����.
    /// </summary>
    /// <param name="key">����.</param>
    void Remove(const std::string& key);

    /// <summary>
    /// ���� �������� �� �����.
    /// </summary>
    /// <param name="key">����.</param>
    /// <returns>��������� �������� ��� ������ ������, ���� ������� �� ������.</returns>
    std::string Find(const std::string& key) const;

    /// <summary>
    /// ���-�������.
    /// </summary>
    /// <param name="key">����.</param>
    /// <returns>��� ��� �����.</returns>
    size_t static GetHash(const std::string& key);

    /// <summary>
    /// �������� ����� �� �������.
    /// </summary>
    /// <param name="index">������.</param>
    /// <returns>�����.</returns>
    Node* GetBucket(size_t index) const;

    /// <summary>
    /// �������� ������ �������.
    /// </summary>
    /// <returns>������ �������.</returns>
    size_t GetSize() const;

    /// <summary>
    /// �������� ���������� ���������.
    /// </summary>
    /// <returns>���������� ���������.</returns>
    size_t GetCount() const;
};
