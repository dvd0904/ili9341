#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <regex>
#include <ctime>
#include <iostream>
#include <sys/utsname.h>

typedef long long ll;

const auto WM_SYS_HW_DIR {"/sys/class/dmi/id/board_serial"};
const auto WM_SYS_CPU_DIR {"/proc/cpuinfo"};
const auto WM_SYS_MEM_DIR {"/proc/meminfo"};
const auto WM_SYS_UPTIME {"/proc/uptime"};
const auto WM_OS_NAME {"/etc/lsb-release"}; // Ubuntu
// const auto WM_OS_NAME {"/etc/os-release"}; // Debian
const auto UNKNOWN_VALUE { " " };


std::string getSerialNumber();

std::string getCpuName();

int getCpuCores();

int getCpuMHz();

std::vector<ll> getMemory();

std::vector<std::string> getOsInfo();

std::string getTimestamp();

std::string getUptime();