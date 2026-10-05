function groupTuples(input) {
    return input.reduce((acc, tuple) => {
        const index = acc.findIndex(item => item[0] === tuple[0]);
        if (index === -1) {
            acc.push([tuple[0], tuple[1]]);
        } else {
            acc[index].push(tuple[1]);
        }
        return acc;
    }, []);
}
