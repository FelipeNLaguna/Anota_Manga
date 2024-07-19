// Objetivo: Criar um arquivo e atualiza-lo , esse arquivo guarda o nome de um mangá ou anime , o genero e o ultimo ep visto pelo usuário.
// Passo a Passo: pergunta se o usuário quer criar ou ler
// se ele quer criar Recebe do usuário um nome de arquivo 
// se o arquivo não existir ele cria um arquivo com o nome fornecido
// se já exixtir ele escreve no arquivo usando alguns padrões de formatação
// pergunta para o usuário se ele deseja escrever sobre um mangá ou anime
// pergunta o nome do mangá ou anime , o genero e o ultimo ep visto
// no mangá coloca " (mangá) <nome> : cap <cap> genero: <genero> "
// no anime coloca " (anime) <nome> : temporada <temporada> ep <ep> genero: <genero> "
// Arquivos : arquivo para lidar com arquivos e outro para lidar com a formatação 
/* Projeto final : Receber o arquivo por email */ 
// MANGÁ E ANIME PODE SER UMA STRUCT/CLASSE
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
// no primeiro plano , vai ser tudo no arquivo main , depois eu separo em arquivos diferentes 
/*Funções:
    - Cria arquivo ;
    - Ler arquivo ;
    - Inputs usuario : ler/escrever , anime/manga , parar , nome_arquivo , nome_obra (Provavelmente vai estar em várias funções) ; 
    - Tudo é minusculo/maisculo p/ leitura
    - Percorre o arquivo p/ descobrir se a obra já existe ;
    - Escreve arquivo p/ mangá ;
    - Escreve arquivo p/ anime ;


*/

// Função responsável por testar se o arquivo existe
bool Existe_arquivo(string nome_arq){
    // declara um arquivo do tipo ifstream que recebe como nome o nome do arquivo
    ifstream arquivo(nome_arq);
    // variável que vai ser retornada
    bool tem_arq;  
    if(arquivo.is_open()){
        arquivo.close(); // Fecha o arquivo
        tem_arq = true;
    }
    else{
        tem_arq = false;
    }
    return tem_arq;
}
bool Cria_arquivo(string nome_arq){
    bool criou_arq = true;
    // classe ofstream pode criar/escrever arquivo , permite manipulação de arq bin/txt   
    ofstream arquivo(nome_arq);
    if(!arquivo){
        criou_arq = false; 
    }
    // fecha arquivo
    arquivo.close();
    // retorna se o arquivo foi criado com sucesso
    return criou_arq;
}
int main (){
    // 'Tela' inicial
    cout << "Bem vindo ao Organizador de mangás e animes!" << endl;
    cout << "Para você que nunca sabe aonde parou na sua obra favorita" << endl;
    cout << "Se deseja criar um arquivo, Digite 0!" << endl ;
    cout << "Se deseja ler um arquivo , Digite 1!" << endl ;
    
    // Pega do usuário 0/1 -> se resposta for False cria arquivo se for True testa se existe se existe lê 
    bool resposta ;
    cin >> resposta;
    // cout << resposta << endl ;

    string nome_arquivo;
    cout << "Digite o nome do arquivo que deseja criar/ler" << endl;
    cin >> nome_arquivo;
    // classe ifsteam
    // ifstream arquivo(nome_arquivo);
    // is_open : função do ifstream , retorna True se existe e False se não existe
    // Lembrar de fechar arquivo - close()
    // do/while até o usuário querer parar o programa
    
    // variável p/ testar se existe o arquivo
    bool exist_arq;
    // testa se quer criar ou ler
    if(!resposta){
        // se quer criar , cria arquivo
        Cria_arquivo(nome_arquivo);
    }
    else{
        // senão , testa se o arquivo existe
        exist_arq = Existe_arquivo(nome_arquivo);
        // se o arquivo não existe entra no if e cria o arquivo
        if(!exist_arq){
            Cria_arquivo(nome_arquivo);
        }
    }

    // Abrir arquivo e escrever e percorre-lo



    return 0;
}

