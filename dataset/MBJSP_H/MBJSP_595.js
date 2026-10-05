function minSwaps(str1, str2) {
    let length1 = str1.length,
        length2 = str2.length;
    if (length1 > length2) {
        let temp = str2,
            temp1 = str1;
        str2 = str1,
        str1 = temp;
        temp = temp1,
        temp1 = str1;
        str2 = temp,
        str1 = temp1;
    }
    for (let i = 0; i < length2; i++) {
        if (str1[i] !== str2[i]) {
            return str2[i] === '1' ? 1 : 'Not Possible';
        }
    }
    return str2[0] === '1' ? 1 : 'Not Possible';
}
