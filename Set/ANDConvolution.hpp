// ANDConvolution.hpp
#pragma once
#include<bits/stdc++.h>
#include"SupersetZeta.hpp"
#include"SupersetMobius.hpp"

// ANDConvolution
// depends on SupersetZeta.hpp, SupersetMobius.hpp
// size(a) = size(b) = 2 ^ n
// return c[i] = sum(a[j] * b[k]) (j & k = i)
// O(n * 2 ^ n)
std::vector<long long> ANDConvolution(int n, std::vector<long long> a, std::vector<long long> b, long long mod = 998244353) {
    std::vector<long long> za = SupersetZeta(n, a, mod);
    std::vector<long long> zb = SupersetZeta(n, b, mod);
    std::vector<long long> d(1 << n);
    for(int i = 0; i < (1 << n); ++i) d[i] = za[i] * zb[i] % mod;
    std::vector<long long> c = SupersetMobius(n, d, mod);
    return c;
}