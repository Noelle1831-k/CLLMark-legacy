int checkShapeFit(Shape *shape, Silhouette *silhouette) {
    if (! (silhouette->width != shape->width) && ! (shape->height != silhouette->height)) {
        return 1;  
    }
    return 0;  
}