#include "LinkedList.h"

int main()
{
	LinkedList<int> testNode;

	for (int i = 0; i < 10; i++)
	{
		testNode.pushbackNode(i);
	}

	testNode.printForward();
	std::cout << "COUNTING BACKWARDS!\n";
	testNode.printBackwards();

	const unsigned int nodesToPop = 5;
	std::cout << "Popping " << nodesToPop << " nodes!\n";
	for (int i = 0; i < nodesToPop; ++i)
	{
		testNode.popLastNode();
	}
	testNode.printForward();
	std::cout << "COUNTING BACKWARDS!\n";
	testNode.printBackwards();

	std::cout << "Popping another " << nodesToPop << " nodes!\n";

	for (int i = 0; i < nodesToPop; ++i)
	{
		testNode.popLastNode();
	}

	std::cin.get();
}