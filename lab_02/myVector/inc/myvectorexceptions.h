#ifndef __MY_VECTOR_EXCEPTIONS_H__
#define __MY_VECTOR_EXCEPTIONS_H__

#include <exception>
#include <string>
#include <utility>

class MyVectorException : public std::exception
{
public:
    MyVectorException(const std::string& filename, const std::string& classname,
                      int line, const char *time,
                      const std::string& info = "MyVector unknown error")
    {
        errInfo = "\nFile:  " + filename + "\n"
                  "Class: " + classname + "\n"
                  "Line:  " + std::to_string(line) + "\n"
                  "At:    " + time +
                  "Info:  " + info;
    }

    [[nodiscard]] const char *what() const noexcept override
    {
        return errInfo.c_str();
    }

protected:
    std::string errInfo;
};

class NullPtrException : public MyVectorException
{
public:
    NullPtrException(const std::string& filename, const std::string& classname,
                     int line, const char *time,
                     const std::string& info = "Null pointer argument") :
            MyVectorException(filename, classname,
                              line, time, info) { }

    [[nodiscard]] const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class DataExpired : public MyVectorException
{
public:
    DataExpired(const std::string& filename, const std::string& classname,
                     int line, const char *time,
                     const std::string& info = "Addressed data was already "
                                               "deleted") :
            MyVectorException(filename, classname,
                              line, time, info) { }

    [[nodiscard]] const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class IndexOutOfRange : public MyVectorException
{
public:
    IndexOutOfRange(const std::string& filename, const std::string& classname,
                int line, const char *time,
                const std::string& info = "Index out of range") :
            MyVectorException(filename, classname,
                              line, time, info) { }

    [[nodiscard]] const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class InappropriateDimensions : public MyVectorException
{
public:
    InappropriateDimensions(const std::string& filename,
                    const std::string& classname, int line, const char *time,
                    const std::string& info = "Dimensions are not suitable "
                                              "for these operation") :
            MyVectorException(filename, classname,
                              line, time, info) { }

    [[nodiscard]] const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class BadAllocation : public MyVectorException
{
public:
    BadAllocation(const std::string& filename,
                            const std::string& classname, int line,
                            const char *time, const std::string& info =
                                    "Memory was not allocated") :
            MyVectorException(filename, classname,
                              line, time, info) { }

    [[nodiscard]] const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class WrongDimensions : public MyVectorException
{
public:
    WrongDimensions(const std::string& filename, const std::string& classname,
                    int line, const char *time,
                    const std::string& info = "Dot product requires 3d "
                                              "vectors") :
            MyVectorException(filename, classname,
                              line, time, info) { }

    [[nodiscard]] const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class BadEpsValue : public MyVectorException
{
public:
    BadEpsValue(const std::string& filename, const std::string& classname,
                int line, const char *time,
                const std::string& info = "Epsilon should be positive") :
            MyVectorException(filename, classname,
                              line, time, info) { }

    [[nodiscard]] const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class EmptyVector : public MyVectorException
{
public:
    EmptyVector(const std::string& filename, const std::string& classname,
                int line, const char *time,
                const std::string& info = "Epsilon should be positive") :
            MyVectorException(filename, classname,
                              line, time, info) { }

    [[nodiscard]] const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

#endif // __MY_VECTOR_EXCEPTIONS_H__
