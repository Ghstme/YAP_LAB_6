#include "password_checker.h"
#include "password_errors.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        std::string password = get_password();
        std::cout << "Пароль принят: " << password << std::endl;
    }
    catch (const LengthError& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const RegisterError& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const DigitError& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const ForbiddenLetterError& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const PasswordError& e) {
        std::cerr << "Неизвестная ошибка пароля: " << e.what() << std::endl;
    }

    return 0;
}