// ORConvolution.hpp
#pragma once
#include<bits/stdc++.h>
#include"SubsetZeta.hpp"
#include"SubsetMobius.hpp"

// ORConvolution
// depends on SubsetZeta.hpp, SubsetMobius.hpp
// size(a) = size(b) = 2 ^ n
// return c[i] = sum(a[j] * b[k]) (j | k = i)
// O(n * 2 ^ n)
std::vector<long long> ORConvolution(int n, std::vector<long long> a, std::vector<long long> b, long long mod = 998244353) {
    std::vector<long long> za = SubsetZeta(n, a, mod);
    std::vector<long long> zb = SubsetZeta(n, b, mod);
    std::vector<long long> d(1 << n);
    for(int i = 0; i < (1 << n); ++i) d[i] = za[i] * zb[i] % mod;
    std::vector<long long> c = SubsetMobius(n, d, mod);
    return c;
}