#ifndef MY_FUNC
#define MY_FUNC

void DoubleSwap(double* const a, double* const b);
void StringSwap(char**  const a, char**  const b);

void string_quick_sort(char **data, int left, int right);

void   clear_input_buff(FILE* const stream);
int is_empty_input_buff(FILE* const stream);

int IsFinite(const double num);
int  IsEqual(const double a, const double b);
int   Signum(const double num);

#endif //My_FUNC
