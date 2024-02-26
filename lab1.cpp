#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для проверки правильности ответа пользователя
bool isValidResponse(const string& response) {
    string r = response;
    transform(r.begin(), r.end(), r.begin(), ::tolower); // Преобразование ответа к нижнему регистру
    return (r == "yes" || r == "ye" || r == "y" || r == "no" || r == "n");
}

int main() {
    ifstream inputFile("questions.txt"); // Файл с вопросами
    ofstream outputFile("answers.txt");  // Файл с ответами

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Не удалось открыть файлы." << endl;
        return 1;
    }

    vector<string> questions;
    string question;

    // Чтение вопросов из файла
    while (getline(inputFile, question)) {
        questions.push_back(question);
    }

    // Задание вопросов и запись ответов в файл
    for (const string& q : questions) {
        string response;
        do {
            cout << q << " (yes/ye/y or no/n): ";
            cin >> response;
            if (!isValidResponse(response)) {
                cout << "Please, enter yes/ye/y or no/n." << endl;
            }
        } while (!isValidResponse(response));

        // Запись ответа в файл
        outputFile << response << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Responses are written to a file 'answers.txt'." << endl;

    return 0;
}
