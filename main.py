class Produto:
    def __init__(self, codigo, nome, quantidade, preco):
        self.codigo = codigo
        self.nome = nome
        self.quantidade = quantidade
        self.preco = preco

def cadastrar_produto():
    codigo = int(input("Digite o codigo do produto: "))
    nome = input("Digite o nome do produto: ")
    quantidade = int(input("Digite a quantidade do produto: "))
    preco = float(input("Digite o preco do produto: "))
    
    return Produto(codigo, nome, quantidade, preco)

def salvar_produtos(produtos):
    with open("produtos.txt", "w") as arquivo:
        for produto in produtos:
            arquivo.write(f"{produto.codigo},{produto.nome},{produto.quantidade},{produto.preco:.2f}\n")
    print("Produtos salvos em arquivo.")

def procurar_produto(produtos, codigo):
    for produto in produtos:
        if produto.codigo == codigo:
            return produto
    return None


def listar_produtos(produtos):
    print("\nLista de produtos cadastrados:")
    for produto in produtos:
        print(f"Codigo: {produto.codigo}, Nome: {produto.nome}, Quantidade: {produto.quantidade}, Preco: {produto.preco:.2f}")

def main():
    produtos = []
    
    while True:
        print("\n1. Cadastrar produto")
        print("2. Listar produtos")
        print("3. Procurar produto")
        print("4. Salvar produtos em arquivo")
        print("5. Sair")
        
        escolha = input("Escolha uma opcao: ")
        
        if escolha == '1':
            produto = cadastrar_produto()
            produtos.append(produto)
        elif escolha == '2':
            listar_produtos(produtos)
        elif escolha == '3':
            codigo = int(input("Digite o codigo do produto a ser procurado: "))
            produto = procurar_produto(produtos, codigo)
            if produto:
                print(f"Produto encontrado: Codigo: {produto.codigo}, Nome: {produto.nome}, Quantidade: {produto.quantidade}, Preco: {produto.preco:.2f}")
            else:
                print("Produto nao encontrado.")
        elif escolha == '4':
            salvar_produtos(produtos)
        elif escolha == '5':
            break
        else:
            print("Opcao invalida. Tente novamente.")
if __name__ == "__main__":
    main()

    
