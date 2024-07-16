#include <windows.h>
#include <iostream>

int main() {
    // 预留 1 MB 的虚拟地址空间
    SIZE_T reserveSize = 1024 * 1024; // 1 MB
    void* reservedPtr = VirtualAlloc(NULL, reserveSize, MEM_RESERVE, PAGE_NOACCESS);
    //上面的VirtualAlloc括号里面的第一个参数是null表示要要由系统分配选择分配的地址
    //如果选择非null则就是在指定的地址分配内存
    /*
    NULL (第一个参数)：

由于没有指定具体的地址，因此传入 NULL，表示让系统自动选择一个合适的虚拟地址来分配内存。
这使得内存分配更加灵活，系统会选择一个未使用的地址区域来满足分配请求。
reserveSize (第二个参数)：

指定要保留的虚拟地址空间的大小（例如 1 MB）。
MEM_RESERVE (第三个参数)：

保留指定大小的虚拟地址空间，但不提交物理内存。
PAGE_NOACCESS (第四个参数)：

指定内存保护类型为 PAGE_NOACCESS，表示这块虚拟地址空间不可访问（因为只预留了地址空间，没有实际分配物理内存）
    */
    if (reservedPtr == NULL) {
        std::cerr << "Failed to reserve memory: " << GetLastError() << std::endl;
        return 1;
    }
    std::cout << "Reserved 1 MB of virtual address space at " << reservedPtr << std::endl;

    // 提交 4 KB 的物理内存
    SIZE_T commitSize = 4096; // 4 KB
    void* committedPtr = VirtualAlloc(reservedPtr, commitSize, MEM_COMMIT, PAGE_READWRITE);
    if (committedPtr == NULL) {
        std::cerr << "Failed to commit memory: " << GetLastError() << std::endl;
        // 释放预留的虚拟地址空间
        VirtualFree(reservedPtr, 0, MEM_RELEASE);
        return 1;
    }
    std::cout << "Committed 4 KB of physical memory at " << committedPtr << std::endl;

    // 使用提交的内存
    char* data = static_cast<char*>(committedPtr);
    strcpy(data, "Hello, VirtualAlloc!");
    std::cout << "Written data: " << data << std::endl;

    // 释放提交的内存
    if (VirtualFree(committedPtr, commitSize, MEM_DECOMMIT) == 0) {
        std::cerr << "Failed to decommit memory: " << GetLastError() << std::endl;
    } else {
        std::cout << "Decommitted 4 KB of physical memory" << std::endl;
    }

    // 释放预留的虚拟地址空间
    if (VirtualFree(reservedPtr, 0, MEM_RELEASE) == 0) {
        std::cerr << "Failed to release memory: " << GetLastError() << std::endl;
    } else {
        std::cout << "Released 1 MB of virtual address space" << std::endl;
    }

    return 0;
}
