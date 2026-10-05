int main(void) {
    Database db;
    Application app(db);
    app.run();
    return 0;
}