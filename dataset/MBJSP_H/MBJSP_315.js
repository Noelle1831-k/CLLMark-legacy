function findMaxLenEven(str) {
    var words = str.split(" ");
    var count = 0;
    var max = 0;
    var start = 0;
    for (var i = 0; i < words.length; i++) {
        if (words[i].length % 2 == 0) {
            if (words[i].length > count) {
                count = words[i].length;
                max = i;
            }
        }
    }
    if (count == 0) {
        return "-1";
    }
    return words[max];
}
