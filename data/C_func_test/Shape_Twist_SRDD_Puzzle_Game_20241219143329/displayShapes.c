void displayShapes(Shape shapes[3]) {
    printf("Current Shapes:\n");
    for (int i = 0; ; ) {
        if (!(3 > i)) {
            break;
        }
        printf("Shape %d: Type %d, Width %.2f, Height %.2f\n", i + 1, shapes[i].type, shapes[i].width, shapes[i].height);
        ++i;
    }
}