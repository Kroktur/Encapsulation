#pragma once
#include "Object.h";
class Node
{
public:
	Node() :Previous(nullptr), Next(nullptr) {}
	virtual ~Node(){}
	Node* Previous;
	Node* Next;
};
class ClientNode : public Node
{
public:
	ClientNode(IClient* client):Client(client){}
	IClient* Client;
};
class MediaNode : public Node
{
public:
	MediaNode(IMedia* media) :Media(media) {}
	IMedia* Media;
};


class NodeList
{
public:
	NodeList()
	{
		//set Ancre
		Ancre.Next = &Ancre;
		Ancre.Previous = &Ancre;
	}
	void PushBack(Node* node)
	{
		// extract last previous node
		Node* lastpreviousnode = Ancre.Previous;
		//associate new last node
		lastpreviousnode->Next = node;
		node->Previous = lastpreviousnode;
		node->Next = &Ancre;
		Ancre.Previous = node;

	}
	void PushFront(Node* node)
	{
		// extract last first node
		Node* lastnextnode = Ancre.Next;
		//associate new first node
		lastnextnode->Previous = node;
		node->Next = lastnextnode;
		node->Previous = &Ancre;
		Ancre.Next = node;
	}
	bool isEmpty()
	{

		return (Ancre.Next == &Ancre && Ancre.Previous == &Ancre);
	}
	int size()
	{
		//not obligatory but more understandable
		if (isEmpty())
			return 0;

		Node* curentnode = Ancre.Next;
		int count = 0;
		//iterate over the container and increment count
		while (curentnode != &Ancre)
		{
			++count;
			curentnode = curentnode->Next;
		}
		return count;
	}
	void erase(Node* node)
	{
		node->Next->Previous = node->Previous;
		node->Previous->Next = node->Next;
		// supress the node
		delete node;
		node = nullptr;

	}
	Node* operator[](int index)
	{
		//in case of error
		if (index < 0 || index >= size())
			return nullptr;

		Node* curentnode = &Ancre;
		for (auto i = 0; i <= index; ++i)
			curentnode = curentnode->Next;
		return curentnode;
	}
private:
	Node Ancre;
};