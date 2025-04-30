#include "IndependentPCB.h"

IndependentPCB::IndependentPCB(int t_pid, int t_runTime, int t_priority, int t_memorySize):
PCB(t_pid,t_runTime,t_priority,t_memorySize)
{
	attribute = ProcessAttribute::Independent;
}

void IndependentPCB::showPCB() {
	std::cout << "pid: " << getPid() << std::endl;
	std::cout << "runTime: " << getRunTime() << std::endl;
	std::cout << "priority: " << getPriority() << std::endl;
	std::cout << "state: " << getAttribute() << std::endl;
	std::cout << "attribute: " << getAttribute() << std::endl;
	std::cout << "memorySize: " << getMemorySize() << std::endl;
	std::cout << "startAddress: " << getStartAddress() << std::endl;
}

bool IndependentPCB::canRun() {
	return true;
}
