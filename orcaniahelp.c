#include <orcania.h>

struct _pointer_list* pointer_list_clone(struct _pointer_list* p)
{
    struct _pointer_list * p2 = o_malloc(sizeof(struct _pointer_list));
    pointer_list_init(p2);
    for(int i=0; i<pointer_list_size(p); i++)
    {
	pointer_list_append(p2, pointer_list_get_at(p, i));
    }

    return p2;
}
