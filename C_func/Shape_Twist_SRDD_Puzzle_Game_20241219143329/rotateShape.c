void rotateShape(Shape *shape) {
    printf("Rotating shape...\n");
    if (shape->type == SQUARE) {
        printf("Square rotated.\n");
    }
    else if (shape->type == TRIANGLE) {
        float temp = shape->width;
        shape->width = shape->height;
        shape->height = temp;
        printf("Triangle rotated. New dimensions: Width %.2f, Height %.2f\n", shape->width, shape->height);
    }
    else if (shape->type == CIRCLE) {
        printf("Circle rotated.\n");
    }
}