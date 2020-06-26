#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;                 //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;         //puntero al prox nodo
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;                       //cada vez que agrego o elimino un elemento size++/--
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* lista);                                       //devuelve el valor del campo int size
Node* test_getNode(LinkedList* lista, int nodeIndex);
int test_addNode(LinkedList* lista, int nodeIndex,void* pElement);
int ll_add(LinkedList* lista, void* pElement);
void* ll_get(LinkedList* lista, int index);
int ll_set(LinkedList* lista, int index,void* pElement);
int ll_remove(LinkedList* lista,int index);
int ll_clear(LinkedList* lista);
int ll_deleteLinkedList(LinkedList* lista);
int ll_indexOf(LinkedList* lista, void* pElement);
int ll_isEmpty(LinkedList* lista);
int ll_push(LinkedList* lista, int index, void* pElement);
void* ll_pop(LinkedList* lista,int index);                           //elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
int ll_contains(LinkedList* lista, void* pElement);
int ll_containsAll(LinkedList* lista,LinkedList* this2);
LinkedList* ll_subList(LinkedList* lista,int from,int to);
LinkedList* ll_clone(LinkedList* lista);
int ll_sort(LinkedList* lista, int (*pFunc)(void* ,void*), int order);
LinkedList* ll_filter(LinkedList* lista, int(*pFunc)(void*));
