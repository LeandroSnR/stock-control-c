#include <stdio.h>

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void registro_produto(Produto *p) {
    
    printf("Digite o codigo do produto: ");
    scanf("%d", &p->codigo);

    printf("Digite o nome do produto: ");
    scanf("%s", p->nome);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &p->quantidade);

    printf("Digite o preco do produto: ");
    scanf("%f", &p->preco);
}
void listar_produtos(Produto produtos[], int num_produtos) {
    printf("\nLista de produtos cadastrados:\n");

    for (int i = 0; i < num_produtos; i++) 
    {
        printf("Codigo: %d, Nome: %s, Quantidade: %d, Preco: %.2f\n",
               produtos[i].codigo, produtos[i].nome,
               produtos[i].quantidade, produtos[i].preco);
    }
}

int main() {

    Produto produtos[10];
    int num_produtos = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Registrar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (num_produtos < 10) {
                    registro_produto(&produtos[num_produtos]);
                    num_produtos++;
                } else {
                    printf("Limite de produtos atingido.\n");
                }
                break;
            case 2:
                listar_produtos(produtos, num_produtos);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);
    return 0;
}