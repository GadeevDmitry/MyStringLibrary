#ifndef STRING_SOLVER
#define STRING_SOLVER

struct text GetData(const char *name);

char *read_file(const char *name, int* const TextSize);

int get_file_size(const char *name);

void SorterMain();
void fill_pointer_array(char *Text, const int TextSize, struct word *Arr);

void ArrOutput(struct word *Arr, FILE *stream);
void TextOutput(char *Text, int TextSize, FILE* const stream);

#endif //STRING_SOLVER
