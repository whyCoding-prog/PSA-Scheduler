#include "PCB.h"


PCB::PCB(int t_pid, int t_runTime, int t_priority,int t_memorySize) {
    pid = t_pid, runTime = t_runTime, priority = t_priority,memorySize=t_memorySize;
    state = ProcessState::RESERVE;  //默认后备状态
    startAddress = -1;              //未分配地址块
}
PCB::~PCB() {
    //PCBRegistry::getPCBInstance().removePCB(pid);
    //不要手动释放指针会报错
}

/*-----  Getter方法实现  -----*/
int PCB::getPid() const {return pid;}
int PCB::getRunTime() const {return runTime;}
int PCB::getPriority() const {return priority;}
std::string PCB::getState() const {
    switch (state) {
    case ProcessState::READY:
        return "READY";
    case ProcessState::RUNNING:
        return "RUNNING";
    case ProcessState::BLOCKED:
        return "BLOCKED";
    case ProcessState::SUSPENDED:
        return "SUSPENDED";
    case ProcessState::FINISHED:
        return "FINISHED";
    case ProcessState::RESERVE:
        return "RESERVE";
    default:
        throw std::runtime_error("Invalid ProcessState");
    }
    return "";
}
std::string PCB::getAttribute() const {
    switch (attribute) {
    case ProcessAttribute::Independent:
        return "Independent";
    case ProcessAttribute::Synchronous:
        return "Synchronous";
    default:
        throw std::runtime_error("Invalid ProcessAttribute");
    }
}
int PCB::getMemorySize() const {return memorySize;}
int PCB::getStartAddress() const {return startAddress;}

/*-----  Setter方法实现  -----*/
void PCB::setPid(int i) {pid = i;}
void PCB::setRunTime(int t) {runTime = t;}
void PCB::setPriority(int p) {priority = p;}
void PCB::setState(ProcessState s) {state = s;}
//void PCB::setAttribute(ProcessAttribute a) {attribute = a;}
void PCB::setMemorySize(int m) {memorySize = m;}
void PCB::setStartAddress(int site) {startAddress = site;}

void PCB::execATimeCycle() {
    if (runTime == 0 || !canRun()) { return; }
    runTime--;
    priority = priority >= 1 ? priority-1 : 0;  /*不允许优先级小于0*/
    if (runTime == 0)toFINISHED();
}

bool PCB::isFinish() { return runTime == 0; }

void PCB::toREADY() {state = ProcessState::READY;}
void PCB::toRUNNING() {state = ProcessState::RUNNING;}
void PCB::toBLOCKED() {state = ProcessState::BLOCKED;}
void PCB::toSUSPENDED() {state = ProcessState::SUSPENDED;}
void PCB::toFINISHED() {
    state = ProcessState::FINISHED;
    PCBRegistry::getPCBInstance().removePCB(pid);
}