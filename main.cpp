#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

const double pi = 3.141592653589;

int randint(int l = -10, int h = 10)
{
	// случайное целое число в диапазоне [l, h]
	if (l > h)
	{
		int temp = h;
		h = l;
		l = temp;
	}
	return l + rand() % (h - l + 1);
}

double uniform(double l = -10.0, double h = 10.0)
{
	// случайное число c плавающей точкой в диапазоне [l, h]
	if (l > h)
	{
		double temp = h;
		h = l;
		l = temp;
	}
	double t = (double)rand() / RAND_MAX;
	return l + t * (h - l);
}

template <typename Num>
Num** allocateAPlaceFor2DArray(unsigned int sizeA, unsigned int sizeB)
{
	// выделение памяти под двухмерный массив
	Num** array = new Num * [sizeA];
	for (int i = 0; i < sizeA; i++)
		array[i] = new Num[sizeB];
	return array;
}

int** allocateAPlaceFor2DArrayRandom(unsigned int sizeA, unsigned int sizeB, int min = -10, int max = 10)
{
	// выделение памяти под двухмерный массив и заполнение его случайными значениями
	int** array = allocateAPlaceFor2DArray<int>(sizeA, sizeB);
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			array[i][j] = randint(min, max);
	return array;
}

double** allocateAPlaceFor2DArrayRandom(unsigned int sizeA, unsigned int sizeB, double min = -10.0, double max = 10.0)
{
	// выделение памяти под двухмерный массив и заполнение его случайными значениями
	double** array = allocateAPlaceFor2DArray<double>(sizeA, sizeB);
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			array[i][j] = uniform(min, max);
	return array;
}

template <typename Num>
Num* allocateAPlaceFor1DArray(unsigned int size)
{
	// выделение памяти под одномерный массив
	Num* array = new Num[size];
	return array;
}

int* allocateAPlaceFor1DArrayRandom(unsigned int size, int min = -10, int max = 10)
{
	// выделение памяти под одномерный массив и заполнение его случайными значениями
	int* array = new int[size];
	for (int i = 0; i < size; i++)
		array[i] = randint(min, max);
	return array;
}

double* allocateAPlaceFor1DArrayRandom(unsigned int size, double min = -10.0, double max = 10.0)
{
	// выделение памяти под одномерный массив и заполнение его случайными значениями
	double* array = new double[size];
	for (int i = 0; i < size; i++)
		array[i] = uniform(min, max);
	return array;
}

template <typename Num>
void delete2DArray(Num** array, unsigned int size)
{
	// высвобождение памяти занятой под двухмерный массив
	if (array)
	{
		for (int i = 0; i < size; i++)
			delete[] array[i];
		delete[] array;
	}
}

template <typename Num>
void print2DArray(Num** array, unsigned int sizeA, unsigned int sizeB)
{
	// вывод в консоль двухмерного массива в формате матрицы
	if (array)
	{
		for (int i = 0; i < sizeA; i++)
		{
			for (int j = 0; j < sizeB; j++)
				cout << array[i][j] << "  ";
			cout << endl;
		}
	}
}

template <typename Num>
void print1DArray(Num* array, unsigned int size)
{
	// вывод в консоль одномерного массива
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

template <typename Num>
Num** transpose2DArray(Num** array, unsigned int sizeA, unsigned int sizeB)
{
	// транспонирование двухмерного массива
	Num** newArray = allocateAPlaceFor2DArray<Num>(sizeB, sizeA);
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			newArray[j][i] = array[i][j];
	return newArray;
}

template <typename Num>
Num sumOfSquares2DArray(Num** array, unsigned int size_i, unsigned int size_j)
{
	// сумма квадратов двухмерного массива поэлементно
	Num sum = 0;
	for (int i = 0; i < size_i; i++)
		for (int j = 0; j < size_j; j++)
			sum += pow(array[i][j], 2);
	return sum;
}

template <typename Num>
Num sumOfSquaresOf1DArray(Num* array, unsigned int size)
{
	// сумма квадратов одномерного массива поэлементно
	Num sum = 0;
	for (int i = 0; i < size; i++)
		sum += pow(array[i], 2);
	return sum;
}

template <typename Num>
Num sumOfPairwiseProductsOfArrays(Num* array1, Num* array2, unsigned int size)
{
	// сумма произведений пар двух одномерных массивов
	Num sum = 0;
	for (int i = 0; i < size; i++)
		sum += (array1[i] * array2[i]);
	return sum;
}

template <typename Num>
Num** rotateClockwise2DArray(Num** array, unsigned int size)
{
	// поворот двухмерного массива 1 раз по часовой стрелке
	Num** newArray = allocateAPlaceFor2DArray<Num>(size, size);
	for (int j = 0; j < size; j++)
		for (int i = 0; i < size; i++)
			newArray[i][size - 1 - j] = array[j][i];
	return newArray;
}

template <typename Num>
Num traceOf2DArray(Num** array, unsigned int size)
{
	// След двухмерного массива
	Num sum = 0;
	for (int i = 0, j = 0; i < size; i++, j++)
		sum += array[i][j];
	return sum;
}

template <typename Num>
Num minElementOf1DArray(Num* array, unsigned int size)
{
	// поиск минимального элемента одномерного массива
	Num min = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] < min)
			min = array[i];
	}
	return min;
}

template <typename Num>
Num maxElementOf1DArray(Num* array, unsigned int size)
{
	// поиск максимального элемента одномерного массива
	Num max = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

template <typename Num>
int getThePositionOfTheFirstEntry(Num* array, unsigned int size, Num element)
{
	// позиция первого вхождения элемента в одномерном массиве
	for (int i = 0; i < size; i++)
		if (array[i] == element)
			return i;
}

template <typename Num>
void makePermutationsRightFor1DArray(Num* array, unsigned int size, int countPermutations)
{
	// циклическая перестановка элементов одномерного массива вправо на заданное количество элементов
	int castRange = countPermutations % size;
	for (int i = size - castRange, j = 0; i < size; i++, j++)
	{
		Num temp1 = array[j];
		array[j] = array[i];
		for (int k = 1; k <= size - castRange; k++)
		{
			Num temp2 = array[j + k];
			array[j + k] = temp1;
			temp1 = temp2;
		}
	}
}

template <typename Num>
void makePermutationsRightLeftFor1DArray(Num* array, unsigned int size, int countPermutations)
{
	// приведение циклической перестановки влево countPermutations < 0 к общему виду
	if (size > 0)
	{
		if (countPermutations < 0)
		{
			countPermutations *= -1;
			countPermutations = size - countPermutations;
		}
		makePermutationsRightFor1DArray<Num>(array, size, countPermutations);
	}
}

void filling2DArrayByRows(int** array, unsigned int size_i, unsigned int size_j)
{
	// заполнение двумерного массива натуральными числами по строкам
	int numb = 1;
	for (int i = 0; i < size_i; i++)
		for (int j = 0; j < size_j; j++)
			array[i][j] = numb++;
}

void filling2DArrayByColumns(int** array, unsigned int size_i, unsigned int size_j)
{
	// заполнение двумерного массива натуральными числами по столбцам
	int numb = 1;
	for (int j = 0; j < size_j; j++)
		for (int i = 0; i < size_i; i++)
			array[i][j] = numb++;
}

template <typename Num>
void filling2DArray(Num** array, unsigned int size_i, unsigned int size_j, Num numb)
{
	// Заполнение двумерного массива заданным числовым значением
	for (int i = 0; i < size_i; i++)
		for (int j = 0; j < size_j; j++)
			array[i][j] = numb;
}

template <typename Num>
void fillingMainAndSideDiagonalsOf2DArray(Num** array, unsigned int size, Num numb)
{
	// Заполнение главной и побочной диагоналей двумерного массива заданным числовым значением
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		array[i][j] = numb;
		array[i][size - 1 - j] = numb;
	}
}

void reverseArray(char* array)
{
	// реверс строкового массива 
	for (int i = 0; i < strlen(array) / 2; i++)
	{
		char temp = array[i];
		array[i] = array[strlen(array) - 1 - i];
		array[strlen(array) - 1 - i] = temp;
	}
}

bool isPosibleMultiplicationMatrix(unsigned int sizeJArray1, unsigned int sizeIArray2)
{
	/* проверка возможно ли произведение двух матриц
	   sizeJArray1 - количество столбцов двумерного массива первой матрицы (первый сомножитель)
	   sizeIArray2 - количество строк двумерного массива второй матрицы (второй сомножитель) */
	return sizeJArray1 == sizeIArray2;
}

template <typename Num>
void Multiplication2DArrays(Num** array1, unsigned int sizeIArray1, unsigned int sizeJArray1, Num** array2, unsigned int sizeIArray2, unsigned int sizeJArray2)
{
	Num** arrayMul = 0;
	if (isPosibleMultiplicationMatrix(sizeJArray1, sizeIArray2))
	{
		arrayMul = allocateAPlaceFor2DArray<Num>(sizeIArray1, sizeJArray2);
		for (int i = 0; i < sizeIArray1; i++)
		{
			for (int j = 0; j < sizeJArray2; j++)
			{
				Num sum = 0;
				for (int k = 0; k < sizeJArray1; k++)
					sum += array1[i][k] * array2[k][j];
				arrayMul[i][j] = sum;
			}
		}
	}
	else
		cout << "Произведение двух массивов невозможно." << endl;
	print2DArray<Num>(arrayMul, sizeIArray1, sizeJArray2);
	delete2DArray<Num>(arrayMul, sizeIArray1);
}

void lower(string& str)
{
	// приведение строки к нижнему регистру
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'a' + (str[i] - 'A');
	}
}

void print(string text)
{
	cout << text;
}

void printLine(string text)
{
	cout << text << endl;
}

int inputInt(string text)
{
	// ввод целочисленного значения
	print(text);
	int result;
	cin >> result;
	return result;
}

unsigned int inputUInt(string text)
{
	// ввод целочисленного беззнакового значения >= 0
	int result = inputInt(text);
	if (result >= 0)
		return result;
	printLine("Введенное значение должно быть положительным числом >= 0. Введите корректное значение.");
	return inputUInt(text);
}

string inputString(string text)
{
	// ввод строки
	string result;
	print(text);
	cin >> result;
	return result;
}

string inputMinOrMax(string text)
{
	// ввод данных min или max
	string sampleMinMax = inputString(text);
	lower(sampleMinMax);
	if (sampleMinMax == "min" || sampleMinMax == "max")
		return sampleMinMax;
	printLine("Допустимые данные min или max. Введите корректные данные.");
	return inputMinOrMax(text);
}

string inputRowOrColumn(string text)
{
	// ввод данных row или column
	string sampleRowColumn = inputString(text);
	lower(sampleRowColumn);
	if (sampleRowColumn == "row" || sampleRowColumn == "column")
		return sampleRowColumn;
	printLine("Допустимые данные row или column. Введите корректные данные.");
	return inputRowOrColumn(text);
}

template <typename Num>
void updateIfGreate(Num** array, unsigned int indexI, unsigned int indexJ, Num& max)
{
	// обновление максимального элемента
	if (array[indexI][indexJ] > max)
		max = array[indexI][indexJ];
}

template <typename Num>
void updateIfLess(Num** array, unsigned int indexI, unsigned int indexJ, Num& min)
{
	// обновление минимального элемента
	if (array[indexI][indexJ] < min)
		min = array[indexI][indexJ];
}

template <typename Num>
int minMax(Num** array, unsigned int size, unsigned int Index, string rowColumn = "row", string minMax = "min")
{
	// нахождение максимального/минимального значения в строке/столбце двумерного массива в зависимости от входных данных
	if (rowColumn == "row" && minMax == "min")
	{
		Num min = array[Index][0];
		for (int j = 1; j < size; j++)
			updateIfLess<Num>(array, Index, j, min);
		return min;
	}
	if (rowColumn == "row" && minMax == "max")
	{
		Num max = array[Index][0];
		for (int j = 1; j < size; j++)
			updateIfGreate<Num>(array, Index, j, max);
		return max;
	}
	if (rowColumn == "column" && minMax == "min")
	{
		Num min = array[0][Index];
		for (int i = 1; i < size; i++)
			updateIfLess<Num>(array, i, Index, min);
		return min;
	}
	else
	{
		Num max = array[0][Index];
		for (int i = 1; i < size; i++)
			updateIfGreate<Num>(array, i, Index, max);
		return max;
	}
}

template <typename Num>
Num* minMaxRowColumn2DArray(Num** array, unsigned int size, unsigned int sizeOther, string sampleRowColumn, string sampleMinMax)
{
	// заполнение одномерного массива минимальными или максимальными значениями по строкам или столбцам двумерного массива
	Num* arrayResult = allocateAPlaceFor1DArray<Num>(size);
	for (int i = 0; i < size; i++)
		arrayResult[i] = minMax<Num>(array, sizeOther, i, sampleRowColumn, sampleMinMax);
	return arrayResult;
}

template <typename Num>
Num* resize1DArray(Num* oldArray, unsigned int size)
{
	// перевыделение памяти под одномерный массив с последующим копированием данных и освобождением памяти
	Num* newArray = allocateAPlaceFor1DArray<Num>(size);
	for (int i = 0; i < size - 1; i++)
		newArray[i] = oldArray[i];
	delete[] oldArray;
	return newArray;
}

pair <int, int*> countWordsAndWordLengthInCharArray(char* array)
{
	/* подсчет количества слов и длинны каждого слова в символьном массиве
	   Результатом будет являться пара: размер массива длинн слов (количество слов) и указатель на массив длин слов */

	string word = "";
	int p = 0;
	pair <int, int*> countWordsAndWordLength = { 0, allocateAPlaceFor1DArray<int>(1) };
	for (int i = 0; i < strlen(array); i++)
		if (array[i] != ' ')
			word.push_back(array[i]);
		else
			if (word != "")
			{
				countWordsAndWordLength.second[p++] = word.size();
				countWordsAndWordLength.second = resize1DArray<int>(countWordsAndWordLength.second, p + 1);
				countWordsAndWordLength.first++;
				word.clear();
			}
	if (word != "")
	{
		countWordsAndWordLength.first++;
		countWordsAndWordLength.second[p] = word.size();
	}
	return countWordsAndWordLength;
}

void symmetricalFilling1DArray(int* array, unsigned int size, int startNumber = 1)
{
	// симметричное заполнение одномерного массива
	for (int i = 0; i < size / 2 + size % 2; i++)
	{
		array[i] = startNumber;
		array[size - 1 - i] = startNumber++;
	}
}

template <typename Num>
Num min(Num a, Num b)
{
	// минимальное из двух чисел
	if (a < b)
		return a;
	return b;
}

template <typename Num>
Num max(Num a, Num b)
{
	// максимальное из двух чисел
	if (a > b)
		return a;
	return b;
}

template <typename Num>
void concat1DArrays(Num* array1, unsigned int sizeArray1, Num* array2, unsigned int sizeArray2, Num* arrayConcat)
{
	// добавление массива1 и массива2 в массив 3
	int j = 0;
	for (int i = 0; i < sizeArray1; i++)
		arrayConcat[j++] = array1[i];
	for (int i = 0; i < sizeArray2; i++)
		arrayConcat[j++] = array2[i];
}

template <typename Num>
void concat1DArrays(Num* array1, Num* array2, unsigned int size, Num* arrayConcat)
{
	/* объединение массива1 и массива2 в третий массив
	   Объединение происходит по одному элементу из первого массива затем второго и так далее */
	for (int i = 0, j = 0; i < size; i++)
	{
		arrayConcat[j++] = array1[i];
		arrayConcat[j++] = array2[i];
	}
}

template <typename Num>
void minor2DArray(Num** array, unsigned int size_i, unsigned int size_j, Num** minor2DArray, unsigned int row, unsigned int column)
{
	// нахождение минора двумерного массива
	int iNew = 0, jNew = 0, count = 0;
	for (int i = 0; i < size_i; i++)
	{
		for (int j = 0; j < size_j; j++)
		{
			if (i != row && j != column)
			{
				count++;
				minor2DArray[iNew][jNew++] = array[i][j];
				if (count == size_j - 1)
				{
					iNew++;
					jNew = 0;
					count = 0;
				}
			}
		}
	}
}

int inputIntInRange(string text, int lRange, int hRange)
{
	// ввод данных в диапазоне [lRange, hRange]
	if (lRange > hRange)
	{
		int temp = lRange;
		lRange = hRange;
		hRange = temp;
	}
	int result;
	while (1)
	{
		result = inputInt(text);
		if (result >= lRange && result <= hRange)
			return result;
		cout << "Введенное значение должно принадлежать промежутку [" << lRange << ", " << hRange << "]. Введите корректное значение." << endl;
	}
}

void adaptation(int& sizeA, int& sizeB)
{
	// адаптер для задания 60
	if (sizeA < 0 || sizeB < 0)
	{
		sizeA = 0;
		sizeB = 0;
	}
}

double inputDouble(string text)
{
	// ввод числа с плавающей точкой
	print(text);
	double result;
	cin >> result;
	return result;
}

double inputUDouble(string text)
{
	// ввод беззнакового числа с плавающей точкой >= 0
	double result = inputDouble(text);
	if (result >= 0)
		return result;
	printLine("Введенное число должно быть >= 0. Введите корректные данные.");
	return inputUDouble(text);
}

double inputDoubleInRange(string text, double lRange, double hRange)
{
	// ввод числа с плавающей точкой в диапазоне [lRange, hRange]
	if (lRange > hRange)
	{
		int temp = lRange;
		lRange = hRange;
		hRange = temp;
	}
	double result;
	while (1)
	{
		result = inputDouble(text);
		if (result >= lRange && result <= hRange)
			return result;
		cout << "Введенное значение должно принадлежать промежутку [" << lRange << ", " << hRange << "]. Введите корректное значение." << endl;
	}
}

void printNumbersInRange(unsigned int range)
{
	// вывод n-натуральных чисел
	cout << "Все натуральные числа в этом дипазоне:" << endl;
	printLine("Все натуральные числа в этом дипазоне:");
	int i = 1;
	while (i <= range)
		cout << i++ << " ";
}

void printOddNumbersInRange(unsigned int count)
{
	// вывод n-нечетных натуральных чисел
	cout << "Вывод " << count << " нечетных чисел: " << endl;
	int i = 1;
	while (count)
	{
		cout << i << " ";
		i += 2;
		count--;
	}
}

void printResiduesNumbers(unsigned int count)
{
	// вывод n-чисел, которые при делении на 4 дают остаток 3
	cout << "Вывод " << count << " чисел, которые при делении на 4 дают остаток 3" << endl;
	int i = 0;
	while (count)
	{
		cout << 4 * i++ + 3 << " ";
		count--;
	}
}

void printFibNumbers(unsigned int count)
{
	// вывод n-чисел из последовательности Фибоначчи
	cout << "Вывод последовательности из " << count << " чисел Фибоначчи" << endl;
	int array[2] = { 0, 1 };
	while (count)
	{
		cout << array[1] << " ";
		int temp = array[1];
		array[1] = array[0] + array[1];
		array[0] = temp;
		count--;
	}
}

void printBinomialKoeff(int n)
{
	// вывод n-биномиальных коэффициентов
	if (n < 1)
		return;
	int i = 0, k = 1;
	cout << k << " ";
	while (i < n)
	{
		int koeff = k * (n - i) / (i + 1);
		cout << koeff << " ";
		k = koeff;
		i++;
	}
}

double convertKmToMilesPart1(double km)
{
	// перевод из километров в мили
	double miles;
	const double kmInMile = 1.609344;
	miles = km / kmInMile;
	return miles;
}

void convertKmToMilesPart2(int km, int m)
{
	// перевод из км и м в мили и футы и вывод результатов
	const int mInKm = 1000;
	const double kmInMile = 1.609344;
	double dKm = km + (double)m / mInKm;
	double dMiles = dKm / kmInMile;
	int miles = (int)dMiles;
	const int ftInMile = 5280;
	int ft = (int)((dMiles - miles) * ftInMile);
	cout << "Расстояние в милях: " << miles << endl;
	cout << "Расстояние в футах: " << ft << endl;
}

double convertSaghToMetrPart1(double saghen)
{
	// перевод из саженей в метры
	const double metrInSagh = 2.16;
	double metr = saghen * metrInSagh;
	return metr;
}

void convertSaghToMetrPart2(unsigned int saghen, unsigned int arshin)
{
	// перевод из саженей и аршинов в метры и сантиметры и вывод результатов
	const double metrInSagh = 2.16;
	const int arshinInSagh = 3;
	double dSaghen = saghen + (double)arshin / arshinInSagh;
	double dMetr = dSaghen * metrInSagh;
	int metr, santimetr;
	metr = (int)dMetr;
	const int smInMetr = 100;
	santimetr = (int)((dMetr - metr) * smInMetr);
	cout << "Вывод расстояний в метрах и сантиметрах: " << endl;
	cout << "Метры: " << metr << endl;
	cout << "Сантиметры: " << santimetr << endl;
}

double convertVelocityValuePart1(double velocityInput)
{
	// перевод из км/ч в м/с
	const int metrInKm = 1000;
	const int secInHour = 3600;
	double velocityOutput = velocityInput * (double)metrInKm / secInHour;
	return velocityOutput;
}

double convertVelocityValuePart2(double velocityInput)
{
	// перевод из м/с в км/ч
	const int metrInKm = 1000;
	const int secInHour = 3600;
	double velocityOutput = velocityInput / metrInKm * secInHour;
	return velocityOutput;
}

int sumOfNaturalNumbers(unsigned int range)
{
	// сумма натуральных чисел от [1 до range]
	int sum = 0;
	while (range)
		sum += range--;
	return sum;
}

int sumOfOddNaturalNumbers(unsigned int range)
{
	// сумма n-количества нечетных чисел
	int i = 1, sumOdd = 0, count = 0;
	while (count++ < range)
	{
		sumOdd += i;
		i += 2;
	}
	return sumOdd;
}

void filling1DArrayWithStepTwoNumbers(int* arrayStepTwoNumbers, const int size, unsigned int count)
{
	// заполнение одномерного массива числами степеней двойки
	int castRange = count;
	if (size < count)
		castRange = size;
	const int numb = 2;
	int i = 0;
	while (i < castRange)
		arrayStepTwoNumbers[i++] = pow(numb, i);
}

void filling1DArrayWithFibonachiNumbers(int* arrayFibonachiNumbers, const int size, unsigned int count)
{
	// заполнение массива числами Фибоначчи
	int castRange = count;
	if (size < count)
		castRange = size;
	int i = 0, preNumb = 0, currentNumb = 1;
	while (i < castRange)
	{
		arrayFibonachiNumbers[i++] = currentNumb;
		int temp = currentNumb;
		currentNumb += preNumb;
		preNumb = temp;
	}
}

void filling1DArrayWithSquareNumbers(int* arraySquaresNumbers, const int size, unsigned int count)
{
	// заполнение одномерного массива квадратами натуральных чисел
	int castRange = count;
	if (size < count)
		castRange = size;
	int i = 0, numb = 1;
	while (i < castRange)
		arraySquaresNumbers[i++] = pow(numb++, 2);
}

void filling1DArrayOddNumbers(int* arrayOddNumbers, const int size, unsigned int count)
{
	// заполнение одномерного массива нечетными числами
	int castRange = count;
	if (size < count)
		castRange = size;
	int i = 0, oddNumber = 1;
	while (i < castRange)
	{
		arrayOddNumbers[i++] = oddNumber;
		oddNumber += 2;
	}
}

void filling1DArrayEvenNumbers(int* arrayEvenNumbers, const int size, unsigned int count)
{
	// заполнение одномерного массива четными числами
	int castRange = count;
	if (size < count)
		castRange = size;
	int i = 0, evenNumber = 0;
	while (i < count)
	{
		arrayEvenNumbers[i++] = evenNumber;
		evenNumber += 2;
	}
}

void filling1DArrayCustom(int* customArray, const int size, unsigned int count)
{
	// заполнение массива нечетными числами в степени 2 и четными числами
	int castRange = count;
	if (size < count)
		castRange = size;
	int i = 0;
	const int power = 2;
	while (i < castRange)
	{
		if (i % 2)
			customArray[i] = pow(i, power);
		else
			customArray[i] = i;
		i++;
	}
}

void filling1DArrayFromInput(int* myArray, const int size, unsigned int count)
{
	// заполнение одномерного массива через ввод из консоли
	int castRange = count;
	if (size < count)
		castRange = size;
	int i = 0;
	while (i < castRange)
	{
		cout << "Введите число №" << i + 1 << ": " << endl;
		cin >> myArray[i++];
	}
}

void filling1DArrayRandom(int* array, const unsigned int size, int limitA = -10, int limitB = 10)
{
	// заполнение одномерного массива случайными значениями
	for (int i = 0; i < size; i++)
		array[i] = randint(limitA, limitB);
}

int sumOddNaturalNumb(unsigned int count)
{
	// сумма n-количества нечетных натуральных чисел
	int sum = 0;
	for (int i = 0, numb = 1; i < count; i++, sum += numb, numb += 2);
	return sum;
}

int sumEvenNaturalNumb(unsigned int count)
{
	// сумма n-четных натуральных чисел
	int sum = 0, numb = 0, i = 0;
	do
	{
		sum += numb;
		numb += 2;
		i++;
	} while (i < count);
	return sum;
}

void printDivisionWithoutRemainder(int numb)
{
	// вывод всех чисел, на которые заданное число делится без остатка:
	if (numb < 0)
		numb = -numb;
	print("Числа, на которые заданное число делится без остатка: ");
	int range = numb / 2;
	for (int i = 1; i <= range; i++)
	{
		if (!(numb % i))
		{
			cout << i << " " << -i << " ";
		}
	}
	cout << numb << " " << -numb << endl;
}

int greatestCommonDivider(int a, int b)
{
	// наибольший общий делитель двух чисел
	int limit = a;
	if (a > b)
		limit = b;
	int max_divider = 1;
	for (int i = 2; i <= limit; i++)
	{
		if (a % i == 0 && b % i == 0)
			max_divider = i;
	}
	return max_divider;
}

double naturalLogarithm(double x)
{
	// расчет натурального логарифма по приближенной формуле
	x--;
	const int n = 100;
	double result = 0;
	int k = -1;
	for (int i = 1; i <= n; i++) {
		k *= -1;
		result += (k * (pow(x, i) / i));
	}
	return result;
}

int fact(unsigned int numb)
{
	// факториал числа
	if (numb)
		return numb * fact(numb - 1);
	return 1;
}

double sinus(double x)
{
	// вычисление синуса по приближенной формуле
	const int n = 10;
	double result = 0;
	int k = -1;
	for (int i = 0; i < n; i++) {
		k *= -1;
		result += (k * (pow(x, 2 * i + 1)) / fact(2 * i + 1));
	}
	return result;
}

double cosinus(double x)
{
	// вычисление косинуса по приближенной формуле
	const int n = 10;
	double result = 0;
	int k = -1;
	for (int i = 0; i < n; i++) {
		k *= -1;
		result += (k * (pow(x, 2 * i)) / fact(2 * i));
	}
	return result;
}

double hyperSinus(double x)
{
	// вычисление гиперболического синуса по приближенной формуле
	const int n = 10;
	double result = 0;
	for (int i = 0; i < n; i++) {
		result += (pow(x, 2 * i + 1) / fact(2 * i + 1));
	}
	return result;
}

double hypercosinus(double x)
{
	// вычисление гиперболического косинуса по приближенной формуле
	const int n = 10;
	double result = 0;
	for (int i = 0; i < n; i++) {
		result += (pow(x, 2 * i) / fact(2 * i));
	}
	return result;
}

double calcMyfanc(double x)
{
	// вычисление (exp(x) - 1) / x по приближенной формуле
	const int n = 10;
	double result = 0;
	for (int i = 0; i < n; i++) {
		result += (pow(x, i) / fact(i + 1));
	}
	return result;
}

void printEquationSolutionPart1(double a, double b)
{
	// Уравнение вида Ax = B;
	if (a)
		cout << "Решение уравнения: x = " << b / a << endl;
	else if (b)
		cout << "Решений нет" << endl;
	else
		cout << "Решение - любое число" << endl;
}

void printEquationsSolutionPart2(int a, int b)
{
	// Уравнение вида Ax = B. Решение целое число
	if (a)
		if (b % a == 0)
			cout << "Решение уравнения: x = " << b / a << endl;
		else
			cout << "Решений нет" << endl;
	else if (b)
		cout << "Решений нет" << endl;
	else
		cout << "Решение любое число" << endl;
}

void printAllSolutionsOfEquations(int limitA, int limitB)
{
	// Уравнение вида a ** 2 + b ** 2 = c ** 2. Все решения уравнения в пределах (limitA, limitB)
	double c;
	int count = 0;
	for (int i = 0; i < limitA; i++)
	{
		for (int j = 0; j < limitB; j++)
		{
			c = sqrt(pow(i, 2) + pow(j, 2));
			if ((int)c == c)
				cout << "Решение №" << ++count << " a = " << i << " b = " << j << " c = " << (int)c << endl;
		}
	}
}

void printSolutionOfQuadraticEquation(double a, double b, double c)
{
	// Уравнение вида a * x ** 2 + b * x + c = 0;
	int exodus;
	if (a == 0 && b == 0 && c == 0)
		exodus = 1;
	else if (a == 0 && b != 0 && c != 0)
		exodus = 4;
	else if (a != 0 && b == 0 && c == 0)
		exodus = 2;
	else if (a != 0 && (c != 0 || b != 0))
		exodus = 3;
	else if (a == 0 && b == 0 && c != 0)
		exodus = 5;
	else if (a == 0 && c == 0 && b != 0)
		exodus = 6;
	else
		exodus = 3;

	switch (exodus)
	{
	case 1:
		cout << "Любое число" << endl;
		break;
	case 2:
		cout << "x1 = " << 0 << endl;
		break;
	case 3:
	{
		double d = b * b - 4 * a * c;
		if (d > 0)
		{
			double x1, x2;
			x1 = (-b + sqrt(d)) / (2 * a);
			x2 = (-b - sqrt(d)) / (2 * a);
			cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
		}
		else if (d == 0)
			cout << "x1 = " << -b / 2 * a << endl;
		else
			cout << "Действительных корней нет ";
		break;
	}
	case 4:
		cout << "x1 = " << -c / b << endl;
		break;
	case 5:
		cout << "Нет корней" << endl;
		break;
	case 6:
		cout << "x1 = " << 0 << endl;
		break;
	}
}

int sumDvider(unsigned int x)
{
	// сумма всех натуральных делителей числа
	int sum = 0;
	int range = x / 2;
	sum += 1;
	for (int i = 2 + x % 2; i <= range; i++)
		if (x % i == 0)
			sum += i;
	sum += x;
	return sum;
}

bool isFibonacciNumber(int numb)
{
	// проверка на число Фибоначчи от 1 до 10
	switch (numb)
	{
	case 1:
	case 2:
	case 3:
	case 5:
	case 8:
		return true;
	default:
		return false;
	}
}

template <typename Num>
void swap(Num* array, int index)
{
	Num temp = array[index];
	array[index] = array[index + 1];
	array[index + 1] = temp;
}

template <typename Num>
void customSort1DArray(Num* array, const int size)
{
	// сортировка одномерного массива сначала нечетные по возрастанию затем четные по возрастанию
	int k = 1;
	while (k >= 0)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				Num x = array[j] % 2;
				Num y = array[j + 1] % 2;
				if ((x * x == k && y * y == k && array[j] > array[j + 1]) || (x == 0 && y))
					swap<Num>(array, j);
			}
		}
		k--;
	}
}

template <typename Num>
void customSort2DArrayV2(Num* array, const int size)
{
	// сортировка одномерного массива: сначала четные по убыванию затем нечетные по возрастанию
	int k = 2;
	bool flag = false;
	while (k)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (!flag)
				{
					if ((array[j] % 2 == 0 && array[j + 1] % 2 == 0 && array[j] < array[j + 1]) || (array[j] % 2 && array[j + 1] % 2 == 0))
						swap<Num>(array, j);
				}
				else
				{
					if (array[j] % 2 && array[j + 1] % 2 && array[j] > array[j + 1])
						swap<Num>(array, j);
				}
			}
		}
		flag = true;
		k--;
	}
}

template <typename Num>
void sortBubble1DArray(Num* array, const int size)
{
	// сортировка одномерного массива по убыванию
	for (int j = 0; j < size - 1; j++)
		for (int i = 0; i < size - 1; i++)
			if (array[i] < array[i + 1])
				swap<Num>(array, i);
}

template <typename Num>
void ReverseSort1DArray(Num* array, const int size)
{
	// сортировка одномерного массива по принципу первый - последний элемент, второй - предпоследний и т.д
	for (int i = 0; i < size / 2; i++)
	{
		Num temp = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = temp;
	}
}

int factV2(unsigned int number)
{
	// факториал числа
	int result = 1;
	for (int i = 2; i <= number; i++)
		result *= i;
	return result;
}

int doubleFact(unsigned int number)
{
	// двойной факториал числа
	if (number != 1 && number != 2)
		return number * doubleFact(number - 2);
	return number;
}

int doubleFactV2(unsigned int number)
{
	// двойной факториал числа
	int result = 1;
	for (int i = 2 + number % 2; i <= number; i += 2)
		result *= i;
	return result;
}

int getFibonacciNumber(unsigned int number, unsigned int penultimate = 0, unsigned int last = 1)
{
	// вывод числа Фибоначчи по номеру в последовательности 1, 1, 2, 3, 5 ...
	if (number > 1)
		return getFibonacciNumber(number - 1, last, last + penultimate);
	return last;
}

int getFibonacciNumberV2(unsigned int number)
{
	// вывод числа Фибоначчи по номеру в последовательности 1, 1, 2, 3, 5 ...
	int last = 1;
	for (int i = 1, penultimate = 0; i < number; i++)
	{
		int temp = penultimate;
		penultimate = last;
		last = temp + last;
	}
	return last;
}

double calcBinomialKoeff(unsigned int n, unsigned int k)
{
	// вычисление биномиального коэффициента
	return fact(n) / (fact(k) * fact(n - k));
}

int sumNaturalNumbers(unsigned int limit)
{
	// сумма всех натуральных чисел от 1 до limit
	if (limit > 1)
		return limit + sumNaturalNumbers(limit - 1);
	return limit;
}

double sumPowerNaturalNumbers(unsigned int limit, double power = 1)
{
	// сумма всех степеней натуральных чисел от 1 до limit
	if (limit > 1)
		return pow(limit, power) + sumPowerNaturalNumbers(limit - 1, power);
	return limit;
}

double expApproximately(double x, unsigned int countIterations)
{
	// нахождение экспоненты от x через ряд Тейлора (!!ряд сходится от -1 до 1)
	if (countIterations > 0)
		return expApproximately(x, countIterations - 1) + pow(x, countIterations) / fact(countIterations);
	return 1;
}

double overchargedFunction(double arg)
{
	// возврат значения
	return arg;
}

double overchargedFunction(double arg1, double arg2)
{
	// возврат суммы квадратов значений
	return arg1 * arg1 + arg2 * arg2;
}

double overchargedFunction(double arg1, double arg2, double arg3)
{
	// возврат суммы кубов значений
	return pow(arg1, 3) + pow(arg2, 3) + pow(arg3, 3);
}

void divideBy2(int& element)
{
	// деление на 2
	element /= 2;
}

void changeAllElements1DArray(void (*F) (int&), int* array, unsigned int size)
{
	// изменение всех элементов одномерного массива через указатель на функцию
	for (int i = 0; i < size; i++)
		F(array[i]);
}

void changeAllElements1DArray(int number, int* array, unsigned int size)
{
	// изменение всех элементов одномерного массива
	for (int i = 0; i < size; i++)
		array[i] *= number;
}

pair <int, unsigned int> minElementOf1DArrayInRange(int* array, unsigned int start_i, unsigned int size)
{
	// поиск минимального элемента и его индекса в части одномерного массива ограниченного индексом начала и конца
	pair <int, unsigned int> result = { array[start_i], start_i };
	for (unsigned int i = start_i + 1; i < size; i++)
	{
		if (array[i] < result.first)
		{
			result.first = array[i];
			result.second = i;
		}
	}
	return result;
}

pair <int, unsigned int> maxElementOf1DArrayInRange(int* array, unsigned int start_i, unsigned int size)
{
	// поиск максимального элемента и его индекса в части одномерного массива ограниченного индексом начала и конца
	pair <int, unsigned int> result = { array[start_i], start_i };
	for (unsigned int i = start_i + 1; i < size; i++)
	{
		if (array[i] > result.first)
		{
			result.first = array[i];
			result.second = i;
		}
	}
	return result;
}

void sorted(int* array, unsigned int size, bool isSortDescending = false)
{
	// сортировка одномерного массива по возрастанию/убыванию в зависимости от параметра isSortDescending (0 - по возрастанию, 1 - по убыванию)
	pair <int, unsigned int>(*commonSorted) (int*, unsigned int, unsigned int) = minElementOf1DArrayInRange;
	if (isSortDescending)
		commonSorted = maxElementOf1DArrayInRange;
	for (int i = 0; i < size - 1; i++)
	{
		pair <int, unsigned int> temp1 = commonSorted(array, i, size);
		int temp2 = array[i];
		array[i] = temp1.first;
		array[temp1.second] = temp2;
	}
}

int* sortedBubbleAscending(int* array, unsigned int size)
{
	// сортировка одномерного массива по возрастанию пузырьковым алгоритмом и возврат указателя на последний элемент массива
	for (int j = 0; j < size - 1; j++)
		for (int i = 0; i < size - 1 - j; i++)
			if (array[i] > array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
	return array + size - 1;
}

int& sortedBubbleDescending(int* array, unsigned int size)
{
	// сортировка одномерного массива по убыванию пузырьковым алгоритмом и возврат ссылки на последний элемент массива
	for (int j = 0; j < size - 1; j++)
		for (int i = 0; i < size - 1 - j; i++)
			if (array[i] < array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
	return array[size - 1];
}

void performanceСomparison()
{
	int* array = allocateAPlaceFor1DArrayRandom(10000, -10, 10);
	auto begin = chrono::steady_clock::now();
	sorted(array, 10000, 0);
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	cout << "The time: " << elapsed_ms.count() << " mks\n";
	auto begin1 = chrono::steady_clock::now();
	//sortedBuble(array, 10000);
	auto end1 = std::chrono::steady_clock::now();
	auto elapsed_ms1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);
	cout << "The time: " << elapsed_ms1.count() << " mks\n";
}

double f(double x)
{
	// функция для дифференцирования
	return x * x;
}

double derivative(double (*F) (double), double x, double point)
{
	// нахождение производной
	return (F(x + point) - F(x)) / point;
}

double* derivative(double (*F) (double), double x, double* arrayPoints, unsigned int sizeArrayPoints, double* arrayResult)
{
	// нахождение производных в разных точках и запись их в массив
	for (int i = 0; i < sizeArrayPoints; i++)
		arrayResult[i] = (F(x + arrayPoints[i]) - F(x)) / arrayPoints[i];
	return arrayResult;
}

double calcPolinom(double* array, unsigned int size, double point)
{
	// расчет полинома
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += (array[i] * pow(point, i));
	return sum;
}

void calcPolinom(double* array, unsigned int size)
{
	// расчет полинома (перегрузка)
	print("Коэффициенты полинома: ");
	print1DArray<double>(array, size);
}

int TheLongestWord(const string& text)
{
	// размер самого длинного слова
	int sizeLongestWord = 0;
	int sizeWord = 0;
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] != ' ')
			sizeWord++;
		else
		{
			if (sizeWord > sizeLongestWord)
				sizeLongestWord = sizeWord;
			sizeWord = 0;
		}
	}
	return sizeLongestWord;
}

string getLine(string text)
{
	// считывание строки
	string result;
	print(text);
	getline(cin, result);
	return result;
}

char inputChar(string text)
{
	// считывание символа
	char result;
	print(text);
	cin >> result;
	return result;
}

void printReverseLine(const string& text, unsigned int size)
{
	// вывод строки в обратном порядке
	if (size)
	{
		cout << text[size - 1];
		printReverseLine(text, --size);
	}
}

int countOfEntries(const string& text, char symbol)
{
	// количество символов в строке текста
	int count = 0;
	for (int i = 0; i < text.size(); i++)
		if (text[i] == symbol)
			count++;
	return count;
}

template <typename Num>
bool IsGreate(const Num& a, const Num& b)
{
	// если больше
	return a > b;
}

template <typename Num>
bool IsLess(const Num& a, const Num& b)
{
	// если меньше
	return a < b;
}

template <typename Num>
Num& maxElement2DArray(Num** array, unsigned int sizeA, unsigned int sizeB)
{
	// максимальный элемент по ссылке
	int offset_i = 0, offset_j = 0;
	Num max = array[0][0];
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			if (IsGreate<Num>(array[i][j], max))
			{
				max = array[i][j];
				offset_i = i;
				offset_j = j;
			}
	return array[offset_i][offset_j];
}

template <typename Num>
Num* minElement2DArray(Num** array, unsigned int sizeA, unsigned int sizeB)
{
	// минимальный элемент по указателю
	Num* p = array[0];
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			if (IsLess<Num>(array[i][j], *p))
				p = array[i] + j;
	return p;
}

template <typename Num>
Num sumOfElements2DArray(Num** array, unsigned int sizeA, unsigned int sizeB)
{
	// сумма всех элементов двумерного массива
	Num sum = 0;
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			sum += array[i][j];
	return sum;
}

template <typename Num>
double average2DArray(Num** array, unsigned int sizeA, unsigned int sizeB)
{
	// среднее арифметическое двумерного массива
	if (sizeA == 0 || sizeB == 0)
		return 0;
	return sumOfElements2DArray<Num>(array, sizeA, sizeB) / ((double)sizeA * sizeB);
}

void filling2DArrayRandomSymbols(char** array, unsigned int sizeA, unsigned int sizeB)
{
	// заполнение массива случайными символами
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			array[i][j] = randint(48, 122);
}

int countOfEntries(char** array, unsigned int sizeA, unsigned int sizeB, char symbol)
{
	// количество вхождений символа в двумерный массив
	int count = 0;
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			if (array[i][j] == symbol)
				count++;
	return count;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////// Глава 1: ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void task1()
{
	unsigned int rangeNumber = inputUInt("Введите натуральное число: ");
	printNumbersInRange(rangeNumber);
}

void task2()
{
	unsigned int count = inputUInt("Введите количество нечетных чисел: ");
	printOddNumbersInRange(count);
}

void task3()
{
	unsigned int count = inputUInt("Введите количество чисел: ");
	printResiduesNumbers(count);
}

void task4()
{
	unsigned int count = inputUInt("Введите количество чисел Фибоначчи: ");
	printFibNumbers(count);
}

void task5()
{
	int x = inputInt("Введите целое число: ");
	print("Биномиальные коэффициенты: ");
	printBinomialKoeff(x);
}

void task6()
{
	double km = inputUDouble("Введите расстояние в километрах : ");
	cout << "Расстояние в милях = " << convertKmToMilesPart1(km) << endl;
}

void task7()
{
	unsigned int km = inputUInt("Введите расстояние в километрах: ");
	unsigned int m = inputUInt("Введите расстояние в метрах: ");
	convertKmToMilesPart2(km, m);
}

void task8()
{
	double saghen = inputUDouble("Введите расстояние в саженях: ");
	cout << "Расстояние в метрах: " << convertSaghToMetrPart1(saghen) << endl;
}

void task9()
{
	unsigned int saghen = inputUInt("Введите растояние в саженях: ");
	unsigned int arshin = inputUInt("Введите растояние в аршинах: ");
	convertSaghToMetrPart2(saghen, arshin);
}

void task10()
{
	double velocityInput = inputDouble("Введите скорость в км/ч: ");
	cout << "Скорость в м/с: " << convertVelocityValuePart1(velocityInput) << endl;
}

void task11()
{
	double velocityInput = inputDouble("Введите скорость в м/с: ");
	cout << "Скорость в км/ч: " << convertVelocityValuePart2(velocityInput) << endl;
}

void task12()
{
	unsigned int range = inputUInt("Введите границу для суммы натуральных чисел: ");
	cout << "Сумма натуральных чисел = " << sumOfNaturalNumbers(range) << endl;
}

void task13()
{
	unsigned int range = inputUInt("Введите количество нечетных натуральных чисел для суммы: ");
	cout << "Сумма нечетных натуральных чисел = " << sumOfOddNaturalNumbers(range) << endl;
}

void task14()
{
	const int sizeArray = 1000;
	int arrayEvenNumbers[sizeArray];
	unsigned int count = inputUInt("Введите требуемое количество четных натуральных чисел: ");
	filling1DArrayEvenNumbers(arrayEvenNumbers, sizeArray, count);
	print("Четные числа: ");
	print1DArray<int>(arrayEvenNumbers, count);
}

void task15()
{
	const int sizeArray = 1000;
	int arrayOddNumbers[sizeArray];
	unsigned int count = inputUInt("Введите требуемое количество нечетных натуральных чисел: ");
	filling1DArrayOddNumbers(arrayOddNumbers, sizeArray, count);
	print("Нечетные числа: ");
	print1DArray<int>(arrayOddNumbers, count);
}

void task16()
{
	const int sizeArray = 1000;
	int arraySquaresNumbers[sizeArray];
	unsigned int count = inputUInt("Введите требуемое количество квадратов натуральных чисел: ");
	filling1DArrayWithSquareNumbers(arraySquaresNumbers, sizeArray, count);
	print("Квадратные числа: ");
	print1DArray<int>(arraySquaresNumbers, count);
}

void task17()
{
	const int sizeArray = 30;
	int arrayStepTwoNumbers[sizeArray];
	unsigned int count = inputUInt("Введите требуемое количество чисел степеней двойки: ");
	filling1DArrayWithStepTwoNumbers(arrayStepTwoNumbers, sizeArray, count);
	print("Числа cтепеней двойки: ");
	print1DArray<int>(arrayStepTwoNumbers, count);
}

void task18()
{
	const int sizeArray = 40;
	int arrayFibonachiNumbers[sizeArray];
	unsigned int count = inputUInt("Введите требуемое количество чисел Фибоначчи: ");
	filling1DArrayWithFibonachiNumbers(arrayFibonachiNumbers, sizeArray, count);
	print("Числа Фибоначчи: ");
	print1DArray<int>(arrayFibonachiNumbers, count);
}

void task19()
{
	const int sizeArray = 1000;
	int customArray[sizeArray];
	unsigned int count = inputUInt("Введите требуемое количество чисел: ");
	filling1DArrayCustom(customArray, sizeArray, count);
	print("Массив из нечетных чисел в степени и четных чисел: ");
	print1DArray<int>(customArray, count);
}

void task20()
{
	const int sizeArray = 1000;
	int myArray[sizeArray];
	unsigned int count = inputUInt("Введите количество чисел: ");
	filling1DArrayFromInput(myArray, sizeArray, count);
	print("Введенные числа массива: ");
	print1DArray<int>(myArray, count);
}




////////////////////////////////////////////////////////////////////////////
////////////////////////////// Глава 2: ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void task21()
{
	unsigned int count = inputUInt("Введите количество нечетных натуральных чисел: ");
	int sum = sumOddNaturalNumb(count);
	cout << "Сумма нечетных натуральных чисел: " << sum << endl;
}

void task22()
{
	unsigned int count = inputUInt("Введите количество четных натуральных чисел: ");
	int sum = sumEvenNaturalNumb(count);
	cout << "Сумма четных натуральных чисел: " << sum << endl;
}

void task23()
{
	int numb = inputInt("Введите целое число: ");
	printDivisionWithoutRemainder(numb);
}

void task24()
{
	printLine("Введите два целых числа.");
	int a = inputInt("Введите число A: ");
	int b = inputInt("Введите число B: ");
	int max_divider = greatestCommonDivider(a, b);
	cout << "Наибольший общий делитель двух чисел: " << max_divider << endl;
}

void task25()
{
	double x = inputDouble("Введите число x: ");
	cout << "Натуральный логарифм = " << log(x) << endl;
	cout << "Натуральный логарифм ~ " << naturalLogarithm(x) << endl;
}

void task26()
{
	double x = inputDouble("Введите число x: ");
	cout << "Синус = " << sin(x) << endl;
	cout << "Синус ~ " << sinus(x) << endl;
}

void task27()
{
	double x = inputDouble("Введите число x: ");
	cout << "Косинус = " << cos(x) << endl;
	cout << "Косинус ~ " << cosinus(x) << endl;
}

void task28()
{
	double x = inputDouble("Введите число x: ");
	cout << "Гиперболический синус = " << sinh(x) << endl;
	cout << "Гиперболический синус ~ " << hyperSinus(x) << endl;
}

void task29()
{
	double x = inputDouble("Введите число x: ");
	cout << "Гиперболический косинус = " << cosh(x) << endl;
	cout << "Гиперболический косинус ~ " << hypercosinus(x) << endl;
}

void task30()
{
	double x = inputDouble("Введите число x: ");
	cout << "Результат = " << (exp(x) - 1) / x << endl;
	cout << "Результат ~ " << calcMyfanc(x) << endl;
}

void task31()
{
	printLine("Введите коэффициенты уравнения вида Ax = B");
	double a = inputDouble("Введите A: ");
	double b = inputDouble("Введите B: ");
	printEquationSolutionPart1(a, b);
}

void task32()
{
	printLine("Введите коэффициенты уравнения вида Ax = B. A и B целые числа.");
	int a = inputDouble("Введите A: ");
	int b = inputDouble("Введите B: ");
	printEquationsSolutionPart2(a, b);
}

void task33()
{
	printLine("Все решения уравнения a ** 2 + b ** 2 = c ** 2:");
	printAllSolutionsOfEquations(100, 100);
}

void task34()
{
	printLine("Введите коээфициенты квадратного уравнения вида a * x ** 2 + b * x + c = 0.");
	double a = inputDouble("Введите коээфициент a: ");
	double b = inputDouble("Введите коээфициент b: ");
	double c = inputDouble("Введите коээфициент c: ");
	print("Решения уравнения: ");
	printSolutionOfQuadraticEquation(a, b, c);
}

void task35()
{
	unsigned int x = inputUInt("Введите целое число: ");
	cout << "Сумма всех натуральных делителей числа " << x << " = " << sumDvider(x) << endl;
}

void task36()
{
	int numb = inputIntInRange("Введите число от 1 до 10: ", 1, 10);
	cout << isFibonacciNumber(numb);
}

void task37()
{
	const int size = 10;
	int array[size];
	filling1DArrayRandom(array, size);
	print("Массив со случайными значениями: ");
	print1DArray<int>(array, size);
	sortBubble1DArray(array, size);
	print("Массив после сортировки элементов по убыванию: ");
	print1DArray<int>(array, size);
}

void task38()
{
	const int size = 10;
	int array[size];
	filling1DArrayRandom(array, size);
	print("Массив со случайными значениями: ");
	print1DArray<int>(array, size);
	ReverseSort1DArray(array, size);
	print("Массив после реверсивной сортировки элементов: ");
	print1DArray<int>(array, size);
}

void task39()
{
	const int size = 10;
	int array[size];
	filling1DArrayRandom(array, size);
	print("Массив со случайными значениями: ");
	print1DArray<int>(array, size);
	customSort1DArray<int>(array, size);
	print("Массив после сортировки (нечетные по возрастанию, четные по возрастанию): ");
	print1DArray<int>(array, size);
}

void task40()
{
	const int size = 10;
	int array[size];
	filling1DArrayRandom(array, size);
	print("Массив со случайными значениями: ");
	print1DArray<int>(array, size);
	customSort2DArrayV2<int>(array, size);
	print("Массив после сортировки (четные по убыванию и нечетные по возрастанию): ");
	print1DArray<int>(array, size);
}



////////////////////////////////////////////////////////////////////////////
////////////////////////////// Глава 3: ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void task41()
{
	unsigned int size = inputUInt("Введите размерность массива: ");
	int* array1 = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int* array2 = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int sum = sumOfPairwiseProductsOfArrays<int>(array1, array2, size);
	cout << "Сумма попарных произведений элементов двух массивов: " << sum << endl;
	delete[] array1;
	delete[] array2;
}

void task42()
{
	unsigned int size = inputUInt("Введите размерность массива: ");
	int* array = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int sum = sumOfSquaresOf1DArray<int>(array, size);
	cout << "Сумма квадратов элементов массива: " << sum << endl;
	delete[] array;
}

void task43()
{
	unsigned int size_i = inputUInt("Введите количество строк для двумерного массива: ");
	unsigned int size_j = inputUInt("Введите количество столбцов для двумерного массива: ");
	int** array = allocateAPlaceFor2DArrayRandom(size_i, size_j, -10, 10);
	int sum = sumOfSquares2DArray<int>(array, size_i, size_j);
	cout << "Сумма квадратов элементов двумерного массива: " << sum << endl;
	delete2DArray<int>(array, size_i);
}

void task44()
{
	unsigned int sizeA = inputUInt("Введите количество строк для двумерного массива: ");
	unsigned int sizeB = inputUInt("Введите количество столбцов для двумерного массива: ");
	int** array = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, -10, 10);
	printLine("Массив после создания:");
	print2DArray<int>(array, sizeA, sizeB);
	int** newArray = transpose2DArray<int>(array, sizeA, sizeB);
	printLine("Массив после транспонирования:");
	print2DArray<int>(newArray, sizeB, sizeA);
	delete2DArray<int>(array, sizeA);
	delete2DArray<int>(newArray, sizeB);
}

void task45()
{
	unsigned int size = inputUInt("Введите размерность двухмерного массива: ");
	int** array = allocateAPlaceFor2DArrayRandom(size, size, 1, 10);
	printLine("Исходная квадратная матрица:");
	print2DArray<int>(array, size, size);
	int** newArray = rotateClockwise2DArray<int>(array, size);
	printLine("Повернутая на 90 градусов по часовой стрелке квадратная матрица:");
	print2DArray<int>(newArray, size, size);
	delete2DArray<int>(array, size);
	delete2DArray<int>(newArray, size);
}

void task46()
{
	unsigned int size = inputUInt("Введите размерность двухмерного массива: ");
	int** array = allocateAPlaceFor2DArrayRandom(size, size, 1, 10);
	printLine("Исходная квадратная матрица:");
	print2DArray<int>(array, size, size);
	int sum = traceOf2DArray<int>(array, size);
	cout << "След матрицы = " << sum << endl;
	delete2DArray<int>(array, size);
}

void task47()
{
	unsigned int size = inputUInt("Введите размерность одномерного массива: ");
	int* array = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	print("Элементы массива: ");
	print1DArray<int>(array, size);
	int min = minElementOf1DArray<int>(array, size);
	int max = maxElementOf1DArray<int>(array, size);
	int posMin = getThePositionOfTheFirstEntry<int>(array, size, min);
	int posMax = getThePositionOfTheFirstEntry<int>(array, size, max);
	cout << "Наибольший элемент массива = " << max << ". Позиция в массиве = " << posMax << endl;
	cout << "Наименьший элемент массива = " << min << ". Позиция в массиве = " << posMin << endl;
	delete[] array;
}

void task48()
{
	unsigned int size = inputUInt("Введите размерность одномерного массива: ");
	int* array = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	print("Элементы массива: ");
	print1DArray<int>(array, size);
	int countPermutations = inputInt("Введите количество перестановок элементов: ");
	makePermutationsRightLeftFor1DArray<int>(array, size, countPermutations);
	print("Элементы массива после перестановок: ");
	print1DArray<int>(array, size);
	delete[] array;
}

void task49()
{
	unsigned int sizeA = inputUInt("Введите количество строк для двумерного массива: ");
	unsigned int sizeB = inputUInt("Введите количество столбцов для двумерного массива: ");
	int** array = allocateAPlaceFor2DArray<int>(sizeA, sizeB);
	printLine("Массив после заполнения натуральными числами по строкам");
	filling2DArrayByRows(array, sizeA, sizeB);
	print2DArray<int>(array, sizeA, sizeB);
	delete2DArray<int>(array, sizeA);
}

void task50()
{
	unsigned int sizeA = inputUInt("Введите количество строк для двумерного массива: ");
	unsigned int sizeB = inputUInt("Введите количество столбцов для двумерного массива: ");
	int** array = allocateAPlaceFor2DArray<int>(sizeA, sizeB);
	filling2DArrayByColumns(array, sizeA, sizeB);
	printLine("Массив после заполнения натуральными числами по столбцам");
	print2DArray<int>(array, sizeA, sizeB);
	delete2DArray<int>(array, sizeA);
}

void task51()
{
	unsigned int size = inputUInt("Введите размерность двухмерного массива: ");
	int** array = allocateAPlaceFor2DArray<int>(size, size);
	filling2DArray<int>(array, size, size, 0);
	fillingMainAndSideDiagonalsOf2DArray<int>(array, size, 1);
	printLine("Массив после заполнения диагоналей единичными значениями");
	print2DArray<int>(array, size, size);
	delete2DArray<int>(array, size);
}

void task52()
{
	unsigned int sizeA = inputUInt("Введите количество строк для первого двумерного массива: ");
	unsigned int sizeB = inputUInt("Введите количество столбцов для первого двумерного массива: ");
	unsigned int sizeC = inputUInt("Введите количество строк для второго двумерного массива: ");
	unsigned int sizeD = inputUInt("Введите количество столбцов для второго двумерного массива: ");
	int** array1 = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, -10, 10);
	int** array2 = allocateAPlaceFor2DArrayRandom(sizeC, sizeD, -10, 10);
	printLine("Первый двумерный массив:");
	print2DArray<int>(array1, sizeA, sizeB);
	printLine("Второй двумерный массив:");
	print2DArray<int>(array2, sizeC, sizeD);
	printLine("Массив произведения:");
	Multiplication2DArrays<int>(array1, sizeA, sizeB, array2, sizeC, sizeD);
	delete2DArray<int>(array1, sizeA);
	delete2DArray<int>(array2, sizeC);
}

void task53()
{
	char text[] = "This is the end";
	reverseArray(text);
	cout << "Массив в обратном порядке: " << text << endl;
}

void task54()
{
	unsigned int sizeA = inputUInt("Введите количество строк для двумерного массива: ");;
	unsigned int sizeB = inputUInt("Введите количество столбцов для двумерного массива: ");
	int** array = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, -10, 10);
	string sampleMinMax = inputMinOrMax("Введите какими элементами заполнять одномерный массив (min или max): ");
	string sampleRowColumn = inputRowOrColumn("Введите тип выборки элементов по строкам или по столбцам (row или column): ");
	printLine("Вывод заданного массива");
	print2DArray<int>(array, sizeA, sizeB);
	int* arrayResult;
	cout << "Вывод " << sampleMinMax << " элементов массива по " << sampleRowColumn << endl;
	if (sampleRowColumn == "row")
	{
		arrayResult = minMaxRowColumn2DArray<int>(array, sizeA, sizeB, sampleRowColumn, sampleMinMax);
		print1DArray<int>(arrayResult, sizeA);
	}
	else
	{
		arrayResult = minMaxRowColumn2DArray<int>(array, sizeB, sizeA, sampleRowColumn, sampleMinMax);
		print1DArray<int>(arrayResult, sizeB);
	}
	delete2DArray<int>(array, sizeA);
	delete[] arrayResult;
}

void task55()
{
	char text[] = " s  d ddddddd dsawe asds asdf";
	pair <int, int*> countWordsAndWordLength = countWordsAndWordLengthInCharArray(text);
	cout << "Общее количество слов: " << countWordsAndWordLength.first << endl;
	print("Длины всех слов по порядку слева направо: ");
	for (int i = 0; i < countWordsAndWordLength.first; i++)
		cout << countWordsAndWordLength.second[i] << " ";
	delete[] countWordsAndWordLength.second;
}

void task56()
{
	const unsigned int size = randint(10, 100);
	int* array = allocateAPlaceFor1DArray<int>(size);
	symmetricalFilling1DArray(array, size);
	print("Симметрично заполненный массив: ");
	print1DArray<int>(array, size);
	delete[] array;
}

void task57()
{
	unsigned int size = inputUInt("Введите размерность для создания 3-х одинаковых одномерных массивов: ");
	int* array1 = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int* array2 = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int* array3 = allocateAPlaceFor1DArray<int>(size);
	string minMax = inputMinOrMax("Введите какое из двух значений записывать в итоговый массив (min или max): ");
	if (minMax == "min")
	{
		for (int i = 0; i < size; i++)
			array3[i] = min<int>(array1[i], array2[i]);
	}
	else
		for (int i = 0; i < size; i++)
			array3[i] = max<int>(array1[i], array2[i]);
	print("Вывод 1го массива: ");
	print1DArray<int>(array1, size);
	print("Вывод 2го массива: ");
	print1DArray<int>(array2, size);
	print("Вывод итогового массива:");
	print1DArray<int>(array3, size);
	delete[] array1;
	delete[] array2;
	delete[] array3;
}

void task58()
{
	unsigned int sizeA = inputUInt("Введите размерность 1-го одномерного массива: ");
	unsigned int sizeB = inputUInt("Введите размерность 2-го одномерного массива: ");
	int* array1 = allocateAPlaceFor1DArrayRandom(sizeA, -10, 10);
	int* array2 = allocateAPlaceFor1DArrayRandom(sizeB, -10, 10);
	int* array3 = allocateAPlaceFor1DArray<int>(sizeA + sizeB);
	concat1DArrays<int>(array1, sizeA, array2, sizeB, array3);
	print("Вывод первого массива: ");
	print1DArray<int>(array1, sizeA);
	print("Вывод второго массива: ");
	print1DArray<int>(array2, sizeB);
	print("Вывод массива объединения: ");
	print1DArray<int>(array3, sizeA + sizeB);
	delete[] array1;
	delete[] array2;
	delete[] array3;
}

void task59()
{
	unsigned int size = inputUInt("Введите размерность для создания 2-х одинаковых одномерных массивов: ");
	int* array1 = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int* array2 = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int* array3 = allocateAPlaceFor1DArray<int>(2 * size);
	concat1DArrays<int>(array1, array2, size, array3);
	print("Вывод первого массива: ");
	print1DArray<int>(array1, size);
	print("Вывод второго массива: ");
	print1DArray<int>(array2, size);
	print("Вывод массива объединения: ");
	print1DArray<int>(array3, 2 * size);
	delete[] array1;
	delete[] array2;
	delete[] array3;
}

void task60()
{
	unsigned int sizeA = inputUInt("Введите количество строк для двумерного массива: ");
	unsigned int sizeB = inputUInt("Введите количество столбцов для двумерного массива: ");
	int newSizeA = sizeA - 1;
	int newSizeB = sizeB - 1;
	adaptation(newSizeA, newSizeB);
	unsigned int row = inputIntInRange("Введите номер строки которую необходимо вычеркнуть ", 0, newSizeA);
	unsigned int column = inputIntInRange("Введите номер столбца который необходимо вычеркнуть ", 0, newSizeB);
	int** array = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, 1, 9);
	printLine("Вывод заданного случайным образом двумерного массива:");
	print2DArray<int>(array, sizeA, sizeB);
	int** newArray = allocateAPlaceFor2DArray<int>(newSizeA, newSizeB);
	minor2DArray<int>(array, sizeA, sizeB, newArray, row, column);
	printLine("Вывод минора двумерного массива:");
	print2DArray<int>(newArray, newSizeA, newSizeB);
	delete2DArray<int>(array, sizeA);
	delete2DArray<int>(newArray, newSizeA);
}



////////////////////////////////////////////////////////////////////////////
////////////////////////////// Глава 4: ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void task61()
{
	unsigned int number = inputUInt("Введите целое неотрицательное число: ");
	cout << "Факториал рекурсией = " << fact(number) << endl;
	cout << "Факториал циклом = " << factV2(number) << endl;
}

void task62()
{
	unsigned int number = inputUInt("Введите целое неотрицательное число: ");
	cout << "Двойной факториал рекурсией = " << doubleFact(number) << endl;
	cout << "Двойной факториал циклом = " << doubleFactV2(number) << endl;
}

void task63()
{
	unsigned int number = inputUInt("Введите номер числа в последовательности Фибоначчи: ");
	cout << "Число Фибоначчи рекурсией = " << getFibonacciNumber(number) << endl;
	cout << "Число Фибоначчи циклом = " << getFibonacciNumberV2(number) << endl;
}

void task64()
{
	cout << calcBinomialKoeff(5, 4);
}

void task65()
{
	unsigned int countNaturalNumbers = inputUInt("Введите количество натуральных чисел для вычисления суммы ");
	double powerNaturalNumbers = inputDouble("Введите степень натуральных чисел для вычисления суммы ");
	int sum = sumNaturalNumbers(countNaturalNumbers);
	double sumPower = sumPowerNaturalNumbers(countNaturalNumbers, powerNaturalNumbers);
	cout << "Сумма натуральных чисел = " << sum << endl;
	cout << "Сумма степеней натуральных чисел  = " << sumPower << endl;
}

void task66()
{
	double x = inputDouble("Введите параметр x для функции exp(x): ");
	unsigned int countIterations = inputUInt("Введите количество итераций для расчета экспоненты: ");
	cout << "Экспонента = " << exp(x) << endl;
	cout << "Экспонента ~ " << expApproximately(x, countIterations) << endl;
}

void task67()
{
	double number1 = inputDouble("Введите первое число с плавающей точкой ");
	double number2 = inputDouble("Введите второе число с плавающей точкой ");
	double number3 = inputDouble("Введите третье число с плавающей точкой ");
	cout << "Вывод первого введенного числа: " << overchargedFunction(number1) << endl;
	cout << "Вывод суммы квадратов первых двух чисел: " << overchargedFunction(number1, number2) << endl;
	cout << "Вывод суммы кубов всех чисел: " << overchargedFunction(number1, number2, number3) << endl;
}

void task68()
{
	unsigned int size = inputUInt("Введите размер одномерного массива: ");
	int* array = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	print("Массив заполненный случайным образом: ");
	print1DArray<int>(array, size);
	void (*func) (int&) = divideBy2;
	changeAllElements1DArray(func, array, size);
	print("Массив после изменений всех элементов: ");
	print1DArray<int>(array, size);
	changeAllElements1DArray(randint(), array, size);
	print("Массив после изменений всех элементов еще раз: ");
	print1DArray<int>(array, size);
	delete[] array;
}

void task69()
{
	double number = inputDouble("Введите аргумент для вычисления производной: ");
	double (*funcForDerivative) (double) = f;
	double point = inputDouble("Введите в какой точке необходимо вычислить производную: ");
	cout << "Производная от " << number << " в точке " << point << " равна " << derivative(funcForDerivative, number, point) << endl;
	const unsigned int size = 10;
	double* arrayPoints = allocateAPlaceFor1DArrayRandom(size, 0.01, 10.0);
	double* arrayResult = allocateAPlaceFor1DArray<double>(size);
	arrayResult = derivative(funcForDerivative, number, arrayPoints, size, arrayResult);
	print("Значения всех производных в заданных точках: ");
	print1DArray<double>(arrayResult, size);
	delete[] arrayPoints;
	delete[] arrayResult;
}

void task70()
{
	const unsigned int size = 10;
	double* array = allocateAPlaceFor1DArrayRandom(size, -10.0, 10.0);
	double number = inputDouble("Введите значение в котором будет вычислен полином ");
	double sum = calcPolinom(array, size, number);
	cout << "Расчетное значение полинома: " << sum << endl;
	calcPolinom(array, size);
	delete[] array;
}

void task71()
{
	unsigned int size = inputUInt("Введите размер одномерного массива: ");
	int* array = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	print("Вывод одномерного массива: ");
	print1DArray<int>(array, size);
	int* lastElement = sortedBubbleAscending(array, size);
	print("Вывод одномерного массива после сортировки по возрастанию: ");
	print1DArray<int>(array, size);
	cout << "Указатель на последний элемент массива = " << lastElement << endl;
	cout << "Значение по этому указателю = " << *lastElement << endl;
	delete[] array;
}

void task72()
{
	unsigned int size = inputUInt("Введите размер одномерного массива: ");
	int* array = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	print("Вывод одномерного массива: ");
	print1DArray<int>(array, size);
	int& lastElement = sortedBubbleDescending(array, size);
	print("Вывод одномерного массива после сортировки по убыванию: ");
	print1DArray<int>(array, size);
	cout << "Значение последнего элемента по ссылке = " << lastElement << endl;
	lastElement = 44;
	cout << "Значение последнего элемента по ссылке после изменения = " << lastElement << endl;
	delete[] array;
}

void task73()
{
	string text = getLine("Введите текст: ");
	cout << "Размер самого длинного слова = " << TheLongestWord(text) << endl;
}

void task74()
{
	string text = getLine("Введите текст: ");
	print("Текст в обратном порядке: ");
	printReverseLine(text, text.size());
}

void task75()
{
	string text = getLine("Введите текст: ");
	char symbol = inputChar("Введите символ: ");
	cout << "Количество символов " << symbol << " в тексте: " << countOfEntries(text, symbol) << endl;
}

void task76()
{
	unsigned int sizeA = inputUInt("Введите количество строк двумерного массива ");
	unsigned int sizeB = inputUInt("Введите количество столбцов двумерного массива ");
	double** array = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, -10.0, 10.0);
	printLine("Вывод двумерного массива");
	print2DArray<double>(array, sizeA, sizeB);
	double& max = maxElement2DArray<double>(array, sizeA, sizeB);
	cout << "Максимальный элемент двумерного массива: " << max << endl;
	delete2DArray<double>(array, sizeA);
}

void task77()
{
	unsigned int sizeA = inputUInt("Введите количество строк двумерного массива ");
	unsigned int sizeB = inputUInt("Введите количество столбцов двумерного массива ");
	double** array = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, -10.0, 10.0);
	printLine("Вывод двумерного массива");
	print2DArray<double>(array, sizeA, sizeB);
	double* pMin = minElement2DArray<double>(array, sizeA, sizeB);
	cout << "Минимальный элемент двумерного массива по указателю: " << *pMin << endl;
	delete2DArray<double>(array, sizeA);
}

void task78()
{
	unsigned int sizeA = inputUInt("Введите количество строк двумерного массива ");
	unsigned int sizeB = inputUInt("Введите количество столбцов двумерного массива ");
	int** array = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, -10, 10);
	printLine("Вывод двумерного массива");
	print2DArray<int>(array, sizeA, sizeB);
	cout << "Среднее арифметическое двумерного массива = " << average2DArray<int>(array, sizeA, sizeB) << endl;
	delete2DArray<int>(array, sizeA);
}

void task79()
{
	unsigned int sizeA = inputUInt("Введите количество строк двумерного массива ");
	unsigned int sizeB = inputUInt("Введите количество столбцов двумерного массива ");
	char symbol = inputChar("Введите символ для подсчета количества таких символов в двумерном массиве ");
	char** array = allocateAPlaceFor2DArray<char>(sizeA, sizeB);
	filling2DArrayRandomSymbols(array, sizeA, sizeB);
	printLine("Массив случайных символов: ");
	print2DArray<char>(array, sizeA, sizeB);
	cout << "Количество символов " << symbol << " в массиве = " << countOfEntries(array, sizeA, sizeB, symbol) << endl;
	delete2DArray<char>(array, sizeA);
}



////////////////////////////////////////////////////////////////////////////
////////////////////////////// Глава 5: ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

class Parallelepiped
{
public:

	Parallelepiped(double width, double depth, double height) : width(width), depth(depth), height(height) { volume = calcVolume(); }

	double calcVolume()
	{
		return width * depth * height;
	}

	void printAll()
	{
		printLine("Геометрические параметры параллелепипеда:");
		cout << "Ширина = " << width << endl;
		cout << "Глубина = " << depth << endl;
		cout << "Высота = " << height << endl;
		cout << "Объем = " << volume << endl;
	}

	double getWidth()
	{
		return width;
	}

	double getDepth()
	{
		return depth;
	}

	double getHeight()
	{
		return height;
	}

	double getVolume()
	{
		return volume;
	}

	void setVolume(double value)
	{
		volume = value;
	}

private:
	double width;
	double depth;
	double height;
	double volume;
};

class ParallelepipedChild : public Parallelepiped
{
public:

	ParallelepipedChild(double width, double depth, double height, double mass) : Parallelepiped(width, depth, height)
	{
		this->mass = mass;
	}

	double calcDensity()
	{
		return mass / this->getVolume();
	}

	double getMass()
	{
		return mass;
	}

	void setMass(double value)
	{
		mass = value;
	}

	void printAll()
	{
		printLine("Геометрические параметры параллелепипеда:");
		cout << "Ширина = " << getWidth() << endl;
		cout << "Глубина = " << getDepth() << endl;
		cout << "Высота = " << getHeight() << endl;
		cout << "Объем = " << getVolume() << endl;
		cout << "Масса = " << mass << endl;
		cout << "Плотность = " << calcDensity() << endl;
	}

	ParallelepipedChild operator+(ParallelepipedChild& obj)
	{
		ParallelepipedChild newObj(10, 10, 10, this->getMass() + obj.getMass());
		newObj.setVolume(this->getVolume() + obj.getVolume());
		return newObj;
	}

private:
	double mass;
};

ParallelepipedChild operator/(ParallelepipedChild& obj, double value)
{
	obj.setMass(obj.getMass() / value);
	return obj;
}

class ComplexNumberAlgebraicForm
{
public:

	ComplexNumberAlgebraicForm(double a, double b) : a(a), b(b) {}

	double getA()
	{
		return a;
	}

	void setA(double value)
	{
		a = value;
	}

	double getB()
	{
		return b;
	}

	void setB(double value)
	{
		b = value;
	}

	void printComplexNumber()
	{
		cout << a;
		if (b >= 0)
			cout << "+";
		cout << b << "i" << endl;
	}

	ComplexNumberAlgebraicForm operator+(ComplexNumberAlgebraicForm& obj)
	{
		return ComplexNumberAlgebraicForm(a + obj.a, b + obj.b);
	}

	ComplexNumberAlgebraicForm operator-(ComplexNumberAlgebraicForm& obj)
	{
		return ComplexNumberAlgebraicForm(a - obj.a, b - obj.b);
	}

	ComplexNumberAlgebraicForm operator*(ComplexNumberAlgebraicForm& obj)
	{
		return ComplexNumberAlgebraicForm(a * obj.a - b * obj.b, a * obj.b + obj.a * b);
	}

	ComplexNumberAlgebraicForm operator/(ComplexNumberAlgebraicForm& obj)
	{
		return ComplexNumberAlgebraicForm((a * obj.a + b * obj.b) / (obj.a * obj.a + obj.b * obj.b), (-a * obj.b + obj.a * b) / (obj.a * obj.a + obj.b * obj.b));
	}

	ComplexNumberAlgebraicForm operator++()
	{
		a = a + 1;
		return *this;
	}

	ComplexNumberAlgebraicForm operator++(int)
	{
		a++;
		return *this;
	}

	ComplexNumberAlgebraicForm operator--()
	{
		a = a - 1;
		return *this;
	}

	ComplexNumberAlgebraicForm operator--(int)
	{
		a--;
		return *this;
	}

private:
	double a;
	double b;
};

ComplexNumberAlgebraicForm operator+=(ComplexNumberAlgebraicForm& obj, double value)
{
	obj.setA(obj.getA() + value);
	return obj;
}

ComplexNumberAlgebraicForm operator-=(ComplexNumberAlgebraicForm& obj, double value)
{
	obj.setA(obj.getA() - value);
	return obj;
}

ComplexNumberAlgebraicForm operator*=(ComplexNumberAlgebraicForm& obj, double value)
{
	obj.setA(obj.getA() * value);
	obj.setB(obj.getB() * value);
	return obj;
}

ComplexNumberAlgebraicForm operator/=(ComplexNumberAlgebraicForm& obj, double value)
{
	obj.setA(obj.getA() / value);
	obj.setB(obj.getB() / value);
	return obj;
}

class ComplexTrigonometricForm : public ComplexNumberAlgebraicForm
{
public:

	ComplexTrigonometricForm(double a, double b) : ComplexNumberAlgebraicForm(a, b) 
	{
		angle = 0;
		module = sqrt(a * a + b * b);
		if (b == 0 && a > 0)
			angle = 0;
		else if (a == 0 && b > 0)
			angle = pi / 2;
		else if (a < 0 && b == 0)
			angle = pi;
		else if (a == 0 && b < 0)
			angle = -pi / 2;
		else if (a > 0)
			angle = atan(b / a);
		else if (a < 0 && b > 0)
			angle = pi + atan(b / a);
		else if (a < 0 && b < 0)
			angle = -pi + atan(b / a);
	}

	void printComplexNumber()
	{
		cout << module << "(cos" << angle << " + isin" << angle << ")" << endl;
	}

private:
	double module;
	double angle;
};

class Vector2D
{
public:

	Vector2D(double x, double y) : x(x), y(y) {}

	Vector2D() {}

	double calcLength()
	{
		return sqrt(x * x + y * y);
	}

	void printInfo()
	{
		cout << "vector(" << x << ", " << y << ")" << endl;
	}

	double getX()
	{
		return x;
	}

	double getY()
	{
		return y;
	}

	void setX(double value)
	{
		x = value;
	}

	void setY(double value)
	{
		y = value;
	}

	Vector2D operator+(Vector2D& obj)
	{
		Vector2D newObj;
		newObj.x = x + obj.x;
		newObj.y = y + obj.y;
		return newObj;
	}

	Vector2D operator-(Vector2D& obj)
	{
		Vector2D newObj;
		newObj.x = x - obj.x;
		newObj.y = y - obj.y;
		return newObj;
	}

	Vector2D operator*=(double value)
	{
		x *= value;
		y *= value;
		return *this;
	}

	Vector2D operator/=(double value)
	{
		x /= value;
		y /= value;
		return *this;
	}

	Vector2D operator*(double value)
	{
		Vector2D newObj;
		newObj.x = x * value;
		newObj.y = y * value;
		return newObj;
	}

	Vector2D operator/(double value)
	{
		Vector2D newObj;
		newObj.x = x / value;
		newObj.y = y / value;
		return newObj;
	}

	double operator*(Vector2D& obj)
	{
		return x * obj.x + y * obj.y;
	}

private:
	double x;
	double y;
};

class Vector3D : public Vector2D
{
public:

	Vector3D(double x, double y, double z) : Vector2D(x, y) { this->z = z; }

	Vector3D() : Vector2D() {}

	double calcLength()
	{
		return sqrt(pow(this->getX(), 2) + pow(this->getY(), 2) + z * z);
	}

	void printInfo()
	{
		cout << "vector(" << this->getX() << ", " << this->getY() << ", " << z << ")" << endl;
	}

	Vector3D operator+(Vector3D& obj)
	{
		Vector3D newObj;
		newObj.setX(this->getX() + obj.getX());
		newObj.setY(this->getY() + obj.getY());
		newObj.z = z + obj.z;
		return newObj;
	}

	Vector3D operator-(Vector3D& obj)
	{
		Vector3D newObj;
		newObj.setX(this->getX() - obj.getX());
		newObj.setY(this->getY() - obj.getY());
		newObj.z = z - obj.z;
		return newObj;
	}

	Vector3D operator*=(double value)
	{
		this->setX(this->getX() * value);
		this->setY(this->getY() * value);
		z *= value;
		return *this;
	}

	Vector3D operator/=(double value)
	{
		this->setX(this->getX() / value);
		this->setY(this->getY() / value);
		z /= value;
		return *this;
	}

	Vector3D operator*(double value)
	{
		Vector3D newObj;
		newObj.setX(this->getX() * value);
		newObj.setY(this->getY() * value);
		newObj.z = z * value;
		return newObj;
	}

	Vector3D operator/(double value)
	{
		Vector3D newObj;
		newObj.setX(this->getX() / value);
		newObj.setY(this->getY() / value);
		newObj.z = z / value;
		return newObj;
	}

	double operator*(Vector3D& obj)
	{
		return this->getX() * obj.getX() + this->getY() * obj.getY() + z * obj.z;
	}

private:
	double z;
};

class Car
{
public:

	Car(string brand, double volumeTank, double fuelСonsumption, double colorRGB[3]) : brand(brand), volumeTank(volumeTank), fuelСonsumption(fuelСonsumption)
	{
		this->colorRGB = new double[3];
		for (int i = 0; i < 3; i++)
			this->colorRGB[i] = colorRGB[i];
	}
	
	virtual ~Car()
	{
		delete[] colorRGB;
	}

	virtual double calcTransportationCost(double priceOfOneLiterOfFuel) = 0;

	double calcPosibleDistanceOnFullTank()
	{
		return (volumeTank / fuelСonsumption) * 100;
	}

	void setColorRGB(double newColorRGB[3])
	{
		for (int i = 0; i < 3; i++)
			colorRGB[i] = newColorRGB[i];
	}

	string getBrand()
	{
		return brand;
	}

	double* getColorRGB()
	{
		return colorRGB;
	}

	double getVolumeTank()
	{
		return volumeTank;
	}

	double getFuelСonsumption()
	{
		return fuelСonsumption;
	}

	virtual void getInfo() = 0;

protected:
	string brand; // марка
	double volumeTank; // объем в литрах
	double fuelСonsumption; // расход топлива литры / 100 км
	double* colorRGB; // цвет
};

class PassengerCar : public Car
{
public:

	PassengerCar(string brand, double volumeTank, double fuelСonsumption, double colorRGB[3]) : Car(brand, volumeTank, fuelСonsumption, colorRGB) {}

	virtual ~PassengerCar() {}

	virtual void getInfo()
	{
		double* color = getColorRGB();
		print("Марка: ");
		cout << getBrand() << endl;
		print("Цвет в формате RGB: ");
		cout << "R = " << color[0] << " G = " << color[1] << " B = " << color[2] << endl;
		print("Объем бака в литрах: ");
		cout << getVolumeTank() << endl;
		print("Нормальный расход топлива л / 100 км: ");
		cout << getFuelСonsumption() << endl;
		print("Возможное расстояние, которое способен проехать автомобиль израсходовав полный бак топлива: ");
		cout << calcPosibleDistanceOnFullTank() << endl;
	}
private:
	virtual double calcTransportationCost(double priceOfOneLiterOfFuel) { return 1; }
};

class Truck : public Car
{
public:

	Truck(string brand, double volumeTank, double fuelСonsumption, double colorRGB[3], double carryingСapacity) : Car(brand, volumeTank, fuelСonsumption, colorRGB)
	{
		this->carryingСapacity = carryingСapacity;
	}

	virtual ~Truck() {}

	double calcTransportationCost(double priceOfOneLiterOfFuel)
	{
		return ((getFuelСonsumption() * priceOfOneLiterOfFuel) / 100) / carryingСapacity;
	}

	virtual void getInfo()
	{
		double* color = getColorRGB();
		print("Марка: ");
		cout << getBrand() << endl;
		print("Цвет в формате RGB: ");
		cout << "R = " << color[0] << " G = " << color[1] << " B = " << color[2] << endl;
		print("Объем бака в литрах: ");
		cout << getVolumeTank() << endl;
		print("Нормальный расход топлива л / 100 км: ");
		cout << getFuelСonsumption() << endl;
		print("Возможное расстояние, которое способен проехать автомобиль израсходовав полный бак топлива: ");
		cout << calcPosibleDistanceOnFullTank() << endl;
		print("Грузоподъемность в тоннах: ");
		cout << carryingСapacity << endl;
	}

private:
	double carryingСapacity; // грузоподъемность тонны
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////// Глава 6: ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

template <typename T>
class Object
{
public:
	Object() : number(randint()) {}

	T getNumber()
	{
		return number;
	}

private:
	T number;
};

template <typename T>
class ArrayInObj
{
	static const unsigned int siseArray = 10;
public:
	ArrayInObj()
	{
		for (int i = 0; i < siseArray; i++)
			array[i] = randint();
	}

	ArrayInObj(T* otherArray)
	{
		for (int i = 0; i < siseArray; i++)
			array[i] = otherArray[i];
	}

	ArrayInObj(T numb)
	{
		for (int i = 0; i < siseArray; i++)
			array[i] = numb;
	}

	ArrayInObj(ArrayInObj& other)
	{
		for (int i = 0; i < siseArray; i++)
			array[i] = other.getArray()[i];
	}

	void printArray()
	{
		for (int i = 0; i < siseArray; i++)
			cout << array[i] << " ";
		cout << endl;
	}

	const unsigned int getSizeArray()
	{
		return siseArray;
	}

	T* getArray()
	{
		return array;
	}

	T& operator[](unsigned int index)
	{
		return array[index];
	}

	ArrayInObj operator+(ArrayInObj& other)
	{
		ArrayInObj<T> newArray;
		for (int i = 0; i < siseArray; i++)
			newArray[i] = (double)(this->getArray()[i] + other.getArray()[i]) / 2;
		return  newArray;
	}

	ArrayInObj operator*(double numb)
	{
		ArrayInObj<T> newArray;
		for (int i = 0; i < siseArray; i++)
			newArray[i] = this->getArray()[i] * numb;
		return newArray;
	}

	ArrayInObj operator/(double numb)
	{
		ArrayInObj<T> newArray;
		for (int i = 0; i < siseArray; i++)
			newArray[i] = this->getArray()[i] / numb;
		return newArray;
	}

	void operator*=(double numb)
	{
		for (int i = 0; i < siseArray; i++)
			array[i] *= numb;
	}

	void operator/=(double numb)
	{
		for (int i = 0; i < siseArray; i++)
			array[i] *= numb;
	}

private:
	T array[siseArray];
};

int main() {
	system("chcp 1251>null");
	srand(time(NULL));
	return 0;
}