#include <iostream>
#include <string.h>

#define MAX_message 50

class Log_message
{
public:
    char Error[MAX_message];
    char Warning[MAX_message];
    char Info[MAX_message];

public:
    Log_message()
    {
        strcpy(Error, "error");
        strcpy(Warning, "warning");
        strcpy(Info, "info");

        std::cout << "Create message class!" << std::endl;
    }

    ~Log_message()
    {
        std::cout << "Destroy the message" << std::endl;
    }
    void SetMessage(const char *error, const char *warning, const char *info)
    {
        strcpy(Error, error);
        strcpy(Warning, warning);
        strcpy(Info, info);
    }
};

class Log : public Log_message
{
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

private:
    int m_LogLevel = LogLevelInfo;

public:
    void SetLevel(int level)
    {
        m_LogLevel = level;
    }

    void LogError()
    {
        if (m_LogLevel >= LogLevelError)
            std::cout << "[Error]:" << Error << std::endl;
    }
    void LogWarning()
    {
        if (m_LogLevel >= LogLevelWarning)
            std::cout << "[Warning]:" << Warning << std::endl;
    }
    void LogInfo()
    {
        if (m_LogLevel >= LogLevelInfo)
            std::cout << "[Info]:" << Info << std::endl;
    }

    void LogAll()
    {
        LogError();
        LogWarning();
        LogInfo();
    }
};

int main()
{
    Log log;
    log.SetLevel(log.LogLevelInfo);
    log.SetMessage("Segment Fault!!!!!", "Warning should be ignored!", "That is nothing");
    log.LogAll();
    return 0;
}