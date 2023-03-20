#include "contabancaria.c"

int main(){
    int loop = 0, op;
    while(loop==0){
        printf("----- MENU -----\n1- Criar conta\n2- Depositar\n3- Sacar\n4- Transferir\n5- Consltar saldo\n6- Excluir conta\n0- Sair\nDigite sua opção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            //Criar conta
            break;
        case 2:
            //Depositar
            break;
        case 3:
            //Sacar
            break;
        case 4:
            //Transferir
            break;
        case 5:
            //Consultar
            break;
        case 6:
            //Excluir conta
            break;
        case 0:
            loop = 1;
            break;
        default:
            break;
        }
    }

    return 0;
}