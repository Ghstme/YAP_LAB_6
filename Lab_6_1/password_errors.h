#ifndef PASSWORD_ERRORS_H
#define PASSWORD_ERRORS_H

#include <stdexcept>
#include <string>

class PasswordError : public std::runtime_error {
public:
    PasswordError(const std::string& message);
};

class LengthError : public PasswordError {
public:
    LengthError();
};

class RegisterError : public PasswordError {
public:
    RegisterError();
};

// Исключение для ошибки отсутствия цифр
class DigitError : public PasswordError {
public:
    DigitError();
};

// Исключение для запрещённых символов
class ForbiddenLetterError : public PasswordError {
public:
    ForbiddenLetterError();
};

#endif // PASSWORD_ERRORS_H