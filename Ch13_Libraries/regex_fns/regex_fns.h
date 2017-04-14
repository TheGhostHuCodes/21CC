typedef struct {
    const char* string;
    const char* regex;
    char*** substrings;
    _Bool use_case;
} regex_fn_s;

#define regex_match(...) regex_match_base((regex_fn_s){__VA_ARGS__})

int regex_match_base(regex_fn_s in);
char* search_and_replace(const char* base, const char* search,
                         const char* replace);
