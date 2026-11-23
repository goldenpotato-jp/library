// SubsetZeta.hpp
#pragma once
#include<bits/stdc++.h>

// SubsetZeta
// size(a) = 2 ^ n
// return a[i] = sum(a[j]) (i & j = j)
// O(n * 2 ^ n)
std::vector<long long> SubsetZeta(int n, std::vector<long long> a, long long mod = 998244353) {
    for(int i = 0; i < n; ++i) {
        int width = 1 << i;
        for(int l = 0, r = width; l < (1 << n); l += width << 1, r += width << 1) {
            for(int j = l; j < r; ++j) a[j + width] = (a[j + width] + a[j]) % mod;
        }
    }
    return a;
}