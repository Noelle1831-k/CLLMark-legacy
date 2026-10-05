function tupleStrInt(teststr) {
    const tupleStr = testStr.match(/\d+/g);
    const strInt = tupleStr.map(item => parseInt(item));

    if (testStr.match(/ *\( */g)) {
        return strInt;
    }

    return strInt.filter(item => !(item === 0 || item === 2));
}
