int loadQuestsFromFile() {
    FILE *file = fopen("quests.dat", "rb");
    if (!file) {
        return 0;
    }
    fread(&questCount, sizeof(int), 1, file);
    fread(quests, sizeof(Quest), questCount, file);
    fclose(file);
    return 1;
}