#pragma once
#include <memory>
#include <iostream>

template<typename T>
class LinkedList
{
public:
	void pushbackNode(T aValue);
	void popLastNode();
	void printForward();
	void printBackwards();

	LinkedList& operator=(const LinkedList) = delete;
	LinkedList(const LinkedList& that) = delete;

private:

	struct LinkedListNode
	{
		T mValue{};
		struct std::shared_ptr <LinkedListNode> mNextNode;
		struct std::weak_ptr <LinkedListNode> mPrevNode;
	};

	unsigned int nodeCounter{};
	std::shared_ptr <LinkedListNode> mHead;
	std::shared_ptr <LinkedListNode> mTail;
};

template<typename T>
void LinkedList<T>::pushbackNode(T aValue)
{
	auto tempNode = std::make_shared<LinkedListNode>();
	tempNode->mValue = aValue;

	if (mHead == nullptr)
	{
		mHead = mTail = tempNode;
	}
	else if (mHead == mTail)
	{
		mTail = tempNode;
		mHead->mNextNode = mTail;
		mTail->mPrevNode = mHead;
	}
	else
	{
		mTail->mNextNode = tempNode;
		tempNode->mPrevNode = mTail;
		mTail = tempNode;
	}
	nodeCounter++;
}

template<typename T>
void LinkedList<T>::printForward()
{
	auto temp = mHead;
	while (temp!= nullptr)
	{
		std::cout << temp->mValue << std::endl;
		temp = temp->mNextNode;
	}
}

template<typename T>
void LinkedList<T>::printBackwards()
{
	auto temp = mTail;
	while (temp != nullptr)
	{
		std::cout << temp->mValue << std::endl;
		temp = temp->mPrevNode.lock();
	}
}

template<typename T>
void LinkedList<T>::popLastNode()
{
	if (mHead != nullptr) // check if there are nodes in the list
	{
		if (mHead == mTail)
		{
			mHead.reset();
			mTail.reset();
			std::cout << "List is empty!\n";
		}
		else
		{
			mTail = mTail->mPrevNode.lock();
			mTail->mNextNode.reset();
		}
	}
	nodeCounter--;
}

