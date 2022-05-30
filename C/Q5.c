#include <stdio.hs>
#include <stdlib.hs>

typedef enum { ATOM, LIST } eltype;
typedef char atom;
struct _listnode;
typedef struct {
eltype type;
union {
atom a;
struct _listnode* l;
};
} element;
typedef struct _listnode {
element el;
struct _listnode* next;
} * list;
const element NIL = { .type=LIST, .l=NULL };


//atom as element, that returns an element whose content is
//set to atom a.
element aasel(atom a) {
    element res;
    res.type = ATOM;
    res.a = a;
    return res;
}

// list as element, that returns an element whose content is set
//to the list, pointed by l.
element lasel(list l) {
    element res;
    res.type = LIST;
    res.l = l;
    return res;
}

//that returns the head of the list, represented by e; returns
//NIL, if e is not a list.
element car(element e) {
    if (e.type != LIST) {
        return NIL;
    }

    return e.l->el;
}

//that returns tail of the list, represented by e. The tail of a list
//with one or zero element is NULL. The tail of an element that is not a list is also NULL.
list cdr(element e) {
    if (e.type != LIST || e.l == NULL) {
        return NULL;
    }

    return e.l->next;
}

//that returns the cdr of the cdr of the list, represented by e.
list cddr(element e) {
    return cdr(lasel(cdr(e)));
}

//that creates a new list whose car and cdr are the
//element e and the list l. The memory for the newly created list is to be allocated
//dynamically
list cons(element e, list l) {
    list head = (list)malloc(sizeof(struct _listnode));
    head->el = e;
    head->next = l;
    return head;
}

//that creates a new list whose elements are shallow
//copies of elements in l1 and l2, appended.
list append(list l1, list l2)
{
    list newList= NULL;
    list temp = l1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = l2;
    
    newList = l1;
        
    return newList;
}

void lfreer(list l){ free();}




//that prints the content of the element e. If e is an atom, it
//prints the char symbol embraced in spaces, and if e it is a list, it (recursively) prints the
//elements of the list enclosed in parentheses (‘(‘ and ‘)’). If e is NIL, the word “NIL” is
//printed
void print(element e)
{
	
    if (e.type == ATOM)
    {
    	printf(" %c ", e.a);
    }
    
    else if(e.type == LIST)
    {
    	
    	list tempList = e.l;
    	while(tempList->el.type != ATOM)
    	{
    		print(tempList->el);
    	}
    	printf(" %c ", tempList->el.a);	
    }
    
    else 
    	printf("NIL");
}