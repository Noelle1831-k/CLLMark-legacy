function listSplit(s, step) {
    return s.reduce((result, v, i) => {
        const target = i % step
        if (!result[target]) result[target] = []
        result[target].push(v)
        return result
    }, [])
}
