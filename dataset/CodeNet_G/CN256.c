#define GREGORIAN_START_YEAR 2012
#define GREGORIAN_START_MONTH 12
#define GREGORIAN_START_DAY 21
#define MAX_DATASETS 500
#define DAYS_IN_YEAR 365
#define DAYS_IN_LEAP_YEAR 366
typedef struct {
    int baktun;
    int katun;
    int tun;
    int winal;
    int kin;
} MayaDate;
typedef struct {
    int year;
    int month;
    int day;
} GregorianDate;
int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return (year % 400 == 0);
        }
        return 1;
    }
    return 0;
}
int days_in_month(int month, int year) {
    static const int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && is_leap_year(year)) return 29;
    return month_days[month - 1];
}
int date_to_days(GregorianDate date) {
    int days_count = 0;
    for (int year = GREGORIAN_START_YEAR; year < date.year; ++year) {
        days_count += is_leap_year(year) ? DAYS_IN_LEAP_YEAR : DAYS_IN_YEAR;
    }
    for (int month = 1; month < date.month; ++month) {
        days_count += days_in_month(month, date.year);
    }
    days_count += (date.day - GREGORIAN_START_DAY);
    return days_count;
}
GregorianDate days_to_date(int days) {
    GregorianDate date = {GREGORIAN_START_YEAR, GREGORIAN_START_MONTH, GREGORIAN_START_DAY};
    date.day += days;
    while (date.day > days_in_month(date.month, date.year)) {
        date.day -= days_in_month(date.month, date.year);
        date.month++;
        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
    }
    return date;
}
int maya_to_days(MayaDate maya) {
    return maya.baktun * 144000 + maya.katun * 7200 + maya.tun * 360 + maya.winal * 20 + maya.kin;
}
MayaDate days_to_maya(int days) {
    MayaDate maya;
    maya.baktun = days / 144000;
    days %= 144000;
    maya.katun = days / 7200;
    days %= 7200;
    maya.tun = days / 360;
    days %= 360;
    maya.winal = days / 20;
    maya.kin = days % 20;
    return maya;
}
void parse_gregorian(char *input, GregorianDate *date) {
    sscanf(input, "%d.%d.%d", &date->year, &date->month, &date->day);
}
void parse_maya(char *input, MayaDate *maya) {
    sscanf(input, "%d.%d.%d.%d.%d", &maya->baktun, &maya->katun, &maya->tun, &maya->winal, &maya->kin);
}
void print_gregorian(GregorianDate date) {
    printf("%d.%d.%d\n", date.year, date.month, date.day);
}
void print_maya(MayaDate maya) {
    printf("%d.%d.%d.%d.%d\n", maya.baktun, maya.katun, maya.tun, maya.winal, maya.kin);
}
void convert_date(char *input) {
    if (strchr(input, '.') != NULL) {
        if (strchr(input, ':') != NULL) {
            MayaDate maya;
            parse_maya(input, &maya);
            GregorianDate gregorian = days_to_date(maya_to_days(maya));
            print_gregorian(gregorian);
        } else {
            GregorianDate gregorian;
            parse_gregorian(input, &gregorian);
            MayaDate maya = days_to_maya(date_to_days(gregorian));
            print_maya(maya);
        }
    }
}