#pragma once
#include <random>
#include <time.h>

class MemoryGame
{
private:
	int field_size; // размер поля (4, 5, 6)
	int square_size; // размер квадрата
	int size; // количество квадратов (16, 25, 36)

public:
	bool* squares; // квадраты
	int timer; // таймер
	int number_of_squares; // количество закрашенных квадратов
	int number_of_selected_squares; // количество выбранных квадратов
	bool without_mistakes; // пройден уровень без ошибок или с ошибками
	bool game_started; // игра началась или нет
	bool game_over; // игра закончена или нет
	int scores; // очки
	int max_scores; // максимум очков

	// конструктор
	MemoryGame()
	{
		max_scores = 0;
	}

	// деструктор
	~MemoryGame()
	{
		if (squares)
		{
			delete[] squares;
		}
	}

	// сеттер для field_size
	void SetFieldSize(int field_size)
	{
		this->field_size = field_size;
		square_size = 480 / field_size;
		size = field_size * field_size;
	}

	// геттер для field_size
	int GetFieldSize()
	{
		return field_size;
	}

	// геттер для square_size
	int GetSquareSize()
	{
		return square_size;
	}

	// геттер для size
	int GetSize()
	{
		return size;
	}

	// функция, которая создаёт игру
	void CreateGame()
	{
		timer = 60;
		game_over = false;
		number_of_squares = 2;
		without_mistakes = true;
		scores = 0;

		if (squares)
		{
			delete[] squares;
		}

		squares = new bool[size];
	}

	// функция, которая создаёт новый уровень
	void NewGame()
	{	
		srand(time(NULL));
		game_started = false;
		number_of_selected_squares = 0;

		for (int i = 0; i < size; i++)
		{
			squares[i] = false;
		}

		if (without_mistakes)
		{
			number_of_squares++;
		}

		else if (number_of_squares > 3)
		{
			number_of_squares--;
		}

		for (size_t i = 0; i < number_of_squares; i++)
		{
			int j = rand() % size; // индекс

			if (!squares[j])
			{
				squares[j] = true;
			}

			else
			{
				while (squares[j] != false)
				{
					j = rand() % size;
				}

				squares[j] = true;
			}
		}	
	}
};
