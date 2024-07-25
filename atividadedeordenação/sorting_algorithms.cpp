#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>  
#include <sstream>  
#include <cstdlib>  
#include <string>   

using namespace std;
using namespace std::chrono;

void selectionSort(vector<int>& vetor) {
    int n = vetor.size();
    for (int i = 0; i < n - 1; ++i) {
        int indiceMinimo = i;
        for (int j = i + 1; j < n; ++j) {
            if (vetor[j] < vetor[indiceMinimo]) {
                indiceMinimo = j;
            }
        }
        swap(vetor[i], vetor[indiceMinimo]);
    }
}

void insertionSort(vector<int>& vetor) {
    int n = vetor.size();
    for (int i = 1; i < n; ++i) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            --j;
        }
        vetor[j + 1] = chave;
    }
}

void imprimeVetor(const vector<int>& vetor) {
    for (int numero : vetor) {
        cout << numero << " ";
    }
    cout << endl;
}

vector<int> lerValoresDoArquivo(const string& nomeArquivo) {
    vector<int> vetor;
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        exit(EXIT_FAILURE);
    }

    string linha;
    while (getline(arquivo, linha)) {
        istringstream iss(linha);
        int valor;
        while (iss >> valor) {
            vetor.push_back(valor);
        }
    }

    arquivo.close();
    return vetor;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo de entrada>" << endl;
        return 1;
    }

    string nomeArquivo = argv[1];
    vector<int> vetor = lerValoresDoArquivo(nomeArquivo);
    vector<int> Vetor2 = vetor;

    cout<<"---------- Tempo Gasto ----------"<<endl;

    auto inicio = high_resolution_clock::now();
    selectionSort(vetor);
    auto fim = high_resolution_clock::now();
    auto duracao = duration_cast<microseconds>(fim - inicio).count();
    cout << "Selection Sort: " << duracao << " microsegundos" << endl;

    
    inicio = high_resolution_clock::now();
    insertionSort(Vetor2);
    fim = high_resolution_clock::now();
    duracao = duration_cast<microseconds>(fim - inicio).count();

    cout << "Insertion Sort: " << duracao << " microsegundos" << endl;




    
   



    return 0;
}
