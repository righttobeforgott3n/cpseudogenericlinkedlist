#ifndef PSEUDO_GENERIC_LINKED_LIST_H
#define PSEUDO_GENERIC_LINKED_LIST_H

#include <stddef.h>

//
#define PSG_LINKED_LIST_STRUCTURE_NAME(user_type) \
    struct psg_##user_type##_linked_list_t

//
#define PSG_LINKED_LIST_OPAQUE_NAME(user_type) \
    psg_##user_type##_linked_list

//
#define PSG_LINKED_LIST_TYPEDEF(user_type) \
    typedef PSG_LINKED_LIST_STRUCTURE_NAME(user_type) * PSG_LINKED_LIST_OPAQUE_NAME(user_type);

//
#define PSG_LINKED_LIST_NEW_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_new

//
#define PSG_LINKED_LIST_NEW_FUNCTION_PROTOTYPE(user_type, item_type) \
    PSG_LINKED_LIST_OPAQUE_NAME(user_type)                           \
    PSG_LINKED_LIST_NEW_FUNCTION_NAME(user_type)(void)

//
#define PSG_LINKED_LIST_FREE_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_free

//
#define PSG_LINKED_LIST_FREE_FUNCTION_PROTOTYPE(user_type, item_type) \
    void PSG_LINKED_LIST_FREE_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_OPAQUE_NAME(user_type) self)

//
#define PSG_LINKED_LIST_GET_SIZE_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_get_size

//
#define PSG_LINKED_LIST_GET_SIZE_FUNCTION_PROTO(user_type, item_type) \
    size_t PSG_LINKED_LIST_GET_SIZE_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_OPAQUE_NAME(user_type) self)

//
#define PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_push_first

//
#define PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_PROTO(user_type, item_type) \
    void PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_OPAQUE_NAME(user_type) self, item_type item)

//
#define PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_pop_last

//
#define PSG_LINKED_LIST_POP_LAST_FUNCTION_PROTO(user_type, item_type) \
    item_type PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_OPAQUE_NAME(user_type) self)

//
#define PSG_LINKED_LIST_ITERATOR_STRUCTURE_NAME(user_type) \
    struct psg_##user_type##_linked_list_iterator_t

//
#define PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(user_type) \
    psg_##user_type##_linked_list_iterator

//
#define PSG_LINKED_LIST_ITERATOR_TYPEDEF(user_type) \
    typedef PSG_LINKED_LIST_ITERATOR_STRUCTURE_NAME(user_type) * PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(user_type);

//
#define PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_iterator_new

//
#define PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_PROTO(user_type) \
    PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(user_type)            \
    PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_OPAQUE_NAME(user_type) iterable)

//
#define PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_iterator_free

//
#define PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION_PROTO(user_type) \
    void PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(user_type) self)

//
#define PSG_LINKED_LIST_ITERATOR_IS_FIRST_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_iterator_is_first

//
#define PSG_LINKED_LIST_ITERATOR_IS_FIRST_FUNCTION_PROTO(user_type) \
    int PSG_LINKED_LIST_ITERATOR_IS_FIRST_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(user_type) self)

//
#define PSG_LINKED_LIST_ITERATOR_IS_EQUAL_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_iterator_is_equal

//
#define PSG_LINKED_LIST_ITERATOR_IS_EQUAL_FUNCTION_PROTO(user_type) \
    int PSG_LINKED_LIST_ITERATOR_IS_EQUAL_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(user_type) self, PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(user_type) to_compare)

//
#define PSG_LINKED_LIST_ITERATOR_IS_LAST_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_iterator_is_last

//
#define PSG_LINKED_LIST_ITERATOR_IS_LAST_FUNCTION_PROTO(user_type) \
    int PSG_LINKED_LIST_ITERATOR_IS_LAST_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(user_type) self)

//
#define PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_iterator_next

//
#define PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_PROTO(user_type) \
    void PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(user_type) self)

//
#define PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_iterator_prev

//
#define PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_PROTO(user_type) \
    void PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(user_type) self)

//
#define PSG_LINKED_LIST_ITERATOR_GET_ITEM_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_iterator_get_item

//
#define PSG_LINKED_LIST_ITERATOR_GET_ITEM_FUNCTION_PROTO(user_type, item_type) \
    item_type PSG_LINKED_LIST_ITERATOR_GET_ITEM_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(user_type) self)

//
#define PSG_LINKED_LIST_ITERATOR_SET_ITEM_FUNCTION_NAME(user_type) \
    psg_##user_type##_linked_list_iterator_set_item

//
#define PSG_LINKED_LIST_ITERATOR_SET_ITEM_FUNCTION_PROTO(user_type, item_type) \
    void PSG_LINKED_LIST_ITERATOR_SET_ITEM_FUNCTION_NAME(user_type)(PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(user_type) self, item_type item)

#define PSG_LINKED_LIST_DECLARATION_MOD(user_type, item_type)               \
    PSG_LINKED_LIST_TYPEDEF(user_type)                                      \
    PSG_LINKED_LIST_NEW_FUNCTION_PROTOTYPE(user_type, item_type);           \
    PSG_LINKED_LIST_FREE_FUNCTION_PROTOTYPE(user_type, item_type);          \
    PSG_LINKED_LIST_GET_SIZE_FUNCTION_PROTO(user_type, item_type);          \
    PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_PROTO(user_type, item_type);        \
    PSG_LINKED_LIST_POP_LAST_FUNCTION_PROTO(user_type, item_type);          \
    PSG_LINKED_LIST_ITERATOR_TYPEDEF(user_type)                             \
    PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_PROTO(user_type);                 \
    PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION_PROTO(user_type);                \
    PSG_LINKED_LIST_ITERATOR_IS_EQUAL_FUNCTION_PROTO(user_type);            \
    PSG_LINKED_LIST_ITERATOR_IS_FIRST_FUNCTION_PROTO(user_type);            \
    PSG_LINKED_LIST_ITERATOR_IS_LAST_FUNCTION_PROTO(user_type);             \
    PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_PROTO(user_type);                \
    PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_PROTO(user_type);                \
    PSG_LINKED_LIST_ITERATOR_GET_ITEM_FUNCTION_PROTO(user_type, item_type); \
    PSG_LINKED_LIST_ITERATOR_SET_ITEM_FUNCTION_PROTO(user_type, item_type);

#endif
