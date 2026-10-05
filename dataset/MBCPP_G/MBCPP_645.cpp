int product = 1;
for (const auto& tuple: testList) {
    product *= tuple[k];
}
return product;
}