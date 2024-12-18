#include "pseudo_generic_linked_list_declaration.h"
#include <stdlib.h>

//
#define PSG_NODE_STRUCTURE_NAME(user_type) \
    struct psg_##user_type##_node_t

//
#define PSG_NODE_STRUCTURE(user_type, item_type)          \
    PSG_NODE_STRUCTURE_NAME(user_type)                    \
    {                                                     \
        item_type item;                                   \
        PSG_NODE_STRUCTURE_NAME(user_type) * prev, *next; \
    }

//
#define PSG_NODE_NEW_FUNCTION_NAME(user_type) \
    psg_##user_type##_node_new

//
#define PSG_NODE_NEW_FUNCTION(user_type, item_type)                                                                                                                                  \
    PSG_NODE_STRUCTURE_NAME(user_type) * PSG_NODE_NEW_FUNCTION_NAME(user_type)(item_type item, PSG_NODE_STRUCTURE_NAME(user_type) * prev, PSG_NODE_STRUCTURE_NAME(user_type) * next) \
    {                                                                                                                                                                                \
        PSG_NODE_STRUCTURE_NAME(user_type) *self = (PSG_NODE_STRUCTURE_NAME(user_type) *)malloc(sizeof(PSG_NODE_STRUCTURE_NAME(user_type)));                                         \
        if (self)                                                                                                                                                                    \
        {                                                                                                                                                                            \
            self->item = item;                                                                                                                                                       \
            self->prev = prev;                                                                                                                                                       \
            self->next = next;                                                                                                                                                       \
        }                                                                                                                                                                            \
        return self;                                                                                                                                                                 \
    }

//
#define PSG_NODE_FREE_FUNCTION_NAME(user_type) \
    psg_##user_type##_node_free

//
#define PSG_NODE_FREE_FUNCTION(user_type, item_type)                                       \
    void PSG_NODE_FREE_FUNCTION_NAME(user_type)(PSG_NODE_STRUCTURE_NAME(user_type) * self) \
    {                                                                                      \
        if (self)                                                                          \
        {                                                                                  \
            free(self);                                                                    \
        }                                                                                  \
    }

//
#define PSG_LINKED_LIST_STRUCTURE(user_type, item_type)    \
    PSG_LINKED_LIST_STRUCTURE_NAME(user_type)              \
    {                                                      \
        PSG_NODE_STRUCTURE_NAME(user_type) * first, *last; \
        size_t size;                                       \
    }

//
#define PSG_LINKED_LIST_NEW_FUNCTION(user_type, item_type)                                                                                                        \
    PSG_LINKED_LIST_NEW_FUNCTION_PROTOTYPE(user_type, item_type)                                                                                                  \
    {                                                                                                                                                             \
        PSG_LINKED_LIST_STRUCTURE_NAME(user_type) *self = (PSG_LINKED_LIST_STRUCTURE_NAME(user_type) *)malloc(sizeof(PSG_LINKED_LIST_STRUCTURE_NAME(user_type))); \
        if (self)                                                                                                                                                 \
        {                                                                                                                                                         \
            self->first = PSG_NODE_NEW_FUNCTION_NAME(user_type)(0, 0, 0);                                                                                         \
            self->last = PSG_NODE_NEW_FUNCTION_NAME(user_type)(0, 0, 0);                                                                                          \
            self->first->next = self->last;                                                                                                                       \
            self->last->prev = self->first;                                                                                                                       \
            self->size = 0;                                                                                                                                       \
        }                                                                                                                                                         \
        return self;                                                                                                                                              \
    }

//
#define PSG_LINKED_LIST_FREE_FUNCTION(user_type, item_type)               \
    PSG_LINKED_LIST_FREE_FUNCTION_PROTOTYPE(user_type, item_type)         \
    {                                                                     \
        if (self)                                                         \
        {                                                                 \
            PSG_NODE_STRUCTURE_NAME(user_type) *node = self->first->next; \
            PSG_NODE_STRUCTURE_NAME(user_type) *tmp = 0;                  \
            while (node && node != self->last)                            \
            {                                                             \
                tmp = node;                                               \
                node = node->next;                                        \
                PSG_NODE_FREE_FUNCTION_NAME(user_type)(tmp);              \
            }                                                             \
            PSG_NODE_FREE_FUNCTION_NAME(user_type)(self->first);          \
            PSG_NODE_FREE_FUNCTION_NAME(user_type)(self->last);           \
            free(self);                                                   \
        }                                                                 \
    }

#define PSG_LINKED_LIST_GET_SIZE_FUNCTION(user_type, item_type)   \
    PSG_LINKED_LIST_GET_SIZE_FUNCTION_PROTO(user_type, item_type) \
    {                                                             \
        size_t size = 0;                                          \
        if (self)                                                 \
        {                                                         \
            size = self->size;                                    \
        }                                                         \
        return size;                                              \
    }

//
#define PSG_LINKED_LIST_PUSH_FIRST_FUNCTION(user_type, item_type)                                                                   \
    PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_PROTO(user_type, item_type)                                                                 \
    {                                                                                                                               \
        if (self)                                                                                                                   \
        {                                                                                                                           \
            PSG_NODE_STRUCTURE_NAME(user_type) *node = PSG_NODE_NEW_FUNCTION_NAME(user_type)(item, self->first, self->first->next); \
            self->first->next->prev = node;                                                                                         \
            self->first->next = node;                                                                                               \
            self->size++;                                                                                                           \
        }                                                                                                                           \
    }

//
#define PSG_LINKED_LIST_POP_LAST_FUNCTION(user_type, item_type)         \
    PSG_LINKED_LIST_POP_LAST_FUNCTION_PROTO(user_type, item_type)       \
    {                                                                   \
        item_type item = 0;                                             \
        if (self && self->size)                                         \
        {                                                               \
            PSG_NODE_STRUCTURE_NAME(user_type) *tmp = self->last->prev; \
            item = tmp->item;                                           \
            self->last->prev = tmp->prev;                               \
            tmp->prev->next = self->last;                               \
            PSG_NODE_FREE_FUNCTION_NAME(user_type)(tmp);                \
            self->size--;                                               \
        }                                                               \
        return item;                                                    \
    }

//
#define PSG_LINKED_LIST_ITERATOR_STRUCTURE_NAME(user_type) \
    struct psg_##user_type##_linked_list_iterator_t

//
#define PSG_LINKED_LIST_ITERATOR_STRUCTURE(user_type)  \
    PSG_LINKED_LIST_ITERATOR_STRUCTURE_NAME(user_type) \
    {                                                  \
        PSG_LINKED_LIST_STRUCTURE_NAME(user_type)      \
        const *iterable;                               \
        PSG_NODE_STRUCTURE_NAME(user_type) * curr;     \
    };

//
#define PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION(user_type)                                                                                              \
    PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_PROTO(user_type)                                                                                            \
    {                                                                                                                                                 \
        if (iterable)                                                                                                                                 \
        {                                                                                                                                             \
            PSG_LINKED_LIST_ITERATOR_STRUCTURE_NAME(user_type) *it = 0;                                                                               \
            if ((it = malloc(sizeof(PSG_LINKED_LIST_ITERATOR_STRUCTURE_NAME(user_type)))))                                                            \
            {                                                                                                                                         \
                *it = (PSG_LINKED_LIST_ITERATOR_STRUCTURE_NAME(user_type)){.iterable = iterable, .curr = iterable->size ? iterable->first->next : 0}; \
            }                                                                                                                                         \
            return it;                                                                                                                                \
        }                                                                                                                                             \
        else                                                                                                                                          \
        {                                                                                                                                             \
            return 0;                                                                                                                                 \
        }                                                                                                                                             \
    }

//
#define PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION(user_type)   \
    PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION_PROTO(user_type) \
    {                                                       \
        if (self)                                           \
        {                                                   \
            free(self);                                     \
        }                                                   \
    }

//
#define PSG_LINKED_LIST_ITERATOR_IS_EQUAL_FUNCTION(user_type)     \
    PSG_LINKED_LIST_ITERATOR_IS_EQUAL_FUNCTION_PROTO(user_type)   \
    {                                                             \
        if (self && self->curr && to_compare && to_compare->curr) \
        {                                                         \
            if (self->curr == to_compare->curr)                   \
            {                                                     \
                return 1;                                         \
            }                                                     \
        }                                                         \
        return 0;                                                 \
    }

//
#define PSG_LINKED_LIST_ITERATOR_IS_FIRST_FUNCTION(user_type)                            \
    PSG_LINKED_LIST_ITERATOR_IS_FIRST_FUNCTION_PROTO(user_type)                          \
    {                                                                                    \
        if (self && self->curr && self->iterable && self->iterable->first == self->curr) \
        {                                                                                \
            return 1;                                                                    \
        }                                                                                \
        else                                                                             \
        {                                                                                \
            return 0;                                                                    \
        }                                                                                \
    }

//
#define PSG_LINKED_LIST_ITERATOR_IS_LAST_FUNCTION(user_type)                            \
    PSG_LINKED_LIST_ITERATOR_IS_LAST_FUNCTION_PROTO(user_type)                          \
    {                                                                                   \
        if (self && self->curr && self->iterable && self->iterable->last == self->curr) \
        {                                                                               \
            return 1;                                                                   \
        }                                                                               \
        else                                                                            \
        {                                                                               \
            return 0;                                                                   \
        }                                                                               \
    }

//
#define PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION(user_type)   \
    PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_PROTO(user_type) \
    {                                                       \
        if (self && self->curr && self->curr->next)         \
        {                                                   \
            self->curr = self->curr->next;                  \
        }                                                   \
    }

//
#define PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION(user_type)   \
    PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_PROTO(user_type) \
    {                                                       \
        if (self && self->curr && self->curr->prev)         \
        {                                                   \
            self->curr = self->curr->prev;                  \
        }                                                   \
    }

//
#define PSG_LINKED_LIST_ITERATOR_GET_ITEM_FUNCTION(user_type, item_type)                                     \
    PSG_LINKED_LIST_ITERATOR_GET_ITEM_FUNCTION_PROTO(user_type, item_type)                                   \
    {                                                                                                        \
        if (self && self->curr && self->curr != self->iterable->first && self->curr != self->iterable->last) \
        {                                                                                                    \
            return self->curr->item;                                                                         \
        }                                                                                                    \
        else                                                                                                 \
        {                                                                                                    \
            return 0;                                                                                        \
        }                                                                                                    \
    }

//
#define PSG_LINKED_LIST_ITERATOR_SET_ITEM_FUNCTION(user_type, item_type)                                     \
    PSG_LINKED_LIST_ITERATOR_SET_ITEM_FUNCTION_PROTO(user_type, item_type)                                   \
    {                                                                                                        \
        if (self && self->curr && self->curr != self->iterable->first && self->curr != self->iterable->last) \
        {                                                                                                    \
            self->curr->item = item;                                                                         \
        }                                                                                                    \
    }

//
#define PSG_LINKED_LIST_DEFINITION_MOD(user_type, item_type)         \
    PSG_NODE_STRUCTURE(user_type, item_type);                        \
    PSG_NODE_NEW_FUNCTION(user_type, item_type)                      \
    PSG_NODE_FREE_FUNCTION(user_type, item_type)                     \
    PSG_LINKED_LIST_STRUCTURE(user_type, item_type);                 \
    PSG_LINKED_LIST_NEW_FUNCTION(user_type, item_type)               \
    PSG_LINKED_LIST_FREE_FUNCTION(user_type, item_type)              \
    PSG_LINKED_LIST_GET_SIZE_FUNCTION(user_type, item_type)          \
    PSG_LINKED_LIST_PUSH_FIRST_FUNCTION(user_type, item_type)        \
    PSG_LINKED_LIST_POP_LAST_FUNCTION(user_type, item_type)          \
    PSG_LINKED_LIST_ITERATOR_STRUCTURE(user_type)                    \
    PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION(user_type)                 \
    PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION(user_type)                \
    PSG_LINKED_LIST_ITERATOR_IS_EQUAL_FUNCTION(user_type)            \
    PSG_LINKED_LIST_ITERATOR_IS_FIRST_FUNCTION(user_type)            \
    PSG_LINKED_LIST_ITERATOR_IS_LAST_FUNCTION(user_type)             \
    PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION(user_type)                \
    PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION(user_type)                \
    PSG_LINKED_LIST_ITERATOR_GET_ITEM_FUNCTION(user_type, item_type) \
    PSG_LINKED_LIST_ITERATOR_SET_ITEM_FUNCTION(user_type, item_type)
