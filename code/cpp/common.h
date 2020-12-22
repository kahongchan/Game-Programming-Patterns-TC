#pragma once

// 讓變量表現得像是在使用中
// 這樣我們不會因爲未使用變量而獲得警告。
// 把警告用於捕獲真正疏忽沒有使用的變量。
template <class T>
void use(const T& obj) {
  // 啥也不做
}

#define ASSERT(condition) \
    if (!(condition)) \
    { \
      std::cout << "FAIL: " #condition << "\n" << __FILE__ \
                << ":" << __LINE__ << std::endl; \
      abort(); \
    }

void assert(bool condition) {
  if (!condition) {
    printf("WTF\n");
    exit(1);
  }
}
