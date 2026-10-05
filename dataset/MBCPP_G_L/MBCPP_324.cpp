int sum1 = 0, sum2 = 0;
for (int i = 0; i < testTuple.size(); i++) {
    if (i % 2 == 0) {
        sum1 += testTuple[i];
    } else {
        sum2 += testTuple[i];
    }
}
return {sum1, sum2};
}