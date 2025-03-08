// Referências e Ponteiros em C++

#include <iostream>
#include <locale.h>

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt-BR");
    int numero{}; // Declaração e inicialização de uma variável inteira
    
    int &Ref = numero; // 'Ref' é uma referência para 'numero'.
                        // Diferente de um ponteiro, a referência é apenas um alias para a variável,
                        // ou seja, qualquer alteração em 'Ref' também altera 'numero'.
    
    int *ptr = &numero; // 'ptr' é um ponteiro que armazena o endereço de 'numero'.
                         // Ele pode ser alterado para apontar para outros endereços de memória.
    
    int &Ref2 = *ptr; // 'Ref2' também se torna uma referência para 'numero', pois '*ptr' é 'numero'.
    ptr = &Ref2; // O ponteiro 'ptr' continua apontando para 'numero' por meio de 'Ref2'.
    

    
    // Verifica se os endereços são os mesmos
    bool verificacao_enderecos = (Ref && ptr == &numero ? "TRUE" : "FALSE");
    bool verificacao_valores = (*ptr == numero ? "TRUE" : "FALSE");
    
    bool ver_endereco = verificacao_enderecos;
    bool ver_valor = verificacao_valores;
    
    for (;;) {
        int opt;
        
        std::cout << "\n1: Verificar se o endereço de memória é igual";
        std::cout << "\n2: Ver se os valores são iguais";
        std::cout << "\n3: Checar endereço de memória do ponteiro";
        std::cout << "\n4: Somar valor ao ponteiro";
        std::cout << "\n5: Sair";
        std::cout << "\n\nDigite uma opção: ";
        std::cin >> opt;
        
        if (opt == 5) {
            break;
        }
        
        switch (opt) {
            case 1:
                if (verificacao_enderecos) {
                    std::cin.ignore();
                    std::cout << "\n\nEndereço de Memória de Ref: " << &Ref;
                    std::cout << "\nEndereço de Memória de Ptr: " << ptr;
                    std::cout << "\nEndereço de Memória de Número: " << &numero;
                    std::cout << "\nFALSE(0) / TRUE(1): " << ver_endereco;
                    std::cout << "\n\nPressione qualquer tecla para continuar: ";
                    std::cin.get();
                } else {
                    std::cout << "\nOs endereços de memória são diferentes!\n";
                }
                break;
            
            case 2:
                std::cin.ignore();
                if (verificacao_valores) {
                    std::cout << "\nValor de Número: " << numero;
                    std::cout << "\nValor de REF: " << Ref;
                    std::cout << "\nValor contido em ptr: " << *ptr << '\n';
                    std::cout << "FALSE(0) / TRUE(1): " << ver_valor;
                    std::cout << "\n\nPressione qualquer tecla para continuar: ";
                    std::cin.get();
                } else {
                    std::cout << "\nOs valores atribuídos são diferentes!\n";
                }
                break;
            
            case 3:
                std::cin.ignore();
                if (*(int*)&Ref2 == *(int*)&ptr) {
                    std::cout << "\nO endereço de memória de 'ptr' é igual ao de 'numero'\n";
                } else {
                    std::cout << "\nO endereço de memória de 'ptr' é diferente do de 'numero'";
                    std::cout << "\n\nEndereço de Memória de ptr: " << &ptr;
                    std::cout << "\nEndereço de Memória de Número: " << &numero;
                    std::cout << "\n\nPressione qualquer tecla para continuar: ";
                    std::cin.get();
                }
                break;
            
            case 4:
                int x;
                std::cout << "\nQuanto você quer somar ao valor apontado pelo ponteiro: ";
                std::cin >> x;
                *ptr += x;
                std::cout << "\n\nValor atualizado contido em ptr: " << *ptr << '\n';
                std::cout << "\n\nPressione qualquer tecla para continuar: ";
                std::cin.ignore(10, '\n');
                std::cin.get();
                break;
            
            default:
                std::cout << "\nOpção Inválida!\n";
                break;
        }
    }
    return 0;
}
