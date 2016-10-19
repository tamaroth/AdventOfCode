#pragma once

#include "../AoC/aoc.hpp"
using std::chrono::high_resolution_clock;

class CDay01 : public CAoC
{
public:
	CDay01() {};
	~CDay01() {};

	virtual
	void init() override;

	virtual
	std::string part_one() const override;

	virtual 
	std::string part_two() const override;

private:
	std::string m_line{};
};
