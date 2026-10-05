function reverseVowels(str1) {
    var arr = str1.split("");
    var vowels = "aeiouAEIOU";
    var i = 0;
    var j = arr.length - 1;
    while (i < j) {
        while (arr[i] && !vowels.includes(arr[i])) {
            i++;
        }
        while (arr[j] && !vowels.includes(arr[j])) {
            j--;
        }
        if (i < j) {
            var temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return arr.join("");
}
