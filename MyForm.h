#include "MemoryGame.h"
#pragma once

MemoryGame game;

namespace MemorySimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			MainScreen();

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ main_container; // основной контейнер
	private: System::Windows::Forms::Button^ button_play; // кнопка "Начать игру"
	private: System::Windows::Forms::Button^ help_button; // кнопка "?"
	private: System::Windows::Forms::ComboBox^ comboBox1; // раскрывающийся список с размерами поля
	private: System::Windows::Forms::Label^ field_size_label; // надпись "Выберите размер поля"
	private: System::Windows::Forms::Timer^ stopwatch; // секундомер
	private: System::Windows::Forms::Label^ timer_label; // надпись с таймером
	private: System::Windows::Forms::Panel^ game_container; // контейнер для игрового поля
	private: System::Windows::Forms::Button^ button_back; // кнопка "<<"
	private: System::Windows::Forms::Label^ scores_label; // надпись с очками
	private: System::Windows::Forms::Label^ game_over_label; // надпись об окончании игры
	private: System::Windows::Forms::Button^ start_game_button; // кнопка "Запомнил!"
	private: System::Windows::Forms::Label^ help_label; // надпись "Правила игры"
	private: System::Windows::Forms::Button^ new_game_button; // кнопка новая игра
	private: System::Windows::Forms::Label^ rules_of_game_label; // надпись с правилами игры

	private: System::ComponentModel::IContainer^ components; // компоненты


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->main_container = (gcnew System::Windows::Forms::Panel());
			this->rules_of_game_label = (gcnew System::Windows::Forms::Label());
			this->help_label = (gcnew System::Windows::Forms::Label());
			this->field_size_label = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button_play = (gcnew System::Windows::Forms::Button());
			this->help_button = (gcnew System::Windows::Forms::Button());
			this->button_back = (gcnew System::Windows::Forms::Button());
			this->game_over_label = (gcnew System::Windows::Forms::Label());
			this->start_game_button = (gcnew System::Windows::Forms::Button());
			this->game_container = (gcnew System::Windows::Forms::Panel());
			this->scores_label = (gcnew System::Windows::Forms::Label());
			this->timer_label = (gcnew System::Windows::Forms::Label());
			this->stopwatch = (gcnew System::Windows::Forms::Timer(this->components));
			this->new_game_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// main_container
			// 
			this->main_container->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->main_container->BackColor = System::Drawing::Color::Transparent;
			this->main_container->Location = System::Drawing::Point(10, 6);
			this->main_container->Name = L"main_container";
			this->main_container->Size = System::Drawing::Size(660, 660);
			this->main_container->TabIndex = 0;
			// 
			// rules_of_game_label
			// 
			this->rules_of_game_label->AutoSize = true;
			this->rules_of_game_label->BackColor = System::Drawing::Color::Transparent;
			this->rules_of_game_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->rules_of_game_label->ForeColor = System::Drawing::Color::White;
			this->rules_of_game_label->Location = System::Drawing::Point(200, 88);
			this->rules_of_game_label->MaximumSize = System::Drawing::Size(250, 0);
			this->rules_of_game_label->Name = L"rules_of_game_label";
			this->rules_of_game_label->Size = System::Drawing::Size(20, 0);
			this->rules_of_game_label->TabIndex = 5;
			this->rules_of_game_label->Text = resources->GetString(L"rules_of_game_label.Text");
			// 
			// help_label
			// 
			this->help_label->AutoSize = true;
			this->help_label->BackColor = System::Drawing::Color::Transparent;
			this->help_label->ForeColor = System::Drawing::Color::White;
			this->help_label->Location = System::Drawing::Point(250, 30);
			this->help_label->Name = L"help_label";
			this->help_label->Size = System::Drawing::Size(225, 36);
			this->help_label->TabIndex = 4;
			this->help_label->Text = L"Правила игры";
			// 
			// field_size_label
			// 
			this->field_size_label->AutoSize = true;
			this->field_size_label->BackColor = System::Drawing::Color::Transparent;
			this->field_size_label->ForeColor = System::Drawing::Color::White;
			this->field_size_label->Location = System::Drawing::Point(195, 220);
			this->field_size_label->Name = L"field_size_label";
			this->field_size_label->Size = System::Drawing::Size(354, 36);
			this->field_size_label->TabIndex = 3;
			this->field_size_label->Text = L"Выберите размер поля";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::Color::White;
			this->comboBox1->DisplayMember = L"1";
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"4x4", L"5x5", L"6x6" });
			this->comboBox1->Location = System::Drawing::Point(280, 270);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 0;
			// 
			// button_play
			// 
			this->button_play->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_play->BackColor = System::Drawing::Color::White;
			this->button_play->Location = System::Drawing::Point(198, 340);
			this->button_play->Name = L"button_play";
			this->button_play->Size = System::Drawing::Size(264, 45);
			this->button_play->TabIndex = 1;
			this->button_play->Text = L"Начать игру";
			this->button_play->UseVisualStyleBackColor = false;
			this->button_play->Click += gcnew System::EventHandler(this, &MyForm::button_play_Click);
			// 
			// help_button
			// 
			this->help_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->help_button->BackColor = System::Drawing::Color::White;
			this->help_button->Location = System::Drawing::Point(590, 590);
			this->help_button->Name = L"help_button";
			this->help_button->Size = System::Drawing::Size(55, 55);
			this->help_button->TabIndex = 2;
			this->help_button->Text = L"\?";
			this->help_button->UseVisualStyleBackColor = false;
			this->help_button->Click += gcnew System::EventHandler(this, &MyForm::help_button_Click);
			// 
			// button_back
			// 
			this->button_back->BackColor = System::Drawing::Color::White;
			this->button_back->Location = System::Drawing::Point(15, 21);
			this->button_back->Name = L"button_back";
			this->button_back->Size = System::Drawing::Size(75, 54);
			this->button_back->TabIndex = 0;
			this->button_back->Text = L"<<";
			this->button_back->UseVisualStyleBackColor = false;
			this->button_back->Click += gcnew System::EventHandler(this, &MyForm::button_back_Click);
			// 
			// game_over_label
			// 
			this->game_over_label->AutoSize = true;
			this->game_over_label->BackColor = System::Drawing::Color::Transparent;
			this->game_over_label->ForeColor = System::Drawing::Color::White;
			this->game_over_label->Location = System::Drawing::Point(130, 599);
			this->game_over_label->Name = L"game_over_label";
			this->game_over_label->Size = System::Drawing::Size(412, 36);
			this->game_over_label->TabIndex = 8;
			this->game_over_label->Text = L"Игра закончилась! Рекорд:";
			// 
			// start_game_button
			// 
			this->start_game_button->BackColor = System::Drawing::Color::White;
			this->start_game_button->Location = System::Drawing::Point(220, 585);
			this->start_game_button->Name = L"start_game_button";
			this->start_game_button->Size = System::Drawing::Size(220, 55);
			this->start_game_button->TabIndex = 2;
			this->start_game_button->Text = L"Запомнил!";
			this->start_game_button->UseVisualStyleBackColor = false;
			this->start_game_button->Click += gcnew System::EventHandler(this, &MyForm::start_game_button_Click);
			// 
			// game_container
			// 
			this->game_container->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->game_container->BackColor = System::Drawing::Color::White;
			this->game_container->Location = System::Drawing::Point(90, 90);
			this->game_container->Name = L"game_container";
			this->game_container->Size = System::Drawing::Size(480, 480);
			this->game_container->TabIndex = 5;
			// 
			// scores_label
			// 
			this->scores_label->AutoSize = true;
			this->scores_label->BackColor = System::Drawing::Color::Transparent;
			this->scores_label->ForeColor = System::Drawing::Color::White;
			this->scores_label->Location = System::Drawing::Point(260, 30);
			this->scores_label->Name = L"scores_label";
			this->scores_label->Size = System::Drawing::Size(121, 36);
			this->scores_label->TabIndex = 7;
			this->scores_label->Text = L"Очки: 0";
			// 
			// timer_label
			// 
			this->timer_label->AutoSize = true;
			this->timer_label->BackColor = System::Drawing::Color::Transparent;
			this->timer_label->ForeColor = System::Drawing::Color::White;
			this->timer_label->Location = System::Drawing::Point(590, 30);
			this->timer_label->Name = L"timer_label";
			this->timer_label->Size = System::Drawing::Size(49, 36);
			this->timer_label->TabIndex = 4;
			this->timer_label->Text = L"60";
			// 
			// stopwatch
			// 
			this->stopwatch->Interval = 1000;
			this->stopwatch->Tick += gcnew System::EventHandler(this, &MyForm::stopwatch_Tick);
			// 
			// new_game_button
			// 
			this->new_game_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"new_game_button.BackgroundImage")));
			this->new_game_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->new_game_button->Location = System::Drawing::Point(15, 585);
			this->new_game_button->Name = L"new_game_button";
			this->new_game_button->Size = System::Drawing::Size(55, 55);
			this->new_game_button->TabIndex = 1;
			this->new_game_button->UseVisualStyleBackColor = true;
			this->new_game_button->Click += gcnew System::EventHandler(this, &MyForm::new_game_button_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(17, 36);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(682, 673);
			this->Controls->Add(this->main_container);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
			this->MinimumSize = System::Drawing::Size(700, 720);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Тренажёр для памяти";
			this->ResumeLayout(false);

		}

		// функция, которая создаёт главный экран
		void MainScreen()
		{
			main_container->Controls->Clear();

			if (!comboBox1->SelectedItem)
			{
				comboBox1->SelectedItem = comboBox1->Items[0];
			}

			main_container->Controls->Add(field_size_label);
			main_container->Controls->Add(comboBox1);
			main_container->Controls->Add(button_play);
			main_container->Controls->Add(help_button);
		}

		// функция, которая создаёт экран "Правила игры"
		void HelpScreen()
		{
			main_container->Controls->Clear();

			main_container->Controls->Add(button_back);
			main_container->Controls->Add(help_label);
			main_container->Controls->Add(rules_of_game_label);
		}

		// функция, которая создаёт новый уровень
		void NewGame()
		{
			if (game.number_of_squares == game.GetSize())
			{
				GameOver();
				return;
			}

			game.NewGame();
			game.without_mistakes = true;

			game_container->Controls->Clear();

			int size = game.GetSize(); // количество квадратов
			int field_size = game.GetFieldSize(); // размер поля
			int square_size = game.GetSquareSize(); // размер квадрата

			for (size_t i = 0; i < size; i++)
			{
				Button^ btn = gcnew Button(); // кнопка квадрат 

				if (game.squares[i])
				{
					btn->BackColor = System::Drawing::Color::LawnGreen;
				}

				else
				{
					btn->BackColor = System::Drawing::Color::DarkBlue;
				}

				btn->Location = System::Drawing::Point(i % field_size * square_size, i / field_size * square_size);
				btn->Name = System::Convert::ToString(i);
				btn->Size = System::Drawing::Size(square_size, square_size);
				btn->TabIndex = i + 10;
				btn->UseVisualStyleBackColor = false;
				btn->Click += gcnew System::EventHandler(this, &MyForm::game_btn_Click);
				game_container->Controls->Add(btn);
			}

			main_container->Controls->Add(start_game_button);
			main_container->Controls->Add(new_game_button);
		}

		// функция, которая создаёт игру
		void CreateGame()
		{
			main_container->Controls->Clear();

			timer_label->Text = L"60";
			scores_label->Text = L"Очки: 0";

			main_container->Controls->Add(game_container);
			main_container->Controls->Add(button_back);
			main_container->Controls->Add(scores_label);
			main_container->Controls->Add(timer_label);

			game.CreateGame();

			NewGame();

			stopwatch->Enabled = true;
		}

		// функция, которая завершает игру
		void GameOver()
		{
			game.game_over = true;
			stopwatch->Enabled = false;
			main_container->Controls->Remove(start_game_button);

			if (game.scores > game.max_scores)
			{
				game.max_scores = game.scores;
			}

			game_over_label->Text = L"Игра закончилась! Рекорд: " + Convert::ToString(game.max_scores);

			main_container->Controls->Add(game_over_label);
		}

#pragma endregion
		// функция, которая вызывается при нажатии на кнопку "Начать игру"
		private: System::Void button_play_Click(System::Object^ sender, System::EventArgs^ e)
		{
			int field_size = Convert::ToInt16(comboBox1->SelectedItem->ToString()[0]) - 48; // размер поля
			game.SetFieldSize(field_size);
			CreateGame();
		}

		// функция, которая вызывается при нажатии на кнопку квадрат
		private: System::Void game_btn_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (!game.game_started || game.game_over)
			{
				return;
			}

			Button^ btn = safe_cast<Button^>(sender); // кнопка квадрат, на которую нажали

			if (btn->BackColor != System::Drawing::Color::DarkBlue)
			{
				return;
			}

			int i = Convert::ToInt16(btn->Name); // индекс

			if (game.squares[i])
			{
				game.number_of_selected_squares++;
				btn->BackColor = System::Drawing::Color::LawnGreen;
				game.scores += game.GetFieldSize() * (game.number_of_squares - 2) * (game.GetFieldSize() - 3);
			}

			else
			{
				game.without_mistakes = false;
				btn->BackColor = System::Drawing::Color::Firebrick;
				game.scores -= game.GetFieldSize() * (game.number_of_squares - 2) * (game.GetFieldSize() - 3);

				if (game.scores < 0)
				{
					game.scores = 0;
				}
			}

			scores_label->Text = L"Очки: " + Convert::ToString(game.scores);

			if (game.number_of_selected_squares == game.number_of_squares)
			{
				NewGame();
			}
		}

		// функция, которая вызывается каждую секунду
		private: System::Void stopwatch_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			if (game.timer == 0)
			{
				GameOver();
				return;
			}

			game.timer--;

			String^ seconds = L""; // строка с секундами

			if (game.timer < 10)
			{
				seconds += L"0";
			}

			seconds += System::Convert::ToString(game.timer);
			timer_label->Text = seconds;
		}

		// функция, которая вызывается при нажатии на кнопку "<<"
		private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e)
		{
			stopwatch->Enabled = false;
			MainScreen();
		}

		// функция, которая вызывается при нажатии на кнопку "Запомнил!"
		private: System::Void start_game_button_Click(System::Object^ sender, System::EventArgs^ e)
		{
			main_container->Controls->Remove(start_game_button);
			game.game_started = true;

			int size = game.GetSize(); // количество квадратов

			for (size_t i = 0; i < size; i++)
			{
				if (game.squares[i])
				{
					auto btn = game_container->Controls->Find(Convert::ToString(i), false)[0]; // кнопка закрашенный квадрат
					btn->BackColor = System::Drawing::Color::DarkBlue;
				}
			}
		}

		// функция, которая вызывается при нажатии на кнопку "?"
		private: System::Void help_button_Click(System::Object^ sender, System::EventArgs^ e)
		{
			HelpScreen();
		}

		// функция, которая вызывается при нажатии на кнопку новая игра
		private: System::Void new_game_button_Click(System::Object^ sender, System::EventArgs^ e) {
			stopwatch->Enabled = false;
			CreateGame();
		}
	};
}