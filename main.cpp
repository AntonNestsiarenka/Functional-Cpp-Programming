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
	// ��������� ����� ����� � ��������� [l, h]
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
	// ��������� ����� c ��������� ������ � ��������� [l, h]
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
	// ��������� ������ ��� ���������� ������
	Num** array = new Num * [sizeA];
	for (int i = 0; i < sizeA; i++)
		array[i] = new Num[sizeB];
	return array;
}

int** allocateAPlaceFor2DArrayRandom(unsigned int sizeA, unsigned int sizeB, int min = -10, int max = 10)
{
	// ��������� ������ ��� ���������� ������ � ���������� ��� ���������� ����������
	int** array = allocateAPlaceFor2DArray<int>(sizeA, sizeB);
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			array[i][j] = randint(min, max);
	return array;
}

double** allocateAPlaceFor2DArrayRandom(unsigned int sizeA, unsigned int sizeB, double min = -10.0, double max = 10.0)
{
	// ��������� ������ ��� ���������� ������ � ���������� ��� ���������� ����������
	double** array = allocateAPlaceFor2DArray<double>(sizeA, sizeB);
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			array[i][j] = uniform(min, max);
	return array;
}

template <typename Num>
Num* allocateAPlaceFor1DArray(unsigned int size)
{
	// ��������� ������ ��� ���������� ������
	Num* array = new Num[size];
	return array;
}

int* allocateAPlaceFor1DArrayRandom(unsigned int size, int min = -10, int max = 10)
{
	// ��������� ������ ��� ���������� ������ � ���������� ��� ���������� ����������
	int* array = new int[size];
	for (int i = 0; i < size; i++)
		array[i] = randint(min, max);
	return array;
}

double* allocateAPlaceFor1DArrayRandom(unsigned int size, double min = -10.0, double max = 10.0)
{
	// ��������� ������ ��� ���������� ������ � ���������� ��� ���������� ����������
	double* array = new double[size];
	for (int i = 0; i < size; i++)
		array[i] = uniform(min, max);
	return array;
}

template <typename Num>
void delete2DArray(Num** array, unsigned int size)
{
	// ������������� ������ ������� ��� ���������� ������
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
	// ����� � ������� ����������� ������� � ������� �������
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
	// ����� � ������� ����������� �������
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

template <typename Num>
Num** transpose2DArray(Num** array, unsigned int sizeA, unsigned int sizeB)
{
	// ���������������� ����������� �������
	Num** newArray = allocateAPlaceFor2DArray<Num>(sizeB, sizeA);
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			newArray[j][i] = array[i][j];
	return newArray;
}

template <typename Num>
Num sumOfSquares2DArray(Num** array, unsigned int size_i, unsigned int size_j)
{
	// ����� ��������� ����������� ������� �����������
	Num sum = 0;
	for (int i = 0; i < size_i; i++)
		for (int j = 0; j < size_j; j++)
			sum += pow(array[i][j], 2);
	return sum;
}

template <typename Num>
Num sumOfSquaresOf1DArray(Num* array, unsigned int size)
{
	// ����� ��������� ����������� ������� �����������
	Num sum = 0;
	for (int i = 0; i < size; i++)
		sum += pow(array[i], 2);
	return sum;
}

template <typename Num>
Num sumOfPairwiseProductsOfArrays(Num* array1, Num* array2, unsigned int size)
{
	// ����� ������������ ��� ���� ���������� ��������
	Num sum = 0;
	for (int i = 0; i < size; i++)
		sum += (array1[i] * array2[i]);
	return sum;
}

template <typename Num>
Num** rotateClockwise2DArray(Num** array, unsigned int size)
{
	// ������� ����������� ������� 1 ��� �� ������� �������
	Num** newArray = allocateAPlaceFor2DArray<Num>(size, size);
	for (int j = 0; j < size; j++)
		for (int i = 0; i < size; i++)
			newArray[i][size - 1 - j] = array[j][i];
	return newArray;
}

template <typename Num>
Num traceOf2DArray(Num** array, unsigned int size)
{
	// ���� ����������� �������
	Num sum = 0;
	for (int i = 0, j = 0; i < size; i++, j++)
		sum += array[i][j];
	return sum;
}

template <typename Num>
Num minElementOf1DArray(Num* array, unsigned int size)
{
	// ����� ������������ �������� ����������� �������
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
	// ����� ������������� �������� ����������� �������
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
	// ������� ������� ��������� �������� � ���������� �������
	for (int i = 0; i < size; i++)
		if (array[i] == element)
			return i;
}

template <typename Num>
void makePermutationsRightFor1DArray(Num* array, unsigned int size, int countPermutations)
{
	// ����������� ������������ ��������� ����������� ������� ������ �� �������� ���������� ���������
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
	// ���������� ����������� ������������ ����� countPermutations < 0 � ������ ����
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
	// ���������� ���������� ������� ������������ ������� �� �������
	int numb = 1;
	for (int i = 0; i < size_i; i++)
		for (int j = 0; j < size_j; j++)
			array[i][j] = numb++;
}

void filling2DArrayByColumns(int** array, unsigned int size_i, unsigned int size_j)
{
	// ���������� ���������� ������� ������������ ������� �� ��������
	int numb = 1;
	for (int j = 0; j < size_j; j++)
		for (int i = 0; i < size_i; i++)
			array[i][j] = numb++;
}

template <typename Num>
void filling2DArray(Num** array, unsigned int size_i, unsigned int size_j, Num numb)
{
	// ���������� ���������� ������� �������� �������� ���������
	for (int i = 0; i < size_i; i++)
		for (int j = 0; j < size_j; j++)
			array[i][j] = numb;
}

template <typename Num>
void fillingMainAndSideDiagonalsOf2DArray(Num** array, unsigned int size, Num numb)
{
	// ���������� ������� � �������� ���������� ���������� ������� �������� �������� ���������
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		array[i][j] = numb;
		array[i][size - 1 - j] = numb;
	}
}

void reverseArray(char* array)
{
	// ������ ���������� ������� 
	for (int i = 0; i < strlen(array) / 2; i++)
	{
		char temp = array[i];
		array[i] = array[strlen(array) - 1 - i];
		array[strlen(array) - 1 - i] = temp;
	}
}

bool isPosibleMultiplicationMatrix(unsigned int sizeJArray1, unsigned int sizeIArray2)
{
	/* �������� �������� �� ������������ ���� ������
	   sizeJArray1 - ���������� �������� ���������� ������� ������ ������� (������ �����������)
	   sizeIArray2 - ���������� ����� ���������� ������� ������ ������� (������ �����������) */
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
		cout << "������������ ���� �������� ����������." << endl;
	print2DArray<Num>(arrayMul, sizeIArray1, sizeJArray2);
	delete2DArray<Num>(arrayMul, sizeIArray1);
}

void lower(string& str)
{
	// ���������� ������ � ������� ��������
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
	// ���� �������������� ��������
	print(text);
	int result;
	cin >> result;
	return result;
}

unsigned int inputUInt(string text)
{
	// ���� �������������� ������������ �������� >= 0
	int result = inputInt(text);
	if (result >= 0)
		return result;
	printLine("��������� �������� ������ ���� ������������� ������ >= 0. ������� ���������� ��������.");
	return inputUInt(text);
}

string inputString(string text)
{
	// ���� ������
	string result;
	print(text);
	cin >> result;
	return result;
}

string inputMinOrMax(string text)
{
	// ���� ������ min ��� max
	string sampleMinMax = inputString(text);
	lower(sampleMinMax);
	if (sampleMinMax == "min" || sampleMinMax == "max")
		return sampleMinMax;
	printLine("���������� ������ min ��� max. ������� ���������� ������.");
	return inputMinOrMax(text);
}

string inputRowOrColumn(string text)
{
	// ���� ������ row ��� column
	string sampleRowColumn = inputString(text);
	lower(sampleRowColumn);
	if (sampleRowColumn == "row" || sampleRowColumn == "column")
		return sampleRowColumn;
	printLine("���������� ������ row ��� column. ������� ���������� ������.");
	return inputRowOrColumn(text);
}

template <typename Num>
void updateIfGreate(Num** array, unsigned int indexI, unsigned int indexJ, Num& max)
{
	// ���������� ������������� ��������
	if (array[indexI][indexJ] > max)
		max = array[indexI][indexJ];
}

template <typename Num>
void updateIfLess(Num** array, unsigned int indexI, unsigned int indexJ, Num& min)
{
	// ���������� ������������ ��������
	if (array[indexI][indexJ] < min)
		min = array[indexI][indexJ];
}

template <typename Num>
int minMax(Num** array, unsigned int size, unsigned int Index, string rowColumn = "row", string minMax = "min")
{
	// ���������� �������������/������������ �������� � ������/������� ���������� ������� � ����������� �� ������� ������
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
	// ���������� ����������� ������� ������������ ��� ������������� ���������� �� ������� ��� �������� ���������� �������
	Num* arrayResult = allocateAPlaceFor1DArray<Num>(size);
	for (int i = 0; i < size; i++)
		arrayResult[i] = minMax<Num>(array, sizeOther, i, sampleRowColumn, sampleMinMax);
	return arrayResult;
}

template <typename Num>
Num* resize1DArray(Num* oldArray, unsigned int size)
{
	// ������������� ������ ��� ���������� ������ � ����������� ������������ ������ � ������������� ������
	Num* newArray = allocateAPlaceFor1DArray<Num>(size);
	for (int i = 0; i < size - 1; i++)
		newArray[i] = oldArray[i];
	delete[] oldArray;
	return newArray;
}

pair <int, int*> countWordsAndWordLengthInCharArray(char* array)
{
	/* ������� ���������� ���� � ������ ������� ����� � ���������� �������
	   ����������� ����� �������� ����: ������ ������� ����� ���� (���������� ����) � ��������� �� ������ ���� ���� */

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
	// ������������ ���������� ����������� �������
	for (int i = 0; i < size / 2 + size % 2; i++)
	{
		array[i] = startNumber;
		array[size - 1 - i] = startNumber++;
	}
}

template <typename Num>
Num min(Num a, Num b)
{
	// ����������� �� ���� �����
	if (a < b)
		return a;
	return b;
}

template <typename Num>
Num max(Num a, Num b)
{
	// ������������ �� ���� �����
	if (a > b)
		return a;
	return b;
}

template <typename Num>
void concat1DArrays(Num* array1, unsigned int sizeArray1, Num* array2, unsigned int sizeArray2, Num* arrayConcat)
{
	// ���������� �������1 � �������2 � ������ 3
	int j = 0;
	for (int i = 0; i < sizeArray1; i++)
		arrayConcat[j++] = array1[i];
	for (int i = 0; i < sizeArray2; i++)
		arrayConcat[j++] = array2[i];
}

template <typename Num>
void concat1DArrays(Num* array1, Num* array2, unsigned int size, Num* arrayConcat)
{
	/* ����������� �������1 � �������2 � ������ ������
	   ����������� ���������� �� ������ �������� �� ������� ������� ����� ������� � ��� ����� */
	for (int i = 0, j = 0; i < size; i++)
	{
		arrayConcat[j++] = array1[i];
		arrayConcat[j++] = array2[i];
	}
}

template <typename Num>
void minor2DArray(Num** array, unsigned int size_i, unsigned int size_j, Num** minor2DArray, unsigned int row, unsigned int column)
{
	// ���������� ������ ���������� �������
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
	// ���� ������ � ��������� [lRange, hRange]
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
		cout << "��������� �������� ������ ������������ ���������� [" << lRange << ", " << hRange << "]. ������� ���������� ��������." << endl;
	}
}

void adaptation(int& sizeA, int& sizeB)
{
	// ������� ��� ������� 60
	if (sizeA < 0 || sizeB < 0)
	{
		sizeA = 0;
		sizeB = 0;
	}
}

double inputDouble(string text)
{
	// ���� ����� � ��������� ������
	print(text);
	double result;
	cin >> result;
	return result;
}

double inputUDouble(string text)
{
	// ���� ������������ ����� � ��������� ������ >= 0
	double result = inputDouble(text);
	if (result >= 0)
		return result;
	printLine("��������� ����� ������ ���� >= 0. ������� ���������� ������.");
	return inputUDouble(text);
}

double inputDoubleInRange(string text, double lRange, double hRange)
{
	// ���� ����� � ��������� ������ � ��������� [lRange, hRange]
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
		cout << "��������� �������� ������ ������������ ���������� [" << lRange << ", " << hRange << "]. ������� ���������� ��������." << endl;
	}
}

void printNumbersInRange(unsigned int range)
{
	// ����� n-����������� �����
	cout << "��� ����������� ����� � ���� ��������:" << endl;
	printLine("��� ����������� ����� � ���� ��������:");
	int i = 1;
	while (i <= range)
		cout << i++ << " ";
}

void printOddNumbersInRange(unsigned int count)
{
	// ����� n-�������� ����������� �����
	cout << "����� " << count << " �������� �����: " << endl;
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
	// ����� n-�����, ������� ��� ������� �� 4 ���� ������� 3
	cout << "����� " << count << " �����, ������� ��� ������� �� 4 ���� ������� 3" << endl;
	int i = 0;
	while (count)
	{
		cout << 4 * i++ + 3 << " ";
		count--;
	}
}

void printFibNumbers(unsigned int count)
{
	// ����� n-����� �� ������������������ ���������
	cout << "����� ������������������ �� " << count << " ����� ���������" << endl;
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
	// ����� n-������������ �������������
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
	// ������� �� ���������� � ����
	double miles;
	const double kmInMile = 1.609344;
	miles = km / kmInMile;
	return miles;
}

void convertKmToMilesPart2(int km, int m)
{
	// ������� �� �� � � � ���� � ���� � ����� �����������
	const int mInKm = 1000;
	const double kmInMile = 1.609344;
	double dKm = km + (double)m / mInKm;
	double dMiles = dKm / kmInMile;
	int miles = (int)dMiles;
	const int ftInMile = 5280;
	int ft = (int)((dMiles - miles) * ftInMile);
	cout << "���������� � �����: " << miles << endl;
	cout << "���������� � �����: " << ft << endl;
}

double convertSaghToMetrPart1(double saghen)
{
	// ������� �� ������� � �����
	const double metrInSagh = 2.16;
	double metr = saghen * metrInSagh;
	return metr;
}

void convertSaghToMetrPart2(unsigned int saghen, unsigned int arshin)
{
	// ������� �� ������� � ������� � ����� � ���������� � ����� �����������
	const double metrInSagh = 2.16;
	const int arshinInSagh = 3;
	double dSaghen = saghen + (double)arshin / arshinInSagh;
	double dMetr = dSaghen * metrInSagh;
	int metr, santimetr;
	metr = (int)dMetr;
	const int smInMetr = 100;
	santimetr = (int)((dMetr - metr) * smInMetr);
	cout << "����� ���������� � ������ � �����������: " << endl;
	cout << "�����: " << metr << endl;
	cout << "����������: " << santimetr << endl;
}

double convertVelocityValuePart1(double velocityInput)
{
	// ������� �� ��/� � �/�
	const int metrInKm = 1000;
	const int secInHour = 3600;
	double velocityOutput = velocityInput * (double)metrInKm / secInHour;
	return velocityOutput;
}

double convertVelocityValuePart2(double velocityInput)
{
	// ������� �� �/� � ��/�
	const int metrInKm = 1000;
	const int secInHour = 3600;
	double velocityOutput = velocityInput / metrInKm * secInHour;
	return velocityOutput;
}

int sumOfNaturalNumbers(unsigned int range)
{
	// ����� ����������� ����� �� [1 �� range]
	int sum = 0;
	while (range)
		sum += range--;
	return sum;
}

int sumOfOddNaturalNumbers(unsigned int range)
{
	// ����� n-���������� �������� �����
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
	// ���������� ����������� ������� ������� �������� ������
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
	// ���������� ������� ������� ���������
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
	// ���������� ����������� ������� ���������� ����������� �����
	int castRange = count;
	if (size < count)
		castRange = size;
	int i = 0, numb = 1;
	while (i < castRange)
		arraySquaresNumbers[i++] = pow(numb++, 2);
}

void filling1DArrayOddNumbers(int* arrayOddNumbers, const int size, unsigned int count)
{
	// ���������� ����������� ������� ��������� �������
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
	// ���������� ����������� ������� ������� �������
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
	// ���������� ������� ��������� ������� � ������� 2 � ������� �������
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
	// ���������� ����������� ������� ����� ���� �� �������
	int castRange = count;
	if (size < count)
		castRange = size;
	int i = 0;
	while (i < castRange)
	{
		cout << "������� ����� �" << i + 1 << ": " << endl;
		cin >> myArray[i++];
	}
}

void filling1DArrayRandom(int* array, const unsigned int size, int limitA = -10, int limitB = 10)
{
	// ���������� ����������� ������� ���������� ����������
	for (int i = 0; i < size; i++)
		array[i] = randint(limitA, limitB);
}

int sumOddNaturalNumb(unsigned int count)
{
	// ����� n-���������� �������� ����������� �����
	int sum = 0;
	for (int i = 0, numb = 1; i < count; i++, sum += numb, numb += 2);
	return sum;
}

int sumEvenNaturalNumb(unsigned int count)
{
	// ����� n-������ ����������� �����
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
	// ����� ���� �����, �� ������� �������� ����� ������� ��� �������:
	if (numb < 0)
		numb = -numb;
	print("�����, �� ������� �������� ����� ������� ��� �������: ");
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
	// ���������� ����� �������� ���� �����
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
	// ������ ������������ ��������� �� ������������ �������
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
	// ��������� �����
	if (numb)
		return numb * fact(numb - 1);
	return 1;
}

double sinus(double x)
{
	// ���������� ������ �� ������������ �������
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
	// ���������� �������� �� ������������ �������
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
	// ���������� ���������������� ������ �� ������������ �������
	const int n = 10;
	double result = 0;
	for (int i = 0; i < n; i++) {
		result += (pow(x, 2 * i + 1) / fact(2 * i + 1));
	}
	return result;
}

double hypercosinus(double x)
{
	// ���������� ���������������� �������� �� ������������ �������
	const int n = 10;
	double result = 0;
	for (int i = 0; i < n; i++) {
		result += (pow(x, 2 * i) / fact(2 * i));
	}
	return result;
}

double calcMyfanc(double x)
{
	// ���������� (exp(x) - 1) / x �� ������������ �������
	const int n = 10;
	double result = 0;
	for (int i = 0; i < n; i++) {
		result += (pow(x, i) / fact(i + 1));
	}
	return result;
}

void printEquationSolutionPart1(double a, double b)
{
	// ��������� ���� Ax = B;
	if (a)
		cout << "������� ���������: x = " << b / a << endl;
	else if (b)
		cout << "������� ���" << endl;
	else
		cout << "������� - ����� �����" << endl;
}

void printEquationsSolutionPart2(int a, int b)
{
	// ��������� ���� Ax = B. ������� ����� �����
	if (a)
		if (b % a == 0)
			cout << "������� ���������: x = " << b / a << endl;
		else
			cout << "������� ���" << endl;
	else if (b)
		cout << "������� ���" << endl;
	else
		cout << "������� ����� �����" << endl;
}

void printAllSolutionsOfEquations(int limitA, int limitB)
{
	// ��������� ���� a ** 2 + b ** 2 = c ** 2. ��� ������� ��������� � �������� (limitA, limitB)
	double c;
	int count = 0;
	for (int i = 0; i < limitA; i++)
	{
		for (int j = 0; j < limitB; j++)
		{
			c = sqrt(pow(i, 2) + pow(j, 2));
			if ((int)c == c)
				cout << "������� �" << ++count << " a = " << i << " b = " << j << " c = " << (int)c << endl;
		}
	}
}

void printSolutionOfQuadraticEquation(double a, double b, double c)
{
	// ��������� ���� a * x ** 2 + b * x + c = 0;
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
		cout << "����� �����" << endl;
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
			cout << "�������������� ������ ��� ";
		break;
	}
	case 4:
		cout << "x1 = " << -c / b << endl;
		break;
	case 5:
		cout << "��� ������" << endl;
		break;
	case 6:
		cout << "x1 = " << 0 << endl;
		break;
	}
}

int sumDvider(unsigned int x)
{
	// ����� ���� ����������� ��������� �����
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
	// �������� �� ����� ��������� �� 1 �� 10
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
	// ���������� ����������� ������� ������� �������� �� ����������� ����� ������ �� �����������
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
	// ���������� ����������� �������: ������� ������ �� �������� ����� �������� �� �����������
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
	// ���������� ����������� ������� �� ��������
	for (int j = 0; j < size - 1; j++)
		for (int i = 0; i < size - 1; i++)
			if (array[i] < array[i + 1])
				swap<Num>(array, i);
}

template <typename Num>
void ReverseSort1DArray(Num* array, const int size)
{
	// ���������� ����������� ������� �� �������� ������ - ��������� �������, ������ - ������������� � �.�
	for (int i = 0; i < size / 2; i++)
	{
		Num temp = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = temp;
	}
}

int factV2(unsigned int number)
{
	// ��������� �����
	int result = 1;
	for (int i = 2; i <= number; i++)
		result *= i;
	return result;
}

int doubleFact(unsigned int number)
{
	// ������� ��������� �����
	if (number != 1 && number != 2)
		return number * doubleFact(number - 2);
	return number;
}

int doubleFactV2(unsigned int number)
{
	// ������� ��������� �����
	int result = 1;
	for (int i = 2 + number % 2; i <= number; i += 2)
		result *= i;
	return result;
}

int getFibonacciNumber(unsigned int number, unsigned int penultimate = 0, unsigned int last = 1)
{
	// ����� ����� ��������� �� ������ � ������������������ 1, 1, 2, 3, 5 ...
	if (number > 1)
		return getFibonacciNumber(number - 1, last, last + penultimate);
	return last;
}

int getFibonacciNumberV2(unsigned int number)
{
	// ����� ����� ��������� �� ������ � ������������������ 1, 1, 2, 3, 5 ...
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
	// ���������� ������������� ������������
	return fact(n) / (fact(k) * fact(n - k));
}

int sumNaturalNumbers(unsigned int limit)
{
	// ����� ���� ����������� ����� �� 1 �� limit
	if (limit > 1)
		return limit + sumNaturalNumbers(limit - 1);
	return limit;
}

double sumPowerNaturalNumbers(unsigned int limit, double power = 1)
{
	// ����� ���� �������� ����������� ����� �� 1 �� limit
	if (limit > 1)
		return pow(limit, power) + sumPowerNaturalNumbers(limit - 1, power);
	return limit;
}

double expApproximately(double x, unsigned int countIterations)
{
	// ���������� ���������� �� x ����� ��� ������� (!!��� �������� �� -1 �� 1)
	if (countIterations > 0)
		return expApproximately(x, countIterations - 1) + pow(x, countIterations) / fact(countIterations);
	return 1;
}

double overchargedFunction(double arg)
{
	// ������� ��������
	return arg;
}

double overchargedFunction(double arg1, double arg2)
{
	// ������� ����� ��������� ��������
	return arg1 * arg1 + arg2 * arg2;
}

double overchargedFunction(double arg1, double arg2, double arg3)
{
	// ������� ����� ����� ��������
	return pow(arg1, 3) + pow(arg2, 3) + pow(arg3, 3);
}

void divideBy2(int& element)
{
	// ������� �� 2
	element /= 2;
}

void changeAllElements1DArray(void (*F) (int&), int* array, unsigned int size)
{
	// ��������� ���� ��������� ����������� ������� ����� ��������� �� �������
	for (int i = 0; i < size; i++)
		F(array[i]);
}

void changeAllElements1DArray(int number, int* array, unsigned int size)
{
	// ��������� ���� ��������� ����������� �������
	for (int i = 0; i < size; i++)
		array[i] *= number;
}

pair <int, unsigned int> minElementOf1DArrayInRange(int* array, unsigned int start_i, unsigned int size)
{
	// ����� ������������ �������� � ��� ������� � ����� ����������� ������� ������������� �������� ������ � �����
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
	// ����� ������������� �������� � ��� ������� � ����� ����������� ������� ������������� �������� ������ � �����
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
	// ���������� ����������� ������� �� �����������/�������� � ����������� �� ��������� isSortDescending (0 - �� �����������, 1 - �� ��������)
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
	// ���������� ����������� ������� �� ����������� ����������� ���������� � ������� ��������� �� ��������� ������� �������
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
	// ���������� ����������� ������� �� �������� ����������� ���������� � ������� ������ �� ��������� ������� �������
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

void performance�omparison()
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
	// ������� ��� �����������������
	return x * x;
}

double derivative(double (*F) (double), double x, double point)
{
	// ���������� �����������
	return (F(x + point) - F(x)) / point;
}

double* derivative(double (*F) (double), double x, double* arrayPoints, unsigned int sizeArrayPoints, double* arrayResult)
{
	// ���������� ����������� � ������ ������ � ������ �� � ������
	for (int i = 0; i < sizeArrayPoints; i++)
		arrayResult[i] = (F(x + arrayPoints[i]) - F(x)) / arrayPoints[i];
	return arrayResult;
}

double calcPolinom(double* array, unsigned int size, double point)
{
	// ������ ��������
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += (array[i] * pow(point, i));
	return sum;
}

void calcPolinom(double* array, unsigned int size)
{
	// ������ �������� (����������)
	print("������������ ��������: ");
	print1DArray<double>(array, size);
}

int TheLongestWord(const string& text)
{
	// ������ ������ �������� �����
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
	// ���������� ������
	string result;
	print(text);
	getline(cin, result);
	return result;
}

char inputChar(string text)
{
	// ���������� �������
	char result;
	print(text);
	cin >> result;
	return result;
}

void printReverseLine(const string& text, unsigned int size)
{
	// ����� ������ � �������� �������
	if (size)
	{
		cout << text[size - 1];
		printReverseLine(text, --size);
	}
}

int countOfEntries(const string& text, char symbol)
{
	// ���������� �������� � ������ ������
	int count = 0;
	for (int i = 0; i < text.size(); i++)
		if (text[i] == symbol)
			count++;
	return count;
}

template <typename Num>
bool IsGreate(const Num& a, const Num& b)
{
	// ���� ������
	return a > b;
}

template <typename Num>
bool IsLess(const Num& a, const Num& b)
{
	// ���� ������
	return a < b;
}

template <typename Num>
Num& maxElement2DArray(Num** array, unsigned int sizeA, unsigned int sizeB)
{
	// ������������ ������� �� ������
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
	// ����������� ������� �� ���������
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
	// ����� ���� ��������� ���������� �������
	Num sum = 0;
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			sum += array[i][j];
	return sum;
}

template <typename Num>
double average2DArray(Num** array, unsigned int sizeA, unsigned int sizeB)
{
	// ������� �������������� ���������� �������
	if (sizeA == 0 || sizeB == 0)
		return 0;
	return sumOfElements2DArray<Num>(array, sizeA, sizeB) / ((double)sizeA * sizeB);
}

void filling2DArrayRandomSymbols(char** array, unsigned int sizeA, unsigned int sizeB)
{
	// ���������� ������� ���������� ���������
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			array[i][j] = randint(48, 122);
}

int countOfEntries(char** array, unsigned int sizeA, unsigned int sizeB, char symbol)
{
	// ���������� ��������� ������� � ��������� ������
	int count = 0;
	for (int i = 0; i < sizeA; i++)
		for (int j = 0; j < sizeB; j++)
			if (array[i][j] == symbol)
				count++;
	return count;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////// ����� 1: ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void task1()
{
	unsigned int rangeNumber = inputUInt("������� ����������� �����: ");
	printNumbersInRange(rangeNumber);
}

void task2()
{
	unsigned int count = inputUInt("������� ���������� �������� �����: ");
	printOddNumbersInRange(count);
}

void task3()
{
	unsigned int count = inputUInt("������� ���������� �����: ");
	printResiduesNumbers(count);
}

void task4()
{
	unsigned int count = inputUInt("������� ���������� ����� ���������: ");
	printFibNumbers(count);
}

void task5()
{
	int x = inputInt("������� ����� �����: ");
	print("������������ ������������: ");
	printBinomialKoeff(x);
}

void task6()
{
	double km = inputUDouble("������� ���������� � ���������� : ");
	cout << "���������� � ����� = " << convertKmToMilesPart1(km) << endl;
}

void task7()
{
	unsigned int km = inputUInt("������� ���������� � ����������: ");
	unsigned int m = inputUInt("������� ���������� � ������: ");
	convertKmToMilesPart2(km, m);
}

void task8()
{
	double saghen = inputUDouble("������� ���������� � �������: ");
	cout << "���������� � ������: " << convertSaghToMetrPart1(saghen) << endl;
}

void task9()
{
	unsigned int saghen = inputUInt("������� ��������� � �������: ");
	unsigned int arshin = inputUInt("������� ��������� � �������: ");
	convertSaghToMetrPart2(saghen, arshin);
}

void task10()
{
	double velocityInput = inputDouble("������� �������� � ��/�: ");
	cout << "�������� � �/�: " << convertVelocityValuePart1(velocityInput) << endl;
}

void task11()
{
	double velocityInput = inputDouble("������� �������� � �/�: ");
	cout << "�������� � ��/�: " << convertVelocityValuePart2(velocityInput) << endl;
}

void task12()
{
	unsigned int range = inputUInt("������� ������� ��� ����� ����������� �����: ");
	cout << "����� ����������� ����� = " << sumOfNaturalNumbers(range) << endl;
}

void task13()
{
	unsigned int range = inputUInt("������� ���������� �������� ����������� ����� ��� �����: ");
	cout << "����� �������� ����������� ����� = " << sumOfOddNaturalNumbers(range) << endl;
}

void task14()
{
	const int sizeArray = 1000;
	int arrayEvenNumbers[sizeArray];
	unsigned int count = inputUInt("������� ��������� ���������� ������ ����������� �����: ");
	filling1DArrayEvenNumbers(arrayEvenNumbers, sizeArray, count);
	print("������ �����: ");
	print1DArray<int>(arrayEvenNumbers, count);
}

void task15()
{
	const int sizeArray = 1000;
	int arrayOddNumbers[sizeArray];
	unsigned int count = inputUInt("������� ��������� ���������� �������� ����������� �����: ");
	filling1DArrayOddNumbers(arrayOddNumbers, sizeArray, count);
	print("�������� �����: ");
	print1DArray<int>(arrayOddNumbers, count);
}

void task16()
{
	const int sizeArray = 1000;
	int arraySquaresNumbers[sizeArray];
	unsigned int count = inputUInt("������� ��������� ���������� ��������� ����������� �����: ");
	filling1DArrayWithSquareNumbers(arraySquaresNumbers, sizeArray, count);
	print("���������� �����: ");
	print1DArray<int>(arraySquaresNumbers, count);
}

void task17()
{
	const int sizeArray = 30;
	int arrayStepTwoNumbers[sizeArray];
	unsigned int count = inputUInt("������� ��������� ���������� ����� �������� ������: ");
	filling1DArrayWithStepTwoNumbers(arrayStepTwoNumbers, sizeArray, count);
	print("����� c������� ������: ");
	print1DArray<int>(arrayStepTwoNumbers, count);
}

void task18()
{
	const int sizeArray = 40;
	int arrayFibonachiNumbers[sizeArray];
	unsigned int count = inputUInt("������� ��������� ���������� ����� ���������: ");
	filling1DArrayWithFibonachiNumbers(arrayFibonachiNumbers, sizeArray, count);
	print("����� ���������: ");
	print1DArray<int>(arrayFibonachiNumbers, count);
}

void task19()
{
	const int sizeArray = 1000;
	int customArray[sizeArray];
	unsigned int count = inputUInt("������� ��������� ���������� �����: ");
	filling1DArrayCustom(customArray, sizeArray, count);
	print("������ �� �������� ����� � ������� � ������ �����: ");
	print1DArray<int>(customArray, count);
}

void task20()
{
	const int sizeArray = 1000;
	int myArray[sizeArray];
	unsigned int count = inputUInt("������� ���������� �����: ");
	filling1DArrayFromInput(myArray, sizeArray, count);
	print("��������� ����� �������: ");
	print1DArray<int>(myArray, count);
}




////////////////////////////////////////////////////////////////////////////
////////////////////////////// ����� 2: ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void task21()
{
	unsigned int count = inputUInt("������� ���������� �������� ����������� �����: ");
	int sum = sumOddNaturalNumb(count);
	cout << "����� �������� ����������� �����: " << sum << endl;
}

void task22()
{
	unsigned int count = inputUInt("������� ���������� ������ ����������� �����: ");
	int sum = sumEvenNaturalNumb(count);
	cout << "����� ������ ����������� �����: " << sum << endl;
}

void task23()
{
	int numb = inputInt("������� ����� �����: ");
	printDivisionWithoutRemainder(numb);
}

void task24()
{
	printLine("������� ��� ����� �����.");
	int a = inputInt("������� ����� A: ");
	int b = inputInt("������� ����� B: ");
	int max_divider = greatestCommonDivider(a, b);
	cout << "���������� ����� �������� ���� �����: " << max_divider << endl;
}

void task25()
{
	double x = inputDouble("������� ����� x: ");
	cout << "����������� �������� = " << log(x) << endl;
	cout << "����������� �������� ~ " << naturalLogarithm(x) << endl;
}

void task26()
{
	double x = inputDouble("������� ����� x: ");
	cout << "����� = " << sin(x) << endl;
	cout << "����� ~ " << sinus(x) << endl;
}

void task27()
{
	double x = inputDouble("������� ����� x: ");
	cout << "������� = " << cos(x) << endl;
	cout << "������� ~ " << cosinus(x) << endl;
}

void task28()
{
	double x = inputDouble("������� ����� x: ");
	cout << "��������������� ����� = " << sinh(x) << endl;
	cout << "��������������� ����� ~ " << hyperSinus(x) << endl;
}

void task29()
{
	double x = inputDouble("������� ����� x: ");
	cout << "��������������� ������� = " << cosh(x) << endl;
	cout << "��������������� ������� ~ " << hypercosinus(x) << endl;
}

void task30()
{
	double x = inputDouble("������� ����� x: ");
	cout << "��������� = " << (exp(x) - 1) / x << endl;
	cout << "��������� ~ " << calcMyfanc(x) << endl;
}

void task31()
{
	printLine("������� ������������ ��������� ���� Ax = B");
	double a = inputDouble("������� A: ");
	double b = inputDouble("������� B: ");
	printEquationSolutionPart1(a, b);
}

void task32()
{
	printLine("������� ������������ ��������� ���� Ax = B. A � B ����� �����.");
	int a = inputDouble("������� A: ");
	int b = inputDouble("������� B: ");
	printEquationsSolutionPart2(a, b);
}

void task33()
{
	printLine("��� ������� ��������� a ** 2 + b ** 2 = c ** 2:");
	printAllSolutionsOfEquations(100, 100);
}

void task34()
{
	printLine("������� ������������ ����������� ��������� ���� a * x ** 2 + b * x + c = 0.");
	double a = inputDouble("������� ����������� a: ");
	double b = inputDouble("������� ����������� b: ");
	double c = inputDouble("������� ����������� c: ");
	print("������� ���������: ");
	printSolutionOfQuadraticEquation(a, b, c);
}

void task35()
{
	unsigned int x = inputUInt("������� ����� �����: ");
	cout << "����� ���� ����������� ��������� ����� " << x << " = " << sumDvider(x) << endl;
}

void task36()
{
	int numb = inputIntInRange("������� ����� �� 1 �� 10: ", 1, 10);
	cout << isFibonacciNumber(numb);
}

void task37()
{
	const int size = 10;
	int array[size];
	filling1DArrayRandom(array, size);
	print("������ �� ���������� ����������: ");
	print1DArray<int>(array, size);
	sortBubble1DArray(array, size);
	print("������ ����� ���������� ��������� �� ��������: ");
	print1DArray<int>(array, size);
}

void task38()
{
	const int size = 10;
	int array[size];
	filling1DArrayRandom(array, size);
	print("������ �� ���������� ����������: ");
	print1DArray<int>(array, size);
	ReverseSort1DArray(array, size);
	print("������ ����� ����������� ���������� ���������: ");
	print1DArray<int>(array, size);
}

void task39()
{
	const int size = 10;
	int array[size];
	filling1DArrayRandom(array, size);
	print("������ �� ���������� ����������: ");
	print1DArray<int>(array, size);
	customSort1DArray<int>(array, size);
	print("������ ����� ���������� (�������� �� �����������, ������ �� �����������): ");
	print1DArray<int>(array, size);
}

void task40()
{
	const int size = 10;
	int array[size];
	filling1DArrayRandom(array, size);
	print("������ �� ���������� ����������: ");
	print1DArray<int>(array, size);
	customSort2DArrayV2<int>(array, size);
	print("������ ����� ���������� (������ �� �������� � �������� �� �����������): ");
	print1DArray<int>(array, size);
}



////////////////////////////////////////////////////////////////////////////
////////////////////////////// ����� 3: ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void task41()
{
	unsigned int size = inputUInt("������� ����������� �������: ");
	int* array1 = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int* array2 = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int sum = sumOfPairwiseProductsOfArrays<int>(array1, array2, size);
	cout << "����� �������� ������������ ��������� ���� ��������: " << sum << endl;
	delete[] array1;
	delete[] array2;
}

void task42()
{
	unsigned int size = inputUInt("������� ����������� �������: ");
	int* array = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int sum = sumOfSquaresOf1DArray<int>(array, size);
	cout << "����� ��������� ��������� �������: " << sum << endl;
	delete[] array;
}

void task43()
{
	unsigned int size_i = inputUInt("������� ���������� ����� ��� ���������� �������: ");
	unsigned int size_j = inputUInt("������� ���������� �������� ��� ���������� �������: ");
	int** array = allocateAPlaceFor2DArrayRandom(size_i, size_j, -10, 10);
	int sum = sumOfSquares2DArray<int>(array, size_i, size_j);
	cout << "����� ��������� ��������� ���������� �������: " << sum << endl;
	delete2DArray<int>(array, size_i);
}

void task44()
{
	unsigned int sizeA = inputUInt("������� ���������� ����� ��� ���������� �������: ");
	unsigned int sizeB = inputUInt("������� ���������� �������� ��� ���������� �������: ");
	int** array = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, -10, 10);
	printLine("������ ����� ��������:");
	print2DArray<int>(array, sizeA, sizeB);
	int** newArray = transpose2DArray<int>(array, sizeA, sizeB);
	printLine("������ ����� ����������������:");
	print2DArray<int>(newArray, sizeB, sizeA);
	delete2DArray<int>(array, sizeA);
	delete2DArray<int>(newArray, sizeB);
}

void task45()
{
	unsigned int size = inputUInt("������� ����������� ����������� �������: ");
	int** array = allocateAPlaceFor2DArrayRandom(size, size, 1, 10);
	printLine("�������� ���������� �������:");
	print2DArray<int>(array, size, size);
	int** newArray = rotateClockwise2DArray<int>(array, size);
	printLine("���������� �� 90 �������� �� ������� ������� ���������� �������:");
	print2DArray<int>(newArray, size, size);
	delete2DArray<int>(array, size);
	delete2DArray<int>(newArray, size);
}

void task46()
{
	unsigned int size = inputUInt("������� ����������� ����������� �������: ");
	int** array = allocateAPlaceFor2DArrayRandom(size, size, 1, 10);
	printLine("�������� ���������� �������:");
	print2DArray<int>(array, size, size);
	int sum = traceOf2DArray<int>(array, size);
	cout << "���� ������� = " << sum << endl;
	delete2DArray<int>(array, size);
}

void task47()
{
	unsigned int size = inputUInt("������� ����������� ����������� �������: ");
	int* array = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	print("�������� �������: ");
	print1DArray<int>(array, size);
	int min = minElementOf1DArray<int>(array, size);
	int max = maxElementOf1DArray<int>(array, size);
	int posMin = getThePositionOfTheFirstEntry<int>(array, size, min);
	int posMax = getThePositionOfTheFirstEntry<int>(array, size, max);
	cout << "���������� ������� ������� = " << max << ". ������� � ������� = " << posMax << endl;
	cout << "���������� ������� ������� = " << min << ". ������� � ������� = " << posMin << endl;
	delete[] array;
}

void task48()
{
	unsigned int size = inputUInt("������� ����������� ����������� �������: ");
	int* array = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	print("�������� �������: ");
	print1DArray<int>(array, size);
	int countPermutations = inputInt("������� ���������� ������������ ���������: ");
	makePermutationsRightLeftFor1DArray<int>(array, size, countPermutations);
	print("�������� ������� ����� ������������: ");
	print1DArray<int>(array, size);
	delete[] array;
}

void task49()
{
	unsigned int sizeA = inputUInt("������� ���������� ����� ��� ���������� �������: ");
	unsigned int sizeB = inputUInt("������� ���������� �������� ��� ���������� �������: ");
	int** array = allocateAPlaceFor2DArray<int>(sizeA, sizeB);
	printLine("������ ����� ���������� ������������ ������� �� �������");
	filling2DArrayByRows(array, sizeA, sizeB);
	print2DArray<int>(array, sizeA, sizeB);
	delete2DArray<int>(array, sizeA);
}

void task50()
{
	unsigned int sizeA = inputUInt("������� ���������� ����� ��� ���������� �������: ");
	unsigned int sizeB = inputUInt("������� ���������� �������� ��� ���������� �������: ");
	int** array = allocateAPlaceFor2DArray<int>(sizeA, sizeB);
	filling2DArrayByColumns(array, sizeA, sizeB);
	printLine("������ ����� ���������� ������������ ������� �� ��������");
	print2DArray<int>(array, sizeA, sizeB);
	delete2DArray<int>(array, sizeA);
}

void task51()
{
	unsigned int size = inputUInt("������� ����������� ����������� �������: ");
	int** array = allocateAPlaceFor2DArray<int>(size, size);
	filling2DArray<int>(array, size, size, 0);
	fillingMainAndSideDiagonalsOf2DArray<int>(array, size, 1);
	printLine("������ ����� ���������� ���������� ���������� ����������");
	print2DArray<int>(array, size, size);
	delete2DArray<int>(array, size);
}

void task52()
{
	unsigned int sizeA = inputUInt("������� ���������� ����� ��� ������� ���������� �������: ");
	unsigned int sizeB = inputUInt("������� ���������� �������� ��� ������� ���������� �������: ");
	unsigned int sizeC = inputUInt("������� ���������� ����� ��� ������� ���������� �������: ");
	unsigned int sizeD = inputUInt("������� ���������� �������� ��� ������� ���������� �������: ");
	int** array1 = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, -10, 10);
	int** array2 = allocateAPlaceFor2DArrayRandom(sizeC, sizeD, -10, 10);
	printLine("������ ��������� ������:");
	print2DArray<int>(array1, sizeA, sizeB);
	printLine("������ ��������� ������:");
	print2DArray<int>(array2, sizeC, sizeD);
	printLine("������ ������������:");
	Multiplication2DArrays<int>(array1, sizeA, sizeB, array2, sizeC, sizeD);
	delete2DArray<int>(array1, sizeA);
	delete2DArray<int>(array2, sizeC);
}

void task53()
{
	char text[] = "This is the end";
	reverseArray(text);
	cout << "������ � �������� �������: " << text << endl;
}

void task54()
{
	unsigned int sizeA = inputUInt("������� ���������� ����� ��� ���������� �������: ");;
	unsigned int sizeB = inputUInt("������� ���������� �������� ��� ���������� �������: ");
	int** array = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, -10, 10);
	string sampleMinMax = inputMinOrMax("������� ������ ���������� ��������� ���������� ������ (min ��� max): ");
	string sampleRowColumn = inputRowOrColumn("������� ��� ������� ��������� �� ������� ��� �� �������� (row ��� column): ");
	printLine("����� ��������� �������");
	print2DArray<int>(array, sizeA, sizeB);
	int* arrayResult;
	cout << "����� " << sampleMinMax << " ��������� ������� �� " << sampleRowColumn << endl;
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
	cout << "����� ���������� ����: " << countWordsAndWordLength.first << endl;
	print("����� ���� ���� �� ������� ����� �������: ");
	for (int i = 0; i < countWordsAndWordLength.first; i++)
		cout << countWordsAndWordLength.second[i] << " ";
	delete[] countWordsAndWordLength.second;
}

void task56()
{
	const unsigned int size = randint(10, 100);
	int* array = allocateAPlaceFor1DArray<int>(size);
	symmetricalFilling1DArray(array, size);
	print("����������� ����������� ������: ");
	print1DArray<int>(array, size);
	delete[] array;
}

void task57()
{
	unsigned int size = inputUInt("������� ����������� ��� �������� 3-� ���������� ���������� ��������: ");
	int* array1 = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int* array2 = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int* array3 = allocateAPlaceFor1DArray<int>(size);
	string minMax = inputMinOrMax("������� ����� �� ���� �������� ���������� � �������� ������ (min ��� max): ");
	if (minMax == "min")
	{
		for (int i = 0; i < size; i++)
			array3[i] = min<int>(array1[i], array2[i]);
	}
	else
		for (int i = 0; i < size; i++)
			array3[i] = max<int>(array1[i], array2[i]);
	print("����� 1�� �������: ");
	print1DArray<int>(array1, size);
	print("����� 2�� �������: ");
	print1DArray<int>(array2, size);
	print("����� ��������� �������:");
	print1DArray<int>(array3, size);
	delete[] array1;
	delete[] array2;
	delete[] array3;
}

void task58()
{
	unsigned int sizeA = inputUInt("������� ����������� 1-�� ����������� �������: ");
	unsigned int sizeB = inputUInt("������� ����������� 2-�� ����������� �������: ");
	int* array1 = allocateAPlaceFor1DArrayRandom(sizeA, -10, 10);
	int* array2 = allocateAPlaceFor1DArrayRandom(sizeB, -10, 10);
	int* array3 = allocateAPlaceFor1DArray<int>(sizeA + sizeB);
	concat1DArrays<int>(array1, sizeA, array2, sizeB, array3);
	print("����� ������� �������: ");
	print1DArray<int>(array1, sizeA);
	print("����� ������� �������: ");
	print1DArray<int>(array2, sizeB);
	print("����� ������� �����������: ");
	print1DArray<int>(array3, sizeA + sizeB);
	delete[] array1;
	delete[] array2;
	delete[] array3;
}

void task59()
{
	unsigned int size = inputUInt("������� ����������� ��� �������� 2-� ���������� ���������� ��������: ");
	int* array1 = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int* array2 = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	int* array3 = allocateAPlaceFor1DArray<int>(2 * size);
	concat1DArrays<int>(array1, array2, size, array3);
	print("����� ������� �������: ");
	print1DArray<int>(array1, size);
	print("����� ������� �������: ");
	print1DArray<int>(array2, size);
	print("����� ������� �����������: ");
	print1DArray<int>(array3, 2 * size);
	delete[] array1;
	delete[] array2;
	delete[] array3;
}

void task60()
{
	unsigned int sizeA = inputUInt("������� ���������� ����� ��� ���������� �������: ");
	unsigned int sizeB = inputUInt("������� ���������� �������� ��� ���������� �������: ");
	int newSizeA = sizeA - 1;
	int newSizeB = sizeB - 1;
	adaptation(newSizeA, newSizeB);
	unsigned int row = inputIntInRange("������� ����� ������ ������� ���������� ���������� ", 0, newSizeA);
	unsigned int column = inputIntInRange("������� ����� ������� ������� ���������� ���������� ", 0, newSizeB);
	int** array = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, 1, 9);
	printLine("����� ��������� ��������� ������� ���������� �������:");
	print2DArray<int>(array, sizeA, sizeB);
	int** newArray = allocateAPlaceFor2DArray<int>(newSizeA, newSizeB);
	minor2DArray<int>(array, sizeA, sizeB, newArray, row, column);
	printLine("����� ������ ���������� �������:");
	print2DArray<int>(newArray, newSizeA, newSizeB);
	delete2DArray<int>(array, sizeA);
	delete2DArray<int>(newArray, newSizeA);
}



////////////////////////////////////////////////////////////////////////////
////////////////////////////// ����� 4: ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void task61()
{
	unsigned int number = inputUInt("������� ����� ��������������� �����: ");
	cout << "��������� ��������� = " << fact(number) << endl;
	cout << "��������� ������ = " << factV2(number) << endl;
}

void task62()
{
	unsigned int number = inputUInt("������� ����� ��������������� �����: ");
	cout << "������� ��������� ��������� = " << doubleFact(number) << endl;
	cout << "������� ��������� ������ = " << doubleFactV2(number) << endl;
}

void task63()
{
	unsigned int number = inputUInt("������� ����� ����� � ������������������ ���������: ");
	cout << "����� ��������� ��������� = " << getFibonacciNumber(number) << endl;
	cout << "����� ��������� ������ = " << getFibonacciNumberV2(number) << endl;
}

void task64()
{
	cout << calcBinomialKoeff(5, 4);
}

void task65()
{
	unsigned int countNaturalNumbers = inputUInt("������� ���������� ����������� ����� ��� ���������� ����� ");
	double powerNaturalNumbers = inputDouble("������� ������� ����������� ����� ��� ���������� ����� ");
	int sum = sumNaturalNumbers(countNaturalNumbers);
	double sumPower = sumPowerNaturalNumbers(countNaturalNumbers, powerNaturalNumbers);
	cout << "����� ����������� ����� = " << sum << endl;
	cout << "����� �������� ����������� �����  = " << sumPower << endl;
}

void task66()
{
	double x = inputDouble("������� �������� x ��� ������� exp(x): ");
	unsigned int countIterations = inputUInt("������� ���������� �������� ��� ������� ����������: ");
	cout << "���������� = " << exp(x) << endl;
	cout << "���������� ~ " << expApproximately(x, countIterations) << endl;
}

void task67()
{
	double number1 = inputDouble("������� ������ ����� � ��������� ������ ");
	double number2 = inputDouble("������� ������ ����� � ��������� ������ ");
	double number3 = inputDouble("������� ������ ����� � ��������� ������ ");
	cout << "����� ������� ���������� �����: " << overchargedFunction(number1) << endl;
	cout << "����� ����� ��������� ������ ���� �����: " << overchargedFunction(number1, number2) << endl;
	cout << "����� ����� ����� ���� �����: " << overchargedFunction(number1, number2, number3) << endl;
}

void task68()
{
	unsigned int size = inputUInt("������� ������ ����������� �������: ");
	int* array = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	print("������ ����������� ��������� �������: ");
	print1DArray<int>(array, size);
	void (*func) (int&) = divideBy2;
	changeAllElements1DArray(func, array, size);
	print("������ ����� ��������� ���� ���������: ");
	print1DArray<int>(array, size);
	changeAllElements1DArray(randint(), array, size);
	print("������ ����� ��������� ���� ��������� ��� ���: ");
	print1DArray<int>(array, size);
	delete[] array;
}

void task69()
{
	double number = inputDouble("������� �������� ��� ���������� �����������: ");
	double (*funcForDerivative) (double) = f;
	double point = inputDouble("������� � ����� ����� ���������� ��������� �����������: ");
	cout << "����������� �� " << number << " � ����� " << point << " ����� " << derivative(funcForDerivative, number, point) << endl;
	const unsigned int size = 10;
	double* arrayPoints = allocateAPlaceFor1DArrayRandom(size, 0.01, 10.0);
	double* arrayResult = allocateAPlaceFor1DArray<double>(size);
	arrayResult = derivative(funcForDerivative, number, arrayPoints, size, arrayResult);
	print("�������� ���� ����������� � �������� ������: ");
	print1DArray<double>(arrayResult, size);
	delete[] arrayPoints;
	delete[] arrayResult;
}

void task70()
{
	const unsigned int size = 10;
	double* array = allocateAPlaceFor1DArrayRandom(size, -10.0, 10.0);
	double number = inputDouble("������� �������� � ������� ����� �������� ������� ");
	double sum = calcPolinom(array, size, number);
	cout << "��������� �������� ��������: " << sum << endl;
	calcPolinom(array, size);
	delete[] array;
}

void task71()
{
	unsigned int size = inputUInt("������� ������ ����������� �������: ");
	int* array = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	print("����� ����������� �������: ");
	print1DArray<int>(array, size);
	int* lastElement = sortedBubbleAscending(array, size);
	print("����� ����������� ������� ����� ���������� �� �����������: ");
	print1DArray<int>(array, size);
	cout << "��������� �� ��������� ������� ������� = " << lastElement << endl;
	cout << "�������� �� ����� ��������� = " << *lastElement << endl;
	delete[] array;
}

void task72()
{
	unsigned int size = inputUInt("������� ������ ����������� �������: ");
	int* array = allocateAPlaceFor1DArrayRandom(size, -10, 10);
	print("����� ����������� �������: ");
	print1DArray<int>(array, size);
	int& lastElement = sortedBubbleDescending(array, size);
	print("����� ����������� ������� ����� ���������� �� ��������: ");
	print1DArray<int>(array, size);
	cout << "�������� ���������� �������� �� ������ = " << lastElement << endl;
	lastElement = 44;
	cout << "�������� ���������� �������� �� ������ ����� ��������� = " << lastElement << endl;
	delete[] array;
}

void task73()
{
	string text = getLine("������� �����: ");
	cout << "������ ������ �������� ����� = " << TheLongestWord(text) << endl;
}

void task74()
{
	string text = getLine("������� �����: ");
	print("����� � �������� �������: ");
	printReverseLine(text, text.size());
}

void task75()
{
	string text = getLine("������� �����: ");
	char symbol = inputChar("������� ������: ");
	cout << "���������� �������� " << symbol << " � ������: " << countOfEntries(text, symbol) << endl;
}

void task76()
{
	unsigned int sizeA = inputUInt("������� ���������� ����� ���������� ������� ");
	unsigned int sizeB = inputUInt("������� ���������� �������� ���������� ������� ");
	double** array = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, -10.0, 10.0);
	printLine("����� ���������� �������");
	print2DArray<double>(array, sizeA, sizeB);
	double& max = maxElement2DArray<double>(array, sizeA, sizeB);
	cout << "������������ ������� ���������� �������: " << max << endl;
	delete2DArray<double>(array, sizeA);
}

void task77()
{
	unsigned int sizeA = inputUInt("������� ���������� ����� ���������� ������� ");
	unsigned int sizeB = inputUInt("������� ���������� �������� ���������� ������� ");
	double** array = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, -10.0, 10.0);
	printLine("����� ���������� �������");
	print2DArray<double>(array, sizeA, sizeB);
	double* pMin = minElement2DArray<double>(array, sizeA, sizeB);
	cout << "����������� ������� ���������� ������� �� ���������: " << *pMin << endl;
	delete2DArray<double>(array, sizeA);
}

void task78()
{
	unsigned int sizeA = inputUInt("������� ���������� ����� ���������� ������� ");
	unsigned int sizeB = inputUInt("������� ���������� �������� ���������� ������� ");
	int** array = allocateAPlaceFor2DArrayRandom(sizeA, sizeB, -10, 10);
	printLine("����� ���������� �������");
	print2DArray<int>(array, sizeA, sizeB);
	cout << "������� �������������� ���������� ������� = " << average2DArray<int>(array, sizeA, sizeB) << endl;
	delete2DArray<int>(array, sizeA);
}

void task79()
{
	unsigned int sizeA = inputUInt("������� ���������� ����� ���������� ������� ");
	unsigned int sizeB = inputUInt("������� ���������� �������� ���������� ������� ");
	char symbol = inputChar("������� ������ ��� �������� ���������� ����� �������� � ��������� ������� ");
	char** array = allocateAPlaceFor2DArray<char>(sizeA, sizeB);
	filling2DArrayRandomSymbols(array, sizeA, sizeB);
	printLine("������ ��������� ��������: ");
	print2DArray<char>(array, sizeA, sizeB);
	cout << "���������� �������� " << symbol << " � ������� = " << countOfEntries(array, sizeA, sizeB, symbol) << endl;
	delete2DArray<char>(array, sizeA);
}



////////////////////////////////////////////////////////////////////////////
////////////////////////////// ����� 5: ////////////////////////////////////
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
		printLine("�������������� ��������� ���������������:");
		cout << "������ = " << width << endl;
		cout << "������� = " << depth << endl;
		cout << "������ = " << height << endl;
		cout << "����� = " << volume << endl;
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
		printLine("�������������� ��������� ���������������:");
		cout << "������ = " << getWidth() << endl;
		cout << "������� = " << getDepth() << endl;
		cout << "������ = " << getHeight() << endl;
		cout << "����� = " << getVolume() << endl;
		cout << "����� = " << mass << endl;
		cout << "��������� = " << calcDensity() << endl;
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

	Car(string brand, double volumeTank, double fuel�onsumption, double colorRGB[3]) : brand(brand), volumeTank(volumeTank), fuel�onsumption(fuel�onsumption)
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
		return (volumeTank / fuel�onsumption) * 100;
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

	double getFuel�onsumption()
	{
		return fuel�onsumption;
	}

	virtual void getInfo() = 0;

protected:
	string brand; // �����
	double volumeTank; // ����� � ������
	double fuel�onsumption; // ������ ������� ����� / 100 ��
	double* colorRGB; // ����
};

class PassengerCar : public Car
{
public:

	PassengerCar(string brand, double volumeTank, double fuel�onsumption, double colorRGB[3]) : Car(brand, volumeTank, fuel�onsumption, colorRGB) {}

	virtual ~PassengerCar() {}

	virtual void getInfo()
	{
		double* color = getColorRGB();
		print("�����: ");
		cout << getBrand() << endl;
		print("���� � ������� RGB: ");
		cout << "R = " << color[0] << " G = " << color[1] << " B = " << color[2] << endl;
		print("����� ���� � ������: ");
		cout << getVolumeTank() << endl;
		print("���������� ������ ������� � / 100 ��: ");
		cout << getFuel�onsumption() << endl;
		print("��������� ����������, ������� �������� �������� ���������� ������������ ������ ��� �������: ");
		cout << calcPosibleDistanceOnFullTank() << endl;
	}
private:
	virtual double calcTransportationCost(double priceOfOneLiterOfFuel) { return 1; }
};

class Truck : public Car
{
public:

	Truck(string brand, double volumeTank, double fuel�onsumption, double colorRGB[3], double carrying�apacity) : Car(brand, volumeTank, fuel�onsumption, colorRGB)
	{
		this->carrying�apacity = carrying�apacity;
	}

	virtual ~Truck() {}

	double calcTransportationCost(double priceOfOneLiterOfFuel)
	{
		return ((getFuel�onsumption() * priceOfOneLiterOfFuel) / 100) / carrying�apacity;
	}

	virtual void getInfo()
	{
		double* color = getColorRGB();
		print("�����: ");
		cout << getBrand() << endl;
		print("���� � ������� RGB: ");
		cout << "R = " << color[0] << " G = " << color[1] << " B = " << color[2] << endl;
		print("����� ���� � ������: ");
		cout << getVolumeTank() << endl;
		print("���������� ������ ������� � / 100 ��: ");
		cout << getFuel�onsumption() << endl;
		print("��������� ����������, ������� �������� �������� ���������� ������������ ������ ��� �������: ");
		cout << calcPosibleDistanceOnFullTank() << endl;
		print("���������������� � ������: ");
		cout << carrying�apacity << endl;
	}

private:
	double carrying�apacity; // ���������������� �����
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////// ����� 6: ////////////////////////////////////
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