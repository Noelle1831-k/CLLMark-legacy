function getLcm(l) {
    const GCD = (a, b) => {
        if (b === 0) {
            return a;
        } else {
            return GCD(b, a % b);
        }
    }

    let lcm = l[0];

    for (let i = 1; i < l.length; i++) {
        lcm = lcm * l[i] / GCD(lcm, l[i]);
    }

    return lcm;
}
