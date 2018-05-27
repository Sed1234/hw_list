#include <iostream>
#include <list>
#include "LinkedList.h"
void main()
{
	LinkedList<int> l;
	l.addToTail(5);
	l.addToTail(10);
	l.addToTail(9);
	l.addToTail(8);
	l.addToTail(1);
	l.addToTail(8);
	l.addToTail(7);
	l.addToTail(8);
	l.addToHead(3);
	l.InsertByPosition(3, 99);
	l.DeleteByPosition(5);
	//l.deleteFromHead();
	//l.deleteFromTail();
	//l.Clear();
	l.ShowElements();
	/*size_t x = 0, y = 2;
	std::cout << l[x] << std::endl;
	auto result = l.searchByValue(8);
	for (auto it : result)
	{
		std::cout << it << ' ';
	}
	l.Clear();
	*/
	system("pause");
}