
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <limits>
#include <stdexcept>

namespace {

bool isIntegerString(const std::string& s) {
    // Trim spaces
    size_t start = 0, end = s.size();
    while (start < end && std::isspace(static_cast<unsigned char>(s[start]))) ++start;
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) --end;
    if (start >= end) return false;

    // Optional sign
    size_t i = start;
    if (s[i] == '+' || s[i] == '-') ++i;
    if (i >= end) return false;

    // Must be digits only (no '.' or 'e')
    for (; i < end; ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    }
    return true;
}

long long toInt(const std::string& s) {
    size_t idx = 0;
    long long v = std::stoll(s, &idx);
    if (idx != s.size()) throw std::invalid_argument("Invalid integer: " + s);
    return v;
}

double toDouble(const std::string& s) {
    size_t idx = 0;
    double v = std::stod(s, &idx);
    if (idx != s.size()) throw std::invalid_argument("Invalid number: " + s);
    return v;
}

void printUsage(const char* argv0) {
    std::cout <<
        "Basic Calculator (int & float)\n"
        "Usage:\n"
        "  " << argv0 << " <op> <a> <b>\n"
        // "Where <op> is one of: add | sub | mul | div | mod\n"
        "Where <op> is one of: add | sub | mul | div\n"
        "Notes:\n"
        "  - If both <a> and <b> are integers, operations use integer math.\n"
        "  - If either is floating-point, operations use floating math.\n"
        // "  - 'mod' uses integer '%' for ints, and fmod(a, b) for floats.\n"
        "Examples:\n"
        "  " << argv0 << " add 2 3            -> 5\n"
        "  " << argv0 << " mul 2.5 3          -> 7.5\n"
        "  " << argv0 << " div 7 2            -> 3 (integer division)\n"
        "  " << argv0 << " div 7 2.0          -> 3.5 (floating division)\n";
        // "  " << argv0 << " mod 10 3           -> 1\n"
        // "  " << argv0 << " mod 5.5 2          -> 1.5 (fmod)\n";
}

} // namespace

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printUsage(argv[0]);
        return (argc == 2 && std::string(argv[1]) == "--help") ? 0 : 1;
    }

    const std::string op = argv[1];
    const std::string aStr = argv[2];
    const std::string bStr = argv[3];

    const bool aIsInt = isIntegerString(aStr);
    const bool bIsInt = isIntegerString(bStr);

    try {
        if (aIsInt && bIsInt) {
            // Integer math path
            long long a = toInt(aStr);
            long long b = toInt(bStr);

            if (op == "add") {
                std::cout << (a + b) << "\n";
            } else if (op == "sub") {
                std::cout << (a - b) << "\n";
            } else if (op == "mul") {
                std::cout << (a * b) << "\n";
            } else if (op == "div") {
                if (b == 0) {
                    std::cerr << "Error: Division by zero.\n";
                    return 2;
                }
                std::cout << (a / b) << "\n"; // integer division
            // } else if (op == "mod") {
            //     if (b == 0) {
            //         std::cerr << "Error: Modulus by zero.\n";
            //         return 2;
            //     }
            //     std::cout << (a % b) << "\n";
            } else {
                std::cerr << "Error: Unknown operation '" << op << "'.\n";
                printUsage(argv[0]);
                return 1;
            }
        } else {
            // Floating math path
            double a = toDouble(aStr);
            double b = toDouble(bStr);

            if (op == "add") {
                std::cout << (a + b) << "\n";
            } else if (op == "sub") {
                std::cout << (a - b) << "\n";
            } else if (op == "mul") {
                std::cout << (a * b) << "\n";
            } else if (op == "div") {
                if (b == 0.0) {
                    std::cerr << "Error: Division by zero.\n";
                    return 2;
                }
                std::cout << (a / b) << "\n";
            // } else if (op == "mod") {
            //     if (b == 0.0) {
            //         std::cerr << "Error: Modulus by zero.\n";
            //         return 2;
            //     }
            //     std::cout << std::fmod(a, b) << "\n";
            } else {
                std::cerr << "Error: Unknown operation '" << op << "'.\n";
                printUsage(argv[0]);
                return 1;
            }
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 3;
    }

    return 0;
}
