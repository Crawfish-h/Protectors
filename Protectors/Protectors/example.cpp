#include "Protector.cpp" 
#include <iostream> 

int main(int argc, char* argv[])
{
	auto a = [](std::vector<double>* var)
	{
		if ((*var)[0] == 10.0)
		{
			return true;
		}

		return false;
	};

	auto b = [](std::vector<double>* var)
	{

		return false;
	};



	Waw::WPROT<int> prot(160);

	prot.Set_Getter_Condition(a);

	std::vector<double> vec;
	vec.push_back(10.0);
	std::cout << prot(&vec) << std::endl;

	return 0;
}