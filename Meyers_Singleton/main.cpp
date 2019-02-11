// Program to show Meyers Singleton

//header file inclusion
#include <cstdlib>  // for rand()
#include <iostream>

//class declarations
class Random 
{
	public:
	
		//2.Define a static class member function that returns the reference to static instance variable. 
		static Random& getInstance()
		{
			static Random instance; //static instance variable
			return instance;
		}
		
		//overloading the () operator
		int operator()(int a, int b) const
		{ 
			return (rand() % b) + a; 
		}
		
		int& num()
		{
			static int val = 27; //static varaible: local declaration,global presence
			return val;
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
};

//function prototype
void printRandom();

//main function of the program
int main()
{
  Random& random = Random::getInstance(); //get the singleton object reference
  std::cout << random(1,100) << std::endl;
  printRandom();
  
  int val = random.num();
  std::cout<<"val = "<<val<<std::endl;
}

//function definations
void printRandom()
{
  //can acess the singleton object from anywhere
  std::cout << (Random::getInstance())(1,100) << std::endl; 
}
