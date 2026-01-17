#include "MyException.h"
#include <sstream>

MyException::MyException(int line, const char* file) noexcept
    :
    line(line),
    file(file)
{
    std::ostringstream oss;
    oss << "[File] " << this->file << '\n'
        << "[Line] " << this->line;
    origin = oss.str();
}

const char* MyException::what() const noexcept
{
    if (whatBuffer.empty())
    {
        std::ostringstream oss;
        oss << GetType() << '\n'
            << origin;
        whatBuffer = oss.str();
    }
    return whatBuffer.c_str();
}

const char* MyException::GetType() const noexcept
{
    return "MyException";
}

int MyException::GetLine() const noexcept
{
    return line;
}

const std::string& MyException::GetFile() const noexcept
{
    return file;
}
