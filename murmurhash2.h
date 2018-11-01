
#ifndef KIME_MURMURHASH2_H
#define KIME_MURMURHASH2_H

typedef unsigned int uint32_t;

uint32_t murmurHash2( const void * key, int len, uint32_t seed );

#endif