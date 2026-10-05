void annotateText() {
    if (annotationCount >= MAX_ANNOTATIONS) {
        printf("Annotation limit reached.\n");
        return;
    }
    printf("Enter annotation: ");
    scanf(" %[^\n]%*c", annotations[annotationCount].note);
    printf("Annotation added: %s\n", annotations[annotationCount].note);
    annotationCount++;
}