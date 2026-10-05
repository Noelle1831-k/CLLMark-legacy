int main(void) {
    try {
        Menu menu;
        menu.displayMenu();
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred." << endl;
    }
    return 0;
}