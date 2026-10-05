int generateRandom(int min, int max) {
        static bool first = true;
        if (first) {
            srand(static_cast<unsigned>(time(0)));
            first = false;
        }
        return min + rand() % (max - min + 1);
    }