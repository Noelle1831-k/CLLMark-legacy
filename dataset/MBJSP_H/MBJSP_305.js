function startWithp(words) {
    let result = [];
    for (let i = 0; i < words.length; i++) {
        let word = words[i];
        if(word.toLowerCase().startsWith("p") || word.toLowerCase().startsWith("P")){
            let p = word.split(" ")[0];
            let n = word.split(" ")[1];
            if(p.charAt(0) == n.charAt(0))
                result.push(p, n);
            }
        }
    return result;
}
