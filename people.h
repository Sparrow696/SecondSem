typedef struct PEOPLE PEOPLE;

typedef struct {
    PEOPLE* array;
    int size;
} ARRAYPEOPLE;

ARRAYPEOPLE createArray(int size_);
void freeArray(ARRAYPEOPLE* dt_);

void add(ARRAYPEOPLE* dt_);
void printAll(const ARRAYPEOPLE* dt_);

void del(ARRAYPEOPLE* dt_, int id_);
int searchBySurname(const ARRAYPEOPLE* dt_, const char* surname);
void sortPeopleBySurname(ARRAYPEOPLE* dt_);
void change(ARRAYPEOPLE* dt_, int id_);
