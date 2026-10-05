#define HASH_LEN 1024
typedef struct {
    int x, y;
} point_t;
typedef struct _hash_element hash_element_t;
struct _hash_element {
    void *value;
    hash_element_t *next;
};
hash_element_t *_hash[HASH_LEN];
hash_element_t _hashelm[HASH_LEN];
int _hashelm_index;
void hash_init() {
    int i;
    for (i = 0; i < HASH_LEN; i++) {
        _hash[i] = NULL;
    }
    _hashelm_index = 0;
}
hash_element_t *hash_new_element(void *value) {
    hash_element_t *elm = &_hashelm[_hashelm_index++];
    elm->value = value;
    return elm;
}
int hash_star(int x, int y) {
    return (x * 33 + y) & (HASH_LEN - 1);
}
void hash_set_star(point_t *star) {
    int h;
    hash_element_t *elm;
    h = hash_star(star->x, star->y);
    elm = hash_new_element((void*)star);
    elm->next = _hash[h];
    _hash[h] = elm;
}
point_t *hash_get_star(int x, int y) {
    int h;
    hash_element_t *elm;
    point_t *p;
    h = hash_star(x, y);
    elm = _hash[h];
    while (elm != NULL) {
        p = (point_t*)elm->value;
        if (p->x == x && p->y == y) return p;
        elm = elm->next;
    }
    return NULL;
}
point_t target[200], offset[200], stars[1000];
int main(void) {
    int m, n, i, j;
    while (scanf("%d", &m) != EOF && m) {
        hash_init();
        point_t *o, *s;
        for (i = 0; i < m; i++) {
            scanf("%d%d", &(target[i].x), &(target[i].y));
            if (i == 0) {
                o = &target[i];
            }
            else {
                offset[i].x = target[i].x - o->x;
                offset[i].y = target[i].y - o->y;
            }
        }
        scanf("%d\n", &n);
        for (i = 0; i < n; i++) {
            scanf("%d%d", &(stars[i].x), &(stars[i].y));
            hash_set_star(&stars[i]);
        }
        for (i = 0; i < n; i++) {
            s = &stars[i];
            for (j = 1; j < m; j++) {
                if (hash_get_star(s->x + offset[j].x, s->y + offset[j].y) == NULL) break;
            }
            if (j == m) {
                printf("%d %d\n", s->x - o->x, s->y - o->y);
                break;
            }
        }
    }
    return 0;
}