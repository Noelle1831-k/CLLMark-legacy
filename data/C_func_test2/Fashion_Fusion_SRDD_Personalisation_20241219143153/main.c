int main() {
    FashionFusion app;
    init_wardrobe(&app.wardrobe);
    add_item(&app.wardrobe, "Shirt");
    add_item(&app.wardrobe, "Pants");
    add_item(&app.wardrobe, "Shoes");
    run(&app);
    return 0;
}