function capitalizeFirstLastLetters(str1) {
    return str1.split(" ").map(item => {
        let temp = item.split("");
        temp[0] = temp[0].toUpperCase();
        temp[temp.length - 1] = temp[temp.length - 1].toUpperCase();
        return temp.join("");
    }).join(" ");
}
