#include<iostream>

#include<set>
#include<map>
#include<unordered_set>

#include<vector>
#include<string>
#include<random>

void DemoBase() {
	std::vector<int>initialData;
	initialData.reserve(10);
	//===================================================================
	std::random_device rd;										//источник истнинно случайных чисел
	std::mt19937 provider(rd());								//источник псевдо случайных чисел,начальное значение задано случайно
	std::uniform_int_distribution<int>distributor(10, 99);	//класс доставщик чисел."Причесывает до нужного нам диапазона
	//===================================================================
	for (int i = initialData.size(); i < initialData.capacity(); i++)
	{
		initialData.push_back(distributor(provider));

	}
	//===================================================================
	std::set<int>uniqueData;							// для класса сет должен присуиствовать оператор "<"
	for (auto& element : initialData)
	{
		/*bool flag{ true };
		for (auto& uElement : uniqueData) {
			if (element == uElement) {
				flag = false;
				break;
			}
		}
		if (flag) {
			uniqueData.push_back(element);
		}*/
		uniqueData.insert(element);
	}
	std::cout << "Attall elemrnts " << initialData.size() << '\n';
	for (auto &i:initialData)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
	std::cout << "Unique elemrnts " << uniqueData.size() << '\n';
	for (auto& i : uniqueData)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

class A { };

namespace std {

	template<>
	struct less<A> {
		bool operator()(const A& a, const A& b) const {
			return bool();
		}
	};
	//перегрузка свойства тип по признаку сравниваемости
	//таким образом мы можем научить работать с нашим типом стандартную
	//библиотеку языка не нагружая функционал класса наследуемыми элементами
}

struct MyStruct {
	std::string id;
	std::string name;
	std::string patrinomyc;
	std::string surname;
};

	int main() {
		DemoBase();
		std::set<A>obj;
		obj.insert(A());
		A z, x;
		obj.contains(z);

		std::map<std::string, MyStruct> dictionary;
		std::vector<MyStruct> data{
			{"q123r15","Jack","Vitalievich","London"},
			{"q113r12","Jonh","Vitalievich","Enisten"},
			{"q113r35","Adam","Vital","frol"},
			{"q123r15","Mike","Ivanivich","Lov"},
			{"q123b15","Liam","Evgenyevich","Enistenv"}
		};
		for (size_t i = 0; i < data.size(); i++)
		{
			if (!dictionary.contains(data[i].id)) {
				dictionary.insert({ data[i].id,data[i] });
			}
			else {
				std::cout << "didn't insert data:\n" << data[i].id << '\n'
					<< data[i].name << '\n'
					<< data[i].patrinomyc << '\n'
					<< data[i].surname << '\n'
					<< "this data already has:\n"
					<< dictionary[data[i].id].id << '\n'
					<< dictionary[data[i].id].name << '\n'
					<< dictionary[data[i].id].patrinomyc << '\n'
					<< dictionary[data[i].id].surname << '\n';

			}
		}


		
		return 0;
}



