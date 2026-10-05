int main(int argc, char *argv[]) {
    Library library;
    UserInterface ui(library);
    ui.run();
    return 0;
}