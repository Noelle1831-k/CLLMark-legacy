string ScaleTrainer::generateRandomScale() {
    int index = rand() % scales.size();
    return scales[index];
}