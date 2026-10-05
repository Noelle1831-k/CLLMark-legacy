function freqCount(list1) {
const freq = {};
for (let i = 0; i < list1.length; i++) {
    const item = list1[i];
    freq[item] = (freq[item] || 0) + 1;
}
return freq;
}
