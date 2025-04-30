#include "SynchronousPCB.h"

SynchronousPCB::SynchronousPCB(int t_pid, int t_runTime, int t_priority, int t_memorySize,const std::vector<int>& t_pioneers,const std::vector<int>& t_successors):
PCB(t_pid, t_runTime, t_priority, t_memorySize),successors(t_successors)
{
	attribute = ProcessAttribute::Synchronous;
	for (auto a : t_pioneers) {
		pioneers.emplace_back(a,false);
	}
}

void SynchronousPCB::showPCB() {
	std::cout << "pid: " << getPid() << std::endl;
	std::cout << "runTime: " << getRunTime() << std::endl;
	std::cout << "priority: " << getPriority() << std::endl;
	std::cout << "state: " << getState() << std::endl;
	std::cout << "attribute: " << getAttribute() << std::endl;
	std::cout << "memorySize: " << getMemorySize() << std::endl;
	std::cout << "startAddress: " << getStartAddress() << std::endl;

	///输出当前前驱信息
	std::cout << "current pioneers: ";
	for (auto pn : pioneers) {
		if (!pn.second) {		//false，未完成
			std::cout << pn.first << "  ";
		}
	}
	std::cout << std::endl;

	//输入后继信息
	std::cout << "successors: ";
	for (auto scs : successors) {
		std::cout << scs << "  ";
	}
	std::cout << std::endl;
}

bool SynchronousPCB::canRun() {
	for (auto pioneer : pioneers) {
		if (pioneer.second == false)return false;
	}
	return true;
}

void SynchronousPCB::updatePioneers(int t_pid) {
	for (auto pioneer : pioneers) {
		if (pioneer.first == t_pid) {
			pioneer.second = true;
			return;
		}
	}
}