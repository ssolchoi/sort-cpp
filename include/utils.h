#pragma once

constexpr int kNumColors = 32;

// 추적 유지 시간을 늘려서 ID 안정성 향상
constexpr int kMaxCoastCycles = 15;  // 객체가 검출되지 않아도 n프레임까지 추적을 유지

// 추적 시작 조건을 완화
constexpr int kMinHits = 1;  // n번 연속 검출되어야 추적 시작

// Set threshold to 0 to accept all detections
constexpr float kMinConfidence = 0.2;  // Detection의 신뢰도가 0.n 이상이어야 추적에 사용