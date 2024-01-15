#include "sysinfo.hh"
#include "os_string.hh"

std::string getSerialNumber()
{
    std::string serial;
    std::fstream file {WM_SYS_HW_DIR, std::ios_base::in};

    if (file.is_open())
    {
        file >> serial;
    }
    else
    {
        serial = UNKNOWN_VALUE;
    }

    return serial;
}

static void parseLineAndFillMap(const std::string& line, const std::string& separator, std::map<std::string, std::string>& systemInfo)
{
    const auto pos{line.find(separator)};

    if (pos != std::string::npos)
    {
        const auto key{Utils::trim(line.substr(0, pos), " \t\"")};
        const auto value{Utils::trim(line.substr(pos + 1), " \t\"")};
        systemInfo[key] = value;
    }
}

static bool getSystemInfo(const std::string& fileName, const std::string& separator, std::map<std::string, std::string>& systemInfo)
{
    std::string info;
    std::fstream file{fileName, std::ios_base::in};
    const bool ret{file.is_open()};

    if (ret)
    {
        std::string line;

        while (file.good())
        {
            std::getline(file, line);
            parseLineAndFillMap(line, separator, systemInfo);
        }
    }

    return ret;
}

std::string getCpuName()
{
    std::string retVal { UNKNOWN_VALUE };
    std::map<std::string, std::string> systemInfo;
    getSystemInfo(WM_SYS_CPU_DIR, ":", systemInfo);
    const auto& it { systemInfo.find("model name") };

    if (it != systemInfo.end())
    {
        retVal = it->second;
    }

    return retVal;

}

int getCpuCores()
{
    int retVal { 0 };
    std::map<std::string, std::string> systemInfo;
    getSystemInfo(WM_SYS_CPU_DIR, ":", systemInfo);
    const auto& it { systemInfo.find("processor") };

    if (it != systemInfo.end())
    {
        retVal = std::stoi(it->second) + 1;
    }

    return retVal;
}

int getCpuMHz()
{
    int retVal { 0 };
    std::map<std::string, std::string> systemInfo;
    getSystemInfo(WM_SYS_CPU_DIR, ":", systemInfo);

    const auto& it { systemInfo.find("cpu MHz") };

    if (it != systemInfo.end())
    {
        retVal = std::stoi(it->second) + 1;
    }

    return retVal;
}

std::vector<ll> getMemory()
{
    std::map<std::string, std::string> systemInfo;
    getSystemInfo(WM_SYS_MEM_DIR, ":", systemInfo);

    std::vector<ll> ret;

    auto memTotal{ 1ull };
    auto memFree{ 0ull };

    const auto& itTotal { systemInfo.find("MemTotal") };

    if (itTotal != systemInfo.end())
    {
        memTotal = std::stoull(itTotal->second);
    }

    const auto& itFree { systemInfo.find("MemFree") };

    if (itFree != systemInfo.end())
    {
        memFree = std::stoull(itFree->second);
    }

    const auto ramTotal { memTotal == 0 ? 1 : memTotal };
    auto ramUsage = 100 - (100 * memFree / ramTotal);

    ret.push_back(ramTotal);
    ret.push_back(memFree);
    ret.push_back(ramUsage);


    std::cout << "ram_total : " << ramTotal << std::endl;
    std::cout << "ram_free  : " << memFree << std::endl;
    std::cout << "ram_usage : " << 100 - (100 * memFree / ramTotal) << std::endl;

    return ret;

}

// std::string getOS


std::vector<std::string> getOsInfo()
{
    struct utsname uts {};
    std::vector<std::string> ret;
    if (uname(&uts) >= 0)
    {
        // ret.push_back(ust.ma)
        // std::cout << uts.sysname  << std::endl;
        std::cout << "Architecture: " << uts.machine  << std::endl; // arch
        std::cout << "kernel Version: " << uts.release  << std::endl; // kernel version
        // std::cout << uts.version  << std::endl;
        // std::cout << uts.nodename  << std::endl;


    }

    std::map<std::string, std::string> systemInfo;
    getSystemInfo(WM_OS_NAME, "=", systemInfo);

    const auto& it { systemInfo.find("PRETTY_NAME") };

    if (it != systemInfo.end())
    {
        std::cout << "OS name: " << it->second << std::endl;
    }
    // std::string os_name = 
    // for(auto x : systemInfo)
    // {
    //     std::cout << x.first << " ----- " << x.second << std::endl;
    // }

    return ret;
}

std::string getTimestamp()
{
    time_t currentTime = time(nullptr);

    struct tm *localTime = localtime(&currentTime);

    int hours = localTime->tm_hour;
    int minutes = localTime->tm_min;
    int seconds = localTime->tm_sec;
    std::string ret = std::to_string(hours) + ":" +
                             (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" +
                             (seconds < 10 ? "0" : "") + std::to_string(seconds);

    return ret;
}

int getUptime() 
{
    std::ifstream uptimeFile(WM_SYS_UPTIME);
    if (!uptimeFile.is_open()) {
        return -1;
    }

    int uptime;
    uptimeFile >> uptime;

    uptimeFile.close();
    return uptime;
}