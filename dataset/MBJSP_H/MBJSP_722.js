function filterData(students, h, w) {
    var filteredStudents = {};
    for (let student in students) {
        if (students[student][0] > h || students[student][1] > w) {
            filteredStudents[student] = students[student];
        }
    }
    return filteredStudents;
}
