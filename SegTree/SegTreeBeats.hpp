// SegTreeBeats.hpp
#pragma once
#include<bits/stdc++.h>

constexpr long long INF = 2e18;

// SegTreeBeats
// chmin(l, r, x) : a[i] = min(a[i], x) (l <= i < r) O((log N) ^ 2)
// chmax(l, r, x) : a[i] = max(a[i], x) (l <= i < r) O((log N) ^ 2)
// add(l, r, x) : a[i] = a[i] + x (l <= i < r) O((log N) ^ 2)
// get_min(l, r) : return min(a[i]) (l <= i < r) O((log N) ^ 2)
// get_max(l, r) : return max(a[i]) (l <= i < r) O((log N) ^ 2)
// get_sum(l, r) : return sum(a[i]) (l <= i < r) O((log N) ^ 2)
// operator[i] : return a[i] O(log N)
// print() : print a[i] (0 <= i < N) O(N * log N)
struct SegTreeBeats {
    int N, n = 1;
    std::vector<long long> max1, max2, min1, min2, sum, max_count, min_count, lazy;
    SegTreeBeats(const std::vector<long long>& v) : N(v.size()) {
        while(n < N) n <<= 1;
        max1.resize(n << 1, -INF);
        max2.assign(n << 1, -INF);
        min1.resize(n << 1, INF);
        min2.assign(n << 1, INF);
        sum.resize(n << 1);
        max_count.resize(n << 1);
        min_count.resize(n << 1);
        lazy.resize(n << 1);
        for(int i = 0; i < N; ++i) {
            max1[i + n] = min1[i + n] = sum[i + n] = v[i];
            max_count[i + n] = min_count[i + n] = 1;
        }
        for(int i = n - 1; i > 0; --i) update(i);
    }
    void apply_add(int i, int64_t x, int64_t len) {
        if(max1[i] != -INF) max1[i] += x;
        if(max2[i] != -INF) max2[i] += x;
        if(min1[i] != INF) min1[i] += x;
        if(min2[i] != INF) min2[i] += x;
        sum[i] += x * len;
        lazy[i] += x;
    }
    void update_max(int i, long long x) {
        sum[i] += (x - max1[i]) * max_count[i];
        if(min1[i] == max1[i]) min1[i] = x;
        else if(min2[i] == max1[i]) min2[i] = x;
        max1[i] = x;
    }
    void update_min(int i, long long x) {
        sum[i] += (x - min1[i]) * min_count[i];
        if(max1[i] == min1[i]) max1[i] = x;
        else if(max2[i] == min1[i]) max2[i] = x;
        min1[i] = x;
    }
    void push(int i, int l, int r) {
        int li = i << 1;
        int ri = i << 1 | 1;
        int mid = (l + r) >> 1;
        if(lazy[i] != 0) {
            apply_add(li, lazy[i], mid - l);
            apply_add(ri, lazy[i], r - mid);
            lazy[i] = 0;
        }
        if(max1[i] < max1[li]) update_max(li, max1[i]);
        if(max1[i] < max1[ri]) update_max(ri, max1[i]);
        if(min1[i] > min1[li]) update_min(li, min1[i]);
        if(min1[i] > min1[ri]) update_min(ri, min1[i]);
    }
    void update(int i) {
        int l = i << 1;
        int r = i << 1 | 1;
        sum[i] = sum[l] + sum[r];
        if(max1[l] < max1[r]){
            max1[i] = max1[r];
            max2[i] = std::max(max1[l], max2[r]);
            max_count[i] = max_count[r];
        } else if(max1[l] > max1[r]) {
            max1[i] = max1[l];
            max2[i] = std::max(max2[l], max1[r]);
            max_count[i] = max_count[l];
        } else {
            max1[i] = max1[l];
            max2[i] = std::max(max2[l], max2[r]);
            max_count[i] = max_count[l] + max_count[r];
        }
        if(min1[l] < min1[r]) {
            min1[i] = min1[l];
            min2[i] = std::min(min2[l], min1[r]);
            min_count[i] = min_count[l];
        } else if(min1[l] > min1[r]) {
            min1[i] = min1[r];
            min2[i] = std::min(min1[l], min2[r]);
            min_count[i] = min_count[r];
        } else {
            min1[i] = min1[l];
            min2[i] = std::min(min2[l], min2[r]);
            min_count[i] = min_count[l] + min_count[r];
        }
    }
    void chmin(long long x, int ql, int qr, int i, int l, int r) {
        if(qr <= l || r <= ql || max1[i] <= x) return;
        if(ql <= l && r <= qr && max2[i] < x) {
            update_max(i, x);
            return;
        }
        push(i, l, r);
        int li = i << 1;
        int ri = i << 1 | 1;
        int mid = (l + r) >> 1;
        chmin(x, ql, qr, li, l, mid);
        chmin(x, ql, qr, ri, mid, r);
        update(i);
    }
    void chmin(int l, int r, long long x) {
        chmin(x, l, r, 1, 0, n);
    }
    void chmax(long long x, int ql, int qr, int i, int l, int r) {
        if(qr <= l || r <= ql || min1[i] >= x) return;
        if(ql <= l && r <= qr && min2[i] > x) {
            update_min(i, x);
            return;
        }
        push(i, l, r);
        int li = i << 1;
        int ri = i << 1 | 1;
        int mid = (l + r) >> 1;
        chmax(x, ql, qr, li, l, mid);
        chmax(x, ql, qr, ri, mid, r);
        update(i);
    }
    void chmax(int l, int r, long long x) {
        chmax(x, l, r, 1, 0, n);
    }
    void add(long long x, int ql, int qr, int i, int l, int r) {
        if(qr <= l || r <= ql) return;
        if(ql <= l && r <= qr) {
            apply_add(i, x, r - l);
            return;
        }
        push(i, l, r);
        int mid = (l + r) >> 1;
        add(x, ql, qr, i << 1, l, mid);
        add(x, ql, qr, i << 1 | 1, mid, r);
        update(i);
    }
    void add(int l, int r, long long x) {
        add(x, l, r, 1, 0, n);
    }
    long long get_max(int ql, int qr, int i, int l, int r) {
        if(qr <= l || r <= ql) return -INF;
        if(ql <= l && r <= qr) return max1[i];
        push(i, l, r);
        int li = i << 1;
        int ri = i << 1 | 1;
        int mid = (l + r) >> 1;
        long long lv = get_max(ql, qr, li, l, mid);
        long long rv = get_max(ql, qr, ri, mid, r);
        return std::max(lv, rv);
    }
    long long get_max(int l, int r) {
        return get_max(l, r, 1, 0, n);
    }
    long long get_min(int ql, int qr, int i, int l, int r) {
        if(qr <= l || r <= ql) return INF;
        if(ql <= l && r <= qr) return min1[i];
        push(i, l, r);
        int li = i << 1;
        int ri = i << 1 | 1;
        int mid = (l + r) >> 1;
        long long lv = get_min(ql, qr, li, l, mid);
        long long rv = get_min(ql, qr, ri, mid, r);
        return std::min(lv, rv);
    }
    long long get_min(int l, int r) {
        return get_min(l, r, 1, 0, n);
    }
    long long get_sum(int ql, int qr, int i, int l, int r) {
        if(qr <= l || r <= ql) return 0;
        if(ql <= l && r <= qr) return sum[i];
        push(i, l, r);
        int li = i << 1;
        int ri = i << 1 | 1;
        int mid = (l + r) >> 1;
        long long lv = get_sum(ql, qr, li, l, mid);
        long long rv = get_sum(ql, qr, ri, mid, r);
        return lv + rv;
    }
    long long get_sum(int l, int r) {
        return get_sum(l, r, 1, 0, n);
    }
    long long get_element(int qi, int i, int l, int r) {
        if(r - l == 1) return sum[i];
        push(i, l, r);
        int mid = (l + r) >> 1;
        if(qi < mid) {
            int li = i << 1;
            return get_element(qi, li, l, mid);
        } else {
            int ri = i << 1 | 1;
            return get_element(qi, ri, mid, r);
        }
    }
    long long operator[](int i) {
        return get_element(i, 1, 0, n);
    }
    void print() {
        for(int i = 0; i < N; ++i) std::cerr << (*this)[i] << ' ';
        std::cerr << '\n';
    }
};