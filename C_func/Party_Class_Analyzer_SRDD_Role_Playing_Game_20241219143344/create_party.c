Party *create_party(int num_members) {
    Party *party = (Party *)malloc(sizeof(Party));
    party->num_members = num_members;
    party->members = (Class **)malloc(num_members * sizeof(Class *));
    return party;
}