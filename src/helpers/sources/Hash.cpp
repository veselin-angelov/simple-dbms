//
// Created by vesko on 14.01.23.
//

#include "../headers/Hash.h"
#include <iomanip>
#include <cstring>

Hash::Hash(const std::string& value)
{
    SHA256((const unsigned char *)value.c_str(), value.size(), hash);
}

const unsigned char* Hash::getHash() const
{
    return hash;
}

bool Hash::operator==(const Hash& other) const
{
    if (memcmp(hash, other.hash, SHA256_DIGEST_LENGTH) == 0) return true;
    return false;
}

std::ostream& operator<<(std::ostream& out, const Hash& hash)
{
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        out << std::hex << std::setw(2) << std::setfill('0') << (int)hash.hash[i];
    }

    return out;
}