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
    - Cria arquivo(Check) ;
    - Ler arquivo ;
    - Inputs usuario : ler/escrever , anime/manga , parar , nome_arquivo , nome_obra (Provavelmente vai estar em várias funções) ; 
    - Tudo é minusculo/maisculo p/ leitura
    - Percorre o arquivo p/ descobrir se a obra já existe ;
    - Escreve arquivo p/ mangá ;
    - Escreve arquivo p/ anime ;


*/
// classe manga usada para Esrever mangas no arquivo
class Manga{
    // Falta lidar com a forma de acesso - Public 
    // variaveis
    public:
        string name;
        int chapter;
    
        void Escreve_manga(string nome_arq){
            // Abre arq em modo append(adiciona o conteudo no final sem sobrescrever)
            ofstream arquivo(nome_arq, ios::app);
            if(!arquivo){
                // cerr emite msg de erro
                cerr << "Erro ao abrir o arquivo"<<endl;
                return;
            }
            // Ex: (M) Tonikaku kawaii - ch140
            arquivo << "(M) " << name << " - " << "ch" << chapter << endl;
            arquivo.close();
        }
};
// classe anime usada para escrever animes no arquivo
class Anime{
    // Falta lidar com a forma de acesso - Public 
    // variaveis
     public:
        string name;
        int Temp;
        int episode;
        
        void Escreve_anime(string nome_arq){
            // Abre arq em modo append(adiciona o conteudo no final sem sobrescrever)
            ofstream arquivo(nome_arq, ios::app);
            if(!arquivo){
                // cerr emite msg de erro
                cerr << "Erro ao abrir o arquivo"<<endl;
                return;
            }
            // Ex: (A) Haikyu - tp1 ep42
            arquivo << "(A) " << name << " - " <<"tp" << Temp  << " ep" << episode << endl;
            arquivo.close();
        }
};
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
    // variavel para manter o looping , se é true continua o while
    bool still;
    still = true ;
    while(still){
        // Pergunta oq o usuário deseja fazer
        cout << "Se deseja Escrever Manga , Digite 0!" << endl;
        cout << "Se deseja Escrever Anime, Digite 1!" << endl;
        cout << "Se deseja Parar de escrever , Digite 2!" << endl; 
        // variavel do switch case
        int write;
        cin >> write;    
        switch(write){
            case 0: {
                // criar objeto manga
                // Variaveis para o manga
                Manga manga;
                string nome_manga;
                int capitulo;
                cout << "Digite o nome do Manga" << endl;
                cin >> nome_manga;
                cout << "Digite o capitulo que tu parou" << endl;
                cin >> capitulo;
                manga.name = nome_manga;
                manga.chapter = capitulo;
                manga.Escreve_manga(nome_arquivo);

                break;
            }
            case 1:{
                // criar objeto anime
                // variaveis para o anime
                Anime anime;
                string nome_anime;
                int temporada;
                int episodio;
                cout << "Digite o nome do Anime " << endl;
                cin >> nome_anime;
                cout << "Digite em qual temporada tu parou" << endl;
                cin >> temporada;
                cout << "Digite em qual episodio tu parou " << endl;
                cin >> episodio;
                anime.name = nome_anime;
                anime.Temp = temporada;
                anime.episode = episodio;
                anime.Escreve_anime(nome_arquivo);
                break;
            }
            case 2 :{
                // encerra o looping
                still = false;
                break;
            }
            default:
                // o user digitou nenhuma das opções dadas 
                cout << "Opcao invalida , por favor tente novamente !" << endl;
                break;
        }


    }


    return 0;
}

// OJETIVOS :
// Terminar a classe;
// Testar se escreve no arquivo
// Salvar no git
// Percorrer o arquivo para atualizações
// Testar e salvar
// Looping de escrever
// Testar e salvar
// Anime temporada
// Dá erro quando é usado espaço

// Dá para só usar touper para testar?