#pragma once
template <typename type>
class ElementOfLinkedList
{
public:
	type value;
	ElementOfLinkedList<type> * next;
	ElementOfLinkedList(const type & value)
	{
		this->value = value;
		next = nullptr;
	}
	~ElementOfLinkedList()
	{
		if (next != nullptr)
		{
			delete next;
		}
	}
};

