#pragma once
#include "PCB.h"
#include <iostream>

/*-----  无前驱与后继关系的独立进程  -----*/

class IndependentPCB :public PCB
{
private:
	
public:
	IndependentPCB(int t_pid, int t_runTime, int t_priority, int t_memorySize);
	~IndependentPCB() override = default;

	void showPCB() override;
	bool canRun() override;
};

