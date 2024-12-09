#pragma once

#include <vector>
#include <stdexcept>

// TODO: Полетела кодироквка русских символов
/**
* @brief Øàáëîííûé êëàññ äëÿ ðåàëèçàöèè ñòåêà.
*/
template <typename T>
class Stack
{
private:
	/**
	* @brief Ñòðóêòóðà óçëà ñòåêà.
	*/
	struct Node
	{
		/** @brief Äàííûå, õðàíÿùèåñÿ â óçëå. */
		T data;

		/** @brief Óêàçàòåëü íà ñëåäóþùèé óçåë. */
		Node* next;

		/**
		* @brief Êîíñòðóêòîð óçëà.
		*/
		Node(const T& data) : data(data), next(nullptr) {}
	};

	/** @brief Óêàçàòåëü íà âåðøèíó ñòåêà. */
	Node* _top;

public:
	/**
	* @brief Êîíñòðóêòîð ñòåêà.
	*/
	Stack() : _top(nullptr) {}

	/**
	* @brief Äåñòðóêòîð ñòåêà.
	*/
	~Stack()
	{
		while (!IsStackEmpty())
		{
			Pop();
		}
	}

	/**
	* @brief Ïðîâåðêà íà ïóñòîòó ñòåêà.
	*/
	bool IsStackEmpty() const
	{
		return _top == nullptr;
	}

	/**
	* @brief Äîáàâëåíèå ýëåìåíòà â ñòåê.
	*/
	void Push(const T& data)
	{
		Node* newNode = new Node(data);
		newNode->next = _top;
		_top = newNode;
	}

	/**
	* @brief Èçâëå÷åíèå ýëåìåíòà èç ñòåêà.
	* @return Âåðõíèé ýëåìåíò ñòåêà.
	* @throw std::underflow_error Åñëè ñòåê ïóñò.
	*/
	T Pop()
	{
		// TODO: RSDN
		if (IsStackEmpty())
		{
			throw std::underflow_error("Ñòåê ïóñò!");
		}
		T data = _top->data;
		Node* temp = _top;
		_top = _top->next;
		delete temp;
		return data;
	}

	/**
	* @brief Âîçâðàùàåò äàííûå ñòåêà â âèäå âåêòîðà.
	* @return Âåêòîð, ñîäåðæàùèé äàííûå ñòåêà.
	*/
	std::vector<T> GetData() const
	{
		// TODO: RSDN
		std::vector<T> data;
		Node* current = _top;
		while (current != nullptr)
		{
			data.push_back(current->data);
			current = current->next;
		}
		return data;
	}
};