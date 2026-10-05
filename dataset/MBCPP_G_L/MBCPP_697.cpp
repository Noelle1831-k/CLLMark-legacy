int count = 0;
auto isEven = [](int num) { return num % 2 == 0; };
for_each(arrayNums.begin(), arrayNums.end(), [&](int num) {
  if (isEven(num)) ++count;
});
return count;
}