#include "PCBFactory.h"
/*两个create未实现*/
PCB* PCBFactory:: createIndependentPCB
(int pid,int runTime,int priority,int memorySize) 
{
	auto& registry = PCBRegistry::getPCBInstance();
	auto pcb = std::make_unique<IndependentPCB>(pid, runTime, priority, memorySize);
	PCB* resPCB = pcb.get();
	registry.addPCB(pid,std::move(pcb));	//要将生成的指针所有权传给注册表
	return resPCB;	//返回的是原指针，无所有权，不能delete，仅观察对象
}

/*get() 方法返回 unique_ptr 管理的原始指针（IndependentPCB*）。*/
/*由于 IndependentPCB 是 PCB 的派生类，IndependentPCB* 可以隐式转换为 PCB* （多态性支持）。*/

PCB* PCBFactory::createSynchronousPCB
(int pid, int runTime, int priority, int memorySize, const std::vector<int>& pioneers, const std::vector<int>& successors)
{
	auto& registry = PCBRegistry::getPCBInstance();
	auto pcb = std::make_unique<SynchronousPCB>(pid, runTime, priority, memorySize, pioneers, successors);
	PCB* resPCB = pcb.get();
	registry.addPCB(pid, std::move(pcb));
	return resPCB;
}