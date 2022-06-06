#include <iostream>

#include<map>

#include <string>

#include<iterator>

using namespace std;

typedef struct Cliente {

  int codigo;
  string nome;

}
Cliente;

typedef struct Funcionario {
  int codigo;
  string nome;
}
Funcionario;

typedef struct Combustivel {

  int codigo;
  string nome;
  float preco;
  string dataAlteracaoPreco;

}
Combustivel;

typedef struct Venda {
  Cliente cliente;
  Combustivel combustivel;
  float litros;
  Funcionario funcionario;
  string dataVenda;
  bool statusVenda;
}
Venda;

int main() {

  int opcao = 0;
  Combustivel combustivel;
  map < int, Combustivel > mapaCombustivel;
  map < int, Cliente > mapaCliente;
  map < int, Funcionario > mapaFuncionario;
  map < int, Venda > mapaVenda;

  combustivel.codigo = 0;
  combustivel.nome = " S10";
  combustivel.preco = 7.00;
  combustivel.dataAlteracaoPreco = "11/04";
  mapaCombustivel[combustivel.codigo] = combustivel;

  combustivel.codigo = 1;
  combustivel.nome = " Gasolina";
  combustivel.preco = 7.24;
  combustivel.dataAlteracaoPreco = "11/04";
  mapaCombustivel[combustivel.codigo] = combustivel;

  combustivel.codigo = 2;
  combustivel.nome = " Etanol Comum";
  combustivel.preco = 5.4;
  combustivel.dataAlteracaoPreco = "11/04";
  mapaCombustivel[combustivel.codigo] = combustivel;

  Funcionario funcionario;
  funcionario.codigo = 0;
  funcionario.nome = "Joao";
  mapaFuncionario[funcionario.codigo] = funcionario;

  Cliente cliente;
  cliente.codigo = 0;
  cliente.nome = "André";
  mapaCliente[cliente.codigo] = cliente;

  int indiceVenda = 0;

  while (opcao != 5) {
    cout << "------ Posto Pitagoras S.A ------ \n";
    cout << "1) Abrir pedido\n";
    cout << "2) Cadastrar Cliente\n";
    cout << "3) Cadastrar Funcionario\n";
    cout << "4) Divida por cliente\n";
    cout << "5) Fechar programa \n";
    cout << "Opcao: ";
    cin >> opcao;

    if (opcao == 1) {
      Venda venda;
      int codigoCliente, codigoCombus, codigoFuncionario, pagamento;
      cout << "\nInforme a data de abertura do pedido: ";
      cin >> venda.dataVenda;

      cout << "Informe o codigo do Cliente: ";
      cin >> codigoCliente;

      if (mapaCliente.find(codigoCliente) == mapaCliente.end()) {

        cout << "Esse cliente nao esta cadastrado";

      } else {

        venda.cliente = mapaCliente[codigoCliente];

        cout << "Informe o codigo do combustivel\n ";
        cout << "0 - S10\n";
        cout << "1 - Gasolina\n";
        cout << "2 - Etanol\n";
        cout << "Opcao: ";
        cin >> codigoCombus;

        if (mapaCombustivel.find(codigoCombus) == mapaCombustivel.end()) {

          cout << "Esse combustivel nao existe";

        } else {

          int quantidadeLitros;
          venda.combustivel = mapaCombustivel[codigoCombus];

          cout << "Quantos litros? ";
          cin >> quantidadeLitros;
          float valorTotal = quantidadeLitros * venda.combustivel.preco;
          cout << "O valor do pedido sera de: R$" << valorTotal;

          venda.litros = quantidadeLitros;

          cout << "\nInforme o codigo do funcionario: ";
          cin >> codigoFuncionario;

          if (mapaFuncionario.find(codigoFuncionario) == mapaFuncionario.end()) {

            cout << "Esse funcionário nao esta cadastrado \n";

          } else {

            venda.funcionario = mapaFuncionario[codigoFuncionario];

            cout << "o valor foi pago? 1- Sim 2- Nao";
            cin >> pagamento;

            if (pagamento == 1) {
              venda.statusVenda = true;
              mapaVenda[indiceVenda] = venda;
              indiceVenda++;
              cout << "Venda registrada com sucesso! \n ";
            }
            if (pagamento == 0) {
              venda.statusVenda = false;
              mapaVenda[indiceVenda] = venda;
              indiceVenda++;
              cout << "Venda registrada com sucesso! \n ";
            }

          }

        }
      }

    }

    if (opcao == 2) {
      cout << "\nInforme o codigo do cliente: ";
      cin >> cliente.codigo;

      cout << "Informe o nome do cliente: ";
      cin >> cliente.nome;

      mapaCliente[cliente.codigo] = cliente;
      cout << "Cliente cadastrado com sucesso! \n";
    }

    if (opcao == 3) {

      cout << "\nInforme o codigo do funcionario: ";
      cin >> funcionario.codigo;

      cout << "Informe o nome do funcionario: ";
      cin >> funcionario.nome;

      mapaFuncionario[funcionario.codigo] = funcionario;
      cout << "Funcionario cadastrado com sucesso! \n";

    }

    if (opcao == 4) {

      int codigoCliente, pagamento;

      cout << "Informe o codigo do cliente que deseja verificar as vendas: ";
      cin >> codigoCliente;

      if (mapaCliente.find(codigoCliente) == mapaCliente.end()) {
        cout << "Esse cliente não existe!";
      } else {

        Cliente cliente = mapaCliente[codigoCliente];

        map < int, Venda > ::iterator it = mapaVenda.begin();

        cout << "-------------Pedidos em aberto ----------------- \n";

        while (it != mapaVenda.end()) {

          int codigo = it -> first;
          Venda venda = it -> second;

          if (venda.cliente.codigo == codigoCliente) {

            if (venda.statusVenda == false) {
              cout << "Data do pedido: " << venda.dataVenda << "\n";
              cout << "Nome do cliente: " << venda.cliente.nome << "\n";
              cout << "Funcionário: " << venda.funcionario.nome << "\n";
              cout << "Total da venda: R$" << venda.litros * venda.combustivel.preco << "\n";

            }

            it++;
          }
        }

      }

      cout << "\n\n";

    }
  }
}
