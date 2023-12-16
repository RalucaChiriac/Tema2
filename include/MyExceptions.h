#ifndef MYEXCEPTIONS_H_INCLUDED
#define MYEXCEPTIONS_H_INCLUDED

#include <stdexcept>

class ExceptieClient : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Exceptie client generica.";
    }
};

// Exceptie pentru client inexistent.
class ExceptieClientInexistent : public ExceptieClient {
public:
    const char* what() const noexcept override {
        return "Client inexistent.";
    }
};


class ExceptieGenerala : public std::exception {
public:
    const char* what() const noexcept override {
        return "Exceptie generala!";
    }
};


class ExceptieNumar : public ExceptieGenerala {
public:
    const char* what() const noexcept override {
        return "Numar nepotrivit! Reincercati!";
    }
};


#endif // MYEXCEPTIONS_H_INCLUDED
