#pragma once

#include <array>

// 重複しない3つの数字を作成
void CreateNumber(std::array<int, 3>& number);

// プレイヤーの入力
void PlayerInput(std::array<int, 3>& guess);

// CPUの入力（Hitした場所は保持）
void CpuInput(std::array<int, 3>& guess, std::array<bool, 3>& hit);

// Hit判定（プレイヤー用）
int CheckHit(const std::array<int, 3>& answer, const std::array<int, 3>& guess);

// CPU専用Hit判定
int CpuCheckHit(const std::array<int, 3>& answer,
    std::array<int, 3>& guess,
    std::array<bool, 3>& hit);

// 配列表示
void ShowNumber(const std::array<int, 3>& number);

// ゲーム
void Game();