function replaceMaxSpecialchar(text, n) {
    return text.split('').map(item => {
        if (item === ' ' && n > 0) {
            n--;
            return ':';
        } else if (item === ',' && n > 0) {
            n--;
            return ':';
        } else if (item === '.' && n > 0) {
            n--;
            return ':';
        } else {
            return item;
        }
    }).join('');
}
