#define MAX_GENRE 10
#define MAX_BOOKS 2000
typedef struct {
    int price;
    int genre;
} Book;
int cmp(const void *a, const void *b) {
    return ((Book *)b)->price - ((Book *)a)->price;
}
int max_purchase_price(int N, int K, Book books[]) {
    int genre_count[MAX_GENRE + 1] = {0};
    int total_price = 0, i;
    qsort(books, N, sizeof(Book), cmp);
    for (i = 0; i < K; i++) {
        books[i].price += genre_count[books[i].genre];
        genre_count[books[i].genre]++;
        total_price += books[i].price;
    }
    return total_price;
}