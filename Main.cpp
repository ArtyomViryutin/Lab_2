
#include "Header.h" // Подключаем заголовочный файл


int main()
{
	setlocale(LC_ALL, "Russian"); 
	system("chcp 1251");
	system("cls");
	

	int N = 1, M = 1; // Переменный для выбора количества объектов для сортировки и действия(оператор выбора switch)
	double StartTime, EndTime; // Переменные определяющие длительность сортировки
	Teachers *ForBubbleSorting = NULL, *ForQuickSorting = NULL; // Указатели типа Teachers для создания массивов объектов для дальнейшей сортировки
	// Создание структурированной базы данных и при неуданом открытии файла с начальными данными InitialData.csv выход
	/*if (CreateDataBase() == -1)
		M = 0;*/

	while (M != 0) { // Пока M не 0
		cout << "Выберите действие:\n" << "1 - Сравнение времени сортировки пузырьком и быстрой сортировки\n" << "2 - Сортировка пузырьком и создание нового файла с отсортированными данными\n" << "3 - Быстрая сортировка и создание нового файла с отсортированными данными\n" << "0 - Выход\n" << "Ваш выбор: ";
		M = InputM(); // Ввод M для выбора действия
		switch (M) {
		case 1:
			while (1) { // Бесконечный цикл
				cout << "Введите количество объктов для сортировки (от 1 до 6000) или 0, чтобы закончить сравнение: ";
				N = InputN(); // Ввод количества объектов для сортировки
				if (N == 0) // Если N равна 0 выходим из бесконечного цикла
					break;
				ForBubbleSorting = new Teachers[N]; // Выделяем память для массива сортировки пузырьком
				ForQuickSorting = new Teachers[N]; // Выделяем память для массива быстрой сортировки
				ClassInitialization(ForBubbleSorting, N); // Инициализируем массив объектов для сортировки пузырьком данными из файла DataBase.csv
				ClassInitialization(ForQuickSorting, N); // Инициализируем массив объектов для быстрой сортировки данными из файла DataBase.csv
				StartTime = clock(); // В переменную StartTime записываем время, пройденное с начала запуска прогрыммы
				BubbleSorting(ForBubbleSorting, N); // Сортируем массив пузырьком
				EndTime = clock(); // В переменную EndTime записываем время, вройденное с начала запуска программы
				cout << "Результат сортировки пузырьком: " << (EndTime - StartTime) / CLK_TCK << " секунд" << endl; // Вывод разность EndTime и StartTime для определения дительности сортировки и делим на макрос CLK_TCK для получения секунд
				StartTime = clock(); // В переменную StartTime записываем время, пройденное с начала запуска прогрыммы
				QuickSorting(ForQuickSorting, 0, N - 1); // Сортируем массив быстрой сортировкой
				EndTime = clock();// В переменную EndTime записываем время, вройденное с начала запуска программы
				cout << "Результат быстрой сортировки : " << (EndTime - StartTime) / CLK_TCK << " сеукунд" << endl; // Вывод разность EndTime и StartTime для определения дительности сортировки и делим на макрос CLK_TCK для получения секунд
			}
			break; // Окончание выполнение кейса
		case 2: // Следующие строки были описаны в case 1
			cout << "Введите количество объктов для сортировки и записи(от 1 до 6000): ";
			N = InputN(); 
			ForBubbleSorting = new Teachers[N];  
			ClassInitialization(ForBubbleSorting, N); 
			StartTime = clock();
			BubbleSorting(ForBubbleSorting, N);
			EndTime = clock();
			cout << "Результат быстрой сортировки : " << (EndTime - StartTime) / CLK_TCK << " сеукунд" << endl;
			CreateNewFile(ForBubbleSorting, N); // Создание нового файла с отсортированными данными
			break; 
		case 3: // Следующие строки были описаны в case 1
			cout << "Введите количество объктов для сортировки и записи(от 1 до 6000): ";
			N = InputN();
			ForQuickSorting = new Teachers[N];
			ClassInitialization(ForQuickSorting, N);
			StartTime = clock();
			QuickSorting(ForQuickSorting, 0, N - 1);
			EndTime = clock();
			cout << "Результат быстрой сортировки : " << (EndTime - StartTime) / CLK_TCK << " сеукунд" << endl;
			CreateNewFile(ForQuickSorting, N); // Создание нового файла с отсортированными данными
			break;

		case 0:
			break; // Выход из оператора выбора
		}
	}

	delete[] ForBubbleSorting; // Очистка массивов
	delete[] ForQuickSorting;
	system("pause");
	return 0;
}
