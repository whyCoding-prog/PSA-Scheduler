#pragma once
#include <unordered_map>
#include <memory>	
//std::unique_ptr 需要包含 <memory> 头文件，否则编译器无法识别该类型!!!!!!

class PCB;

class PCBRegistry
{
private:
	std::unordered_map<int,std::unique_ptr<PCB>> PCBList;
	PCBRegistry()=default;		//私有构造函数实现单实例

public:
	/*单实例访问入口*/
	static PCBRegistry& getPCBInstance();

	// 删除拷贝构造和赋值运算符，防止意外复制
	PCBRegistry(const PCBRegistry&) = delete;		
	void operator=(const PCBRegistry&) = delete;

	void addPCB(int pid, std::unique_ptr<PCB> pcb);
	bool isExist(int pid);
	void removePCB(int pid);


	//std::unique_ptr<PCB>& getPCB(int pid);	不能这样写，会暴露指针的使用权
	PCB* getPCB(int pid);	//返回原指针


	// 迭代器
	using const_iterator = std::unordered_map<int, std::unique_ptr<PCB>>::const_iterator;
	const_iterator begin() const { return PCBList.begin(); }
	const_iterator end() const { return PCBList.end(); }
};

