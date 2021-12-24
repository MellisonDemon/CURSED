#include <iostream>
#include <iomanip>
#include <chrono>
#include <Windows.h>
using namespace std;
using namespace chrono;

void printing(float * ptr, int n)
{
	for (int a = 1; a < n * n + 1; a++)
	{
		cout << *(ptr + a - 1) << " ";
		if (a % n == 0) { cout << endl; }
	}
	cout << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int switcher;
	while (true)
	{
		cout << "Выберите лабораторную работу:" << endl << "1. Типы данных и их внутреннее представление в памяти" << endl << "2. Одномерные статические массивы" << endl << "3. Указатели" << endl << "4. Текстовые строки" << endl;
		cin >> switcher;
		switch (switcher)
		{
			case 1:
			{
				cout << "int -- " << sizeof(int) << endl;
				cout << "short int -- " << sizeof(short int) << endl;
				cout << "long int -- " << sizeof(long int) << endl;
				cout << "float -- " << sizeof(float) << endl;
				cout << "double -- " << sizeof(double) << endl;
				cout << "long double -- " << sizeof(long double) << endl;
				cout << "char -- " << sizeof(char) << endl;
				cout << "bool -- " << sizeof(bool) << endl;

				//--------------------------------------------//

				unsigned int bytes = 4;
				unsigned int amount = bytes * 8;
				unsigned int mask = 1 << (amount - 1);
				int value;

				//--------------------------------------------//

				cout << "Введите целое число: ";
				cin >> value;

				cout << "Побитовое представление: ";
				for (int i = 1; i <= amount; i++)
				{
					cout << ((value & mask) ? '1' : '0');
					value <<= 1;
					if (i == 1) { cout << ' '; }
				}
				cout << endl;

				//--------------------------------------------//

				union
				{
					int value;
					float number;
				} Float;

				cout << "Введите число float: ";
				cin >> Float.number;

				cout << "Побитовое представление: ";
				for (int i = 1; i <= amount; i++)
				{
					cout << ((Float.value & mask) ? '1' : '0');
					Float.value <<= 1;
					if (i == 9 || i == 1) { cout << ' '; }
				}
			}
			cout << endl;
			break;
			case 2:
			{
				system_clock::time_point start;
				system_clock::time_point end;
				duration<double> sec;
				bool firstFlag = false, secondFlag = false;
				int action;

				cout << "Выберите пункт, который хотите выполнить:" << endl << "1. Создать массив" << endl << "2. Отсортировать массив" << endl << "3. Найти максимальный и минимальный элемент массива" << endl << "4. Вывести среднее значение минимального и максимального элемента массива" << endl << "5. Вывести количество элементов, меньших чем число А" << endl << "6. Вывести количество элементов, большмх чем чисто В" << endl << "7. Поменять местами элементы массива" << endl << "0. Выход из работы" << endl;

				while (true)
				{
					cin >> action;

					switch (action) {
					case(1):
						//------1. СОЗДАНИЕ МАССИВА------//	
						//------1. СОЗДАНИЕ МАССИВА------//	
						int arr[100], agg[100], pause;
						for (int i = 0; i < 100; i++)
						{
							arr[i] = (rand() % 199) - 99;
							agg[i] = arr[i];
						}
						cout << "Ваш массив для работы: ";
						for (int i = 0; i < 100; i++)
						{
							cout << arr[i] << " ";
						}
						cout << endl;
						firstFlag = true;
						secondFlag = false;
						break;
					case(2):
						if (firstFlag == true)
						{
							//------2. СОРТИРОВКА МАССИВА------//
							int sort;
							cout << "Выберите номер способа, которым хотите отсортировать массив:" << endl << "1. Пузырьковая сортировка" << endl << "2. Шейкер-сортировка" << endl << "3. Сортировка расчёской" << endl << "4. Сортировка вставками" << endl;
							cin >> sort;
							switch (sort) {
							case(1):
								start = system_clock::now();
								for (int i = 0; i < 100; i++) {
									for (int j = 1; j < (100 - i); j++)
									{
										if (arr[j - 1] > arr[j])
										{
											swap(arr[j - 1], arr[j]);
										}
									}
								}
								end = system_clock::now();
								break;
							case(2):
								start = system_clock::now();
								for (int i = 0; i < 50; i++)
								{
									for (int j = 1; j < (100 - i); j++)
									{
										if (arr[j - 1] > arr[j])
										{
											swap(arr[j - 1], arr[j]);
										}
									}
									for (int k = 100 - 1; k > i; k--)
									{
										if (arr[k] < arr[k - 1])
										{
											swap(arr[k - 1], arr[k]);
										}
									}
								}
								end = system_clock::now();
								break;
							case(3):
								start = system_clock::now();
								for (int k = 100 - 1; k > 0; k = int(k / 1.2))
								{
									for (int j = k; j < 100; j++)
									{
										if (arr[j] < arr[j - k])
										{
											swap(arr[j], arr[j - k]);
										}
									}
								}
								end = system_clock::now();
								break;
							case(4):
								int n;
								start = system_clock::now();
								for (int i = 1; i < 100; i++)
								{
									n = arr[i];
									for (int j = i - 1; j >= 0; j--)
									{
										if (n < arr[j])
										{
											swap(arr[j], arr[j + 1]);
										}

									}
								}
								end = system_clock::now();
								break;
							default: cout << "Ошибка. Введи номер заново." << endl;
							}
							sec = end - start;
							cout << "Время сортировки: " << sec.count() << endl;
							secondFlag = true;
							cout << "Ваш отсортированный массив: ";
							for (int i = 0; i < 100; i++)
							{
								cout << arr[i] << " ";
							}
							cout << endl;
						}
						else { cout << "Выполните пункт 1 чтобы продолжить" << endl; }
						break;
					case(3):
						if (firstFlag == true && secondFlag == true)
						{
							//------3. MAX & MIN------//
							int minimum = 100, maximum = -100, mi, ma;
							start = system_clock::now();
							arr[0];
							end = system_clock::now();
							sec = end - start;
							cout << "время поиска минимального элемента в отсортиванном массиве: " << sec.count() << endl;
							start = system_clock::now();
							arr[99];
							end = system_clock::now();
							sec = end - start;
							cout << "время поиска максимального элемента в отсортиванном массиве: " << sec.count() << endl;
							start = system_clock::now();
							for (int i = 0; i < 100; i++)
							{
								if (agg[i] > maximum)
								{
									maximum = agg[i];
								}
							}
							end = system_clock::now();
							sec = end - start;
							cout << "время поиска максимального элемента в неотсортиванном массиве: " << sec.count() << endl;
							start = system_clock::now();
							for (int i = 0; i < 100; i++)
							{
								if (agg[i] < minimum)
								{
									minimum = agg[i];
								}
							}
							end = system_clock::now();
							sec = end - start;
							cout << "время поиска минимального элемента в неотсортиванном массиве: " << sec.count() << endl;
						}
						else
						{
							if (firstFlag == false) { cout << "Выполните пункт 1 чтобы продолжить" << endl; }
							if (secondFlag == false) { cout << "Выполните пункт 2 чтобы продолжить" << endl; }
						}
						break;
					case(4):
						if (firstFlag == true && secondFlag == true)
						{
							//------4. СРЕДНЕЕ ЗНАЧЕНИЕ------//
							int average, countAverage = 0, maxim = arr[99], minim = arr[0];
							average = (maxim + minim) / 2;
							cout << "индексы элементов, соответствующие среднему значению максимального и минимального значения: ";
							for (int i = 0; i < 100; i++)
							{
								if (agg[i] == average)
								{
									cout << i << " ";
									countAverage += 1;
								}
							}
							cout << endl << "количество элементов, соответствующие среднему значению максимального и минимального значения: " << countAverage << endl;
						}
						else
						{
							if (firstFlag == false) { cout << "Выполните пункт 1 чтобы продолжить" << endl; }
							if (secondFlag == false) { cout << "Выполните пункт 2 чтобы продолжить" << endl; }
						}
						break;
					case(5):
						if (firstFlag == true && secondFlag == true)
						{
							//------5. МЕНЬШЕ А------//
							{int a, pointA = 100;
							cout << "введитете значение a: ";
							cin >> a;
							for (int i = 0; i < 100; i++)
							{
								if (arr[i] > a)
								{
									pointA = i;
									break;
								}
							}
							cout << "количество элементов, которые меньше числа a: " << pointA << endl; }
						}
						else
						{
							if (firstFlag == false) { cout << "Выполните пункт 1 чтобы продолжить" << endl; }
							if (secondFlag == false) { cout << "Выполните пункт 2 чтобы продолжить" << endl; }
						}
						break;
					case(6):
						if (firstFlag == true && secondFlag == true)
						{
							//------6. БОЛЬШЕ B------//
							int b, pointB = 100;
							cout << "введитете значение b: ";
							cin >> b;
							for (int i = 0; i < 100; i++)
							{
								if (arr[i] > b)
								{
									pointB = i;
									break;
								}
							}
							cout << "количество элементов, которые больше числа b: " << 100 - pointB << endl;
						}
						else
						{
							if (firstFlag == false) { cout << "Выполните пункт 1 чтобы продолжить" << endl; }
							if (secondFlag == false) { cout << "Выполните пункт 2 чтобы продолжить" << endl; }
						}
						break;
					case(7):
						if (firstFlag == true && secondFlag == true)
						{
							//------7. ОБМЕН ЗНАЧЕНИЯМИ------//
							int changeOne, changeTwo, changer, arg[100];
							for (int i = 0; i < 100; i++)
							{
								arg[i] = arr[i];
							}
							cout << "введитете индексы элементов: ";
							cin >> changeOne >> changeTwo;
							start = system_clock::now();
							changer = arr[changeOne];
							arr[changeOne] = arr[changeTwo];
							arr[changeTwo] = changer;
							end = system_clock::now();
							sec = end - start;
							cout << "время перестановки элементов: " << sec.count() << endl;
						}
						else
						{
							if (firstFlag == false) { cout << "Выполните пункт 1 чтобы продолжить" << endl; }
							if (secondFlag == false) { cout << "Выполните пункт 2 чтобы продолжить" << endl; }
						}
						break;
					case(0): goto escape; break;
					default:
						//------ОШИБКА------//
						cout << "Ошибка ввода. Повторите попытку." << endl;
						break;
					}
				}
			}
			escape:
			break;
			case 3: 
			{
				int n, pom, numb = 11;

				while (true)
				{
					cout << "Введите какого размера создать массив (6, 8, 10): ";
					cin >> n;
					if (n != 6 && n != 8 && n != 10) { cout << "Ошибка. Повторите ввод." << endl; }
					else { break; }
				}

				float ** arr = new float *[n];
				for (int i = 0; i < n; i++)
				{
					arr[i] = new float[n];
				}

				float * ptr = &arr[0][0];

				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						arr[i][j] = 0;
					}
				}

				int choise;
				cout << "Выберите вид заполнения массива:" << endl << "1. Улитка" << endl << "2. Змейка" << endl;
				while (true)
				{
					cin >> choise;
					switch (choise)
					{
					case (1):
					{
						//----ЗАПОЛНЕНИЕ УЛИТКОЙ----//
						for (int i = 0; i < n / 2; i++)
						{
							//----1 ВИД СТРОК-----//

							for (int j = 0 + i; j < (n - 1 - i); j++)
							{
								*(ptr + j + i * n) = (rand() % 100);
							}
							printing(ptr, n);

							//----2 ВИД СТРОК-----//

							pom = -1;
							for (int k = i; k < n - i - 1; k++)
							{
								pom += 1;
								*(ptr + (n - 1) * (i + 1) + n * pom) = (rand() % 100);
							}
							printing(ptr, n);

							//----3 ВИД СТРОК-----//

							for (int l = 0 + i; l < n - 1 - i; l++)
							{
								*(ptr + (n * n - 1) - l - n * i) = (rand() % 100);
							}
							printing(ptr, n);

							//----4 ВИД СТРОК-----//

							for (int m = n - i - 1; m > i; m--)
							{
								*(ptr + i + m * n) = (rand() % 100);
							}
							printing(ptr, n);
						}
						break;
					}

					case(2):
					{
						//----ЗАПОЛНЕНИЕ ЗМЕЙКОЙ----//
						{
							for (int i = 0; i < n; i++)
							{
								if (i % 2 == 0)
								{
									for (int j = 0; j < n; j++)
									{
										*(ptr + i + j * n) = (rand() % 100);
									}

									printing(ptr, n);
								}

								else
								{
									for (int m = n - 1; m > -1; m--)
									{
										*(ptr + i + m * n) = (rand() % 100);
									}

									printing(ptr, n);
								}
							}
						}
						break;
					}

					default:
					{
						cout << "Ошибка. Повторите ввод.";
						break;
					}

					}
					if (choise == 1 || choise == 2)
					{
						choise = 0;
						break;
					}
				}

				cout << endl << "Выберите вид перестановки элементов:" << endl << "1. По часовой стрелке" << endl << "2. Крест-накрест" << endl << "3. По вертикали" << endl << "4. По горизонтали" << endl;
				while (true)
				{
					cin >> choise;
					switch (choise)
					{
					case(1):
					{
						//----ПЕРЕСТАНОВКА A----//
						for (int i = 0; i < n / 2; i++)
						{
							for (int j = 0; j < n / 2; j++)
							{
								swap(*(ptr + j + i * n), *(ptr + j + i * n + (n / 2)));
								swap(*(ptr + j + i * n), *(ptr + j + i * n + (n / 2) + (n / 2) * n));
								swap(*(ptr + j + i * n), *(ptr + j + i * n + (n / 2) * n));
							}
						}
						printing(ptr, n);
						break;
					}


					case(2):
					{
						//----ПЕРЕСТАНОВКА B----//
						for (int i = 0; i < n / 2; i++)
						{
							for (int j = 0; j < n / 2; j++)
							{
								swap(*(ptr + j + i * n), *(ptr + j + i * n + (n / 2) + (n / 2) * n));
								swap(*(ptr + j + i * n + (n / 2) * n), *(ptr + j + i * n + (n / 2)));
							}
						}
						printing(ptr, n);
						break;
					}

					case(3):
					{
						//----ПЕРЕСТАНОВКА С----//
						for (int i = 0; i < n / 2; i++)
						{
							for (int j = 0; j < n / 2; j++)
							{
								swap(*(ptr + j + i * n), *(ptr + j + i * n + n * (n / 2)));
								swap(*(ptr + j + i * n + n / 2), *(ptr + j + i * n + n * (n / 2) + n / 2));
							}
						}
						printing(ptr, n);
						break;
					}

					case(4):
					{
						//----ПЕРЕСТАНОВКА D----//
						for (int i = 0; i < n / 2; i++)
						{
							for (int j = 0; j < n / 2; j++)
							{
								swap(*(ptr + i * n + j), *(ptr + i * n + j + n / 2));
								swap(*(ptr + i * n + j + n * (n / 2)), *(ptr + i * 10 + j + n / 2 + n * (n / 2)));
							}
						}
						printing(ptr, n);
						break;
					}

					default:
					{
						cout << "Ошибка. Повторите ввод.";
						break;
					}
					}
					if (choise == 1 || choise == 2 || choise == 3 || choise == 4)
					{
						choise = 0;
						break;
					}
				}

				cout << endl << "Отсортированный массив (сортировка пузырьком):" << endl;

				//----СОРТИРОВКА БАБЛ----//
				{
					for (int i = 0; i < n * n; i++) {
						for (int j = 1; j < (n * n - i); j++)
						{
							if (*(ptr + i) > *(ptr + i + j)) { swap(*(ptr + i), *(ptr + i + j)); }
						}
					}
					cout << endl;
					printing(ptr, n);
				}

				cout << endl << "Выберите действие над массивом:" << endl << "1. Увеличение(+)" << endl << "2. Уменьшение (-)" << endl << "3. Умножение (*)" << endl << "4. Деление (/)" << endl;
				float helper;
				while (true)
				{
					cin >> choise;
					switch (choise)
					{
					case(1):
					{
						cout << "Введите число, на которое хотите увеличить элементы массива: ";
						cin >> helper;
						for (int a = 0; a < n * n; a++)
						{
							*(ptr + a) = float(*(ptr + a)) + helper;
						}
						printing(ptr, n);
						break;
					}

					case(2):
					{
						cout << "Введите число, на которое хотите уменьшить элементы массива: ";
						cin >> helper;
						for (int a = 0; a < n * n; a++)
						{
							*(ptr + a) = float(*(ptr + a)) - helper;
						}
						printing(ptr, n);
						break;
					}

					case(3):
					{
						cout << "Введите число, во сколько раз вы хотите увеличить элементы массива: ";
						cin >> helper;
						for (int a = 0; a < n * n; a++)
						{
							*(ptr + a) = float(*(ptr + a)) * helper;
						}
						printing(ptr, n);
						break;
					}

					case(4):
					{
						cout << "Введите число, во сколько раз вы хотите уменьшить элементы массива: ";
						cin >> helper;
						for (int a = 0; a < n * n; a++)
						{
							*(ptr + a) = float(*(ptr + a)) / helper;
						}
						printing(ptr, n);
						break;
					}

					default:
					{
						cout << "Ошибка. Повторите ввод.";
						break;
					}
					}
					if (choise == 1 || choise == 2 || choise == 3 || choise == 4)
					{
						choise = 0;
						break;
					}
				}

				for (int i = 0; i < n; i++)
				{
					delete[] arr[i];
				}
				delete[] arr;
			}
			break;
			case 4:
			{
				//===1 ВВОД ТЕКСТА==//
				char helpp[10];
				cout << endl;
				cin.getline(helpp, 10, '\n');
				char text[1000];
				int punct[11] = { 33, 34, 39, 40, 41, 44, 45, 59, 59, 63, 96 };
				cout << "Введите текст: ";
				cin.getline(text, 1000, '\n');
				if (int(text[strlen(text) - 1]) != 46)
				{
					cout << "Ошибка. Перезапустите программу и поставьте точку в конце строки." << endl;
				}
				else
				{
					cout << "Текст для работы: ";
					for (int i = 0; i < strlen(text); i++)
					{
						cout << text[i];
					}
					cout << endl;

					//===2 ПРАВКА ТЕКСТА==//

					//2.1 лишние пробелы.
					for (int i = 0; i < strlen(text); i++)
					{
						if (int(text[i]) == 32)
						{
							while (text[i] == text[i + 1])
							{
								for (int j = i + 1; j < strlen(text); j++)
								{
									text[j] = text[j + 1];
								}
							}
						}
					}
					cout << "Текст без лишних пробелов: ";
					for (int i = 0; i < strlen(text); i++)
					{
						cout << text[i];
					}
					cout << endl;

					//2.2 лишние знаки.
					for (int i = 0; i < strlen(text); i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (int(text[i]) == punct[j])
							{
								while (int(text[i]) == int(text[i + 1]))
								{
									for (int k = i + 1; k < strlen(text); k++)
									{
										text[k] = text[k + 1];
									}
								}
							}
						}
					}

					for (int i = 0; i < strlen(text); i++)
					{
						if (int(text[i]) == 46)
						{
							if (int(text[i]) == int(text[i + 1]) && int(text[i]) == int(text[i + 2]))
							{
								i += 3;
							}
							else
							{
								if (int(text[i]) == int(text[i + 1]))
								{
									for (int l = i + 1; l < strlen(text); l++)
									{
										text[l] = text[l + 1];
									}
								}
							}
						}
					}

					for (int i = 0; i < strlen(text); i++)
					{
						if (int(text[i]) == 46)
						{
							if (int(text[i]) == int(text[i + 1]) && int(text[i]) == int(text[i + 2]) && int(text[i]) == int(text[i + 3]))
							{
								while (int(text[i + 3]) != 32)
								{
									for (int l = i + 1; l < strlen(text); l++)
									{
										text[l] = text[l + 1];
									}
								}
							}
						}
					}
					cout << "Текст без лишних знаков препинания: ";
					for (int i = 0; i < strlen(text); i++)
					{
						cout << text[i];
					}
					cout << endl;

					//2.3 регистр.
					if (-33 < int(text[0]) && int(text[0]) < 0)
					{
						text[0] = char(int(text[0]) - 32);
					}

					for (int i = 1; i < strlen(text); i++)
					{
						if (int(text[i]) < -32)
						{
							text[i] = char(int(text[i]) + 32);
						}
					}

					for (int i = 2; i < strlen(text); i++)
					{
						if ((int(text[i - 2]) == 33 || int(text[i - 2]) == 63 || int(text[i - 2]) == 46) && (-33 < int(text[i])) && (int(text[i]) < 0))
						{
							text[i] = char(int(text[i]) - 32);
						}
					}
					cout << "Текст с исправленным регистром букв: ";
					for (int i = 0; i < strlen(text); i++)
					{
						cout << text[i];
					}
					cout << endl;

					//===3 ПОВОРОТ==//
					//(1) Вывести на экран слова последовательности в обратном порядке.
					int lengthWord = 0;

					cout << "Строка, с напечатанными в обратном порядке словами: ";
					for (int i = 0; i < strlen(text); i++)
					{
						if (int(text[i]) < 0 || (47 < int(text[i]) && int(text[i]) < 58))
						{
							lengthWord += 1;
						}
						else
						{
							if (lengthWord > 0)
							{
								for (int j = i - 1; j > i - lengthWord - 1; j--)
								{
									cout << text[j];
								}
							}
							cout << text[i];
							lengthWord = 0;
						}

					}
					cout << endl;

					//===4 СТРОЧНЫЕ БУКВЫ==//
					//(1)Вывести на экран ту же последовательность, заменив во всех словах первую букву соответствующей прописной буквой.

					cout << "Строка, каждое слово в которой начинается с большой буквы: ";
					cout << text[0];
					for (int i = 1; i < strlen(text); i++)
					{
						if (int(text[i - 1]) == 32 && int(text[i]) < 0 && -33 < int(text[i]))
						{
							cout << char(int(text[i]) - 32);
						}
						else
						{
							cout << text[i];
						}
					}
					cout << endl;


					//===5 ПОИСК ПОДСТРОКИ==//
					//(1)Вывести на экран ту же последовательность, заменив во всех словах первую букву соответствующей прописной буквой.
					char text1[1000];
					cout << "Введите подстроку, которую хотите найти: ";
					cin.getline(text1, 1000, '\n');

					cout << "Позиции текста, которые содержат введённую Вами подстроку (считая, что позиция первой буквы – 0): ";
					for (int i = strlen(text1) - 1; i < strlen(text); i++)
					{
						for (int j = strlen(text1) - 1; j > -1; j--)
						{
							for (int k = i; k > i - strlen(text1); k--)
							{
							repeat:
								if (int(text[k]) == int(text1[j]))
								{
									if (j == 0)
									{
										cout << k << " ";
									}
									else
									{
										k--;
										j--;
										goto repeat;
									}
								}
								else
								{
									goto skip;
								}
							}
						skip:
							break;
						}

					}
					cout << endl;
				}
			};
			break;
			default: cout << "Ошибка. Повторите ввод." << endl;
		}
	}
}

