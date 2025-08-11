#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 1
typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void cadastrarProduto(Produto produtos[], int *totalProdutos) {
    if (*totalProdutos >= MAX_PRODUTOS) {
        printf("Capacidade de estoque atingida.\n");
        return;
    }

    Produto novoProduto;
    
    printf("\nDigite o código do produto: ");
    scanf("%d", &novoProduto.codigo);
    
    printf("Digite o nome do produto: ");
    getchar();  
    fgets(novoProduto.nome, 50, stdin);
    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0;  
    
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novoProduto.quantidade);
    
    printf("Digite o preço do produto: ");
    scanf("%f", &novoProduto.preco);
    
    produtos[*totalProdutos] = novoProduto;
    (*totalProdutos)++;
    
    printf("\nProduto cadastrado com sucesso!\n");
}

void consultarProdutos(Produto produtos[], int totalProdutos) {
    if (totalProdutos == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\nProdutos cadastrados:\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Código: %d | Nome: %s | Quantidade: %d | Preço: R$%.2f\n",
               produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    }
}


void ajustarEstoque(Produto produtos[], int totalProdutos) {
    int codigo, novaQuantidade;
    
    printf("\nDigite o código do produto que deseja ajustar: ");
    scanf("%d", &codigo);
    
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Produto encontrado: %s\n", produtos[i].nome);
            printf("Digite a nova quantidade para o produto: ");
            scanf("%d", &novaQuantidade);
            produtos[i].quantidade = novaQuantidade;
            printf("Estoque do produto atualizado com sucesso!\n");
            return;
        }
    }
    
    printf("Produto com o código %d não encontrado.\n", codigo);
}

void exibirMenu() {
    printf("\nMenu de Controle de Estoque:\n");
    printf("1. Cadastrar Produto\n");
    printf("2. Consultar Produtos\n");
    printf("3. Ajustar Estoque\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &totalProdutos);
                break;
            case 2:
                consultarProdutos(produtos, totalProdutos);
                break;
            case 3:
                ajustarEstoque(produtos, totalProdutos);
                break;
            case 4:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
