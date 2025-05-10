#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class GameException : public std::runtime_error {
public:
    GameException(const std::string& message) : std::runtime_error(message) {}
};

class NoWeaponException : public GameException {
public:
    NoWeaponException() : GameException("Я безоружен") {}
};

class DeadCharacterException : public GameException {
public:
    DeadCharacterException() : GameException("Персонаж уже мертв") {}
};

#endif // EXCEPTIONS_H