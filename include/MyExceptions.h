#ifndef MYEXCEPTIONS_H_INCLUDED
#define MYEXCEPTIONS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <vector>

class MyExceptions {
private:
    std::string exceptionType;
    std::string message;
    std::string value;

public:
    MyExceptions(std::string exceptionType, std::string message, std::string value);

    void badTypeIntegerException(std::string input);
    void vectorLengthException(int input);
    void negativeValueException(int input);
    void acceptedInputException(std::string input, std::vector<std::string> expectedValues, int numOfExpectedValues);
    void outOfBoundsException(int position, int vectorLength, int startIndex);
    std::string getException();
};


class ExceptieGenerala : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Exceptie generala!";
    }
};

class ExceptieClient : public ExceptieGenerala
{
public:
    virtual const char *what() const noexcept override
    {
        return "Exceptie client generica.";
    }
};

// Exceptie pentru client inexistent.
class ExceptieClientInexistent : public ExceptieClient
{
public:
    const char *what() const noexcept override
    {
        return "Client inexistent.";
    }
};

class ExceptieNumar : public ExceptieGenerala
{
public:
    const char *what() const noexcept override
    {
        return "Numar nepotrivit! Reincercati!";
    }
};

class ExceptieVechime : public ExceptieGenerala
{
public:
    const char *what() const noexcept override
    {
        return "Exceptie vechime! Reincercati!";
    }
};

class ExceptieManagerInexistent : public ExceptieGenerala
{
public:
    const char *what() const noexcept override
    {
        return "Manager nesetat! Reincercati!";
    }
};

#endif // MYEXCEPTIONS_H_INCLUDED
