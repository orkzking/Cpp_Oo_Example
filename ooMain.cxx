#ifdef NOANDROID
#include "std_header.h"
#include "Felement.cxx"
#else
#include "/storage/0000-0000/Android/data/com.termux/files/cpp_oo_example_code/std_header.h"
#include "/storage/0000-0000/Android/data/com.termux/files/cpp_oo_example_code/Felement.cxx"
#endif


int main() { 
  int a =0,dof = 2,b = 0;
  std::vector<int> lVector;
  char s [100];

  std::cout << "This is a sample program." << std::endl;

  std::cout << "Lets generate a finite element. It consists of as many nodes you like.\n Give me the non negative node numbers. A negative input finishes the list and is the number of the element." <<std::endl;

  while(a>=0)
  {
  	std::cout << "New node number : " << std::endl; 
	  std::cin >> a;
	  if(a>=0)
	  	lVector.push_back(a);
  }
	b = -1*a;
	std::list<Felement*> lElements;

	lElements.push_back(new QuadEle(b,lVector,dof));
/*
	for (std::list<Felement*>::iterator iter = lElements.begin();iter!=lElements.end();++iter)
	{
		Felement *ele = *iter;
		std::cout << "Element " << ele->get_number() << " has the following nodes:" << ele->toString() << ". " << std::endl; 
	}
	*/
	for (auto &i : lElements)
		std::cout << "Element " << i->get_number() << " has the following nodes:" << i->toString() << "and the matrices have the dimension MxM with M = "<< i->get_MatricesDimensions() << std::endl;

/*
  std::cout << "Type your name: \n"; 
  std::cin >> s;

  std::cout << std::endl;

  std::cout << "Hello " << s << " you're " << a << " old." << std::endl; 
  std::cout << std::endl << std::endl << "Bye!" << std::endl;
*/
  return 0;
}
