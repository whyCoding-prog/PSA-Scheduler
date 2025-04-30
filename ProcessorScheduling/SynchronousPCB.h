#pragma once
#include "PCB.h"
#include <vector>

/*-----  有前驱与后继关系的同步进程  -----*/
class SynchronousPCB :public PCB
{
private:
	std::vector<std::pair<int, bool>>pioneers;	//前驱
	std::vector<int>successors;	//后继

public:
	SynchronousPCB(int t_pid, int t_runTime, int t_priority, int t_memorySize,const std::vector<int>& t_pioneers,const std::vector<int>& t_p_successors);
	~SynchronousPCB() override = default;
	void showPCB() override;
	bool canRun() override;
	void updatePioneers(int pid);

};

