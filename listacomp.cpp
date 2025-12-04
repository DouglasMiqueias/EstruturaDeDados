#include<stdio.h>

struct Node{
    int value;
    Node *next;

    // metodos construtores para o nó com parametro
    // o next sempre deve ser iniciado como nulo
    Node(int _value){
        value = _value;
        next = NULL;
    }

    // metodo construtor sem receber parametros
    Node(){
        next = NULL;
    }
};

struct List{
    Node *start;
    Node *end;
    int c;

    // metodo construtor para a lista, inicializando seu inicio e fim como nulo
    List()
    {
        start = NULL;
        end = NULL;
        c = 0;
    }

    // metodo para verificar se a lista está vazia
    //se a lista estiver vazia, retorna true;
    bool empty()
    {
        return start == NULL;
    }

    void pushfront(int value)
    {
        // cria um novo no, *n guarda a referencia do no;
        Node *n = new Node(value);
        c++;

        if(empty())
        {
            // se a lista estiver vazia, o inicio e o fim estao na mesma posicao;
            start = n;
            end = n;
            return;
        }
        // proximo do novo no recebe o valor de inicio; o inicio começa a tere o valor do novo no ;
        n->next = start;
        start = n;
    }

    // atribuimos o valor à lista, chamando o construtor com parametro
    void pushback(int value)
    {
        // cria um novo no, *n guarda a referencia do no;
        Node *n = new Node(value);
        c++;

        if(empty())
        {
            // se a lista estiver vazia, o inicio e o fim estao na mesma posicao;
            start = n;
            end = n;
            return;
        }
        // usa seta ao inves do ponto para acessar as propriedades de um ponteiro
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

    // complexidade tempo: O(n)
 /*
    int size()
    {
        int c = 0;
        Node *aux = start;
        while(aux != NULL)
        {
            c++;
            aux = aux->next;
        }
        return c;
    }
    */
    // complexidade O(1)
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
};




int main()
{
    List l;

    l.pushback(30);
    l.pushback(50);
    l.pushback(60);
    l.pushfront(10);
    l.pushfront(5);

    l.imprimir();

    l.popBack();
    l.popFront();

    l.imprimir();

    printf("%d", l.size());
    return 0;
}
