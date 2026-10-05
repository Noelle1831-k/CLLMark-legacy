int main(int argc, char *argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    Game sniperAssassin;
    sniperAssassin.initialize();
    sniperAssassin.run();
    return 0;
}