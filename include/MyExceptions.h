#ifndef MYEXCEPTIONS_H_INCLUDED
#define MYEXCEPTIONS_H_INCLUDED

#include <stdexcept>

class PretInvalidException : public std::runtime_error {
public:
    PretInvalidException() : std::runtime_error("Pretul abonamentului nu poate fi negativ.") {}
};

class AbonamentNullException : public std::logic_error {
public:
    AbonamentNullException() : std::logic_error("Abonamentul nu poate fi null.") {}
};

#endif // MYEXCEPTIONS_H_INCLUDED
