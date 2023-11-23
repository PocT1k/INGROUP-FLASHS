#include <iostream>
#include <fstream>
#include <Windows.h>
#include <filesystem>
#include <conio.h>

using namespace std;


bool FormatDrive(const TCHAR* driveLetter) {
    // Собираем команду форматирования
    std::wstring formatCommand = L"format ";
    formatCommand += driveLetter;
    formatCommand += L": /FS:exFAT /Q /V: /Y";  // Добавляем ключ /V: для указания метки тома и ключ /Y для подтверждения

    // Запускаем команду форматирования
    int result = _wsystem(formatCommand.c_str());

    return result == 0; // 0 означает успешное выполнение команды
}

bool CopyVideoToFlashDrive(const TCHAR* sourcePath, const TCHAR* flashDrivePath) {
    std::wcout << std::endl << L"Начало копирования видеофайла." << std::endl;
    if (CopyFile(sourcePath, flashDrivePath, FALSE)) {
        return true;
    }
    return false;
}


int main() {
    setlocale(LC_ALL, "RU");
    int key = true;

    if (key = _getch());
    while (key) {
        // Указываем букву диска, которую вы хотите использовать для флешки
        TCHAR driveLetter[] = L"H";

        // Форматируем флешку
        if (FormatDrive(driveLetter)) {
            std::wcout << L"V Флешка успешно отформатирована." << std::endl;
        }
        else {
            std::wcerr << L"X Ошибка форматирования флешки." << std::endl;
            key = _getch();
            system("CLS");
            continue;
        }


        // Указываем путь к флешке (букву диска)
        TCHAR flashDrivePath[] = L"H:\\video.mp4";
        // Указываем путь к видеофайлу
        TCHAR sourcePath[] = L"F:\\Backups and saves\\INGROUP\\forWrite\\Af_2111\\Argon.mp4";

        // Копируем видеофайл на флешку
        if (CopyVideoToFlashDrive(sourcePath, flashDrivePath)) {
            std::wcout << L"V Видеофайл успешно скопирован на флешку." << std::endl;
        }
        else {
            std::wcerr << L"X Ошибка копирования видеофайла на флешку.\a\7" << std::endl;
        }

        MessageBeep(MB_ICONINFORMATION);
        if (key = _getch());
        system("CLS");
    }

    return 0;
}
