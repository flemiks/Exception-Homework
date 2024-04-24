#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class DivisionByZeroException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Division by zero error";
    }
};

class NegativeSqrtException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Square root of negative number";
    }
};

class MemoryException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Out of memory";
    }
};

class FileNotFoundException : public std::exception {
private:
    std::string message;
public:
    FileNotFoundException(const std::string& filename) {
        message = "File not found: " + filename;
    }
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class FileAccessException : public std::exception {
private:
    std::string message;
public:
    FileAccessException(const std::string& filename) {
        message = "Access denied to file: " + filename;
    }
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif 