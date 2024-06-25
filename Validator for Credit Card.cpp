#include <iostream>
#include <string>

// Function to check if the input is a valid credit card number using Luhn algorithm
bool isValidCreditCardNumber(const std::string &cardNumber) {
    int sum = 0;
    bool alternate = false;

    // Start from the rightmost digit and process each digit
    for (int i = cardNumber.length() - 1; i >= 0; --i) {
        int n = cardNumber[i] - '0';

        if (alternate) {
            n *= 2;
            if (n > 9) {
                n -= 9;
            }
        }

        sum += n;
        alternate = !alternate;
    }

    // If the sum is divisible by 10, the number is valid
    return (sum % 10 == 0);
}

int main() {
    std::string cardNumber;
    
    std::cout << "Enter a credit card number: ";
    std::cin >> cardNumber;

    if (isValidCreditCardNumber(cardNumber)) {
        std::cout << "The credit card number is valid." << std::endl;
    } else {
        std::cout << "The credit card number is invalid." << std::endl;
    }

    return 0;
}
