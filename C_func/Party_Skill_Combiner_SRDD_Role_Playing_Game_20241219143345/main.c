int main() {
    Party myParty;
    initialize_party(&myParty);
    Character hero;
    initialize_character(&hero, "Hero", 10, 8, 7);
    add_character(&myParty, &hero);
    Character mage;
    initialize_character(&mage, "Mage", 5, 6, 10);
    add_character(&myParty, &mage);
    display_party(&myParty);
    optimize_party(&myParty);
    display_party(&myParty);
    return 0;
}