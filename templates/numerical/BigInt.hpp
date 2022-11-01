#include <bits/stdc++.h>

typedef std::vector<int> Int;

const int base = 1000 * 1000 * 1000;

void Print(Int a) {
  std::cout << (a.empty() ? 0 : a.back());
  for (int i = (int) a.size() - 2; i >= 0; --i) {
    std::cout << a[i];
  }
}

void Read(Int &a, std::string s) {
  for (int i = (int) s.size(); i > 0; i -= 9) {
    if (i < 9) {
      a.push_back(std::atoi(s.substr(0, i).c_str()));
    } else {
      a.push_back(std::stoi(s.substr(i - 9, 9).c_str()));
    }
  }
}

void TrimZeros(Int& a) {
  while (a.size() > 1 && a.back() == 0) {
    a.pop_back();
  }
}

void Addition(Int& a, const Int& b) {
  int carry = 0;
  for (size_t i = 0; i < std::max(a.size(), b.size()) || carry; ++i) {
    if (i == a.size()) {
      a.push_back(0);
    }
    a[i] += carry + (i < b.size() ? b[i] : 0);
    carry = a[i] >= base;
    if (carry) a[i] -= base;
  }
}

void Subtraction(Int& a, const Int& b) {
  int carry = 0;
  for (size_t i = 0; i < b.size() || carry; ++i) {
    a[i] -= carry + (i < b.size() ? b[i] : 0);
    carry = a[i] < 0;
    if (carry) a[i] += base;
  }
  TrimZeros(a);
}

void MultiplyShort(Int& a, int b) {
  int carry = 0;
  for (size_t i = 0; i < a.size() || carry; ++i) {
    if (i == a.size()) {
      a.push_back(0);
    }
    long long cur = carry + a[i] * 1LL * b;
    a[i] = int(cur % base);
    carry = int(cur / base);
  }
  TrimZeros(a);
}

Int Multiply(const Int& a, const Int& b) {
  Int c (a.size() + b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    for (int j = 0, carry = 0; j < (int) b.size() || carry; ++j) {
      long long cur = c[i + j] + a[i] * 1LL * (j < (int) b.size() ? b[j] : 0) + carry;
      c[i + j] = int(cur % base);
      carry = int(cur / base);
    }
  }
  TrimZeros(c);
  return c;
}

void DivisionShort(Int& a, int b) {
  int carry = 0;
  for (int i = (int) a.size() - 1; i >= 0; --i) {
    long long cur = a[i] + carry * 1LL * base;
    a[i] = int(cur / b);
    carry = int(cur % b);
  }
  TrimZeros(a);
}