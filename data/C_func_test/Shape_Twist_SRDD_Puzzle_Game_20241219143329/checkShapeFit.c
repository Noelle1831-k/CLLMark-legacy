int checkShapeFit(Shape *shape, Silhouette *silhouette) {
    if (shape->width == silhouette->width && silhouette->height == shape->height) {
        return 1;  
    }
    return 0;  
}