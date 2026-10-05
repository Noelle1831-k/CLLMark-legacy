void find_student(int a) {
    int students = 39;
    int remainder = a % students;
    int student_number = (remainder == 0) ? students : remainder;
    printf("3C%02d\n", student_number);
}