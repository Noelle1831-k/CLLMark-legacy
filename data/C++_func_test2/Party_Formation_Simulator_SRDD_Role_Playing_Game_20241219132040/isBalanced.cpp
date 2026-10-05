bool Party::isBalanced() {
    int melee = 0, ranged = 0, magic = 0;
    for (auto &character : characters) {
        if (character.getClass() == "Melee") melee++;
        else if (character.getClass() == "Ranged") ranged++;
        else if (character.getClass() == "Magic") magic++;
    }
    return (melee > 0 && ranged > 0 && magic > 0);
}