#include <stdio.h>

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

int main() {

    Produto p;

    printf("Digite o codigo do produto: ");
    scanf("%d", &p.codigo);

    printf("Digite o nome do produto: ");
    scanf("%s", p.nome);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &p.quantidade);

    printf("Digite o preco do produto: ");
    scanf("%f", &p.preco);

    printf("\nProduto cadastrado:\n");
    printf("Codigo: %d\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Quantidade: %d\n", p.quantidade);
    printf("Preco: %.2f\n", p.preco);

    return 0;
}