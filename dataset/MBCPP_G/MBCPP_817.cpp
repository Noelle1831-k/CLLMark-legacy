return nums | views::filter([m, n](int x){ return x % m == 0 || x % n == 0; }) | ranges::to<vector<int>>();
}