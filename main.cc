#include <iostream>
#include "sysinfo.hh"


int main()
{
    // std::string cpu_name; 
    // getMemory();
    // int cpu_cores = getCpuCores();
    // int cpu_mhz = getCpuMHz();
    // cpu_name = getCpuName();
    // int uptime = getUptime();
    // std::cout << "CPU Name: " << cpu_name << std::endl;
    // std::cout << "CPU Cores: " << cpu_cores << std::endl;
    // std::cout << "CPU MHz: " << cpu_mhz << std::endl;
    // std::cout << "Uptime: " << uptime << std::endl;

    // std::vector<ll> mem = getMemory();

    // for (auto x : mem)
    //     std::cout << x << std::endl;

    // std::string arch = getOsInfo();
    // getOsInfo();
    // std::cout << arch;

    std::string a = getTimestamp();
    std::cout << a;

    return 0;
}