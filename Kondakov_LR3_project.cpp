#include <iostream>
#include <map>
#include <functional>
#include <sstream>
#include <string>

using namespace std;

struct MenuItem {
    string title;
    function<void()> action;
};

// Удаление пробелов вначале и в конце (trim)
void trim(string& str) {
	// Удаляем пробелы с начала
	while (!str.empty() && str.front() == ' ')
		str.erase(str.begin());

	// Удаляем пробелы с конца
	while (!str.empty() && str.back() == ' ')
		str.pop_back();
}

// Проверка на пустой ввод для отмены операции
bool is_input_empty(string input) {
	if (input.empty()) {
		cout << endl << "[Отмена операции]";
		return true;
	}
	return false;
}

// Проверка конвертации в целое число
bool is_int(string input, int min, int max) {
	try {
		int number = stoi(input);
		if (number < min) { cout << endl << "Вы ввели \"" << number << "\" — значение должно быть не меньше \"" << min << "\"" << endl << endl; return false; }
		if (number > max) { cout << endl << "Вы ввели \"" << number << "\" — значение должно быть не больше \"" << max << "\"" << endl << endl; return false; }
	}
	catch (const invalid_argument&) {
        cerr << endl << "Введённое вами значение \"" << input << "\" не является числом!" << endl << endl;
        return false;
    }
    catch (const out_of_range&) {
        cerr << endl << "Число \"" << input << "\" выходит за допустимый диапазон!" << endl << endl;
        return false;
    }
    return true;
}

// Проверка конвертации в вещественное число
bool is_float(string input, int min, int max) {
	try {
		float number = stof(input);
		if (number < min) { cout << endl << "Вы ввели \"" << number << "\" — значение должно быть не меньше \"" << min << "\"" << endl << endl; return false; }
		if (number > max) { cout << endl << "Вы ввели \"" << number << "\" — значение должно быть не больше \"" << max << "\"" << endl << endl; return false; }
	}
    catch (const invalid_argument&) {
        cerr << endl << "Введённое вами значение \"" << input << "\" не является числом!" << endl << endl;
        return false;
    }
    catch (const out_of_range&) {
        cerr << endl << "Число \"" << input << "\" выходит за допустимый диапазон!" << endl << endl;
        return false;
    }
	return true;
}

// Вспомогательная функция для ввода целых чисел
void enter_number(int& varLink, bool& escapeLink, const string& label, int min = 0, int max = 2147483647) {
	string raw_input;

	do {
		cout << label;
		getline(cin, raw_input);
		trim(raw_input);
		escapeLink = is_input_empty(raw_input);
		if (escapeLink) return;
	} while (!is_int(raw_input, min, max));

	varLink = stoi(raw_input);
}

// Перегрузка функции для типа float
void enter_float(float& varLink, bool& escapeLink, const string& label, int min = 0, int max = 2147483647) {
	string raw_input;

	do {
		cout << label;
		getline(cin, raw_input);
		trim(raw_input);
		escapeLink = is_input_empty(raw_input);
		if (escapeLink) return;
	} while (!is_float(raw_input, min, max));

	varLink = stof(raw_input);
}

// Вспомогательная функция для ввода строк
void enter_string(string& varLink, bool& escapeLink, string label) {
	string raw_input;

	cout << label;
	getline(cin, raw_input);
	trim(raw_input);
	escapeLink = is_input_empty(raw_input);
	if (!escapeLink)
		varLink = raw_input;
}

// Вычисление объёма параллелепипеда
function<void()> v_parallelepiped() {
    return []() {
        // разрабатывает Иван И.И. — ветка branch_fun_1
    };
}

// Произведение цифр четырёхзначного числа
function<void()> quad_nums_product() {
    return []() {
        // разрабатывает Пётр П.П. — ветка branch_fun_2
    };
}

// Наибольшее из трёх чисел
function<void()> max_of_3() {
    return []() {
        // разрабатывает Сидор С.С. — ветка branch_fun_3
    };
}

// Существование треугольника
function<void()> triangle_exists() {
    return []() {
        // разрабатывает Олег О.О. — ветка branch_fun_4
    };
}

// Текстовая трансляция цифры
function<void()> itos() {
    return []() {
        // разрабатывает Михаил М.М. — ветка branch_fun_5
    };
}

// Поиск дробной части
float find_fraction(float f) {
    if (f < 0) f *= -1;
    return f - static_cast<int>(f);
}

// Найти дробную часть суммы 3-х чисел
function<void()> fractional_part_of_sum_3() {
    return []() {
        // разрабатывает Сергей С.С. — ветка branch_fun_6
    };
}

// Округлить до ближайшего целого сумму 3-х чисел
function<void()> round_sum_3() {
    return []() {
        // разрабатывает Алина А.А. — ветка branch_fun_7
    };
}

void show_menu(const map<int, MenuItem>& menu) {
    for (const auto& item : menu)
        cout << item.first << ". " << item.second.title << endl;
    cout << "0. Выход." << endl << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    map<int, MenuItem> menu {
        { 1, { "Вычисление объёма параллелепипеда;", v_parallelepiped() } },
        { 2, { "Произведение цифр четырёхзначного числа;", quad_nums_product() } },
        { 3, { "Наибольшее из трёх чисел;", max_of_3() } },
        { 4, { "Существование треугольника;", triangle_exists() } },
        { 5, { "Текстовая трансляция цифры;", itos() } },
        { 6, { "Нахождение дробной части суммы трёх чисел;", fractional_part_of_sum_3() } },
        { 7, { "Округлениие до ближайшего целого суммы трёх чисел;", round_sum_3() } }
    };

    int choice;
    bool escape = false;
    while (true) {
        show_menu(menu);

        enter_number(choice, escape, "Введите номер пункта: ");
        cout << endl << endl;
    
        if (!escape) {
            if (choice == 0) {
                cout << "© 2025 Fedor Kondakov" << endl;
                break;
            }
    
            if (menu.find(choice) != menu.end()) {
                menu[choice].action();
            }
            else {
                cout << "Некорректный ввод!";
            }
        }
        escape = false;
        cout << endl << endl << endl;
    }

    return 0;
}