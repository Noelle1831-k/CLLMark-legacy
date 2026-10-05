function subjectMarks(subjectmarks) {
    return subjectmarks.sort((a, b) => {
        return a[1] - b[1];
    });
}
