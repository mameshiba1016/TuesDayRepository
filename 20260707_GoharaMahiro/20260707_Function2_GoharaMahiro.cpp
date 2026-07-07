#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include "20260707_Header2_GoharaMahiro.h"

// 重複しない3つの数字を作成
void CreateNumber(std::array<int, 3>& number)
{
    bool used[10] = { false };

    for (int i = 0; i < 3; i++)
    {
        int n;

        do
        {
            n = rand() % 10;
        } while (used[n]);

        used[n] = true;
        number[i] = n;
    }
}

// プレイヤー入力
void PlayerInput(std::array<int, 3>& guess)
{
    std::cout << "\n数字を3つ入力してください。\n";

    for (int i = 0; i < 3; i++)
    {
        std::cout << i + 1 << "個目：";
        std::cin >> guess[i];
    }
}

// CPU入力（Hitした場所はそのまま）
void CpuInput(std::array<int, 3>& guess, std::array<bool, 3>& hit)
{
    for (int i = 0; i < 3; i++)
    {
        if (!hit[i])
        {
            guess[i] = rand() % 10;
        }
    }

    std::cout << "CPUの予想：";
    ShowNumber(guess);
}

// プレイヤー用Hit判定
int CheckHit(const std::array<int, 3>& answer, const std::array<int, 3>& guess)
{
    int hit = 0;

    for (int i = 0; i < 3; i++)
    {
        if (answer[i] == guess[i])
        {
            std::cout << "Hit ";
            hit++;
        }
        else
        {
            std::cout << "Miss ";
        }
    }

    std::cout << std::endl;

    return hit;
}

// CPU専用Hit判定
int CpuCheckHit(const std::array<int, 3>& answer,
    std::array<int, 3>& guess,
    std::array<bool, 3>& hit)
{
    int hitCount = 0;

    for (int i = 0; i < 3; i++)
    {
        if (answer[i] == guess[i])
        {
            std::cout << "Hit ";
            hit[i] = true;      // Hitした場所を記憶
            hitCount++;
        }
        else
        {
            std::cout << "Miss ";
        }
    }

    std::cout << std::endl;

    return hitCount;
}

// 配列表示
void ShowNumber(const std::array<int, 3>& number)
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << number[i] << " ";
    }

   std:: cout << std::endl;
}

// ゲーム
void Game()
{
    std::array<int, 3> playerNumber;
    std::array<int, 3> cpuNumber;
    std::array<int, 3> playerGuess;
    std::array<int, 3> cpuGuess = { 0, 0, 0 };

    // CPUがHitした場所を記憶
    std::array<bool, 3> hit = { false, false, false };

    CreateNumber(playerNumber);
    CreateNumber(cpuNumber);

    while (true)
    {
        // プレイヤーのターン
        std::cout << "\n--- プレイヤーのターン ---" << std::endl;
        PlayerInput(playerGuess);

        if (CheckHit(cpuNumber, playerGuess) == 3)
        {
            std::cout << "\nプレイヤーの勝利！" << std::endl;
            break;
        }

        // CPUのターン
        std::cout << "\n--- CPUのターン ---" << std::endl;
        CpuInput(cpuGuess, hit);

        if (CpuCheckHit(playerNumber, cpuGuess, hit) == 3)
        {
            std::cout << "\nCPUの勝利！" << std::endl;
            break;
        }
    }
}
