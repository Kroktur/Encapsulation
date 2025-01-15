#include <iostream>
#include "Mymath.h"
int main()
{

	Client* client = new Client("aea", "dzqd",53534,"dzq","dqsd");
	Media* media = new Book("sqetset","dqsdqd");
	NodeList list;
	ClientNode* myclient = new ClientNode(client );
	MediaNode* nymedia = new MediaNode(media);
	list.PushBack(myclient);
	list.PushBack(nymedia);
	auto clientmodif = static_cast<ClientNode*>(list[0]);
	std::cout <<list[0]->getObject()->gettype();
	std::cout << list[1]->getObject()->gettype();
	if (list[1]->getObject()->gettype() == 1)
	{
		auto mediamodif = static_cast<Media*>(list[1]->getObject());
		auto book = static_cast<Book*> (mediamodif);

	}



	std::cout << "hello world" << std::endl;
	return 0;
}