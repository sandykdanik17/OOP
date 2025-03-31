#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;


int countBits(unsigned short x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

void encrypt() {
    const int numLines = 8, lineLength = 8;
    string lines[numLines];

    
    ofstream clearFile("encrypted.bin", ios::trunc);
    clearFile.close();

    ofstream outFile("encrypted.bin", ios::binary);
    if (!outFile) { cerr << "Помилка відкриття файлу!" << endl; return; }

    cout << "Введіть 8 рядків тексту (до 8 символів):\n";
    for (int i = 0; i < numLines; i++) {
        getline(cin, lines[i]);
        lines[i].resize(lineLength, ' '); // Доповнення пробілами

        for (int j = 0; j < lineLength; j++) {
            unsigned short value = (i & 0x07) |
                ((lines[i][j] & 0x0F) << 3) |
                (((countBits((i & 0x07) | ((lines[i][j] & 0x0F) << 3)) % 2) ? 1 : 0) << 7) |
                (((lines[i][j] >> 4) & 0x0F) << 8) |
                ((j & 0x07) << 12);

            if (countBits(value & 0x7FFF) % 2) value |= (1 << 15);
            outFile.write(reinterpret_cast<const char*>(&value), sizeof(value));
        }
    }
    cout << "Шифрування завершено :)" << endl;
}

void decrypt() {
    const int numLines = 8, lineLength = 8;
    char decrypted[numLines][lineLength + 1] = {};
    ifstream inFile("encrypted.bin", ios::binary);
    if (!inFile) { cerr << "Помилка відкриття" << endl; return; }

    for (int i = 0; i < numLines * lineLength; i++) {
        unsigned short value;
        inFile.read(reinterpret_cast<char*>(&value), sizeof(value));
        int row = value & 0x07;
        int ascii_low = (value >> 3) & 0x0F;
        int ascii_high = (value >> 8) & 0x0F;
        int pos = (value >> 12) & 0x07;
        decrypted[row][pos] = static_cast<char>((ascii_high << 4) | ascii_low);
    }

    cout << "Розшифрований текст:\n";
    for (int i = 0; i < numLines; i++) cout << decrypted[i] << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    cout << "1 - Шифрування\n2 - Розшифрування\nВиберіть: ";
    cin >> choice; cin.ignore();
    choice == 1 ? encrypt() : decrypt();
    return 0;
}