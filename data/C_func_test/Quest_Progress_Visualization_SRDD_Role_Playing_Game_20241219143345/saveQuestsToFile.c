int saveQuestsToFile() {
    FILE *file = fopen("quests.dat", "wb");
    if (!file) {
        return 0;
    }
    fwrite(&questCount, sizeof(int), 1, file);
    fwrite(quests, sizeof(Quest), questCount, file);
    fclose(file);
    return 1;
}