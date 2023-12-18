#include <iostream>
#include "sysinfo.hh"


int main()
{
    std::string cpu_name; 
    getMemory();
    int cpu_cores = getCpuCores();
    int cpu_mhz = getCpuMHz();
    cpu_name = getCpuName();
    int uptime = getUptime();
    std::cout << "CPU Name: " << cpu_name << std::endl;
    std::cout << "CPU Cores: " << cpu_cores << std::endl;
    std::cout << "CPU MHz: " << cpu_mhz << std::endl;
    std::cout << "Uptime: " << uptime << std::endl;
    return 0;
}