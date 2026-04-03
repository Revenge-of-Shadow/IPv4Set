#ifndef IPV4PREFIX
#define IPV4PREFIX

#include "includes.h"

class IPv4Prefix{

public:
    uint32_t base;
    uint8_t maskLength;

    IPv4Prefix():base(0), maskLength(0){};
    IPv4Prefix(uint32_t base, uint8_t maskLength):
        base(base), maskLength(maskLength){};

    //  Comparison with IP
    bool operator==(const uint32_t& ip) const{
        return masked() == (ip & getMask());
    }
    bool operator>(const uint32_t& ip) const{
        return masked() > (ip & getMask());
    }
    bool operator<(const uint32_t& ip) const{
        return masked() < (ip & getMask());
    }


    //  Comparison with IPv4Prefix
    bool operator==(const IPv4Prefix& other) const{
        return other.base == base && other.maskLength == maskLength;
    }

    bool operator>(const IPv4Prefix& other) const{
        return (masked() == other.masked())?
                maskLength > other.maskLength:
                masked() > other.masked();
    }
    bool operator<(const IPv4Prefix& other) const{
        return (masked() == other.masked())?
                maskLength < other.maskLength:
                masked() < other.masked();
    }

    uint32_t getMask() const{
        return (0xFFFFFFFF << (32-maskLength)) % 0x100000000;

    }

    uint32_t masked() const{
        return base & getMask();
    }

};
#endif
