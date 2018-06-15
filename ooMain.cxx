#include <iostream>
#include "/storage/0000-0000/Android/data/com.termux/files/cpp_oo_example_code/std_header.h"
class Felement {
	protected:
		int zNumber;
		std::vector<int> zNodes;
	
	public:
		Felement(int& pNumber, std::vector<int>& pNodes) {
			zNumber = pNumber;
			zNodes = pNodes;
		}
		
		void set_number(int& pNumber) {
			zNumber = pNumber;
		}
		
		int get_number() {
			return zNumber;
		}
		
		std::string toString() {
			std::string lValue = "";
			for(int i=0;i<zNodes.size();i++)
			{
				lValue += std::to_string(zNodes[i]) + " ";
			}
			return lValue;
		}
		
		std::string to_string() {
			return this->toString();
		}
};
int main() { 
  int a =0;
  std::vector<int> lVector;
  char s [100];

  std::cout << "This is a sample program." << std::endl;

  std::cout << "Lets generate a finite element. It consists of as many nodes you like.\n Give me the non negative node numbers. A negative input finishes the list." <<std::endl;

  while(a>=0)
  {
  	std::cout << "New node number : " << std::endl; 
	  std::cin >> a;
	  if(a>=0)
	  	lVector.push_back(a);
  }

	Felement lEle(a,lVector);

	std::cout << "Element " << lEle.get_number() << " has the following nodes:" << lEle.toString() << ". " << std::endl; 

/*
  std::cout << "Type your name: \n"; 
  std::cin >> s;

  std::cout << std::endl;

  std::cout << "Hello " << s << " you're " << a << " old." << std::endl; 
  std::cout << std::endl << std::endl << "Bye!" << std::endl;
*/
  return 0;
}