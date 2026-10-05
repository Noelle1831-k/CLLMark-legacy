double sum = accumulate(numbers.begin(), numbers.end(), 0);
return static_cast<double>(sum) / numbers.size();
}