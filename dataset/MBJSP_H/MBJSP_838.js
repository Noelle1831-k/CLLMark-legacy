function minSwaps(s1, s2) {
    const len1 = s1.length;
    const len2 = s2.length;

    // 1 <= len1 <= len2
    if (len1 <= 0 || len2 <= 0) {
        return 0;
    }

    const s1Array = s1.split('');
    const s2Array = s2.split('');

    for (let i = 0; i < len1; i++) {
        for (let j = 0; j < len2; j++) {
            if (s1Array[i] !== s2Array[j]) {
                return i + j + 1;
            }
        }
    }

    return 0;
}
