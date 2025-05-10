#include "password_checker.h"
#include "password_errors.h"
#include <iostream>
#include <cctype>

std::string get_password() {
    std::string password;
    std::cout << "Введите пароль: ";
    std::cin >> password;

    if (password.length() < 9) {
        throw LengthError();
    }

    bool has_upper = false, has_lower = false;
    for (char c : password) {
        if (isupper(c)) has_upper = true;
        if (islower(c)) has_lower = true;
    }
    if (!has_upper || !has_lower) {
        throw RegisterError();
    }

    bool has_digit = false;
    for (char c : password) {
        if (isdigit(c)) {
            has_digit = true;
            break;
        }
    }
    if (!has_digit) {
        throw DigitError();
    }

    const std::string forbidden = "lI1oO0";
    for (char c : password) {
        if (forbidden.find(c) != std::string::npos) {
            throw ForbiddenLetterError();
        }
    }

    return password;
}