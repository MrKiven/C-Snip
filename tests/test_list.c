#include <assert.h>
#include "list.h"

void case_list_push()
{
    struct List *list = create_list();
    char *s1 = "s1", *s2 = "s2";
    assert(push(list, s1) == "s1")
}
