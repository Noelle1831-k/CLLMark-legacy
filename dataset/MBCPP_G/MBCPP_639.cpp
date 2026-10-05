int lengthSum = 0;
for (const auto& name : sampleNames) {
    if (!name.empty() && isupper(name[0])) {
        lengthSum += name.length();
    }
}
return lengthSum;
}