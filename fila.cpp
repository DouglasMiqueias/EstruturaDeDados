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

struct Queue{
    Node *start;
    Node *end;

    // metodo construtor para a lista, inicializando seu inicio e fim como nulo
    List(){
        start = NULL;
        end = NULL;
    }

    // metodo para verificar se a lista está vazia
    //se a lista estiver vazia, retorna true;
    bool empty()
    {
        return start == NULL;
    }

    void dequeue()
    {


    }

    // atribuimos o valor à lista, chamando o construtor com parametro
    void enqueue(int value)
    {
        Node *n = new Node(value);

        if(empty)
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
};

int main()
{
    return 0;
}
