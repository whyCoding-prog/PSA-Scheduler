#include "PCBRegistry.h"
#include "PCB.h"

/*创建单实例*/

PCBRegistry& PCBRegistry::getPCBInstance() {
	static PCBRegistry PCBInstance;
	return PCBInstance;
}

void PCBRegistry::addPCB(int pid, std::unique_ptr<PCB> pcb) {
	if (isExist(pid)) {
		throw std::runtime_error("PID已存在！");
	}
	PCBList[pid] = std::move(pcb);		///转移所有权！！！！！
}

bool PCBRegistry::isExist(int pid) {
	return PCBList.find(pid) != PCBList.end();
}

void PCBRegistry::removePCB(int pid) {
	PCBList.erase(pid);
}

PCB* PCBRegistry::getPCB(int pid) {
    auto it = PCBList.find(pid);
    return (it != PCBList.end()) ? it->second.get() : nullptr;
}
