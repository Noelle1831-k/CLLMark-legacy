int sum = 0;
for (double num : list1) {
    sum += round(num);
}
return sum * list1.size();
}