#include "solution.h"

int
main()
{
#define test(a, b)                   \
        char *res = toGoatLatin(a);  \
        printf("res: '%s'\n", res);  \
        assert(strcmp(b, res) == 0); \
        free(res);

        test("I speak Goat Latin", "Imaa peaksmaaa oatGmaaaa atinLmaaaaa");
}
