# 🚀 wingui.dll

[![Platform](https://img.shields.io/badge/platform-Windows-blue.aspx)](https://en.wikipedia.org/wiki/Microsoft_Windows)
[![Language](https://img.shields.io/badge/language-C%20%2F%20Win32%20API-orange.aspx)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/license-MIT-green.aspx)](https://opensource.org/licenses/MIT)

**wingui.dll** — это супер-легковесная графическая библиотека, написанная на чистом **Win32 API (C)**. Она создана специально для того, чтобы стать графическим движком для кастомных интерпретаторов (например, axis языка программирования) или для использования в минималистичных C/C++ приложениях без тяжелых фреймворков.

---

## ✨ Главные фичи

* 🪟 **Менеджер окон** - поддержка до 16 одновременно открытых окон.
* 🖱️ **Нативные контролы** - простое добавление кнопок (`BUTTON`), полей ввода (`EDIT`) и текстовых меток (`STATIC`).
* 🎨 **Двойная буферизация (Canvas)** - рисование на холсте происходит в скрытом буфере памяти (`off-screen buffer`), что полностью убирает мерцание экрана.
* 🔄 **Очередь событий** - встроенный кольцевой буфер на 256 событий (клики, нажатия клавиш, таймеры, закрытие окон).
* 📁 **Системные диалоги** - готовые обертки для MessageBox и проводника Windows (выбор/сохранение файлов).
* 💬 **коментарии** - внимание исходный код содержит коментарии которые сделала ИИ , я добавил их что бы сам код был более ЧИТАЕМЫЙ 
---

## 🛠 Быстрый старт (Пример на C)

Минимальный код для создания окна размером `800x600` с заголовком **"ut"**:

```c
#include "wingui.h"

int main() {
    // 1. Создаем и показываем окно
    int win_id = gui_create_window("ut", 800, 600);
    gui_show_window(win_id);

    char event_data[256];

    // 2. Главный цикл обработки событий
    while (gui_is_open(win_id)) {
        int event_type = gui_poll_event(win_id, event_data, sizeof(event_data));
        
        // Тип события 3 — это клик на системный крестик окна
        if (event_type == 3) {
            gui_close_window(win_id);
            break;
        }
        
        gui_sleep(10); // Разгружаем процессор
    }

    return 0;
}

