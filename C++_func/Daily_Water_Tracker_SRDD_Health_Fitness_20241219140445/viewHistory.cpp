void WaterHistory::viewHistory() {
    printf("\n--- Water Intake History ---\n");
    for (const auto& entry : history) {
        printf("%s: %d ml\n", entry.first.c_str(), entry.second);
    }
}