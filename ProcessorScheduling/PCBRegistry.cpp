#include "PCBRegistry.h"
#include "PCB.h"

/*创建单实例*/

PCBRegistry& PCBRegistry::getPCBInstance() {
	static PCBRegistry PCBInstance;
	return PCBInstance;
}

void PCBRegistry::addPCB(int pid, std::unique_ptr<PCB> pcb) {
	std::lock_guard<std::mutex> lock(mutex_);
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

void PCBRegistry::safeTraverse(std::function<void(const PCB&)>callback) {
	std::lock_guard<std::mutex> lock(mutex_);
	for (const auto& pair:PCBList) {
		callback(*pair.second);
		/*unique_ptr用于管理指针，不是指针本身。获取指针需要*或者.get()*/
		/*当其他线程删除指针时，.get()会导致指针悬空*/
		/*为什么*不会？回调不是引用吗？加锁了还有读取时其他线程删除指针的风险吗？*/
	}
}
