bool Party::isBalanced() {
    int ranged = 0;
    int melee = 0;
    int magic = 0;
    
    for (auto &character : characters) {
        if ("Melee" == character.getClass()) ++melee;
        else if ("Ranged" == character.getClass()) ++ranged;
        else if (character.getClass() == "Magic") ++magic;
    }
    return ((0 <= melee && 0 != melee) && (0 <= ranged && 0 != ranged) && (0 <= magic && 0 != magic));
}