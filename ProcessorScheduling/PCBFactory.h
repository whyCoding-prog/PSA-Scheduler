#pragma once

#include<vector>
#include "PCBRegistry.h"
#include "PCB.h"
#include "IndependentPCB.h"
#include "SynchronousPCB.h"

class PCBFactory
{
public:

	//创建独立进程接口  改为返回PCB* 返回原指针，不持有所有权
	static PCB* createIndependentPCB(
		int pid,
		int runTime,
		int priority,
		int memorySize
	);

	//创建同步进程接口
	static PCB* createSynchronousPCB(
		int pid,
		int runTime,
		int priority,
		int memorySize,
		const std::vector<int>& pioneers,
		const std::vector<int>& successors
	);

private:

	//参数验证,暂时不需要实现
	/*
	static bool validateCommonParams(
		int pid,
		int runTime,
		int priority,
		int memorySize
	);

	static bool validateSynchronousPCB(
		const std::vector<int>& pioneers,
		const std::vector<int>& successors
	);
	*/
};

