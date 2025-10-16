#include <stdio.h>
#include <string.h>

struct produto {
    char nome[40];
    float preco;
    int codigo;
    int quantidade;
    int vendidos;

};

struct cliente {
    char nome[30];
    int codigo_produto;
    int quantidade_produto;
};

int main() {
    struct cliente clientes[2];
    struct produto produtos[4] = {
        {"Geladeira", 5000, 101, 5, 0},
        {"Fogao", 3500, 102, 10, 0},
        {"Ventilador", 800, 103, 15, 0},
        {"Aspirador de po", 650, 104, 20, 0},
    };

    int i, j; 
    int total_vendidos = 0;
    double valor_pagar;
    float total_estoque;
    float maior_valor = 0;

    // Exibe produtos
    printf("----Produtos----\n\n");
    for (i = 0; i < 4; i++) {
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: %.2f\n", produtos[i].preco);
        printf("Codigo: %d\n", produtos[i].codigo);
        printf("Quantidade em estoque: %d\n", produtos[i].quantidade);
        printf("Vendidos: %d\n", produtos[i].vendidos);


        total_estoque = produtos[i].preco * produtos[i].quantidade;
        printf("Valor total em estoque: %.2f\n\n", total_estoque);

        if (total_estoque > maior_valor) {
            maior_valor = total_estoque;
            j = i;
        }
    }

    printf("--Produto com maior valor em estoque--\n\n");
    printf("Nome: %s\n", produtos[j].nome);
    printf("Valor em estoque: %.2f\n\n", maior_valor);

    // Cadastra clientes
    printf("-----Bem-vindo-----\n\n");
    for (i = 0; i < 2; i++) {
        printf("Informe o seu nome: ");
        fflush(stdin);
        fgets(clientes[i].nome, sizeof(clientes[i].nome), stdin);
        clientes[i].nome[strcspn(clientes[i].nome, "\n")] = '\0'; // remove \n

        printf("Informe o codigo do produto desejado: ");
        scanf("%d", &clientes[i].codigo_produto);

        printf("Informe a quantidade desejada: ");
        scanf("%d", &clientes[i].quantidade_produto);
    

        int encontrado = 0;

        for (j = 0; j < 4; j++) {
            if (clientes[i].codigo_produto == produtos[j].codigo) {
                encontrado = 1;
                if (clientes[i].quantidade_produto <= produtos[j].quantidade) {

                    valor_pagar = clientes[i].quantidade_produto*produtos[j].preco;

                    printf("Nome do cliente: %s\n", clientes[i].nome);
                    printf("Codigo do produto: %d\n", clientes[i].codigo_produto);
                    printf("Quantidade comprada: %d\n", clientes[i].quantidade_produto);
                    printf("Valor a pagar: %.2lf\n", valor_pagar);

                    total_vendidos = total_vendidos + clientes[i].quantidade_produto;


                    printf("Compra concluida com sucesso!\n");
                    produtos[j].quantidade -= clientes[i].quantidade_produto;
                } else {
                    printf("Nao ha produtos suficientes em estoque!\n");
                }
                break;
            }
        }

        if (!encontrado) {
            printf("Codigo invalido! Produto nao encontrado.\n");
        }

        printf("\n");
    }


    printf("\n\n----Estoque atualizado!----\n");

    for (i = 0; i < 4; i++)
    {
        printf("Nome do produto: %s\n", produtos[i].nome);
        printf("Codigo: %d\n", produtos[i].codigo);
        printf("Quantidade restante: %d\n", produtos[i].quantidade);
    }
    printf("Total de produtos vendidos: %d\n", total_vendidos);

    return 0;
}
