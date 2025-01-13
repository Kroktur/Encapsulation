#include <iostream>
#include "Mymath.h"
int main()
{
	Client client;
	NodeList list;
	ClientNode* myclient = new ClientNode(&client );
	list.PushBack(myclient);
	static_cast<ClientNode*>(list[0])->Client->getAge();
	std::cout << "hello world" << std::endl;
	return 0;
}