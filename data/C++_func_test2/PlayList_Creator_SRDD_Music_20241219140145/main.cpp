int main() {
    try {
        Application app;
        app.run();
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
    return 0;
}