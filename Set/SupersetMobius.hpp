// SupersetMobius.hpp
#pragma once
#include<bits/stdc++.h>

// SupersetMobius
// size(a) = 2 ^ n
// inverse of SupersetZeta
// O(n * 2 ^ n)
std::vector<long long> SupersetMobius(int n, std::vector<long long> a, long long mod = 998244353) {
    for(int i = 0; i < n; ++i) {
        int width = 1 << i;
        for(int l = 0, r = width; l < (1 << n); l += width << 1, r += width << 1) {
            for(int j = l; j < r; ++j) a[j] = (a[j] - a[j + width] + mod) % mod;
        }
    }
    return a;
}