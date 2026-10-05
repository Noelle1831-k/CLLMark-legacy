int checkShapeFit(Shape *shape, Silhouette *silhouette) {
    if (shape->width == silhouette->width && shape->height == silhouette->height) {
        return 1;  
    }
    return 0;  
}