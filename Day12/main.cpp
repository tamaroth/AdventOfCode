/************************************************************************/
/* Advent of Code:
/* Day 12: JSAbacusFramework.io
/************************************************************************/

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

using namespace boost;
using namespace property_tree;

int countElements(const ptree& pt, const bool& filterRed = false)
{
	int local = 0;
	for (const auto& v : pt)
	{
		local += countElements(v.second, filterRed);
		int ret = v.second.get_value<int>(0);
		local += ret;
		if (ret == 0 && filterRed )
		{
			if ((v.first != "") && (v.second.get_value<std::string>("") == "red"))
				return 0;
		}
	}
	return local;
}

size_t partOne()
{
	std::ifstream infile("data_d12.txt");
	std::string input;
	ptree pt;
	read_json(infile, pt);
	return countElements(pt);
}

size_t partTwo()
{
	std::ifstream infile("data_d12.txt");
	std::string input;
	ptree pt;
	read_json(infile, pt);
	return countElements(pt, true);
}

int main()
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	std::cout << partOne() << std::endl;
	std::cout << partTwo() << std::endl;
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - t1);
	std::cout << "Time: " << time_span.count() << "s.";
}
