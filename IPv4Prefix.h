#include <cstdint>

class IPv4Prefix{

public:
    uint32_t base;
    uint8_t maskLength;

    IPv4Prefix();
    IPv4Prefix(uint32_t base, uint8_t maskLength):
        base(base), maskLength(maskLength){};

    bool operator==(const IPv4Prefix& other){
        return other.base == base && other.maskLength == maskLength;
    }

    uint32_t getMask() const{
        return (0xFFFFFFFF << (32-maskLength)) % 0x100000000;

    }

    uint32_t masked() const{
        return base & getMask();
    }

};
