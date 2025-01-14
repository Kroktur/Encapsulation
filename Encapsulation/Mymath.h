#pragma once
#include "Object.h";
class Node
{
public:
	Node() :Previous(nullptr), Next(nullptr), m_object(nullptr){}
	virtual ~Node(){}
	Object* getObject(){return m_object;}
	Node* Previous;
	Node* Next;
protected:
	Object* m_object;
};
class ClientNode : public Node
{
public:
	ClientNode(Client* client){ m_object = client;}
};
class MediaNode : public Node
{
public:
	MediaNode(Media* media)  { m_object = media; }
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
	~NodeList()
	{
		if (isEmpty())
			return;
		Node* currentnode = Ancre.Next;
		while (currentnode != &Ancre)
		{
			Node* next = currentnode->Next;
			delete currentnode;
			currentnode = next;
		}
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