#include<stdio.h>

struct Node{
    int value;
    Node *next;

    Node(int _value){
        value = _value;
        next = NULL;
    }

    Node(){
        next = NULL;
    }
};

struct List{
    Node *start;
    Node *end;
    int c;

    List()
    {
        start = NULL;
        end = NULL;
        c = 0;
    }

    bool empty()
    {
        return start == NULL;
    }

    void pushfront(int value)
    {
        Node *n = new Node(value);
        c++;

        if(empty())
        {
            start = n;
            end = n;
            return;
        }
        n->next = start;
        start = n;
    }

    void pushback(int value)
    {
        Node *n = new Node(value);
        c++;

        if(empty())
        {
            start = n;
            end = n;
            return;
        }
        end->next = n;
        end = n;
    }

    void imprimir()
    {
        Node *aux = start;

        while(aux != NULL){
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }

    void popFront()
    {
        if(empty()) return;
        c--;

        if(start == end)
        {
            delete(start);
            start = NULL;
            end = NULL;
            return;
        }

        Node *aux = start;
        start = start->next;
        delete(aux);
    }

    void popBack()
    {
        if(empty()) return;
        c--;

        if(start == end)
        {
            delete(start);
            start = NULL;
            end = NULL;
            return;
        }
        Node *newEnd = start;
        while(newEnd->next != end)
        {
            newEnd = newEnd->next;
        }
        delete(end);
        end = newEnd;
        end->next = NULL;
    }
    int size()
    {
        return c;
    }


    void insertPenultimate(int value)
    {
        if(c <= 1) return;

        Node *n = new Node(value);
        c++;

        if(c == 2)
        {
            n->next = end;
            start->next = n;
            return;
        }

        Node *aux = start;
        while(aux->next != end)
        {
            aux = aux->next;
        }

        n->next = end;
        aux->next = n;
    }
};

int main()
{
    List l;
    l.pushback(10);
    l.pushback(20);
    l.pushback(30);
    l.pushback(40);

    l.imprimir();

    l.insertPenultimate(99);

    l.imprimir();

    return 0;
}
