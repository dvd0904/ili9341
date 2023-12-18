#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <regex>
#include <iostream>

const auto WM_SYS_HW_DIR {"/sys/class/dmi/id/board_serial"};
const auto WM_SYS_CPU_DIR {"/proc/cpuinfo"};
const auto WM_SYS_MEM_DIR {"/proc/meminfo"};
const auto WM_SYS_UPTIME {"/proc/uptime"};
const auto UNKNOWN_VALUE { " " };


std::string getSerialNumber();

std::string getCpuName();

int getCpuCores();

int getCpuMHz();

void getMemory();

int getUptime();