#include "password_errors.h"

PasswordError::PasswordError(const std::string& message) 
    : std::runtime_error(message) {}

LengthError::LengthError() 
    : PasswordError("Ошибка: Длина пароля должна быть не менее 9 символов") {}

RegisterError::RegisterError() 
    : PasswordError("Ошибка: Пароль должен содержать символы разного регистра") {}

DigitError::DigitError() 
    : PasswordError("Ошибка: Пароль должен содержать хотя бы одну цифру") {}

ForbiddenLetterError::ForbiddenLetterError() 
    : PasswordError("Ошибка: Пароль содержит запрещённые символы (l, I, 1, o, O, 0)") {}