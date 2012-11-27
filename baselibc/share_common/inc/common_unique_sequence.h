#ifndef _COMMON_UNIQUE_SEQUENCE_H_
#define _COMMON_UNIQUE_SEQUENCE_H_

#include "common_types.h"


class unique_sequence64
{
public:
    static unique_sequence64* Instance()
    {
        static unique_sequence64 __uin64s;
        return &__uin64s;
    }

public:
    unique_sequence64() : m_sequence_(0) { }

    inline uint64_t sequence() { return ++m_sequence_; }

private:
    uint64_t m_sequence_;
};


class unique_sequence
{
public:
    static unique_sequence* Instance()
    {
        static unique_sequence __uin32s;
        return &__uin32s;
    }

public:
    unique_sequence() : m_sequence_(0) { }

    inline uint32_t sequence() { return ++m_sequence_; }

private:
    uint32_t m_sequence_;
};


#endif // _COMMON_UNIQUE_SEQUENCE_H_
