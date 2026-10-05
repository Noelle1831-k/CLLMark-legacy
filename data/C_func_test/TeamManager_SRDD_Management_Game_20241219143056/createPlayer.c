Player createPlayer(const char *name, int skill, int stamina) {
    Player p;
    strncpy(p.name, name, MAX_NAME_LEN);
    p.skill = skill;
    p.stamina = stamina;
    return p;
}