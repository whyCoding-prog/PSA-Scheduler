#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include "PCBRegistry.h"

enum class ProcessState {
	READY, RUNNING, BLOCKED, SUSPENDED, FINISHED, RESERVE
  ///就绪    运行     阻塞     挂起       完成     后备   
};

enum class ProcessAttribute {
	Independent, Synchronous        //独立进程，同步进程
};

class PCB
{
public:
	int pid;		//进程号
	int runTime;	//运行时间
	int priority;	//优先级

	ProcessState state;				//进程状态
	ProcessAttribute attribute;		//进程类型

	int memorySize;	//占内存大小
	int startAddress;	//起始地址，为-1时表示不占用内存块

public:
	PCB(int t_pid, int t_runTime, int t_priority,int t_memorySize);
	virtual ~PCB();

	int getPid() const;
	int getRunTime() const;
	int getPriority() const;
	std::string getState() const;
	std::string getAttribute() const;
	int getMemorySize() const;
	int getStartAddress() const;

	void setPid(int i);
	void setRunTime(int t);
	void setPriority(int p);
	void setState(ProcessState s);
	//void setAttribute(ProcessAttribute a);
	void setMemorySize(int m);
	void setStartAddress(int s);

	virtual void showPCB() const = 0;
	virtual bool canRun() = 0;

	void execATimeCycle();
	bool isFinish();

	void toREADY();
	void toRUNNING();
	void toBLOCKED();
	void toSUSPENDED();
	void toFINISHED();
	//void toRESERVE();
};
