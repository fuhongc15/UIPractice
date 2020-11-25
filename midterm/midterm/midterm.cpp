
#include <bitset>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


void error(const std::string& cmd, const std::string& msg) {
    std::cout << "Error: " << msg << std::endl;
    std::cout << " type '" << cmd << " -?' to see usage." << std::endl;

    exit(-1);
}

void numInBase(
    const std::string& dec,
    const std::string& base,
    const std::string& num
) {
    std::cout
        << "Decimal number "
        << dec
        << base
        << num
        << std::endl;
} 
std::string dec2bin(const std::string& dec) {
    std::stringstream bin;

    bin << std::bitset<16>(std::stoi(dec));

    numInBase(dec, " in 16 bits binary: ", bin.str());

    return bin.str();
} 
std::string dec2hex(const std::string& dec) {
    std::stringstream hex;

    hex << "0x" << std::hex << std::stoi(dec);

    numInBase(dec, " in hexadecimal: ", hex.str());

    return hex.str();
} 
std::string dec2oct(const std::string& dec) {
    std::stringstream oct;

    oct << "0" << std::oct << std::stoi(dec);

    numInBase(dec, " in octal: ", oct.str());

    return oct.str();
} 
void numInDec(
    const std::string& base,
    const std::string& num,
    const std::string& dec
) {
    std::cout
        << base
        << " number "
        << num
        << " in decimal: "
        << dec
        << std::endl;
} 
std::string bin2dec(const std::string& bin) {
    std::stringstream dec;

    dec << std::stol(bin, nullptr, 2);

    numInDec("Binary", bin, dec.str());

    return dec.str();
} 
std::string oct2dec(const std::string& oct) {
    std::stringstream dec;

    dec << std::stol(oct, nullptr, 8);

    numInDec("Octal", oct, dec.str());

    return dec.str();
} 
std::string hex2dec(const std::string& hex) {
    std::stringstream dec;

    dec << std::stol(hex, nullptr, 16);

    numInDec("Hexadecimal", hex, dec.str());

    return dec.str();
} 
bool is_number(const std::string& str, int base = 10) {
    size_t sz;

    try {
        std::stol(str, &sz, base);
    }
    catch (const std::invalid_argument& e) {
        ;
    }

    return (sz == str.length());
} 
bool test_dec_bin(const std::string& cmd, const std::string& dec) {
    std::string bin;
    std::string num;

    std::cout << "C:\\" << cmd << " -b " << dec << std::endl;
    bin = dec2bin(dec);

    std::cout << "C:\\" << cmd << " -B " << num << std::endl;
    num = bin2dec(bin);

    std::cout << std::endl;

    return (dec == num);
} 
bool test_dec_hex(const std::string& cmd, const std::string& dec) {
    std::string hex;
    std::string num;

    std::cout << "C:\\" << cmd << " -h " << dec << std::endl;
    hex = dec2hex(dec);

    std::cout << "C:\\" << cmd << " -H " << num << std::endl;
    num = hex2dec(hex);

    std::cout << std::endl;

    return (dec == num);
} 
bool test_dec_oct(const std::string& cmd, const std::string& dec) {
    std::string oct;
    std::string num;

    std::cout << "C:\\" << cmd << " -o " << dec << std::endl;
    oct = dec2oct(dec);

    std::cout << "C:\\" << cmd << " -O " << num << std::endl;
    num = oct2dec(oct);

    std::cout << std::endl;

    return (dec == num);
} 
void sample_usage(const std::string& cmd, const std::string& dec) {
    std::cout << "Examples: " << std::endl << std::endl;

    test_dec_bin(cmd, dec) ? (void)0 : error(cmd, "Dec-Bin converting error!");
    test_dec_hex(cmd, dec) ? (void)0 : error(cmd, "Dec-Hex converting error!");
    test_dec_oct(cmd, dec) ? (void)0 : error(cmd, "Dec-Oct converting error!");
} 
void usage(const std::string& cmd) {
    std::string num;

    std::cout << cmd << " v0.1.0 " << std::endl;
    std::cout << "usage: " << std::endl;
    std::cout << " -H hexadecimal to decimal." << std::endl;
    std::cout << " -h decimal to hexadecimal." << std::endl;
    std::cout << " -O octal to decimal." << std::endl;
    std::cout << " -o decimal to octal." << std::endl;
    std::cout << " -B binary to decimail." << std::endl;
    std::cout << " -b decimal to binary." << std::endl;
    std::cout << " -? print this usage." << std::endl;
    std::cout << " -x some usage samples." << std::endl;
    std::cout << std::endl;

    sample_usage(cmd, "101");
}
void args_dump(int argc, char* argv[]) {
    std::cout << "command line arguments: argv[i]" << std::endl;

    for (int i = 0; i < argc; i++) {
        std::cout
            << std::setfill(' ') << std::setw(3)
            << i << ": "
            << argv[i] << std::endl;
    }
}


int main(int argc, char* argv[], const string& cmd) {

    string type = argv[1];
    if (type == "-b") {
        string num = argv[2];
        dec2bin(num);
    }
    else if (type == "-B") {
        string num = argv[2];
        bin2dec(num);
    }
    else if (type == "-h") {
        string num = argv[2];
        dec2hex(num);
    }
    else if (type == "-H") {
        string num = argv[2];
        hex2dec(num);
    }
    else if (type == "-o") {
        string num = argv[2];
        dec2oct(num);
    }
    else if (type == "-O") {
        string num = argv[2];
        oct2dec(num);
    }
    else if (type == "-x") {
        sample_usage("midterm", "101");
    }
    else if (type == "-?") {
        usage("midterm");
    }
    else {
        error("midterm", "Wrong symbel. Please type again.");
    }
    return 0;
} 
