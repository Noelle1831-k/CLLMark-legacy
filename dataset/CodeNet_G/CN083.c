void convert_to_wareki(int year, int month, int day) {
    if (year < 1868 || (year == 1868 && (month < 9 || (month == 9 && day < 8)))) {
        printf("pre-meiji\n");
    } else if (year < 1912 || (year == 1912 && (month < 7 || (month == 7 && day <= 29)))) {
        int meiji_year = year - 1868 + 1;
        printf("meiji %d %d %d\n", meiji_year, month, day);
    } else if (year < 1926 || (year == 1926 && (month < 12 || (month == 12 && day <= 24)))) {
        int taisho_year = year - 1912 + 1;
        printf("taisho %d %d %d\n", taisho_year, month, day);
    } else if (year < 1989 || (year == 1989 && (month < 1 || (month == 1 && day <= 7)))) {
        int showa_year = year - 1926 + 1;
        printf("showa %d %d %d\n", showa_year, month, day);
    } else {
        int heisei_year = year - 1989 + 1;
        printf("heisei %d %d %d\n", heisei_year, month, day);
    }
}