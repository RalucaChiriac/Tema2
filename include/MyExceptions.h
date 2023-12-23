#ifndef MYEXCEPTIONS_H_INCLUDED
#define MYEXCEPTIONS_H_INCLUDED

#include <stdexcept>


class ExceptieGenerala : public std::exception {
public:
    const char* what() const noexcept override {
        return "Exceptie generala!";
    }
};


class ExceptieClient : public ExceptieGenerala {
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


class ExceptieNumar : public ExceptieGenerala {
public:
    const char* what() const noexcept override {
        return "Numar nepotrivit! Reincercati!";
    }
};

class ExceptieVechime : public ExceptieGenerala {
public:
    const char* what() const noexcept override {
        return "Exceptie vechime! Reincercati!";
    }
};

class ExceptieManagerInexistent : public ExceptieGenerala {
public:
    const char* what() const noexcept override {
        return "Manager nesetat! Reincercati!";
    }
};

#endif // MYEXCEPTIONS_H_INCLUDED
