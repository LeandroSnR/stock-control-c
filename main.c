#include <stdio.h>
#include <string.h>

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

void salvar_produtos(Produto produtos[], int num_produtos) {
    FILE *arquivo = fopen("dados.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fwrite(&num_produtos, sizeof(int), 1, arquivo);
    fwrite(produtos, sizeof(Produto), num_produtos, arquivo);

    fclose(arquivo);

    printf("Produtos salvos com sucesso.\n");
}

void carregar_produtos(Produto produtos[], int *num_produtos) {
    FILE *arquivo = fopen("dados.dat", "rb");

    if(arquivo == NULL) {
        return;
    }

    fread(num_produtos, sizeof(int), 1, arquivo);
    fread(produtos, sizeof(Produto), *num_produtos, arquivo);

    fclose(arquivo);

}

void procurar_produto(Produto produtos[], int num_produtos, int codigo) {
    int encontrado = 0;
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Codigo: %d, Nome: %s, Quantidade: %d, Preco: %.2f\n",
                   produtos[i].codigo,
                   produtos[i].nome,
                   produtos[i].quantidade,
                   produtos[i].preco);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }
}

int main() {

    Produto produtos[10];
    int num_produtos = 0;
    int opcao;
    carregar_produtos(produtos, &num_produtos);

    do {
        printf("\nMenu:\n");
        printf("1. Registrar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Procurar produtos\n");
        printf("4. Salvar produtos\n");
        printf("5. Sair\n");
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
            case 3: {
                int codigo_procurado;
                printf("Digite o codigo do produto a ser procurado: ");
                scanf("%d", &codigo_procurado);
                procurar_produto(produtos, num_produtos, codigo_procurado);
                break;
                }
            case 4:
                salvar_produtos(produtos, num_produtos);
                break;
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);
    return 0;
}