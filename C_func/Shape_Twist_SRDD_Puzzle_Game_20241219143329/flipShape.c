void flipShape(Shape *shape) {
    printf("Flipping shape...\n");
    if (shape->type == SQUARE) {
        printf("Square flipped.\n");
    }
    else if (shape->type == TRIANGLE) {
        printf("Triangle flipped.\n");
    }
    else if (shape->type == CIRCLE) {
        printf("Circle flipped.\n");
    }
}