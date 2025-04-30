#include <iostream>

#include <memory>
#include "PCBFactory.h"
#include "PCBRegistry.h"

int main() {

    try {
        // 获取单例注册表实例
        PCBRegistry& registry = PCBRegistry::getPCBInstance();

        //创建进程
        PCB* syncProcess1 = PCBFactory::createSynchronousPCB(1, 1, 5, 1024, {}, { 2 });
        PCB* syncProcess2 = PCBFactory::createSynchronousPCB(2, 2, 5, 2048, { 1 }, {});
        PCB* indepProcess1 = PCBFactory::createIndependentPCB(3, 3, 4, 512);


        // 打印进程信息
        std::cout << "所有已创建进程信息：" << std::endl;
        for (auto it = registry.begin(); it != registry.end();it++) {
            int pid = it->first;
            if (registry.isExist(pid)) {
                PCB* pcb = registry.getPCB(pid); // 使用findPCB返回原始指针
                if (pcb) {
                    pcb->showPCB();
                    std::cout << "------------------------" << std::endl;
                }
            }
        }

        //尝试运行syncProcess1和indepProcess1
        syncProcess1->execATimeCycle();
        indepProcess1->execATimeCycle();

        // 打印进程信息
        std::cout << "执行一个周期后现存进程信息：" << std::endl;
        for (auto it = registry.begin(); it != registry.end(); it++) {
            int pid = it->first;
            if (registry.isExist(pid)) {
                PCB* pcb = registry.getPCB(pid); // 使用findPCB返回原始指针
                if (pcb) {
                    pcb->showPCB();
                    std::cout << "------------------------" << std::endl;
                }
            }
        }

    }
    catch (const std::exception& e) {
        std::cerr << "错误：" << e.what() << std::endl;
    }

    return 0;
}