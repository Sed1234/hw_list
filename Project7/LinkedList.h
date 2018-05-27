#pragma once
#pragma once
#include "ElementOfLinkedList.h"
#include <vector>
#include <ostream>
template <typename type>
class LinkedList
{
	ElementOfLinkedList<type> * head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	void swap(size_t & first, size_t & second)
	{
		ElementOfLinkedList<type> * first_temp = head, *second_temp = head;
		while (first > 0)
		{
			first_temp = first_temp->next;
			first--;
		}
		while (second > 0)
		{
			second_temp = second_temp->next;
			second--;
		}
		type temp = first_temp->value;
		first_temp->value = second_temp->value;
		second_temp->value = temp;
	}
	std::vector<size_t> searchByValue(const type & value) const
	{
		std::vector<size_t> result;
		size_t i = 0;
		for (
			ElementOfLinkedList<type> * temp = head;
			temp != nullptr;
			temp = temp->next)
		{
			if (temp->value == value)
			{
				result.push_back(i);
			}
			++i;
		}
		return result;
	}
	type & operator [](size_t & position) const {
		ElementOfLinkedList<type> * result = head;
		while (position > 0)
		{
			result = result->next;
			position--;
		}
		return result->value;
	}
	void addToTail(const type & value)
	{
		if (head == nullptr)
		{
			head = new ElementOfLinkedList<type>(value);
		}
		else
		{
			ElementOfLinkedList<type> * temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new ElementOfLinkedList<type>(value);
		}
	}
	void addToHead(const type & value)
	{
		if (head == nullptr)
		{
			head = new ElementOfLinkedList<type>(value);
		}
		else
		{
			ElementOfLinkedList<type> * temp = head;
			head = new ElementOfLinkedList<type>(value);
			head->next = temp;
		}
	}
	void deleteFromHead()
	{
		head = head->next;

	}
	void deleteFromTail()
	{
		ElementOfLinkedList<type> * temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		//head->next = temp;
	}
	void deleteByValue(const type & value)
	{
		if (head != nullptr)
		{
			ElementOfLinkedList<type> * temp = head;
			if (head->value == value)
			{
				head = head->next;
			}
			else
			{
				while (temp->next != nullptr)
				{
					if (temp->next->value == value)
					{
						temp->next = temp->next->next;
					}
					temp = temp->next;
				}
			}
		}
	}
	 void Clear()
	{
		head = nullptr;
		//head->next = nullptr;
	}
	friend std::ostream & operator << (std::ostream & stream, LinkedList<type> & list)
	{
		if (list.head != nullptr)
		{
			ElementOfLinkedList<type> * temp = list.head;
			while (temp != nullptr)
			{
				stream << temp->value << std::endl;
				temp = temp->next;
			}
		}
		return stream;
	}
	void ShowElements()
	{
		for (
			ElementOfLinkedList<type> * temp = head;
			temp != nullptr;
			temp = temp->next)

		{
			std::cout << temp->value << ' ';
		}

	}
	void InsertByPosition(int x, const type & value) const
	{
		size_t i = 0;
		ElementOfLinkedList<type> * temp = head;
		while (i != x)
		{
			temp = temp->next;
			i++;
			if (i == x)
			{
				temp->value = value;
				temp = temp->next;
			}
		}
		
	}
	void DeleteByPosition(int x) const
	{
		size_t i = 0;
		ElementOfLinkedList<type> * temp = head;
		while (i != x)
		{
			temp = temp->next;
			i++;
			if (i == x)
			{
				temp->next = temp->next->next;
			}
		}

	}

	~LinkedList()
	{
		delete head;
	}
};

