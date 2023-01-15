//
// Created by vesko on 14.01.23.
//

#ifndef DBMS_HASH_H
#define DBMS_HASH_H

#include <openssl/sha.h>
#include <string>

class Hash
{
private:
    unsigned char hash[SHA256_DIGEST_LENGTH];

public:
    Hash(const std::string& value);

public:
    const unsigned char* getHash() const;

public:
    bool operator==(const Hash& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Hash& hash);
};

#endif // DBMS_HASH_H
