// Program to show GoF Singleton

//header file inclusion
#include <cstdlib>  // for rand()
#include <iostream>

//class declarations
class Random 
{
	public:
	
		//4. Define a static class member function to access the instance variable. 
		static Random* getInstance()
		{
			if ( !instance ) instance = new Random;
			return instance;
		}
		
		//overloading the () operator
		int operator()(int a, int b) const
		{ 
			return (rand() % b) + a; 
		}
		
	private:
	
		//1. Place constructors and assignment in private section.
		Random() 
		{ 
			int seed = time(0);
			srand(seed); 
		}
		Random(const Random&);
		Random& operator=(const Random&);
		
		//2. Declare a static instance variable as a data attribute of the class
		static Random* instance;
};

//3. Define the static instance variable somewhere in the anonymous namespace.
Random* Random::instance = nullptr;

//function prototype
void printRandom();

//main function of the program
int main()
{
  Random* random = Random::getInstance(); //get the singleton object
  std::cout << (*random)(1,100) << std::endl; //need to dereference
  printRandom();
  delete random;
}

//function definations
void printRandom()
{
  //can acess the singleton object from anywhere
  std::cout << (*Random::getInstance())(1,100) << std::endl; 
}
