#include<stdio.h>
#include<stdlib.h>
//#include<locale.h>

typedef struct funcionario{
    char nome[50];
    char cargo[50];
    float salario;
    int id;

}Funcionario;

void puxar_info(Funcionario * funcionario, int qtd_funcionarios){
    int i;
    for(i=0;i<qtd_funcionarios;i++){
        printf("\nNome do funcionario: %s", funcionario[i].nome);
        printf("\nCargo do funcionario: %s", funcionario[i].cargo);
        printf("\nSalario: R$ %.2f", funcionario[i].salario);
        printf("\nIdentificador: %d\n", funcionario[i].id);
    } 
}

void cadastrar_funcionarios(Funcionario * funcionario, int qtd_funcionarios){
    int i;
    for(i=0;i<qtd_funcionarios;i++){
        printf("Digite o nome do %d° funcinario : ", i+1);
        scanf(" %[^\n]s", funcionario[i].nome);
        printf("Digite o cargo do %d° funcinario : ", i+1);
        scanf(" %[^\n]s", funcionario[i].cargo);
        funcionario[i].id = i;
        printf("Digite o salario do %d° funcinario : ", i+1);
        scanf("%f", &funcionario[i].salario);
    } 
}

void alt_salario(Funcionario * funcionario){
    int idd;
    float n_salario;
    printf("Digite o Identificador do funcionario que deseja alterar o salario: ");
    scanf("%d", &idd);
    printf("Digite o novo salario do funcionario: ");
    scanf("%f", &n_salario);
    funcionario[idd].salario = n_salario;
    
}

void maiormenor(Funcionario * funcionario, int qtd_funcionarios){
    int i;
    int maior, menor;
    float salmaior = 0;
    float salmenor = 99999999999999999999999999999999999;
    for(i=0;i<qtd_funcionarios;i++){
        if(funcionario[i].salario > salmaior){
            salmaior = funcionario[i].salario;
            maior = funcionario[i].id;
        }
        if(funcionario[i].salario < salmenor){
            salmenor = funcionario[i].salario;
            menor = funcionario[i].id;
        }
    }
    printf("Funcionario com maior salario: \nNome: %s\nCargo: %s\nSalario: R$ %.2f\n", funcionario[maior].nome, funcionario[maior].cargo, funcionario[maior].salario);
    printf("Funcionario com menor salario: \nNome: %s\nCargo: %s\nSalario: R$ %.2f\n", funcionario[menor].nome, funcionario[menor].cargo, funcionario[menor].salario);


}

void main(){
    //setlocale(LC_ALL, "Portuguese");
    int qtd_funcionarios;
    printf("Digite a quantidade de funcionarios a ser cadastrada: ");
    scanf("%d", &qtd_funcionarios);
    Funcionario * vetor_de_funcionarios = (Funcionario*) malloc(qtd_funcionarios*sizeof(Funcionario));
    if (vetor_de_funcionarios==NULL){
        printf("Erro de alocação de memoria");
        exit(1);
    };
    
    cadastrar_funcionarios(vetor_de_funcionarios, qtd_funcionarios);
    puxar_info(vetor_de_funcionarios, qtd_funcionarios);
    maiormenor(vetor_de_funcionarios, qtd_funcionarios);
    alt_salario(vetor_de_funcionarios);
    puxar_info(vetor_de_funcionarios, qtd_funcionarios);
    maiormenor(vetor_de_funcionarios, qtd_funcionarios);
    free(vetor_de_funcionarios);

}
