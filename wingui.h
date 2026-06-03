#pragma once
#ifdef WINGUI_EXPORTS
#define WINGUI_API __declspec(dllexport)
#else
#define WINGUI_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

// === ОКНО ===
WINGUI_API int  gui_create_window(const char* title, int width, int height);
WINGUI_API void gui_show_window(int win_id);
WINGUI_API void gui_close_window(int win_id);
WINGUI_API int  gui_is_open(int win_id);
WINGUI_API void gui_set_title(int win_id, const char* title);
WINGUI_API void gui_set_bg_color(int win_id, int r, int g, int b);

// === ОБРАБОТКА СОБЫТИЙ ===
// Возвращает тип события: 0=нет, 1=клик, 2=клавиша, 3=закрытие, 4=таймер
WINGUI_API int  gui_poll_event(int win_id, char* out_data, int data_size);
WINGUI_API void gui_set_timer(int win_id, int ms);

// === КНОПКИ ===
WINGUI_API int  gui_add_button(int win_id, const char* text, int x, int y, int w, int h);
WINGUI_API void gui_set_button_text(int win_id, int ctrl_id, const char* text);
WINGUI_API void gui_enable_control(int win_id, int ctrl_id, int enabled);

// === ТЕКСТОВЫЕ ПОЛЯ ===
WINGUI_API int  gui_add_label(int win_id, const char* text, int x, int y, int w, int h);
WINGUI_API int  gui_add_input(int win_id, const char* placeholder, int x, int y, int w, int h);
WINGUI_API void gui_set_text(int win_id, int ctrl_id, const char* text);
WINGUI_API void gui_get_text(int win_id, int ctrl_id, char* out, int out_size);

// === CANVAS / РИСОВАНИЕ ===
// Все draw-функции буферизованы, применяются после gui_canvas_flush
WINGUI_API int  gui_add_canvas(int win_id, int x, int y, int w, int h);
WINGUI_API void gui_canvas_clear(int win_id, int ctrl_id, int r, int g, int b);
WINGUI_API void gui_canvas_line(int win_id, int ctrl_id, int x1, int y1, int x2, int y2, int r, int g, int b, int thick);
WINGUI_API void gui_canvas_rect(int win_id, int ctrl_id, int x, int y, int w, int h, int r, int g, int b, int fill);
WINGUI_API void gui_canvas_circle(int win_id, int ctrl_id, int cx, int cy, int radius, int r, int g, int b, int fill);
WINGUI_API void gui_canvas_text(int win_id, int ctrl_id, const char* text, int x, int y, int r, int g, int b, int font_size);
WINGUI_API void gui_canvas_flush(int win_id, int ctrl_id);

// === ДИАЛОГИ ===
WINGUI_API int  gui_msgbox(const char* title, const char* text, int type); // type: 0=OK, 1=OKCancel, 2=YesNo
WINGUI_API int  gui_input_dialog(const char* title, const char* prompt, char* out, int out_size);
WINGUI_API int  gui_open_file_dialog(char* out_path, int out_size, const char* filter);
WINGUI_API int  gui_save_file_dialog(char* out_path, int out_size, const char* filter);

// === УТИЛИТЫ ===
WINGUI_API void gui_sleep(int ms);
WINGUI_API void gui_process_messages();  // не блокирующая прокачка сообщений

#ifdef __cplusplus
}
#endif
