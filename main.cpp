#include <iostream>
#include <string>
#include <map>
#include <limits>

std::map<std::string, double> produtos = {
    {"Produto A", 10.0},
    {"Produto B", 20.0},
    {"Produto C", 30.0}
};

std::map<std::string, int> inventario = {
    {"Produto A", 5},
    {"Produto B", 10},
    {"Produto C", 15}
};

double faturamento = 0.0;

void modoUsuario()
{
    while (true)
    {
        std::cout << "==============================" << std::endl;
        std::cout << "|        Modo Usuário        |" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "| 1. Comprar produto         |" << std::endl;
        std::cout << "| 2. Voltar                  |" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "Escolha uma opção: ";

        int opcao;
        std::cin >> opcao;

        switch (opcao)
        {
            case 1:
            {
                std::cout << "====================================" << std::endl;
                std::cout << "|       Produtos Disponíveis       |" << std::endl;
                std::cout << "====================================" << std::endl;
                std::cout << "| Produto               | Preço    |" << std::endl;
                std::cout << "------------------------------------" << std::endl;
                for (const auto& produto : produtos)
                {
                    std::cout << "| " << produto.first;
                    std::cout << std::string(26 - produto.first.length(), ' ');
                    std::cout << "| R$ " << produto.second;
                    std::cout << std::string(9 - std::to_string(produto.second).length(), ' ');
                    std::cout << "|" << std::endl;
                }
                std::cout << "====================================" << std::endl;

                std::string produtoCompra;
                int quantidadeCompra;
                std::cout << "Digite o nome do produto desejado (ou digite 'voltar' para retornar): ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, produtoCompra);

                if (produtoCompra == "voltar") {
                    break;
                }

                if (produtos.find(produtoCompra) != produtos.end())
                {
                    std::cout << "Digite a quantidade desejada: ";
                    std::cin >> quantidadeCompra;

                    if (inventario[produtoCompra] >= quantidadeCompra)
                    {
                        double precoTotal = produtos[produtoCompra] * quantidadeCompra;
                        inventario[produtoCompra] -= quantidadeCompra;
                        faturamento += precoTotal;

                        std::cout << "Compra realizada com sucesso." << std::endl;
                        std::cout << "Preço total: R$" << precoTotal << std::endl;
                        std::cout << "Pressione ENTER para continuar." << std::endl;
                    }
                    else
                    {
                        std::cout << "Quantidade insuficiente em estoque." << std::endl;
                    }
                }
                else
                {
                    std::cout << "Produto não encontrado." << std::endl;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpar o buffer do teclado
                std::cin.get(); // Aguardar pressionar ENTER
                break;
            }
            case 2:
                return;
            default:
                std::cout << "Opção inválida." << std::endl;
                break;
        }
    }
}

void modoAdministrador()
{
    while (true)
    {
        std::cout << "==============================" << std::endl;
        std::cout << "|     Modo Administrador     |" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "| 1. Adicionar produto       |" << std::endl;
        std::cout << "| 2. Visualizar inventário   |" << std::endl;
        std::cout << "| 3. Visualizar faturamento  |" << std::endl;
        std::cout << "| 4. Voltar                  |" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "Escolha uma opção: ";

        int opcao;
        std::cin >> opcao;

        switch (opcao)
        {
            case 1:
            {
                std::string nomeProduto;
                double precoProduto;
                std::cout << "Digite o nome do produto: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, nomeProduto);

                if (produtos.find(nomeProduto) == produtos.end())
                {
                    std::cout << "Digite o preço do produto: ";
                    std::cin >> precoProduto;

                    produtos[nomeProduto] = precoProduto;
                    inventario[nomeProduto] = 0;

                    std::cout << "Produto adicionado com sucesso." << std::endl;
                }
                else
                {
                    std::cout << "Produto já existe." << std::endl;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpar o buffer do teclado
                std::cin.get(); // Aguardar pressionar ENTER
                break;
            }
            case 2:
            {
                std::cout << "======================================" << std::endl;
                std::cout << "|              Inventário            |" << std::endl;
                std::cout << "======================================" << std::endl;
                std::cout << "| Produto               | Quantidade |" << std::endl;
                std::cout << "--------------------------------------" << std::endl;
                for (const auto& produto : inventario)
                {
                    std::cout << "| " << produto.first;
                    std::cout << std::string(26 - produto.first.length(), ' ');
                    std::cout << "| " << produto.second;
                    std::cout << std::string(10 - std::to_string(produto.second).length(), ' ');
                    std::cout << "|" << std::endl;
                }
                std::cout << "====================================" << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpar o buffer do teclado
                std::cin.get(); // Aguardar pressionar ENTER
                break;
            }
            case 3:
                std::cout << "==============================" << std::endl;
                std::cout << "|      Faturamento Atual     |" << std::endl;
                std::cout << "==============================" << std::endl;
                std::cout << "| Faturamento atual: R$" << faturamento << std::endl;
                std::cout << "| Pressione ENTER para continuar." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpar o buffer do teclado
                std::cin.get(); // Aguardar pressionar ENTER
                break;
            case 4:
                return;
            default:
                std::cout << "Opção inválida." << std::endl;
                break;
        }
    }
}

int main()
{
    while (true)
    {
        std::cout << "==============================" << std::endl;
        std::cout << "|      Sistema de Vendas     |" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "| 1. Modo Usuário            |" << std::endl;
        std::cout << "| 2. Modo Administrador      |" << std::endl;
        std::cout << "| 3. Sair                    |" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "Escolha uma opção: ";

        int opcao;
        std::cin >> opcao;

        switch (opcao)
        {
            case 1:
                modoUsuario();
                break;
            case 2:
                modoAdministrador();
                break;
            case 3:
                return 0;
            default:
                std::cout << "Opção inválida." << std::endl;
                break;
        }
    }
    return 0;
}
