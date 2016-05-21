#include <fstream>
#include <iostream>
#include <string>
#include <cstdint>

const unsigned int n_buckets = 30;

unsigned int hash(const std::string &s)
{
    //return s[0];
    uint32_t hash, i;
    for(hash = i = 0; i < s.size(); ++i)
    {
        hash += s[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

int main()
{
    unsigned int count[n_buckets];
    std::ifstream in("dict-en.txt");
    std::string s;

    for (size_t i = 0; i < n_buckets; i++)
        count[i] = 0;

    while (in >> s)
    {
        count[hash(s) % n_buckets]++;
    }
    for (size_t i = 0; i < n_buckets; i++)
        std::cout << "idx " << i << " count " << count[i] << std::endl;

    return 0;
}
