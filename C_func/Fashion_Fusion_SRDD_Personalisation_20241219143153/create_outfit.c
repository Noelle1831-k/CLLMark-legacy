void create_outfit(FashionFusion *app) {
    printf("Creating a new outfit...\n");
    Outfit outfit;
    init_outfit(&outfit);
    add_to_outfit(&outfit, "Shirt");
    add_to_outfit(&outfit, "Pants");
    display_outfit(&outfit);
}