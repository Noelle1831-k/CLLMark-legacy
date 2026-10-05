void add_character_class(Party* party, CharacterClass* cclass) {
    party->members = (CharacterClass*)realloc(party->members, sizeof(CharacterClass) * (party->num_members + 1));
    party->members[party->num_members] = *cclass;
    party->num_members++;
}