#ifndef MY_FUNC
#define MY_FUNC

void MySwap(void *a, void *b, const size_t len);

void QuickSort(void *data, int len, int left, int right, int (*cmp)(void *, void *));

void   clear_input_buff(FILE* const stream);
int is_empty_input_buff(FILE* const stream);

void *GetPtr(void *BeginArray, const int index, const int len);

int                    DigitCmp(void *a_ptr, void *b_ptr);
int      only_letter_string_cmp(void *a_ptr, void *b_ptr);
int back_only_letter_string_cmp(void *a_ptr, void *b_ptr);

int at_least_one_letter(const char *s);

int replace(const char was, const char will, char *start, int n);

int IsFinite(const double num);
int  IsEqual(const double a, const double b);
int   Signum(const double num);

#endif //My_FUNC
