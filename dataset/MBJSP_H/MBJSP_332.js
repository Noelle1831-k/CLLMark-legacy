function charFrequency(str1) {
    let arr = str1.split('');
    let obj = {};
    arr.forEach((ele) => {
        let key = `"${ele}"`;
        if(obj.hasOwnProperty(key)) {
            obj[key] += 1;
        }
        else {
            obj[key] = 1;
        }
    });
    return obj;
}
