#pragma once
#include "Mymath.h"
#include "Object.h"
// to remove
#include <iostream>

class mediatheque
{
public:
	void addclient(ClientNode* client)
	{
		m_clientlist.PushBack(client);
	}
	NodeList Findclientsbyname(std::string& name)
	{
		NodeList tmplist;
		for (auto i = 0; i < m_clientlist.size(); ++i)
		{
			auto myclient = static_cast<Client*>(m_clientlist[i]->getObject());
			if (myclient->getname() == name)
				tmplist.PushBack(m_clientlist[i]);
		}
		return tmplist;
	}
	NodeList Findclientsbyfirstname(std::string& firstname)
	{
		NodeList tmplist;
		for (auto i = 0; i < m_clientlist.size(); ++i)
		{
			auto myclient = static_cast<Client*>(m_clientlist[i]->getObject());
			if (myclient->getfirstname() == firstname)
				tmplist.PushBack(m_clientlist[i]);
		}
		return tmplist;
	}
	NodeList Findclientsbyage(int& age)
	{
		NodeList tmplist;
		for (auto i = 0; i < m_clientlist.size(); ++i)
		{
			auto myclient = static_cast<Client*>(m_clientlist[i]->getObject());
			if (myclient->getage() == age)
				tmplist.PushBack(m_clientlist[i]);
		}
		return tmplist;
	}
	NodeList Findclientsbyaddress(std::string& address)
	{
		NodeList tmplist;
		for (auto i = 0; i < m_clientlist.size(); ++i)
		{
			auto myclient = static_cast<Client*>(m_clientlist[i]->getObject());
			if (myclient->getaddress() == address)
				tmplist.PushBack(m_clientlist[i]);
		}
		return tmplist;
	}
	NodeList FindclientsbyphoneNumber(std::string& phoneNumber)
	{
		NodeList tmplist;
		for (auto i = 0; i < m_clientlist.size(); ++i)
		{
			auto myclient = static_cast<Client*>(m_clientlist[i]->getObject());
			if (myclient->getphoneNumber() == phoneNumber)
				tmplist.PushBack(m_clientlist[i]);
		}
		return tmplist;
	}
	void showclient(ClientNode* client)
	{
		auto myclient = static_cast<Client*>(client->getObject());
		// add show class 
		//exemple
		std::cout << myclient->getname() << std::endl;
		std::cout << myclient->getfirstname() << std::endl;
		std::cout << myclient->getage() << std::endl;
		std::cout << myclient->getaddress() << std::endl;
		std::cout << myclient->getphoneNumber() << std::endl;
		//
	}
	void showclients(NodeList list)
	{
		for (auto i = 0; i < list.size(); ++i)
			showclient(static_cast<ClientNode*>(list[i]));
	}
	void addBook(std::string Title, std::string& ISBN)
	{
		m_medialist.PushBack(new MediaNode(new Book{ Title ,ISBN}));
	}
private:
	//vecteur de client
	NodeList m_clientlist;
	//vecteur de mediat
	NodeList m_medialist;
};
class bibliothecaire
{
public:
	bibliothecaire(mediatheque Mediatheque): m_mediatheque(Mediatheque){}
	void CreateClientAccount(std::string name, std::string firstname, int age, std::string address, std::string phoneNumber)
	{
		if(!Clientalereadyexist(name, firstname, age, address, phoneNumber))
		m_mediatheque.addclient(new ClientNode(new Client{ name ,firstname,age,address, phoneNumber }));
	}
	void showclientbyname(std::string& name)
	{
		auto myclientlist = m_mediatheque.Findclientsbyname(name);
		m_mediatheque.showclients(myclientlist);
	}
	void showclientbyfirs(std::string& name)
	{
		auto myclientlist = m_mediatheque.Findclientsbyname(name);
		m_mediatheque.showclients(myclientlist);
	}
	bool Clientalereadyexist(std::string& name, std::string& firstname, int& age, std::string& address, std::string& phoneNumber)
	{
		if (m_mediatheque.Findclientsbyname(name).size() == 0
			&& m_mediatheque.Findclientsbyfirstname(firstname).size() == 0
			&& m_mediatheque.Findclientsbyage(age).size() == 0
			&& m_mediatheque.Findclientsbyaddress(address).size() == 0
			&& m_mediatheque.FindclientsbyphoneNumber(phoneNumber).size() == 0)
			return false;
		else
			return true; 
	}
private:
	mediatheque m_mediatheque;
 };